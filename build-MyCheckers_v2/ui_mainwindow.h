/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCreate_the_connection;
    QAction *actionConnect_to_Server;
    QAction *actionStart;
    QAction *actionAdmit_defeat;
    QWidget *centralwidget;
    QPushButton *selectButton;
    QLabel *ballImage;
    QGroupBox *ColorBox;
    QGridLayout *gridLayout;
    QPushButton *redColor;
    QPushButton *yellowColor;
    QPushButton *greenColor;
    QPushButton *blueColor;
    QPushButton *purpleColor;
    QPushButton *pinkColor;
    QLabel *coordinateLabel;
    QPushButton *startButton;
    QGroupBox *GameInfoBox;
    QLCDNumber *lcdNumberEnemy;
    QLCDNumber *lcdNumberYour;
    QLabel *EnemysTimerLabel;
    QLabel *YourTimerLabel;
    QLabel *MyBall;
    QLabel *EnemyBall;
    QLabel *loadLabel;
    QWidget *widget;
    QVBoxLayout *LeftBottomLayout;
    QPushButton *helpButton;
    QPushButton *scoreButton;
    QPushButton *quitButton;
    QMenuBar *menubar;
    QMenu *menuConnect;
    QMenu *menuPlay;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(675, 715);
        actionCreate_the_connection = new QAction(MainWindow);
        actionCreate_the_connection->setObjectName(QString::fromUtf8("actionCreate_the_connection"));
        actionConnect_to_Server = new QAction(MainWindow);
        actionConnect_to_Server->setObjectName(QString::fromUtf8("actionConnect_to_Server"));
        actionStart = new QAction(MainWindow);
        actionStart->setObjectName(QString::fromUtf8("actionStart"));
        actionAdmit_defeat = new QAction(MainWindow);
        actionAdmit_defeat->setObjectName(QString::fromUtf8("actionAdmit_defeat"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        selectButton = new QPushButton(centralwidget);
        selectButton->setObjectName(QString::fromUtf8("selectButton"));
        selectButton->setGeometry(QRect(50, 40, 351, 101));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(30);
        font.setBold(false);
        font.setUnderline(false);
        selectButton->setFont(font);
        selectButton->setCursor(QCursor(Qt::PointingHandCursor));
        selectButton->setAutoFillBackground(false);
        selectButton->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"color:white;\n"
"border:2px solid white;"));
        ballImage = new QLabel(centralwidget);
        ballImage->setObjectName(QString::fromUtf8("ballImage"));
        ballImage->setGeometry(QRect(180, 230, 91, 61));
        QFont font1;
        font1.setStyleStrategy(QFont::PreferAntialias);
        ballImage->setFont(font1);
        ballImage->setAlignment(Qt::AlignCenter);
        ColorBox = new QGroupBox(centralwidget);
        ColorBox->setObjectName(QString::fromUtf8("ColorBox"));
        ColorBox->setGeometry(QRect(60, 140, 331, 91));
        gridLayout = new QGridLayout(ColorBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        redColor = new QPushButton(ColorBox);
        redColor->setObjectName(QString::fromUtf8("redColor"));
        redColor->setCursor(QCursor(Qt::PointingHandCursor));
        redColor->setAutoFillBackground(false);

        gridLayout->addWidget(redColor, 0, 0, 1, 1);

        yellowColor = new QPushButton(ColorBox);
        yellowColor->setObjectName(QString::fromUtf8("yellowColor"));
        yellowColor->setCursor(QCursor(Qt::PointingHandCursor));
        yellowColor->setAutoFillBackground(false);

        gridLayout->addWidget(yellowColor, 0, 1, 1, 1);

        greenColor = new QPushButton(ColorBox);
        greenColor->setObjectName(QString::fromUtf8("greenColor"));
        greenColor->setCursor(QCursor(Qt::PointingHandCursor));
        greenColor->setAutoFillBackground(false);

        gridLayout->addWidget(greenColor, 0, 2, 1, 1);

        blueColor = new QPushButton(ColorBox);
        blueColor->setObjectName(QString::fromUtf8("blueColor"));
        blueColor->setCursor(QCursor(Qt::PointingHandCursor));
        blueColor->setAutoFillBackground(false);

        gridLayout->addWidget(blueColor, 1, 0, 1, 1);

        purpleColor = new QPushButton(ColorBox);
        purpleColor->setObjectName(QString::fromUtf8("purpleColor"));
        purpleColor->setCursor(QCursor(Qt::PointingHandCursor));
        purpleColor->setAutoFillBackground(false);

        gridLayout->addWidget(purpleColor, 1, 1, 1, 1);

        pinkColor = new QPushButton(ColorBox);
        pinkColor->setObjectName(QString::fromUtf8("pinkColor"));
        pinkColor->setCursor(QCursor(Qt::PointingHandCursor));
        pinkColor->setAutoFillBackground(false);

        gridLayout->addWidget(pinkColor, 1, 2, 1, 1);

        coordinateLabel = new QLabel(centralwidget);
        coordinateLabel->setObjectName(QString::fromUtf8("coordinateLabel"));
        coordinateLabel->setGeometry(QRect(220, 490, 141, 71));
        QFont font2;
        font2.setPointSize(15);
        coordinateLabel->setFont(font2);
        coordinateLabel->setStyleSheet(QString::fromUtf8("color:white;\n"
"size:10px"));
        coordinateLabel->setAlignment(Qt::AlignCenter);
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(40, 300, 381, 131));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Times New Roman")});
        font3.setPointSize(25);
        font3.setBold(true);
        font3.setUnderline(true);
        startButton->setFont(font3);
        startButton->setCursor(QCursor(Qt::PointingHandCursor));
        startButton->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"color:white;\n"
"border:none"));
        GameInfoBox = new QGroupBox(centralwidget);
        GameInfoBox->setObjectName(QString::fromUtf8("GameInfoBox"));
        GameInfoBox->setGeometry(QRect(40, 10, 371, 421));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Times New Roman")});
        font4.setPointSize(20);
        font4.setBold(true);
        font4.setItalic(true);
        GameInfoBox->setFont(font4);
        GameInfoBox->setCursor(QCursor(Qt::ArrowCursor));
        GameInfoBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255)"));
        lcdNumberEnemy = new QLCDNumber(GameInfoBox);
        lcdNumberEnemy->setObjectName(QString::fromUtf8("lcdNumberEnemy"));
        lcdNumberEnemy->setGeometry(QRect(40, 70, 281, 121));
        lcdNumberYour = new QLCDNumber(GameInfoBox);
        lcdNumberYour->setObjectName(QString::fromUtf8("lcdNumberYour"));
        lcdNumberYour->setGeometry(QRect(40, 230, 281, 141));
        EnemysTimerLabel = new QLabel(GameInfoBox);
        EnemysTimerLabel->setObjectName(QString::fromUtf8("EnemysTimerLabel"));
        EnemysTimerLabel->setGeometry(QRect(10, 40, 151, 31));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Times New Roman")});
        font5.setPointSize(15);
        font5.setBold(false);
        font5.setItalic(true);
        EnemysTimerLabel->setFont(font5);
        YourTimerLabel = new QLabel(GameInfoBox);
        YourTimerLabel->setObjectName(QString::fromUtf8("YourTimerLabel"));
        YourTimerLabel->setGeometry(QRect(10, 200, 111, 31));
        YourTimerLabel->setFont(font5);
        MyBall = new QLabel(GameInfoBox);
        MyBall->setObjectName(QString::fromUtf8("MyBall"));
        MyBall->setGeometry(QRect(110, 200, 61, 21));
        EnemyBall = new QLabel(GameInfoBox);
        EnemyBall->setObjectName(QString::fromUtf8("EnemyBall"));
        EnemyBall->setGeometry(QRect(140, 40, 61, 21));
        loadLabel = new QLabel(centralwidget);
        loadLabel->setObjectName(QString::fromUtf8("loadLabel"));
        loadLabel->setGeometry(QRect(160, 390, 121, 41));
        loadLabel->setFont(font2);
        loadLabel->setStyleSheet(QString::fromUtf8("color: white"));
        loadLabel->setAlignment(Qt::AlignCenter);
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 490, 111, 171));
        LeftBottomLayout = new QVBoxLayout(widget);
        LeftBottomLayout->setObjectName(QString::fromUtf8("LeftBottomLayout"));
        LeftBottomLayout->setContentsMargins(0, 0, 0, 0);
        helpButton = new QPushButton(widget);
        helpButton->setObjectName(QString::fromUtf8("helpButton"));
        helpButton->setFont(font2);
        helpButton->setCursor(QCursor(Qt::PointingHandCursor));
        helpButton->setStyleSheet(QString::fromUtf8("background-color:rgb(90, 183, 180);\n"
"color:rgb(0, 0, 0);"));

        LeftBottomLayout->addWidget(helpButton);

        scoreButton = new QPushButton(widget);
        scoreButton->setObjectName(QString::fromUtf8("scoreButton"));
        scoreButton->setFont(font2);
        scoreButton->setCursor(QCursor(Qt::PointingHandCursor));
        scoreButton->setStyleSheet(QString::fromUtf8("background-color:rgb(90, 183, 180);\n"
"color:rgb(0, 0, 0);"));

        LeftBottomLayout->addWidget(scoreButton);

        quitButton = new QPushButton(widget);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        quitButton->setFont(font2);
        quitButton->setCursor(QCursor(Qt::PointingHandCursor));
        quitButton->setStyleSheet(QString::fromUtf8("background-color:rgb(90, 183, 180);\n"
"color:rgb(0, 0, 0);"));

        LeftBottomLayout->addWidget(quitButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 675, 17));
        menuConnect = new QMenu(menubar);
        menuConnect->setObjectName(QString::fromUtf8("menuConnect"));
        menuConnect->setCursor(QCursor(Qt::ArrowCursor));
        menuPlay = new QMenu(menubar);
        menuPlay->setObjectName(QString::fromUtf8("menuPlay"));
        menuPlay->setCursor(QCursor(Qt::ArrowCursor));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuConnect->menuAction());
        menubar->addAction(menuPlay->menuAction());
        menuConnect->addAction(actionCreate_the_connection);
        menuConnect->addAction(actionConnect_to_Server);
        menuPlay->addAction(actionStart);
        menuPlay->addAction(actionAdmit_defeat);

        retranslateUi(MainWindow);
        QObject::connect(selectButton, &QPushButton::clicked, ColorBox, qOverload<>(&QGroupBox::show));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionCreate_the_connection->setText(QCoreApplication::translate("MainWindow", "Create the connection", nullptr));
        actionConnect_to_Server->setText(QCoreApplication::translate("MainWindow", "Connect to Server", nullptr));
        actionStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        actionAdmit_defeat->setText(QCoreApplication::translate("MainWindow", "Admit defeat", nullptr));
        selectButton->setText(QCoreApplication::translate("MainWindow", "Select A Color", nullptr));
        ballImage->setText(QCoreApplication::translate("MainWindow", "ballImage", nullptr));
        ColorBox->setTitle(QString());
        redColor->setText(QCoreApplication::translate("MainWindow", "red", nullptr));
        yellowColor->setText(QCoreApplication::translate("MainWindow", "yellow", nullptr));
        greenColor->setText(QCoreApplication::translate("MainWindow", "green", nullptr));
        blueColor->setText(QCoreApplication::translate("MainWindow", "blue", nullptr));
        purpleColor->setText(QCoreApplication::translate("MainWindow", "purple", nullptr));
        pinkColor->setText(QCoreApplication::translate("MainWindow", "pink", nullptr));
        coordinateLabel->setText(QCoreApplication::translate("MainWindow", "coordinate", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "Now Start Your Game!", nullptr));
        GameInfoBox->setTitle(QCoreApplication::translate("MainWindow", "Game Info:", nullptr));
        EnemysTimerLabel->setText(QCoreApplication::translate("MainWindow", "Enemy's Timer:", nullptr));
        YourTimerLabel->setText(QCoreApplication::translate("MainWindow", "Your Timer:", nullptr));
        MyBall->setText(QCoreApplication::translate("MainWindow", "MyBall", nullptr));
        EnemyBall->setText(QCoreApplication::translate("MainWindow", "EnemyBall", nullptr));
        loadLabel->setText(QCoreApplication::translate("MainWindow", "Loading...", nullptr));
        helpButton->setText(QCoreApplication::translate("MainWindow", "Help", nullptr));
        scoreButton->setText(QCoreApplication::translate("MainWindow", "Score", nullptr));
        quitButton->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        menuConnect->setTitle(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        menuPlay->setTitle(QCoreApplication::translate("MainWindow", "Play", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
