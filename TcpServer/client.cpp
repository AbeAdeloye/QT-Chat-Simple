#include "client.h"

Client::Client(const QString &userName,
               QObject *parent)
    : userName(userName),
      QObject(parent)
{ }

QString Client::nickName() const
{
    return userName;
}

void Client::setNickName(const QString &userName)
{
    this->userName = userName;
}


