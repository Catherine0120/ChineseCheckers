/********************************************************************************
** Form generated from reading UI file 'admitdefeatdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMITDEFEATDIALOG_H
#define UI_ADMITDEFEATDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AdmitDefeatDialog
{
public:
    QLabel *TitleLabel;
    QGroupBox *choiceBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *yesButton;
    QPushButton *noButton;

    void setupUi(QDialog *AdmitDefeatDialog)
    {
        if (AdmitDefeatDialog->objectName().isEmpty())
            AdmitDefeatDialog->setObjectName(QString::fromUtf8("AdmitDefeatDialog"));
        AdmitDefeatDialog->resize(380, 223);
        TitleLabel = new QLabel(AdmitDefeatDialog);
        TitleLabel->setObjectName(QString::fromUtf8("TitleLabel"));
        TitleLabel->setGeometry(QRect(20, 10, 341, 111));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(20);
        TitleLabel->setFont(font);
        TitleLabel->setAlignment(Qt::AlignCenter);
        choiceBox = new QGroupBox(AdmitDefeatDialog);
        choiceBox->setObjectName(QString::fromUtf8("choiceBox"));
        choiceBox->setGeometry(QRect(30, 100, 321, 81));
        horizontalLayout = new QHBoxLayout(choiceBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        yesButton = new QPushButton(choiceBox);
        yesButton->setObjectName(QString::fromUtf8("yesButton"));

        horizontalLayout->addWidget(yesButton);

        noButton = new QPushButton(choiceBox);
        noButton->setObjectName(QString::fromUtf8("noButton"));

        horizontalLayout->addWidget(noButton);


        retranslateUi(AdmitDefeatDialog);
        QObject::connect(noButton, &QPushButton::clicked, AdmitDefeatDialog, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(AdmitDefeatDialog);
    } // setupUi

    void retranslateUi(QDialog *AdmitDefeatDialog)
    {
        AdmitDefeatDialog->setWindowTitle(QCoreApplication::translate("AdmitDefeatDialog", "Dialog", nullptr));
        TitleLabel->setText(QCoreApplication::translate("AdmitDefeatDialog", "Are you sure to Admit Defeat??", nullptr));
        choiceBox->setTitle(QString());
        yesButton->setText(QCoreApplication::translate("AdmitDefeatDialog", "Yes", nullptr));
        noButton->setText(QCoreApplication::translate("AdmitDefeatDialog", "No", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdmitDefeatDialog: public Ui_AdmitDefeatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMITDEFEATDIALOG_H
