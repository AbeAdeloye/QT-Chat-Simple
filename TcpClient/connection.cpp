#include "connection.h"
#include "configs.h"

constexpr int PingInterval = 5 * 1000;
constexpr int PongInterval = PingInterval * 10;
constexpr int PingRandomValue = 2 * 1000;
constexpr char Separator = ' ';

Connection::Connection(QObject *parent)
    : Singleton<Connection>(*this)
{
    _isGreetingMessageSent = false;
    _isServerFound = false;
    _currentDataType = DataType::Undefined;
    _numBytesForCurrentDataType = -1;
    _pingTimer.setInterval(PingInterval + qrand() % PingRandomValue);    

    connect(this, SIGNAL(readyRead()), this, SLOT(processReadyRead()));
    connect(this, SIGNAL(connected()), this, SLOT(stopTryConnect()));
    connect(this, SIGNAL(connected()), this, SLOT(sendGreetingMessage()));
    connect(&_pingTimer, SIGNAL(timeout()), this, SLOT(tryConnect()));
    connect(this, SIGNAL(disconnected()), &_pingTimer, SLOT(start()));
    
    _pingTimer.start();
    _pongTime.start();
    tryConnect();    
}

Connection::~Connection()
{ }

bool Connection::sendMessage(const QString &sender, const QString &message)
{
    if (message.isEmpty())
        return false;
    
    #ifdef QT_DEBUG
    qDebug() << QString("Message: %1 to %2").arg(message, sender);
    #endif
    
    QByteArray snd = sender.toUtf8();
    QByteArray msg = message.toUtf8();
    QByteArray data = "MSSG " + QByteArray::number(snd.size()) + Separator +
            snd + Separator + QByteArray::number(msg.size()) + Separator + msg;
    return write(data) == data.size();
}

void Connection::sendGreetingMessage()
{
    #ifdef QT_DEBUG
    qDebug() << "Greeting message send";
    #endif
    
    if (!_isGreetingMessageSent) {
        QByteArray greeting = Configs::i()->nickName().toUtf8();
        QByteArray data = "GRTG " + QByteArray::number(greeting.size()) +
                Separator + greeting;
        
        if (write(data) == data.size()) {        
            _isGreetingMessageSent = true;
            emit readyRead();
        }
    }
}

void Connection::processReadyRead()
{    
    
    #ifdef QT_DEBUG
    qDebug() << "Process ready read";
    #endif
    
    do {
        if (_currentDataType == DataType::Undefined) {
            if (!readProtocolHeader())
                return;
        }
        
        if (!hasEnoughData())
            return;        
        processData();     
    } while (bytesAvailable() > 0);
}

void Connection::sendPing()
{
    #ifdef QT_DEBUG
    qDebug() << _pongTime.elapsed();
    #endif
    
    if (_pongTime.elapsed() > PongInterval) {
        _isGreetingMessageSent = false;
        _isServerFound = false;
        disconnect(&_pingTimer, SIGNAL(timeout()), this, SLOT(sendPing()));
        connect(&_pingTimer, SIGNAL(timeout()), this, SLOT(tryConnect()));
        emit serverIsConnected(false);
        abort();
        return;
    }        
    
    if (this->isOpen())
        write("PING 1 p");
}

void Connection::tryConnect()
{
    #ifdef QT_DEBUG
    qDebug() << "Try connect to server";
    #endif
    
    emit serverIsConnected(false);
    
    if (_isServerFound) {
        disconnect(&_pingTimer, SIGNAL(timeout()), this, SLOT(sendPing()));
        connect(&_pingTimer, SIGNAL(timeout()), this, SLOT(tryConnect()));
        _isServerFound = false;     
        _isGreetingMessageSent = false;
    }
    
    if (this->state() == QAbstractSocket::UnconnectedState)
        connectToHost(Configs::i()->serverIp(), Configs::i()->serverPort());    
}

void Connection::stopTryConnect()
{
    #ifdef QT_DEBUG
    qDebug() << "Stop try connect to Server";
    #endif
        
    disconnect(&_pingTimer, SIGNAL(timeout()), this, SLOT(tryConnect()));
    connect(&_pingTimer, SIGNAL(timeout()), this, SLOT(sendPing()));
    _isServerFound = true;
    _pongTime.restart();
    // readAll(); // Очистка буфера
    emit serverIsConnected(true);
}

int Connection::readDataIntoBuffer(int maxSize)
{
    if (maxSize > MaxBufferSize)
        return 0;
    
    int numBytesBeforeRead = _buffer.size();
    if (numBytesBeforeRead == MaxBufferSize) {
        abort();
        return 0;
    }
    
    while (bytesAvailable() > 0 && _buffer.size() < maxSize) {
        _buffer.append(read(1));
        
        if (_buffer == "\n") {
            _buffer.clear();
            _currentDataType = DataType::Undefined;
            return -1;
        }
            
        if (_buffer.endsWith(Separator))
            break;
    }
    
    return _buffer.size() - numBytesBeforeRead;
}

bool Connection::readExtraData()
{
    _extraData.clear();
    
    int numBytesForExtraData = dataLengthForCurrentDataType();
    _buffer = read(numBytesForExtraData);
    
    if (_buffer.size() != numBytesForExtraData)
        return false;    
    _extraData = QString::fromUtf8(_buffer);
    
    read(1);
    _buffer.clear();
    return true;        
}

int Connection::dataLengthForCurrentDataType()
{
    if (bytesAvailable() <= 0 || readDataIntoBuffer() <= 0 ||
            !_buffer.endsWith(Separator)) 
        return 0;
    
    _buffer.chop(1);
    int number = _buffer.toInt();
    _buffer.clear();
    return number;
}

bool Connection::readProtocolHeader()
{
    if (readDataIntoBuffer() <= 0) {
        return false;
    }
    
    _buffer.chop(1); // Удаляем Separator
    if (_buffer == "PING") {
        _currentDataType = DataType::Ping;
    } else if (_buffer == "MSSG") {
        _buffer.clear();
        if (!readExtraData()) {
            abort();
            return false;
        }
        _currentDataType = DataType::Message;           
    } else if (_buffer == "PONG") {
        _currentDataType = DataType::Pong;
    } else if (_buffer == "GRTG") {
        _currentDataType = DataType::Greeting;   
    } else if(_buffer == "NICK") {
        _currentDataType = DataType::Nick;
    } else if (_buffer == "ERRO") {
        _buffer.clear();
        if (!readExtraData()) {
            abort();
            return false;
        }
        _currentDataType = DataType::Error;
    } else {
        _currentDataType = DataType::Undefined;
        abort();
        return false;
    }
    
    _buffer.clear();
    _numBytesForCurrentDataType = dataLengthForCurrentDataType();
    return true;        
}

bool Connection::hasEnoughData()
{
    
    if (_numBytesForCurrentDataType <= 0)
        _numBytesForCurrentDataType = dataLengthForCurrentDataType();
    
    if (bytesAvailable() < _numBytesForCurrentDataType ||
            _numBytesForCurrentDataType <= 0) {
        return false;
    }
    
    return true;
}

void Connection::processData()
{
    _buffer = read(_numBytesForCurrentDataType);
    if (_buffer.size() != _numBytesForCurrentDataType) {
        abort();
        return;
    }
    
    switch (_currentDataType) {
    case DataType::Message:
        emit newMessage(_extraData, _buffer);
        break;
    case DataType::Ping:
        write("PONG 1 p");
        break;
    case DataType::Nick:
        emit newUser(_buffer);
        break;
    case DataType::Pong:
        emit serverIsConnected(true);
        _pongTime.restart();
        break;
    case DataType::Error:
        processError(_extraData);
        break;        
    default:
        break;
    }
    
    _currentDataType = DataType::Undefined;
    _numBytesForCurrentDataType = 0;
    _buffer.clear();    
}

void Connection::processError(const QString &errorType)
{
    #ifdef QT_DEBUG
    qDebug() << "Error message";
    #endif
    
    if (errorType == "DISCON") {
        emit disconnectedUser(_buffer);
    } else if (errorType == "REPEAT") {
        _pingTimer.stop();
        disconnect(&_pingTimer, SIGNAL(timeout()), this, SLOT(sendPing()));
        abort();
        emit repeatNickName();        
    } else {
        abort();
        return;
    }
}
