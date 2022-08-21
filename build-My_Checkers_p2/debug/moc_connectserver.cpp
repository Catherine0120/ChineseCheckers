/****************************************************************************
** Meta object code from reading C++ file 'connectserver.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../My_Checkers_p2/connectserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'connectserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_connectserver_t {
    const uint offsetsAndSize[34];
    char stringdata0[262];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_connectserver_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_connectserver_t qt_meta_stringdata_connectserver = {
    {
QT_MOC_LITERAL(0, 13), // "connectserver"
QT_MOC_LITERAL(14, 14), // "startPermitted"
QT_MOC_LITERAL(29, 0), // ""
QT_MOC_LITERAL(30, 11), // "changeColor"
QT_MOC_LITERAL(42, 13), // "getEnemyColor"
QT_MOC_LITERAL(56, 7), // "endGame"
QT_MOC_LITERAL(64, 12), // "updateMyTime"
QT_MOC_LITERAL(77, 15), // "updateEnemyTime"
QT_MOC_LITERAL(93, 11), // "updateRound"
QT_MOC_LITERAL(105, 15), // "messageReceived"
QT_MOC_LITERAL(121, 16), // "EnemyAdmitDefeat"
QT_MOC_LITERAL(138, 10), // "enemyPause"
QT_MOC_LITERAL(149, 14), // "enemyStopPause"
QT_MOC_LITERAL(164, 21), // "outputMessageReceived"
QT_MOC_LITERAL(186, 24), // "on_connectButton_clicked"
QT_MOC_LITERAL(211, 27), // "on_disconnectButton_clicked"
QT_MOC_LITERAL(239, 22) // "on_closeButton_clicked"

    },
    "connectserver\0startPermitted\0\0changeColor\0"
    "getEnemyColor\0endGame\0updateMyTime\0"
    "updateEnemyTime\0updateRound\0messageReceived\0"
    "EnemyAdmitDefeat\0enemyPause\0enemyStopPause\0"
    "outputMessageReceived\0on_connectButton_clicked\0"
    "on_disconnectButton_clicked\0"
    "on_closeButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_connectserver[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  104,    2, 0x06,    1 /* Public */,
       3,    0,  107,    2, 0x06,    3 /* Public */,
       4,    0,  108,    2, 0x06,    4 /* Public */,
       5,    0,  109,    2, 0x06,    5 /* Public */,
       6,    1,  110,    2, 0x06,    6 /* Public */,
       7,    1,  113,    2, 0x06,    8 /* Public */,
       8,    1,  116,    2, 0x06,   10 /* Public */,
       9,    3,  119,    2, 0x06,   12 /* Public */,
      10,    0,  126,    2, 0x06,   16 /* Public */,
      11,    0,  127,    2, 0x06,   17 /* Public */,
      12,    0,  128,    2, 0x06,   18 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      13,    1,  129,    2, 0x08,   19 /* Private */,
      14,    0,  132,    2, 0x08,   21 /* Private */,
      15,    0,  133,    2, 0x08,   22 /* Private */,
      16,    0,  134,    2, 0x08,   23 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void connectserver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<connectserver *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->startPermitted((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 1: _t->changeColor(); break;
        case 2: _t->getEnemyColor(); break;
        case 3: _t->endGame(); break;
        case 4: _t->updateMyTime((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->updateEnemyTime((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->updateRound((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->messageReceived((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 8: _t->EnemyAdmitDefeat(); break;
        case 9: _t->enemyPause(); break;
        case 10: _t->enemyStopPause(); break;
        case 11: _t->outputMessageReceived((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->on_connectButton_clicked(); break;
        case 13: _t->on_disconnectButton_clicked(); break;
        case 14: _t->on_closeButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (connectserver::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&connectserver::startPermitted)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (connectserver::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&connectserver::changeColor)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (connectserver::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&connectserver::getEnemyColor)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (connectserver::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&connectserver::endGame)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (connectserver::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&connectserver::updateMyTime)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (connectserver::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&connectserver::updateEnemyTime)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (connectserver::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&connectserver::updateRound)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (connectserver::*)(int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&connectserver::messageReceived)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (connectserver::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&connectserver::EnemyAdmitDefeat)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (connectserver::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&connectserver::enemyPause)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (connectserver::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&connectserver::enemyStopPause)) {
                *result = 10;
                return;
            }
        }
    }
}

const QMetaObject connectserver::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_connectserver.offsetsAndSize,
    qt_meta_data_connectserver,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_connectserver_t
, QtPrivate::TypeAndForceComplete<connectserver, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *connectserver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *connectserver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_connectserver.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int connectserver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void connectserver::startPermitted(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void connectserver::changeColor()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void connectserver::getEnemyColor()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void connectserver::endGame()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void connectserver::updateMyTime(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void connectserver::updateEnemyTime(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void connectserver::updateRound(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void connectserver::messageReceived(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void connectserver::EnemyAdmitDefeat()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void connectserver::enemyPause()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void connectserver::enemyStopPause()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
