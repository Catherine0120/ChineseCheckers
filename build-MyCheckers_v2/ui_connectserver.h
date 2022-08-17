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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_connectserver
{
public:
    QLabel *EnterIPLabel;
    QLineEdit *InputIP;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *okButton;
    QPushButton *CancelButton;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_8;
    QPushButton *pushButton_0;
    QPushButton *pushButton_dot;
    QLabel *label;

    void setupUi(QDialog *connectserver)
    {
        if (connectserver->objectName().isEmpty())
            connectserver->setObjectName(QString::fromUtf8("connectserver"));
        connectserver->resize(312, 338);
        EnterIPLabel = new QLabel(connectserver);
        EnterIPLabel->setObjectName(QString::fromUtf8("EnterIPLabel"));
        EnterIPLabel->setGeometry(QRect(21, 30, 81, 23));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(15);
        font.setBold(true);
        EnterIPLabel->setFont(font);
        InputIP = new QLineEdit(connectserver);
        InputIP->setObjectName(QString::fromUtf8("InputIP"));
        InputIP->setGeometry(QRect(120, 29, 181, 22));
        groupBox = new QGroupBox(connectserver);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 60, 291, 41));
        groupBox->setAlignment(Qt::AlignCenter);
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        okButton = new QPushButton(groupBox);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(okButton);

        CancelButton = new QPushButton(groupBox);
        CancelButton->setObjectName(QString::fromUtf8("CancelButton"));
        CancelButton->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(CancelButton);

        groupBox_2 = new QGroupBox(connectserver);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 120, 291, 141));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_1 = new QPushButton(groupBox_2);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(pushButton_1, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(pushButton_3, 0, 2, 1, 1);

        pushButton_4 = new QPushButton(groupBox_2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(pushButton_4, 1, 0, 1, 1);

        pushButton_5 = new QPushButton(groupBox_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(pushButton_5, 1, 1, 1, 1);

        pushButton_6 = new QPushButton(groupBox_2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(pushButton_6, 1, 2, 1, 1);

        pushButton_7 = new QPushButton(groupBox_2);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(pushButton_7, 2, 0, 1, 1);

        pushButton_9 = new QPushButton(groupBox_2);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(pushButton_9, 2, 1, 1, 1);

        pushButton_10 = new QPushButton(groupBox_2);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(pushButton_10, 2, 2, 1, 1);

        pushButton_8 = new QPushButton(groupBox_2);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(pushButton_8, 3, 0, 1, 1);

        pushButton_0 = new QPushButton(groupBox_2);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        pushButton_0->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(pushButton_0, 3, 1, 1, 1);

        pushButton_dot = new QPushButton(groupBox_2);
        pushButton_dot->setObjectName(QString::fromUtf8("pushButton_dot"));
        pushButton_dot->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(pushButton_dot, 3, 2, 1, 1);

        label = new QLabel(connectserver);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 270, 151, 31));
        QFont font1;
        font1.setPointSize(12);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(connectserver);

        QMetaObject::connectSlotsByName(connectserver);
    } // setupUi

    void retranslateUi(QDialog *connectserver)
    {
        connectserver->setWindowTitle(QCoreApplication::translate("connectserver", "Dialog", nullptr));
        EnterIPLabel->setText(QCoreApplication::translate("connectserver", "Enter IP:", nullptr));
        groupBox->setTitle(QString());
        okButton->setText(QCoreApplication::translate("connectserver", "OK", nullptr));
        CancelButton->setText(QCoreApplication::translate("connectserver", "Cancel", nullptr));
        groupBox_2->setTitle(QString());
        pushButton_1->setText(QCoreApplication::translate("connectserver", "1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("connectserver", "2", nullptr));
        pushButton_3->setText(QCoreApplication::translate("connectserver", "3", nullptr));
        pushButton_4->setText(QCoreApplication::translate("connectserver", "4", nullptr));
        pushButton_5->setText(QCoreApplication::translate("connectserver", "5", nullptr));
        pushButton_6->setText(QCoreApplication::translate("connectserver", "6", nullptr));
        pushButton_7->setText(QCoreApplication::translate("connectserver", "7", nullptr));
        pushButton_9->setText(QCoreApplication::translate("connectserver", "8", nullptr));
        pushButton_10->setText(QCoreApplication::translate("connectserver", "9", nullptr));
        pushButton_8->setText(QCoreApplication::translate("connectserver", "Delete", nullptr));
        pushButton_0->setText(QCoreApplication::translate("connectserver", "0", nullptr));
        pushButton_dot->setText(QCoreApplication::translate("connectserver", ".", nullptr));
        label->setText(QCoreApplication::translate("connectserver", "\346\225\260\345\255\227\351\224\256\347\233\230\346\232\202\344\270\215\345\217\257\347\224\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class connectserver: public Ui_connectserver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTSERVER_H
