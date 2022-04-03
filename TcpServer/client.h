#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>

class Client : public QObject {
    Q_OBJECT
public:
    explicit Client(const QString &userName = "",
                    QObject *parent = nullptr);
    
    QString nickName() const;
    void setNickName(const QString &userName);
    
signals:
    void newMessage(const QString &from, const QString &message);
     
public slots:
    
    
private slots:  
    
    
private:
    QString userName;
};

#endif // CLIENT_H
