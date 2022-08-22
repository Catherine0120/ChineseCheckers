QT       += core gui network websockets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admitdefeatdialog.cpp \
    connectserver.cpp \
    createconnection.cpp \
    enemywindialog.cpp \
    helpdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    mewindialog.cpp \
    playdialog.cpp

HEADERS += \
    admitdefeatdialog.h \
    chess.h \
    connectserver.h \
    createconnection.h \
    enemywindialog.h \
    helpdialog.h \
    mainwindow.h \
    mewindialog.h \
    playdialog.h

FORMS += \
    admitdefeatdialog.ui \
    connectserver.ui \
    createconnection.ui \
    enemywindialog.ui \
    helpdialog.ui \
    mainwindow.ui \
    mewindialog.ui \
    playdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ReadMe.txt