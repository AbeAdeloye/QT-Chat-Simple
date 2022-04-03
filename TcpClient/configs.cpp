#include <QSettings>
#include <QDir>
#include <QDebug>

#include "configs.h"

static const QString fileName = "configs";

Configs::Configs()
    : Singleton<Configs>(*this),
      _isReaded(false),      
      _serverPort(0),
      _serverIp(QHostAddress("Unknown")),
      _nickName("Unknown")
{
    readConfigs();    
}

bool Configs::reRead()
{
    return _isReaded = readConfigs();
}

QHostAddress Configs::serverIp() const
{
    return _isReaded ? _serverIp : QHostAddress(); 
}

quint16 Configs::serverPort() const
{
    return _isReaded ? _serverPort : 0;
}

QString Configs::nickName() const
{
    return _isReaded ? _nickName : "Unknown";
}

bool Configs::readConfigs()
{    
    QString iniFilePath(QDir::currentPath() + QDir::separator() + 
                    fileName + ".ini");
    iniFilePath.replace('/', QDir::separator());
    
    if (!QFile::exists(iniFilePath)) {
        #ifdef QT_DEBUG
        qDebug() << "ini file doesn't exist";
        #endif        
        return false;
    }
    
    QSettings iniFile(iniFilePath, QSettings::IniFormat);
    
    iniFile.beginGroup("SERVER");
    _serverIp = QHostAddress(iniFile.value("Ip").toString());
    _serverPort = iniFile.value("Port").toInt();
    iniFile.endGroup();
    
    _nickName = iniFile.value("USER/nickName").toString();
    
    return _isReaded = true;
}
