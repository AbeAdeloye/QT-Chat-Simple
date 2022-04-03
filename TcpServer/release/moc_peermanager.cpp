/****************************************************************************
** Meta object code from reading C++ file 'peermanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../peermanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'peermanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PeerManager_t {
    QByteArrayData data[21];
    char stringdata0[236];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PeerManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PeerManager_t qt_meta_stringdata_PeerManager = {
    {
QT_MOC_LITERAL(0, 0, 11), // "PeerManager"
QT_MOC_LITERAL(1, 12, 10), // "newMessage"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 4), // "from"
QT_MOC_LITERAL(4, 29, 7), // "message"
QT_MOC_LITERAL(5, 37, 13), // "newConnection"
QT_MOC_LITERAL(6, 51, 11), // "Connection*"
QT_MOC_LITERAL(7, 63, 10), // "connection"
QT_MOC_LITERAL(8, 74, 12), // "disconnected"
QT_MOC_LITERAL(9, 87, 8), // "nickName"
QT_MOC_LITERAL(10, 96, 6), // "ipPort"
QT_MOC_LITERAL(11, 103, 23), // "greetingMessageRecieved"
QT_MOC_LITERAL(12, 127, 15), // "errorRepeatUser"
QT_MOC_LITERAL(13, 143, 10), // "disconnect"
QT_MOC_LITERAL(14, 154, 11), // "readyForUse"
QT_MOC_LITERAL(15, 166, 14), // "newConnections"
QT_MOC_LITERAL(16, 181, 11), // "sendMessage"
QT_MOC_LITERAL(17, 193, 8), // "fromName"
QT_MOC_LITERAL(18, 202, 10), // "senderName"
QT_MOC_LITERAL(19, 213, 10), // "stopServer"
QT_MOC_LITERAL(20, 224, 11) // "startServer"

    },
    "PeerManager\0newMessage\0\0from\0message\0"
    "newConnection\0Connection*\0connection\0"
    "disconnected\0nickName\0ipPort\0"
    "greetingMessageRecieved\0errorRepeatUser\0"
    "disconnect\0readyForUse\0newConnections\0"
    "sendMessage\0fromName\0senderName\0"
    "stopServer\0startServer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PeerManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x06 /* Public */,
       5,    1,   74,    2, 0x06 /* Public */,
       8,    2,   77,    2, 0x06 /* Public */,
      11,    2,   82,    2, 0x06 /* Public */,
      12,    2,   87,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    2,   92,    2, 0x08 /* Private */,
      14,    0,   97,    2, 0x08 /* Private */,
      15,    1,   98,    2, 0x08 /* Private */,
      16,    3,  101,    2, 0x08 /* Private */,
      19,    0,  108,    2, 0x08 /* Private */,
      20,    0,  109,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    9,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    9,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    9,   10,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    9,   10,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   17,   18,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PeerManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PeerManager *_t = static_cast<PeerManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newMessage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->newConnection((*reinterpret_cast< Connection*(*)>(_a[1]))); break;
        case 2: _t->disconnected((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->greetingMessageRecieved((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: _t->errorRepeatUser((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 5: _t->disconnect((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->readyForUse(); break;
        case 7: _t->newConnections((*reinterpret_cast< Connection*(*)>(_a[1]))); break;
        case 8: _t->sendMessage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 9: _t->stopServer(); break;
        case 10: _t->startServer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Connection* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Connection* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (PeerManager::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PeerManager::newMessage)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (PeerManager::*_t)(Connection * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PeerManager::newConnection)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (PeerManager::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PeerManager::disconnected)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (PeerManager::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PeerManager::greetingMessageRecieved)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (PeerManager::*_t)(const QString , const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PeerManager::errorRepeatUser)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PeerManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PeerManager.data,
      qt_meta_data_PeerManager,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PeerManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PeerManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PeerManager.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Singleton<PeerManager>"))
        return static_cast< Singleton<PeerManager>*>(this);
    return QObject::qt_metacast(_clname);
}

int PeerManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void PeerManager::newMessage(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PeerManager::newConnection(Connection * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PeerManager::disconnected(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PeerManager::greetingMessageRecieved(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PeerManager::errorRepeatUser(const QString _t1, const QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
