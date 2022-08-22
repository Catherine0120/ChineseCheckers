/********************************************************************************
** Form generated from reading UI file 'enemywindialog.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENEMYWINDIALOG_H
#define UI_ENEMYWINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EnemyWinDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *textLabel;
    QGroupBox *buttonBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *TryAgainButton;
    QPushButton *QuitButton;

    void setupUi(QDialog *EnemyWinDialog)
    {
        if (EnemyWinDialog->objectName().isEmpty())
            EnemyWinDialog->setObjectName(QString::fromUtf8("EnemyWinDialog"));
        EnemyWinDialog->resize(300, 220);
        verticalLayout = new QVBoxLayout(EnemyWinDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textLabel = new QLabel(EnemyWinDialog);
        textLabel->setObjectName(QString::fromUtf8("textLabel"));
        QFont font;
        font.setPointSize(25);
        textLabel->setFont(font);
        textLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(textLabel);

        buttonBox = new QGroupBox(EnemyWinDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        horizontalLayout = new QHBoxLayout(buttonBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        TryAgainButton = new QPushButton(buttonBox);
        TryAgainButton->setObjectName(QString::fromUtf8("TryAgainButton"));

        horizontalLayout->addWidget(TryAgainButton);

        QuitButton = new QPushButton(buttonBox);
        QuitButton->setObjectName(QString::fromUtf8("QuitButton"));

        horizontalLayout->addWidget(QuitButton);


        verticalLayout->addWidget(buttonBox);


        retranslateUi(EnemyWinDialog);
        QObject::connect(QuitButton, &QPushButton::clicked, EnemyWinDialog, qOverload<>(&QDialog::close));
        QObject::connect(TryAgainButton, &QPushButton::clicked, EnemyWinDialog, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(EnemyWinDialog);
    } // setupUi

    void retranslateUi(QDialog *EnemyWinDialog)
    {
        EnemyWinDialog->setWindowTitle(QCoreApplication::translate("EnemyWinDialog", "Dialog", nullptr));
        textLabel->setText(QCoreApplication::translate("EnemyWinDialog", "Oops... You LOSE!", nullptr));
        buttonBox->setTitle(QString());
        TryAgainButton->setText(QCoreApplication::translate("EnemyWinDialog", "Try Again", nullptr));
        QuitButton->setText(QCoreApplication::translate("EnemyWinDialog", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EnemyWinDialog: public Ui_EnemyWinDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENEMYWINDIALOG_H
