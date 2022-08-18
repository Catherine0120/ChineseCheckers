/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../MyCheckers_v2/mainwindow.h"
#include <QtGui/qtextcursor.h>
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
    const uint offsetsAndSize[62];
    char stringdata0[523];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 9), // "mouseMove"
QT_MOC_LITERAL(21, 0), // ""
QT_MOC_LITERAL(22, 12), // "QMouseEvent*"
QT_MOC_LITERAL(35, 5), // "event"
QT_MOC_LITERAL(41, 12), // "startMyTimer"
QT_MOC_LITERAL(54, 15), // "startEnemyTimer"
QT_MOC_LITERAL(70, 19), // "increaseRoundNumber"
QT_MOC_LITERAL(90, 10), // "endMyRound"
QT_MOC_LITERAL(101, 13), // "endEnemyRound"
QT_MOC_LITERAL(115, 19), // "on_redColor_clicked"
QT_MOC_LITERAL(135, 22), // "on_yellowColor_clicked"
QT_MOC_LITERAL(158, 21), // "on_greenColor_clicked"
QT_MOC_LITERAL(180, 20), // "on_blueColor_clicked"
QT_MOC_LITERAL(201, 22), // "on_purpleColor_clicked"
QT_MOC_LITERAL(224, 20), // "on_pinkColor_clicked"
QT_MOC_LITERAL(245, 23), // "on_selectButton_pressed"
QT_MOC_LITERAL(269, 23), // "on_selectButton_clicked"
QT_MOC_LITERAL(293, 9), // "drawMouse"
QT_MOC_LITERAL(303, 24), // "on_open_start_collection"
QT_MOC_LITERAL(328, 22), // "on_open_connect_server"
QT_MOC_LITERAL(351, 27), // "on_open_admit_defeat_action"
QT_MOC_LITERAL(379, 20), // "on_open_start_action"
QT_MOC_LITERAL(400, 22), // "on_startButton_clicked"
QT_MOC_LITERAL(423, 16), // "myTimerSlotStart"
QT_MOC_LITERAL(440, 10), // "myLCDCount"
QT_MOC_LITERAL(451, 19), // "enemyTimerSlotStart"
QT_MOC_LITERAL(471, 13), // "enemyLCDCount"
QT_MOC_LITERAL(485, 16), // "roundLCDIncrease"
QT_MOC_LITERAL(502, 8), // "myLCDend"
QT_MOC_LITERAL(511, 11) // "enemyLCDend"

    },
    "MainWindow\0mouseMove\0\0QMouseEvent*\0"
    "event\0startMyTimer\0startEnemyTimer\0"
    "increaseRoundNumber\0endMyRound\0"
    "endEnemyRound\0on_redColor_clicked\0"
    "on_yellowColor_clicked\0on_greenColor_clicked\0"
    "on_blueColor_clicked\0on_purpleColor_clicked\0"
    "on_pinkColor_clicked\0on_selectButton_pressed\0"
    "on_selectButton_clicked\0drawMouse\0"
    "on_open_start_collection\0"
    "on_open_connect_server\0"
    "on_open_admit_defeat_action\0"
    "on_open_start_action\0on_startButton_clicked\0"
    "myTimerSlotStart\0myLCDCount\0"
    "enemyTimerSlotStart\0enemyLCDCount\0"
    "roundLCDIncrease\0myLCDend\0enemyLCDend"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  176,    2, 0x06,    1 /* Public */,
       5,    0,  179,    2, 0x06,    3 /* Public */,
       6,    0,  180,    2, 0x06,    4 /* Public */,
       7,    0,  181,    2, 0x06,    5 /* Public */,
       8,    0,  182,    2, 0x06,    6 /* Public */,
       9,    0,  183,    2, 0x06,    7 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      10,    0,  184,    2, 0x08,    8 /* Private */,
      11,    0,  185,    2, 0x08,    9 /* Private */,
      12,    0,  186,    2, 0x08,   10 /* Private */,
      13,    0,  187,    2, 0x08,   11 /* Private */,
      14,    0,  188,    2, 0x08,   12 /* Private */,
      15,    0,  189,    2, 0x08,   13 /* Private */,
      16,    0,  190,    2, 0x08,   14 /* Private */,
      17,    0,  191,    2, 0x08,   15 /* Private */,
      18,    1,  192,    2, 0x08,   16 /* Private */,
      19,    0,  195,    2, 0x08,   18 /* Private */,
      20,    0,  196,    2, 0x08,   19 /* Private */,
      21,    0,  197,    2, 0x08,   20 /* Private */,
      22,    0,  198,    2, 0x08,   21 /* Private */,
      23,    0,  199,    2, 0x08,   22 /* Private */,
      24,    0,  200,    2, 0x08,   23 /* Private */,
      25,    0,  201,    2, 0x08,   24 /* Private */,
      26,    0,  202,    2, 0x08,   25 /* Private */,
      27,    0,  203,    2, 0x08,   26 /* Private */,
      28,    0,  204,    2, 0x08,   27 /* Private */,
      29,    0,  205,    2, 0x08,   28 /* Private */,
      30,    0,  206,    2, 0x08,   29 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
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
        case 0: _t->mouseMove((*reinterpret_cast< std::add_pointer_t<QMouseEvent*>>(_a[1]))); break;
        case 1: _t->startMyTimer(); break;
        case 2: _t->startEnemyTimer(); break;
        case 3: _t->increaseRoundNumber(); break;
        case 4: _t->endMyRound(); break;
        case 5: _t->endEnemyRound(); break;
        case 6: _t->on_redColor_clicked(); break;
        case 7: _t->on_yellowColor_clicked(); break;
        case 8: _t->on_greenColor_clicked(); break;
        case 9: _t->on_blueColor_clicked(); break;
        case 10: _t->on_purpleColor_clicked(); break;
        case 11: _t->on_pinkColor_clicked(); break;
        case 12: _t->on_selectButton_pressed(); break;
        case 13: _t->on_selectButton_clicked(); break;
        case 14: _t->drawMouse((*reinterpret_cast< std::add_pointer_t<QMouseEvent*>>(_a[1]))); break;
        case 15: _t->on_open_start_collection(); break;
        case 16: _t->on_open_connect_server(); break;
        case 17: _t->on_open_admit_defeat_action(); break;
        case 18: _t->on_open_start_action(); break;
        case 19: _t->on_startButton_clicked(); break;
        case 20: _t->myTimerSlotStart(); break;
        case 21: _t->myLCDCount(); break;
        case 22: _t->enemyTimerSlotStart(); break;
        case 23: _t->enemyLCDCount(); break;
        case 24: _t->roundLCDIncrease(); break;
        case 25: _t->myLCDend(); break;
        case 26: _t->enemyLCDend(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(QMouseEvent * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::mouseMove)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::startMyTimer)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::startEnemyTimer)) {
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
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::endMyRound)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::endEnemyRound)) {
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
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


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
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 27)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 27;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::mouseMove(QMouseEvent * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::startMyTimer()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::startEnemyTimer()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainWindow::increaseRoundNumber()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MainWindow::endMyRound()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MainWindow::endEnemyRound()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
