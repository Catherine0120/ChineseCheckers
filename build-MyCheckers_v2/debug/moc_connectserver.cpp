/****************************************************************************
** Meta object code from reading C++ file 'connectserver.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../MyCheckers_v2/connectserver.h"
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
    const uint offsetsAndSize[20];
    char stringdata0[162];
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
QT_MOC_LITERAL(64, 21), // "outputMessageReceived"
QT_MOC_LITERAL(86, 24), // "on_connectButton_clicked"
QT_MOC_LITERAL(111, 27), // "on_disconnectButton_clicked"
QT_MOC_LITERAL(139, 22) // "on_closeButton_clicked"

    },
    "connectserver\0startPermitted\0\0changeColor\0"
    "getEnemyColor\0endGame\0outputMessageReceived\0"
    "on_connectButton_clicked\0"
    "on_disconnectButton_clicked\0"
    "on_closeButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_connectserver[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x06,    1 /* Public */,
       3,    0,   63,    2, 0x06,    2 /* Public */,
       4,    0,   64,    2, 0x06,    3 /* Public */,
       5,    0,   65,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    1,   66,    2, 0x08,    5 /* Private */,
       7,    0,   69,    2, 0x08,    7 /* Private */,
       8,    0,   70,    2, 0x08,    8 /* Private */,
       9,    0,   71,    2, 0x08,    9 /* Private */,

 // signals: parameters
    QMetaType::Void,
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
        case 0: _t->startPermitted(); break;
        case 1: _t->changeColor(); break;
        case 2: _t->getEnemyColor(); break;
        case 3: _t->endGame(); break;
        case 4: _t->outputMessageReceived((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->on_connectButton_clicked(); break;
        case 6: _t->on_disconnectButton_clicked(); break;
        case 7: _t->on_closeButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (connectserver::*)();
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
    }
}

const QMetaObject connectserver::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_connectserver.offsetsAndSize,
    qt_meta_data_connectserver,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_connectserver_t
, QtPrivate::TypeAndForceComplete<connectserver, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
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
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void connectserver::startPermitted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
