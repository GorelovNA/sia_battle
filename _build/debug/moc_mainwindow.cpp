/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[17];
    char stringdata0[244];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 23), // "on_butt_connect_clicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 14), // "name_pass_edit"
QT_MOC_LITERAL(4, 51, 11), // "redrow_func"
QT_MOC_LITERAL(5, 63, 11), // "int[10][10]"
QT_MOC_LITERAL(6, 75, 3), // "arr"
QT_MOC_LITERAL(7, 79, 19), // "slot_send_name_pass"
QT_MOC_LITERAL(8, 99, 27), // "on_action_journal_triggered"
QT_MOC_LITERAL(9, 127, 7), // "checked"
QT_MOC_LITERAL(10, 135, 13), // "close_journal"
QT_MOC_LITERAL(11, 149, 22), // "on_action_IP_triggered"
QT_MOC_LITERAL(12, 172, 16), // "update_server_IP"
QT_MOC_LITERAL(13, 189, 3), // "str"
QT_MOC_LITERAL(14, 193, 21), // "slot_send_com_to_serv"
QT_MOC_LITERAL(15, 215, 1), // "i"
QT_MOC_LITERAL(16, 217, 26) // "on_actionRestart_triggered"

    },
    "MainWindow\0on_butt_connect_clicked\0\0"
    "name_pass_edit\0redrow_func\0int[10][10]\0"
    "arr\0slot_send_name_pass\0"
    "on_action_journal_triggered\0checked\0"
    "close_journal\0on_action_IP_triggered\0"
    "update_server_IP\0str\0slot_send_com_to_serv\0"
    "i\0on_actionRestart_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    1,   66,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    1,   70,    2, 0x08 /* Private */,
      10,    0,   73,    2, 0x08 /* Private */,
      11,    0,   74,    2, 0x08 /* Private */,
      12,    1,   75,    2, 0x08 /* Private */,
      14,    1,   78,    2, 0x08 /* Private */,
      16,    0,   81,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_butt_connect_clicked(); break;
        case 1: _t->name_pass_edit(); break;
        case 2: _t->redrow_func((*reinterpret_cast< int(*)[10][10]>(_a[1]))); break;
        case 3: _t->slot_send_name_pass(); break;
        case 4: _t->on_action_journal_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->close_journal(); break;
        case 6: _t->on_action_IP_triggered(); break;
        case 7: _t->update_server_IP((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->slot_send_com_to_serv((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 9: _t->on_actionRestart_triggered(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
