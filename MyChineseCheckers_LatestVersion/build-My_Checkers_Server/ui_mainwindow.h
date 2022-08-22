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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *IPLabel;
    QLabel *label_2;
    QLabel *portLabel;
    QPushButton *gotitButton;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *menuMy_Checker_Server;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(375, 358);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(20);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        IPLabel = new QLabel(centralwidget);
        IPLabel->setObjectName(QString::fromUtf8("IPLabel"));
        QFont font1;
        font1.setPointSize(15);
        IPLabel->setFont(font1);

        gridLayout->addWidget(IPLabel, 0, 1, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        portLabel = new QLabel(centralwidget);
        portLabel->setObjectName(QString::fromUtf8("portLabel"));
        portLabel->setFont(font1);

        gridLayout->addWidget(portLabel, 1, 1, 1, 1);

        gotitButton = new QPushButton(centralwidget);
        gotitButton->setObjectName(QString::fromUtf8("gotitButton"));

        gridLayout->addWidget(gotitButton, 2, 0, 1, 2);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setReadOnly(true);

        gridLayout->addWidget(textEdit, 3, 0, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 375, 17));
        menuMy_Checker_Server = new QMenu(menubar);
        menuMy_Checker_Server->setObjectName(QString::fromUtf8("menuMy_Checker_Server"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuMy_Checker_Server->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Server IP:", nullptr));
        IPLabel->setText(QCoreApplication::translate("MainWindow", "show host IP", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "port :", nullptr));
        portLabel->setText(QCoreApplication::translate("MainWindow", "show port", nullptr));
        gotitButton->setText(QCoreApplication::translate("MainWindow", "Got it!", nullptr));
        menuMy_Checker_Server->setTitle(QCoreApplication::translate("MainWindow", "My_Checkers_Server", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
