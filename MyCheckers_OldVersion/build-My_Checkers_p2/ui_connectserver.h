/********************************************************************************
** Form generated from reading UI file 'connectserver.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTSERVER_H
#define UI_CONNECTSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_connectserver
{
public:
    QGridLayout *gridLayout;
    QLabel *EnterIPLabel;
    QLineEdit *IPInput;
    QLabel *EnterPortLabel;
    QLineEdit *portInput;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QPushButton *connectButton;
    QPushButton *disconnectButton;
    QPushButton *closeButton;
    QTextEdit *textEdit;

    void setupUi(QDialog *connectserver)
    {
        if (connectserver->objectName().isEmpty())
            connectserver->setObjectName(QString::fromUtf8("connectserver"));
        connectserver->resize(272, 250);
        gridLayout = new QGridLayout(connectserver);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        EnterIPLabel = new QLabel(connectserver);
        EnterIPLabel->setObjectName(QString::fromUtf8("EnterIPLabel"));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(15);
        font.setBold(true);
        EnterIPLabel->setFont(font);

        gridLayout->addWidget(EnterIPLabel, 0, 0, 1, 1);

        IPInput = new QLineEdit(connectserver);
        IPInput->setObjectName(QString::fromUtf8("IPInput"));

        gridLayout->addWidget(IPInput, 0, 1, 1, 1);

        EnterPortLabel = new QLabel(connectserver);
        EnterPortLabel->setObjectName(QString::fromUtf8("EnterPortLabel"));
        EnterPortLabel->setFont(font);

        gridLayout->addWidget(EnterPortLabel, 1, 0, 1, 1);

        portInput = new QLineEdit(connectserver);
        portInput->setObjectName(QString::fromUtf8("portInput"));

        gridLayout->addWidget(portInput, 1, 1, 1, 1);

        groupBox = new QGroupBox(connectserver);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setAlignment(Qt::AlignCenter);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        connectButton = new QPushButton(groupBox);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));
        connectButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_2->addWidget(connectButton, 0, 0, 1, 1);

        disconnectButton = new QPushButton(groupBox);
        disconnectButton->setObjectName(QString::fromUtf8("disconnectButton"));
        disconnectButton->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout_2->addWidget(disconnectButton, 0, 1, 1, 1);

        closeButton = new QPushButton(groupBox);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        gridLayout_2->addWidget(closeButton, 0, 2, 1, 1);


        gridLayout->addWidget(groupBox, 2, 0, 1, 2);

        textEdit = new QTextEdit(connectserver);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 3, 0, 1, 2);


        retranslateUi(connectserver);

        QMetaObject::connectSlotsByName(connectserver);
    } // setupUi

    void retranslateUi(QDialog *connectserver)
    {
        connectserver->setWindowTitle(QCoreApplication::translate("connectserver", "Dialog", nullptr));
        EnterIPLabel->setText(QCoreApplication::translate("connectserver", "Enter IP:", nullptr));
        EnterPortLabel->setText(QCoreApplication::translate("connectserver", "Enter port:", nullptr));
        groupBox->setTitle(QString());
        connectButton->setText(QCoreApplication::translate("connectserver", "Connect", nullptr));
        disconnectButton->setText(QCoreApplication::translate("connectserver", "Disconnect", nullptr));
        closeButton->setText(QCoreApplication::translate("connectserver", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class connectserver: public Ui_connectserver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTSERVER_H
