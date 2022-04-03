#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include "connection.h"

static const int Port = 50000;

class TcpServer : public QTcpServer {
    Q_OBJECT
public:
    TcpServer(QObject *parent = 0);
    
public slots:
    bool startServer(quint16 port = Port);
    void stopServer();
    
signals:
    void newConnection(Connection *connection);
    
protected:
    void incomingConnection(qintptr socketDescriptor) override;
    
};

#endif // SERVER_H
