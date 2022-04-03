#include <QtAlgorithms>

#include "peermanager.h"

PeerManager::PeerManager(QObject *parent) 
    : QObject(parent),
      Singleton<PeerManager>(*this)
{    
    _tcpServer = new TcpServer(this);
    
    connect(_tcpServer, SIGNAL(newConnection(Connection*)), 
            this, SLOT(newConnections(Connection*)), Qt::DirectConnection);
    connect(_tcpServer, SIGNAL(newConnection(Connection*)),
            this, SIGNAL(newConnection(Connection*)));
}

PeerManager::~PeerManager()
{    
    disconectedAllPeers();
    _peers.clear();
    delete _tcpServer;
}

TcpServer *PeerManager::server() const
{
    return _tcpServer;
}

void PeerManager::disconectedAllPeers()
{
   foreach (Connection *peer, _peers.values()) {       
        peer->disconnectFromHost();
        QObject::disconnect(peer, 0, 0, 0);
    }
}

void PeerManager::disconnect(QString nickName, QString ipPort)
{
    if (_peers.remove(nickName) != 0) {       
        foreach (Connection *value, _peers) {
            value->sendError(ErrorType::DisconectedUser, nickName);
        }
    }         
    
    emit disconnected(nickName, ipPort);  
}

void PeerManager::readyForUse(Connection *sender)
{  
    if (!sender)
        return;
    
    /* Проверяем на повторный никнейм*/
    if (_peers.contains(sender->nickName())) {
        sender->sendError(ErrorType::RepeatedUser, sender->nickName());
        QObject::disconnect(connection, 0, 0, 0);
        while (sender->flush() == false); //ToDo: Добавить счетчик
        emit errorRepeatUser(sender->nickName(), sender->addresPort());
        sender->disconnectFromHost();
        sender->deleteLater();
        return;
    }
    
    /* Отправляем никнейм нового юзера и новому юзеру все никнеймы*/
    QHash<QString, Connection *>::iterator i;
    for (i = _peers.begin(); i != _peers.end(); ++i) {
        i.value()->sendNickName(sender->nickName());
        sender->sendNickName(i.key());
    }
    
    _peers.insert(sender->nickName(), sender);
    connect(sender, SIGNAL(newMessage(QString,QString,QString)), 
            this, SLOT(sendMessage(QString,QString,QString)));  

    emit greetingMessageRecieved(sender->nickName(), 
                                 sender->addresPort());    
}

void PeerManager::newConnections(Connection *connection)
{   
    connection->setStringAddresPort(); // ToDo: Эта функция должна быть private
    connect(connection, SIGNAL(disconnected(QString, QString)),
            this, SLOT(disconnect(QString, QString)));
    connect(connection, SIGNAL(readyForUse()), this, SLOT(readyForUse()), 
            Qt::DirectConnection);
    connect(connection, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SIGNAL(connectionError(QAbstractSocket::SocketError)));
}

void PeerManager::sendMessage(const QString &fromName, const QString &senderName,
                              const QString &message)
{
    Connection *sender = _peers.value(fromName);
    if (sender != nullptr && sender->sendMessage(senderName, message))
        emit newMessage(senderName, message);    
}

void PeerManager::stopServer()
{
    if (_tcpServer != nullptr) {
        disconectedAllPeers();
        qDeleteAll(_peers);
        _tcpServer->stopServer();
    }
}

void PeerManager::startServer()
{
    if (_tcpServer == nullptr)
        _tcpServer = new TcpServer();
    
    _tcpServer->startServer();
}
