/********************************************************************************
** Form generated from reading UI file 'mywidget.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIDGET_H
#define UI_MYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWidget
{
public:
    QPushButton *startButton;
    QGroupBox *ColorBox;
    QGridLayout *gridLayout;
    QPushButton *redColor;
    QPushButton *yellowColor;
    QPushButton *greenColor;
    QPushButton *blueColor;
    QPushButton *purpleColor;
    QPushButton *pinkColor;
    QLabel *ballImage;

    void setupUi(QWidget *MyWidget)
    {
        if (MyWidget->objectName().isEmpty())
            MyWidget->setObjectName(QString::fromUtf8("MyWidget"));
        MyWidget->resize(606, 376);
        startButton = new QPushButton(MyWidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(60, 50, 351, 101));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(35);
        font.setBold(true);
        startButton->setFont(font);
        startButton->setAutoFillBackground(false);
        startButton->setStyleSheet(QString::fromUtf8(""));
        ColorBox = new QGroupBox(MyWidget);
        ColorBox->setObjectName(QString::fromUtf8("ColorBox"));
        ColorBox->setGeometry(QRect(70, 150, 331, 91));
        gridLayout = new QGridLayout(ColorBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        redColor = new QPushButton(ColorBox);
        redColor->setObjectName(QString::fromUtf8("redColor"));
        redColor->setAutoFillBackground(false);

        gridLayout->addWidget(redColor, 0, 0, 1, 1);

        yellowColor = new QPushButton(ColorBox);
        yellowColor->setObjectName(QString::fromUtf8("yellowColor"));
        yellowColor->setAutoFillBackground(false);

        gridLayout->addWidget(yellowColor, 0, 1, 1, 1);

        greenColor = new QPushButton(ColorBox);
        greenColor->setObjectName(QString::fromUtf8("greenColor"));
        greenColor->setAutoFillBackground(false);

        gridLayout->addWidget(greenColor, 0, 2, 1, 1);

        blueColor = new QPushButton(ColorBox);
        blueColor->setObjectName(QString::fromUtf8("blueColor"));
        blueColor->setAutoFillBackground(false);

        gridLayout->addWidget(blueColor, 1, 0, 1, 1);

        purpleColor = new QPushButton(ColorBox);
        purpleColor->setObjectName(QString::fromUtf8("purpleColor"));
        purpleColor->setAutoFillBackground(false);

        gridLayout->addWidget(purpleColor, 1, 1, 1, 1);

        pinkColor = new QPushButton(ColorBox);
        pinkColor->setObjectName(QString::fromUtf8("pinkColor"));
        pinkColor->setAutoFillBackground(false);

        gridLayout->addWidget(pinkColor, 1, 2, 1, 1);

        ballImage = new QLabel(MyWidget);
        ballImage->setObjectName(QString::fromUtf8("ballImage"));
        ballImage->setGeometry(QRect(190, 240, 91, 61));
        ballImage->setAlignment(Qt::AlignCenter);

        retranslateUi(MyWidget);
        QObject::connect(startButton, &QPushButton::clicked, ColorBox, qOverload<>(&QGroupBox::show));

        QMetaObject::connectSlotsByName(MyWidget);
    } // setupUi

    void retranslateUi(QWidget *MyWidget)
    {
        MyWidget->setWindowTitle(QCoreApplication::translate("MyWidget", "MyWidget", nullptr));
        startButton->setText(QCoreApplication::translate("MyWidget", "Select A Color", nullptr));
        ColorBox->setTitle(QString());
        redColor->setText(QCoreApplication::translate("MyWidget", "red", nullptr));
        yellowColor->setText(QCoreApplication::translate("MyWidget", "yellow", nullptr));
        greenColor->setText(QCoreApplication::translate("MyWidget", "green", nullptr));
        blueColor->setText(QCoreApplication::translate("MyWidget", "blue", nullptr));
        purpleColor->setText(QCoreApplication::translate("MyWidget", "purple", nullptr));
        pinkColor->setText(QCoreApplication::translate("MyWidget", "pink", nullptr));
        ballImage->setText(QCoreApplication::translate("MyWidget", "ballImage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyWidget: public Ui_MyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
