#ifndef CONFIGS_H
#define CONFIGS_H
#include <QHostAddress>

#include "Singleton"

class Configs : public Singleton<Configs> 
{
public:
    Configs();
    ~Configs() = default;
    
    bool reRead();
    QHostAddress serverIp() const;
    quint16 serverPort() const;
    QString nickName() const;  
    
protected:
    bool readConfigs();

private:
    bool _isReaded;
    quint16 _serverPort;
    QHostAddress _serverIp;
    QString _nickName;
};

#endif // CONFIGS_H
