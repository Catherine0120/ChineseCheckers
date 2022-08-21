/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../My_Checkers_Server/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[40];
    char stringdata0[296];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 11), // "startTiming"
QT_MOC_LITERAL(23, 0), // ""
QT_MOC_LITERAL(24, 15), // "startEarlyTimer"
QT_MOC_LITERAL(40, 14), // "startLateTimer"
QT_MOC_LITERAL(55, 19), // "increaseRoundNumber"
QT_MOC_LITERAL(75, 14), // "earlyLCDupdate"
QT_MOC_LITERAL(90, 13), // "lateLCDupdate"
QT_MOC_LITERAL(104, 15), // "onNewConnection"
QT_MOC_LITERAL(120, 21), // "onTextMessageReceived"
QT_MOC_LITERAL(142, 3), // "str"
QT_MOC_LITERAL(146, 14), // "onDisconnected"
QT_MOC_LITERAL(161, 15), // "earlyTimerStart"
QT_MOC_LITERAL(177, 13), // "earlyLCDCount"
QT_MOC_LITERAL(191, 14), // "lateTimerStart"
QT_MOC_LITERAL(206, 12), // "lateLCDCount"
QT_MOC_LITERAL(219, 14), // "roundLCDUpdate"
QT_MOC_LITERAL(234, 21), // "earlyClientTimeUpdate"
QT_MOC_LITERAL(256, 20), // "lateClientTimeUpdate"
QT_MOC_LITERAL(277, 18) // "timeMachineRunning"

    },
    "MainWindow\0startTiming\0\0startEarlyTimer\0"
    "startLateTimer\0increaseRoundNumber\0"
    "earlyLCDupdate\0lateLCDupdate\0"
    "onNewConnection\0onTextMessageReceived\0"
    "str\0onDisconnected\0earlyTimerStart\0"
    "earlyLCDCount\0lateTimerStart\0lateLCDCount\0"
    "roundLCDUpdate\0earlyClientTimeUpdate\0"
    "lateClientTimeUpdate\0timeMachineRunning"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  122,    2, 0x06,    1 /* Public */,
       3,    0,  123,    2, 0x06,    2 /* Public */,
       4,    0,  124,    2, 0x06,    3 /* Public */,
       5,    0,  125,    2, 0x06,    4 /* Public */,
       6,    0,  126,    2, 0x06,    5 /* Public */,
       7,    0,  127,    2, 0x06,    6 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    0,  128,    2, 0x08,    7 /* Private */,
       9,    1,  129,    2, 0x08,    8 /* Private */,
       9,    0,  132,    2, 0x28,   10 /* Private | MethodCloned */,
      11,    0,  133,    2, 0x08,   11 /* Private */,
      12,    0,  134,    2, 0x08,   12 /* Private */,
      13,    0,  135,    2, 0x08,   13 /* Private */,
      14,    0,  136,    2, 0x08,   14 /* Private */,
      15,    0,  137,    2, 0x08,   15 /* Private */,
      16,    0,  138,    2, 0x08,   16 /* Private */,
      17,    0,  139,    2, 0x08,   17 /* Private */,
      18,    0,  140,    2, 0x08,   18 /* Private */,
      19,    0,  141,    2, 0x08,   19 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->startTiming(); break;
        case 1: _t->startEarlyTimer(); break;
        case 2: _t->startLateTimer(); break;
        case 3: _t->increaseRoundNumber(); break;
        case 4: _t->earlyLCDupdate(); break;
        case 5: _t->lateLCDupdate(); break;
        case 6: _t->onNewConnection(); break;
        case 7: _t->onTextMessageReceived((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->onTextMessageReceived(); break;
        case 9: _t->onDisconnected(); break;
        case 10: _t->earlyTimerStart(); break;
        case 11: _t->earlyLCDCount(); break;
        case 12: _t->lateTimerStart(); break;
        case 13: _t->lateLCDCount(); break;
        case 14: _t->roundLCDUpdate(); break;
        case 15: _t->earlyClientTimeUpdate(); break;
        case 16: _t->lateClientTimeUpdate(); break;
        case 17: _t->timeMachineRunning(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::startTiming)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::startEarlyTimer)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::startLateTimer)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::increaseRoundNumber)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::earlyLCDupdate)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::lateLCDupdate)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


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
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::startTiming()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::startEarlyTimer()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::startLateTimer()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainWindow::increaseRoundNumber()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MainWindow::earlyLCDupdate()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MainWindow::lateLCDupdate()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
