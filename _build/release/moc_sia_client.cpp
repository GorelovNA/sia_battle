/****************************************************************************
** Meta object code from reading C++ file 'sia_client.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../sia_client.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sia_client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_sia_client_t {
    QByteArrayData data[12];
    char stringdata0[170];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_sia_client_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_sia_client_t qt_meta_stringdata_sia_client = {
    {
QT_MOC_LITERAL(0, 0, 10), // "sia_client"
QT_MOC_LITERAL(1, 11, 19), // "print_client_signal"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 3), // "str"
QT_MOC_LITERAL(4, 36, 23), // "send_com_to_serv_signal"
QT_MOC_LITERAL(5, 60, 1), // "i"
QT_MOC_LITERAL(6, 62, 15), // "slot_ready_read"
QT_MOC_LITERAL(7, 78, 19), // "slot_sock_connected"
QT_MOC_LITERAL(8, 98, 22), // "slot_sock_disconnected"
QT_MOC_LITERAL(9, 121, 15), // "slot_sock_error"
QT_MOC_LITERAL(10, 137, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(11, 166, 3) // "err"

    },
    "sia_client\0print_client_signal\0\0str\0"
    "send_com_to_serv_signal\0i\0slot_ready_read\0"
    "slot_sock_connected\0slot_sock_disconnected\0"
    "slot_sock_error\0QAbstractSocket::SocketError\0"
    "err"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_sia_client[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   50,    2, 0x0a /* Public */,
       7,    0,   51,    2, 0x0a /* Public */,
       8,    0,   52,    2, 0x0a /* Public */,
       9,    1,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,

       0        // eod
};

void sia_client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        sia_client *_t = static_cast<sia_client *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->print_client_signal((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->send_com_to_serv_signal((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 2: _t->slot_ready_read(); break;
        case 3: _t->slot_sock_connected(); break;
        case 4: _t->slot_sock_disconnected(); break;
        case 5: _t->slot_sock_error((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (sia_client::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&sia_client::print_client_signal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (sia_client::*)(const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&sia_client::send_com_to_serv_signal)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject sia_client::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_sia_client.data,
      qt_meta_data_sia_client,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *sia_client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *sia_client::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_sia_client.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int sia_client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void sia_client::print_client_signal(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void sia_client::send_com_to_serv_signal(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
