#ifndef CONNECTION_H
#define CONNECTION_H

#include <QObject>
#include <QTcpSocket>
#include <QTimer>
#include <QTime>
#include <QHostAddress>

#include "client.h"
#include "namespaces.h"

static const int MaxBufferSize = 1024000;

class Connection : public QTcpSocket
{
    Q_OBJECT
    
public:   
    Connection(QObject *parent = 0);
    ~Connection();
    
    QString nickName() const;
    bool sendMessage(const QString &sender, const QString &message);
    bool sendNickName(const QString &nickName);
    bool sendError(const ErrorType::ErrorType type, const QString &message);
    virtual void disconnectFromHost() override;
    QString addresPort() const;
    void setStringAddresPort();

signals:
    void newMessage(const QString &from, const QString &sender,
                    const QString &message);
    void readyForUse(Connection *connection);
    void disconnected(QString nickName, QString addresPort);

private slots:
    void sendGreetingMessage();
    void processReadyRead();
    void sendPing();

private:
    int readDataIntoBuffer(int maxSize = MaxBufferSize);
    bool readNickNameForSend();
    int dataLengthForCurrentDataType();
    bool readProtocolHeader();
    bool hasEnoughData();
    void processData();
    QString greetingMessage();    

private:
    QTimer _pingTimer;
    QTime _pongTime;
    QByteArray _buffer;
    DataType::DataType _currentDataType;
    int _numBytesForCurrentDataType;
    int _transferTimerId;
    Client *_client; 
    ConnectedState::ConnectedState _state;
    bool _isGreetingMessageSent;
    QString _nickNameForSendMessage;
    QString _addresPort;
};

#endif // CONNECTION_H
