#ifndef SINGLETON_H
#define SINGLETON_H

#include <QtGlobal>
#include <QDebug>
#include <typeinfo>

template <class T>
class Singleton
{
public:
    Singleton(T& ) { }

    ~Singleton() 
    {
        s_pInstance = 0;
    }

    static T* i() 
    {
        if (s_pInstance == 0) {
            s_pInstance = new T();
        }
        return (s_pInstance);
    }

private:
    static T* s_pInstance;
};

template <class T> T* Singleton<T>::s_pInstance = 0;
#endif // SINGLETON_H
