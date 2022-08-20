/********************************************************************************
** Form generated from reading UI file 'playdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYDIALOG_H
#define UI_PLAYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PlayDialog
{
public:
    QLabel *TitleLabel;
    QLabel *descrpitionLabel;
    QGroupBox *choiceBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *yesButton;
    QPushButton *noButton;

    void setupUi(QDialog *PlayDialog)
    {
        if (PlayDialog->objectName().isEmpty())
            PlayDialog->setObjectName(QString::fromUtf8("PlayDialog"));
        PlayDialog->resize(333, 169);
        TitleLabel = new QLabel(PlayDialog);
        TitleLabel->setObjectName(QString::fromUtf8("TitleLabel"));
        TitleLabel->setGeometry(QRect(100, 10, 141, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(25);
        TitleLabel->setFont(font);
        TitleLabel->setAlignment(Qt::AlignCenter);
        descrpitionLabel = new QLabel(PlayDialog);
        descrpitionLabel->setObjectName(QString::fromUtf8("descrpitionLabel"));
        descrpitionLabel->setGeometry(QRect(40, 50, 261, 41));
        QFont font1;
        font1.setPointSize(10);
        descrpitionLabel->setFont(font1);
        descrpitionLabel->setAlignment(Qt::AlignCenter);
        choiceBox = new QGroupBox(PlayDialog);
        choiceBox->setObjectName(QString::fromUtf8("choiceBox"));
        choiceBox->setGeometry(QRect(30, 90, 281, 61));
        horizontalLayout = new QHBoxLayout(choiceBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        yesButton = new QPushButton(choiceBox);
        yesButton->setObjectName(QString::fromUtf8("yesButton"));

        horizontalLayout->addWidget(yesButton);

        noButton = new QPushButton(choiceBox);
        noButton->setObjectName(QString::fromUtf8("noButton"));

        horizontalLayout->addWidget(noButton);


        retranslateUi(PlayDialog);
        QObject::connect(noButton, &QPushButton::clicked, PlayDialog, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(PlayDialog);
    } // setupUi

    void retranslateUi(QDialog *PlayDialog)
    {
        PlayDialog->setWindowTitle(QCoreApplication::translate("PlayDialog", "Dialog", nullptr));
        TitleLabel->setText(QCoreApplication::translate("PlayDialog", "Play Now?", nullptr));
        descrpitionLabel->setText(QCoreApplication::translate("PlayDialog", "notice that this will kill your present game", nullptr));
        choiceBox->setTitle(QString());
        yesButton->setText(QCoreApplication::translate("PlayDialog", "Yes, start new game", nullptr));
        noButton->setText(QCoreApplication::translate("PlayDialog", "No, continue or wait", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlayDialog: public Ui_PlayDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYDIALOG_H
