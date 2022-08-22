/********************************************************************************
** Form generated from reading UI file 'createconnection.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATECONNECTION_H
#define UI_CREATECONNECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_createconnection
{
public:
    QGroupBox *groupBox;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QLabel *hostIPLabel;
    QLabel *showIPLabel;

    void setupUi(QDialog *createconnection)
    {
        if (createconnection->objectName().isEmpty())
            createconnection->setObjectName(QString::fromUtf8("createconnection"));
        createconnection->resize(272, 275);
        groupBox = new QGroupBox(createconnection);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 160, 271, 81));
        okButton = new QPushButton(groupBox);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(40, 40, 81, 21));
        cancelButton = new QPushButton(groupBox);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(140, 40, 81, 21));
        hostIPLabel = new QLabel(createconnection);
        hostIPLabel->setObjectName(QString::fromUtf8("hostIPLabel"));
        hostIPLabel->setGeometry(QRect(20, 60, 141, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(18);
        font.setBold(true);
        hostIPLabel->setFont(font);
        showIPLabel = new QLabel(createconnection);
        showIPLabel->setObjectName(QString::fromUtf8("showIPLabel"));
        showIPLabel->setGeometry(QRect(120, 70, 151, 41));
        QFont font1;
        font1.setPointSize(13);
        showIPLabel->setFont(font1);
        showIPLabel->setAlignment(Qt::AlignCenter);

        retranslateUi(createconnection);
        QObject::connect(okButton, &QPushButton::clicked, createconnection, qOverload<>(&QDialog::close));
        QObject::connect(cancelButton, &QPushButton::clicked, createconnection, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(createconnection);
    } // setupUi

    void retranslateUi(QDialog *createconnection)
    {
        createconnection->setWindowTitle(QCoreApplication::translate("createconnection", "Dialog", nullptr));
        groupBox->setTitle(QString());
        okButton->setText(QCoreApplication::translate("createconnection", "OK", nullptr));
        cancelButton->setText(QCoreApplication::translate("createconnection", "Cancel", nullptr));
        hostIPLabel->setText(QCoreApplication::translate("createconnection", "Host IP:", nullptr));
        showIPLabel->setText(QCoreApplication::translate("createconnection", "nothing found...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class createconnection: public Ui_createconnection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECONNECTION_H
