/********************************************************************************
** Form generated from reading UI file 'mewindialog.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEWINDIALOG_H
#define UI_MEWINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MeWinDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *textLabel;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *playAgainButton;
    QPushButton *quitButton;

    void setupUi(QDialog *MeWinDialog)
    {
        if (MeWinDialog->objectName().isEmpty())
            MeWinDialog->setObjectName(QString::fromUtf8("MeWinDialog"));
        MeWinDialog->resize(300, 220);
        verticalLayout = new QVBoxLayout(MeWinDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textLabel = new QLabel(MeWinDialog);
        textLabel->setObjectName(QString::fromUtf8("textLabel"));
        QFont font;
        font.setPointSize(20);
        textLabel->setFont(font);
        textLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(textLabel);

        groupBox = new QGroupBox(MeWinDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        playAgainButton = new QPushButton(groupBox);
        playAgainButton->setObjectName(QString::fromUtf8("playAgainButton"));

        horizontalLayout_2->addWidget(playAgainButton);

        quitButton = new QPushButton(groupBox);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));

        horizontalLayout_2->addWidget(quitButton);


        verticalLayout->addWidget(groupBox);


        retranslateUi(MeWinDialog);

        QMetaObject::connectSlotsByName(MeWinDialog);
    } // setupUi

    void retranslateUi(QDialog *MeWinDialog)
    {
        MeWinDialog->setWindowTitle(QCoreApplication::translate("MeWinDialog", "Dialog", nullptr));
        textLabel->setText(QCoreApplication::translate("MeWinDialog", "Congratulations! You WIN!", nullptr));
        groupBox->setTitle(QString());
        playAgainButton->setText(QCoreApplication::translate("MeWinDialog", "Play Again", nullptr));
        quitButton->setText(QCoreApplication::translate("MeWinDialog", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MeWinDialog: public Ui_MeWinDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEWINDIALOG_H
