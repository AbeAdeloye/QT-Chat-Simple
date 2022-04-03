/****************************************************************************
** Meta object code from reading C++ file 'connection.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../connection.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'connection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Connection_t {
    QByteArrayData data[17];
    char stringdata0[199];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Connection_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Connection_t qt_meta_stringdata_Connection = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Connection"
QT_MOC_LITERAL(1, 11, 10), // "newMessage"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 4), // "from"
QT_MOC_LITERAL(4, 28, 7), // "message"
QT_MOC_LITERAL(5, 36, 7), // "newUser"
QT_MOC_LITERAL(6, 44, 8), // "nickName"
QT_MOC_LITERAL(7, 53, 11), // "readyForUse"
QT_MOC_LITERAL(8, 65, 17), // "serverIsConnected"
QT_MOC_LITERAL(9, 83, 11), // "isConnected"
QT_MOC_LITERAL(10, 95, 16), // "disconnectedUser"
QT_MOC_LITERAL(11, 112, 14), // "repeatNickName"
QT_MOC_LITERAL(12, 127, 19), // "sendGreetingMessage"
QT_MOC_LITERAL(13, 147, 16), // "processReadyRead"
QT_MOC_LITERAL(14, 164, 8), // "sendPing"
QT_MOC_LITERAL(15, 173, 10), // "tryConnect"
QT_MOC_LITERAL(16, 184, 14) // "stopTryConnect"

    },
    "Connection\0newMessage\0\0from\0message\0"
    "newUser\0nickName\0readyForUse\0"
    "serverIsConnected\0isConnected\0"
    "disconnectedUser\0repeatNickName\0"
    "sendGreetingMessage\0processReadyRead\0"
    "sendPing\0tryConnect\0stopTryConnect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Connection[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x06 /* Public */,
       5,    1,   74,    2, 0x06 /* Public */,
       7,    0,   77,    2, 0x06 /* Public */,
       8,    1,   78,    2, 0x06 /* Public */,
      10,    1,   81,    2, 0x06 /* Public */,
      11,    0,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   85,    2, 0x08 /* Private */,
      13,    0,   86,    2, 0x08 /* Private */,
      14,    0,   87,    2, 0x08 /* Private */,
      15,    0,   88,    2, 0x08 /* Private */,
      16,    0,   89,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Connection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Connection *_t = static_cast<Connection *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newMessage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->newUser((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->readyForUse(); break;
        case 3: _t->serverIsConnected((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->disconnectedUser((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->repeatNickName(); break;
        case 6: _t->sendGreetingMessage(); break;
        case 7: _t->processReadyRead(); break;
        case 8: _t->sendPing(); break;
        case 9: _t->tryConnect(); break;
        case 10: _t->stopTryConnect(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Connection::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Connection::newMessage)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Connection::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Connection::newUser)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Connection::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Connection::readyForUse)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Connection::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Connection::serverIsConnected)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Connection::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Connection::disconnectedUser)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Connection::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Connection::repeatNickName)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Connection::staticMetaObject = {
    { &QTcpSocket::staticMetaObject, qt_meta_stringdata_Connection.data,
      qt_meta_data_Connection,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Connection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Connection::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Connection.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Singleton<Connection>"))
        return static_cast< Singleton<Connection>*>(this);
    return QTcpSocket::qt_metacast(_clname);
}

int Connection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Connection::newMessage(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Connection::newUser(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Connection::readyForUse()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Connection::serverIsConnected(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Connection::disconnectedUser(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Connection::repeatNickName()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
