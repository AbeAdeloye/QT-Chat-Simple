#ifndef CONNECTION_H
#define CONNECTION_H

#include <QObject>
#include <QTcpSocket>
#include <QTimer>
#include <QTime>
#include <QHostAddress>

#include "Singleton"
#include "namespaces.h"


static const int MaxBufferSize = 1024000;

class Connection : public QTcpSocket, public Singleton<Connection>
{
    Q_OBJECT
    
public:        
    Connection(QObject *parent = 0);
    ~Connection();
    
    bool sendMessage(const QString &sender, const QString &message);

signals:
    void newMessage(const QString &from, const QString &message);
    void newUser(const QString &nickName);
    void readyForUse();
    void serverIsConnected(bool isConnected);
    void disconnectedUser(const QString &nickName);
    void repeatNickName();

private slots:
    void sendGreetingMessage();
    void processReadyRead();
    void sendPing();
    void tryConnect();
    void stopTryConnect();

private:
    int readDataIntoBuffer(int maxSize = MaxBufferSize);
    bool readExtraData();
    int dataLengthForCurrentDataType();
    bool readProtocolHeader();
    bool hasEnoughData();
    void processData();
    QString greetingMessage();
    void processError(const QString &errorType);

private:
    QByteArray _buffer;
    DataType::DataType _currentDataType;
    int _numBytesForCurrentDataType;
    bool _isGreetingMessageSent;
    bool _isServerFound;
    QString _extraData;
    QTimer _pingTimer;
    QTime _pongTime;
};

#endif // CONNECTION_H
