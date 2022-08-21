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
    const uint offsetsAndSize[80];
    char stringdata0[629];
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
QT_MOC_LITERAL(101, 8), // "EnemyWin"
QT_MOC_LITERAL(110, 5), // "MeWin"
QT_MOC_LITERAL(116, 12), // "packageReady"
QT_MOC_LITERAL(129, 19), // "on_redColor_clicked"
QT_MOC_LITERAL(149, 22), // "on_yellowColor_clicked"
QT_MOC_LITERAL(172, 21), // "on_greenColor_clicked"
QT_MOC_LITERAL(194, 20), // "on_blueColor_clicked"
QT_MOC_LITERAL(215, 22), // "on_purpleColor_clicked"
QT_MOC_LITERAL(238, 20), // "on_pinkColor_clicked"
QT_MOC_LITERAL(259, 23), // "on_selectButton_pressed"
QT_MOC_LITERAL(283, 23), // "on_selectButton_clicked"
QT_MOC_LITERAL(307, 9), // "drawMouse"
QT_MOC_LITERAL(317, 24), // "on_open_start_collection"
QT_MOC_LITERAL(342, 22), // "on_open_connect_server"
QT_MOC_LITERAL(365, 14), // "start_new_page"
QT_MOC_LITERAL(380, 27), // "on_open_admit_defeat_action"
QT_MOC_LITERAL(408, 18), // "judge_admit_defeat"
QT_MOC_LITERAL(427, 20), // "on_open_start_action"
QT_MOC_LITERAL(448, 22), // "on_startButton_clicked"
QT_MOC_LITERAL(471, 15), // "displayEnemyWin"
QT_MOC_LITERAL(487, 12), // "displayMeWin"
QT_MOC_LITERAL(500, 9), // "startGame"
QT_MOC_LITERAL(510, 4), // "flag"
QT_MOC_LITERAL(515, 13), // "onChangeColor"
QT_MOC_LITERAL(529, 13), // "setEnemyColor"
QT_MOC_LITERAL(543, 9), // "setMyTime"
QT_MOC_LITERAL(553, 12), // "setEnemyTime"
QT_MOC_LITERAL(566, 8), // "setRound"
QT_MOC_LITERAL(575, 12), // "onMyRoundEnd"
QT_MOC_LITERAL(588, 19), // "sendPackageToServer"
QT_MOC_LITERAL(608, 20) // "parseMessageReceived"

    },
    "MainWindow\0mouseMove\0\0QMouseEvent*\0"
    "event\0startMyTimer\0startEnemyTimer\0"
    "increaseRoundNumber\0endMyRound\0EnemyWin\0"
    "MeWin\0packageReady\0on_redColor_clicked\0"
    "on_yellowColor_clicked\0on_greenColor_clicked\0"
    "on_blueColor_clicked\0on_purpleColor_clicked\0"
    "on_pinkColor_clicked\0on_selectButton_pressed\0"
    "on_selectButton_clicked\0drawMouse\0"
    "on_open_start_collection\0"
    "on_open_connect_server\0start_new_page\0"
    "on_open_admit_defeat_action\0"
    "judge_admit_defeat\0on_open_start_action\0"
    "on_startButton_clicked\0displayEnemyWin\0"
    "displayMeWin\0startGame\0flag\0onChangeColor\0"
    "setEnemyColor\0setMyTime\0setEnemyTime\0"
    "setRound\0onMyRoundEnd\0sendPackageToServer\0"
    "parseMessageReceived"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      35,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  224,    2, 0x06,    1 /* Public */,
       5,    0,  227,    2, 0x06,    3 /* Public */,
       6,    0,  228,    2, 0x06,    4 /* Public */,
       7,    0,  229,    2, 0x06,    5 /* Public */,
       8,    0,  230,    2, 0x06,    6 /* Public */,
       9,    0,  231,    2, 0x06,    7 /* Public */,
      10,    0,  232,    2, 0x06,    8 /* Public */,
      11,    0,  233,    2, 0x06,    9 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      12,    0,  234,    2, 0x08,   10 /* Private */,
      13,    0,  235,    2, 0x08,   11 /* Private */,
      14,    0,  236,    2, 0x08,   12 /* Private */,
      15,    0,  237,    2, 0x08,   13 /* Private */,
      16,    0,  238,    2, 0x08,   14 /* Private */,
      17,    0,  239,    2, 0x08,   15 /* Private */,
      18,    0,  240,    2, 0x08,   16 /* Private */,
      19,    0,  241,    2, 0x08,   17 /* Private */,
      20,    1,  242,    2, 0x08,   18 /* Private */,
      21,    0,  245,    2, 0x08,   20 /* Private */,
      22,    0,  246,    2, 0x08,   21 /* Private */,
      23,    0,  247,    2, 0x08,   22 /* Private */,
      24,    0,  248,    2, 0x08,   23 /* Private */,
      25,    0,  249,    2, 0x08,   24 /* Private */,
      26,    0,  250,    2, 0x08,   25 /* Private */,
      27,    0,  251,    2, 0x08,   26 /* Private */,
      28,    0,  252,    2, 0x08,   27 /* Private */,
      29,    0,  253,    2, 0x08,   28 /* Private */,
      30,    1,  254,    2, 0x08,   29 /* Private */,
      32,    0,  257,    2, 0x08,   31 /* Private */,
      33,    0,  258,    2, 0x08,   32 /* Private */,
      34,    1,  259,    2, 0x08,   33 /* Private */,
      35,    1,  262,    2, 0x08,   35 /* Private */,
      36,    1,  265,    2, 0x08,   37 /* Private */,
      37,    0,  268,    2, 0x08,   39 /* Private */,
      38,    0,  269,    2, 0x08,   40 /* Private */,
      39,    3,  270,    2, 0x08,   41 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
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
    QMetaType::Void, QMetaType::Bool,   31,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,

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
        case 5: _t->EnemyWin(); break;
        case 6: _t->MeWin(); break;
        case 7: _t->packageReady(); break;
        case 8: _t->on_redColor_clicked(); break;
        case 9: _t->on_yellowColor_clicked(); break;
        case 10: _t->on_greenColor_clicked(); break;
        case 11: _t->on_blueColor_clicked(); break;
        case 12: _t->on_purpleColor_clicked(); break;
        case 13: _t->on_pinkColor_clicked(); break;
        case 14: _t->on_selectButton_pressed(); break;
        case 15: _t->on_selectButton_clicked(); break;
        case 16: _t->drawMouse((*reinterpret_cast< std::add_pointer_t<QMouseEvent*>>(_a[1]))); break;
        case 17: _t->on_open_start_collection(); break;
        case 18: _t->on_open_connect_server(); break;
        case 19: _t->start_new_page(); break;
        case 20: _t->on_open_admit_defeat_action(); break;
        case 21: _t->judge_admit_defeat(); break;
        case 22: _t->on_open_start_action(); break;
        case 23: _t->on_startButton_clicked(); break;
        case 24: _t->displayEnemyWin(); break;
        case 25: _t->displayMeWin(); break;
        case 26: _t->startGame((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 27: _t->onChangeColor(); break;
        case 28: _t->setEnemyColor(); break;
        case 29: _t->setMyTime((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 30: _t->setEnemyTime((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 31: _t->setRound((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 32: _t->onMyRoundEnd(); break;
        case 33: _t->sendPackageToServer(); break;
        case 34: _t->parseMessageReceived((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
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
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::EnemyWin)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::MeWin)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::packageReady)) {
                *result = 7;
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
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QMouseEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


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
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 35)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 35;
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
void MainWindow::EnemyWin()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void MainWindow::MeWin()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void MainWindow::packageReady()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
