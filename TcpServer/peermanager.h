#ifndef PEERMANAGER_H
#define PEERMANAGER_H

#include <QObject>
#include <QHash>
#include "Singleton"
#include "TcpServer.h"
#include "connection.h"

class PeerManager : public QObject, public Singleton<PeerManager>
{
    Q_OBJECT
public:
    explicit PeerManager(QObject *parent = nullptr);
    ~PeerManager();
    
    TcpServer *server() const;

private:
    void disconectedAllPeers();
    
private slots:
    void disconnect(QString nickName, QString ipPort);
    void readyForUse(Connection *sender);
    void newConnections(Connection *connection);
    void sendMessage(const QString &fromName, const QString &senderName,
                     const QString &message);
    void stopServer();
    void startServer();

signals:
    void newMessage(const QString &from, const QString &message);
    void newConnection(Connection *connection);
    void disconnected(QString nickName, QString ipPort);
    void greetingMessageRecieved(const QString &nickName,const QString &ipPort);
    void errorRepeatUser(const QString nickName, const QString ipPort);
    
private:
    TcpServer *_tcpServer;
    //QList<Connection *> peers;
    QHash<QString, Connection *> _peers;
};

#endif // PEERMANAGER_H
