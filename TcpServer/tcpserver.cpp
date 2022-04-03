#include <QDebug>
#include "tcpserver.h"

TcpServer::TcpServer(QObject *parent)
    : QTcpServer(parent)
{ }

bool TcpServer::startServer(quint16 port)
{
    if (!listen(QHostAddress::Any, (quint16)port)) {
        #ifdef QT_DEBUG
        qDebug() << "Server not started";
        qDebug() << errorString();
        #endif
        return false;
    }
    
    return true;
}

void TcpServer::stopServer() 
{
    close();
}

void TcpServer::incomingConnection(qintptr socketDescriptor) 
{
    Connection *connection = new Connection(this);
    connection->setSocketDescriptor(socketDescriptor);
    emit newConnection(connection);
}
