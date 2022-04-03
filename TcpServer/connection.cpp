#include "connection.h"

constexpr int PingInterval = 7 * 1000;
constexpr int PongInterval = 45 * 1000;
constexpr int TransferTimeout = 30 * 1000;
constexpr char Separator = ' ';

Connection::Connection(QObject *parent)
    : QTcpSocket(parent)
{
    _transferTimerId = 0;
    _isGreetingMessageSent = true; // ToDo: сменить true на false
    _client = new Client("Unknow", this);
    _currentDataType = DataType::Undefined;
    _numBytesForCurrentDataType = -1;
    _state = ConnectedState::WaitingGreeting;
    _addresPort = "";
    _pingTimer.setInterval(PingInterval);
    
    connect(this, SIGNAL(readyRead()), this, SLOT(processReadyRead()));
    connect(this, SIGNAL(disconnected()), &_pingTimer, SLOT(stop()));
    connect(&_pingTimer, SIGNAL(timeout()), this, SLOT(sendPing()));
    connect(this, SIGNAL(connected()), this, SLOT(sendGreetingMessage()));    
}

Connection::~Connection()
{
    delete _client;
}

QString Connection::nickName() const
{
    return _client->nickName();
}

bool Connection::sendMessage(const QString &sender, const QString &message)
{
    if (message.isEmpty())
        return false;
    
    QByteArray snd = sender.toUtf8();
    QByteArray msg = message.toUtf8();
    QByteArray data = "MSSG"; // Почему-то если объеденить data, не работает
    data += Separator + QByteArray::number(snd.size()) + 
            Separator + snd + Separator + 
            QByteArray::number(msg.size()) + Separator + msg;
    return write(data) == data.size();
}

bool Connection::sendNickName(const QString &nickName)
{
    if (nickName.isEmpty())
        return false;
    
    QByteArray newUser = nickName.toUtf8();
    QByteArray data= "NICK"; // Почему-то если объеденить data, не работает
    data += Separator + QByteArray::number(newUser.size()) + 
            Separator + newUser;
    
    return write(data) == data.size();
}

bool Connection::sendError(const ErrorType::ErrorType type, const QString &message)
{
    #ifdef QT_DEBUG
    qDebug() << "Error message";
    #endif
    
    if (message.isEmpty())
        return false;
    
    QString mssg = "ERRO ";
    if (type == ErrorType::DisconectedUser) {
        mssg += QString::number(6) + " DISCON ";
    } else if (type == ErrorType::RepeatedUser) {
        mssg += QString::number(6) + " REPEAT ";
    } else {
        return false;
    }   
    mssg += QString::number(message.size()) + Separator + message;
    
    QByteArray data = mssg.toUtf8();
    return write(data) == data.size();
}

void Connection::disconnectFromHost()
{
    QAbstractSocket::disconnectFromHost();
    emit disconnected(nickName(), addresPort());
}

QString Connection::addresPort() const
{
    return _addresPort;
}

void Connection::sendGreetingMessage()
{
    QByteArray greeting = greetingMessage().toUtf8();
    QByteArray data = "GRTG " + QByteArray::number(greeting.size()) +
            Separator + greeting;
    if (write(data) == data.size())
        _isGreetingMessageSent = true;
}

void Connection::processReadyRead()
{
    if (_state == ConnectedState::WaitingGreeting) {
        if (!readProtocolHeader())
            return;
        
        if (_currentDataType != DataType::Greeting) {
            abort();
            return;
        }
        _state = ConnectedState::ReadingGreeting;            
    }
    
    if (_state == ConnectedState::ReadingGreeting) {
        
        if (!hasEnoughData())
            return;
        
        _buffer = read(_numBytesForCurrentDataType);
        if (_buffer.size() != _numBytesForCurrentDataType) {
            abort();
            return;
        }
              
        _client->setNickName(QString(_buffer));
        _currentDataType = DataType::Undefined;
        _numBytesForCurrentDataType = 0;
        _buffer.clear();
        
        if (!isValid()) {
            abort();
            return;
        }
        
        if (!_isGreetingMessageSent)
            sendGreetingMessage();
        
        _pingTimer.start();
        _pongTime.start();
        _state = ConnectedState::ReadyForUse;
        emit readyForUse(this);           
    }
    
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
    write("PING 1 p");
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
            
        if (_buffer.endsWith(Separator)) {
            _buffer.chop(1); // Удаляем сепаратор
            break;
        }
    }
    
    return _buffer.size() - numBytesBeforeRead;
}

bool Connection::readNickNameForSend()
{
    _nickNameForSendMessage.clear();
    
    int numBytesForNickName = dataLengthForCurrentDataType();
    _buffer = read(numBytesForNickName);
    
    if (_buffer.size() != numBytesForNickName)
        return false;
    _nickNameForSendMessage = QString::fromUtf8(_buffer);
    
    read(1);
    _buffer.clear();
    return true;        
}

int Connection::dataLengthForCurrentDataType()
{
    if (bytesAvailable() <= 0 || readDataIntoBuffer() <= 0) 
        return 0;
    
    int number = _buffer.toInt();
    _buffer.clear();
    return number;
}

bool Connection::readProtocolHeader()
{
    if (readDataIntoBuffer() <= 0) {
        _transferTimerId = startTimer(TransferTimeout);
        return false;
    }
    
    if (_buffer == "PING") {
        _currentDataType = DataType::Ping;
    } else if (_buffer == "MSSG") {
        _buffer.clear();
        if (!readNickNameForSend()) {
            abort();
            return false;
        }
        _currentDataType = DataType::Message;           
    } else if (_buffer == "PONG") {
        _currentDataType = DataType::Pong;
    } else if (_buffer == "GRTG") {
        _currentDataType = DataType::Greeting;   
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
        _transferTimerId = startTimer(TransferTimeout);
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
        emit newMessage(_nickNameForSendMessage, nickName(),
                        QString::fromUtf8(_buffer));
        break;
    case DataType::Ping:
        write("PONG 1 p");
        break;
    case DataType::Pong:
        _pongTime.restart();
    default:
        break;
    }
    
    _currentDataType = DataType::Undefined;
    _numBytesForCurrentDataType = 0;
    _buffer.clear();    
}

QString Connection::greetingMessage()
{
    return QString("Hello %1").arg(_client->nickName());
}

void Connection::setStringAddresPort()
{
    QStringList splitAddres = peerAddress().toString().split(':');
    
    /* В случае 0 возвращаем 1, чтобы можно было вычесть 1 во втором случае*/
    _addresPort = splitAddres.at((splitAddres.size() == 0 ?
                                      1 : splitAddres.size()) - 1);
    _addresPort += ':' + QString::number(peerPort());    
}
