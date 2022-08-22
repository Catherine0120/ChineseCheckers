/********************************************************************************
** Form generated from reading UI file 'helpdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPDIALOG_H
#define UI_HELPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_HelpDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *HelpDialog)
    {
        if (HelpDialog->objectName().isEmpty())
            HelpDialog->setObjectName(QString::fromUtf8("HelpDialog"));
        HelpDialog->resize(415, 211);
        gridLayout = new QGridLayout(HelpDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(HelpDialog);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(25);
        font.setBold(true);
        font.setItalic(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(HelpDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\347\255\211\347\272\277")});
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setKerning(true);
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);


        retranslateUi(HelpDialog);

        QMetaObject::connectSlotsByName(HelpDialog);
    } // setupUi

    void retranslateUi(QDialog *HelpDialog)
    {
        HelpDialog->setWindowTitle(QCoreApplication::translate("HelpDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("HelpDialog", "Help", nullptr));
        label_2->setText(QCoreApplication::translate("HelpDialog", "1. \346\211\200\346\234\21110\351\242\227\346\243\213\345\255\220\346\210\220\345\212\237\350\277\233\345\205\245\346\255\243\345\257\271\351\235\242\347\232\204\345\257\271\346\226\271\350\220\245\345\214\272\346\227\266\350\216\267\350\203\234\343\200\202\n"
"2. \346\257\217\346\255\245\344\270\213\346\243\213\346\227\266\351\227\264\344\270\27220\347\247\222\357\274\214\350\266\205\346\227\266\345\210\231\350\275\256\345\210\260\345\257\271\346\226\271\350\265\260\346\243\213\343\200\202\350\266\205\346\227\2663\346\254\241\350\207\252\345\212\250\345\210\244\350\264\237\343\200\202\n"
"3. \346\257\217\344\275\215\347\216\251\345\256\266\345\234\250\347\254\254 20\343\200\20125\343\200\20130 \345\233\236\345\220\210\357\274\210\345\217\214\346\226\271\345\220\204\350\265\260\344\270\200\345\255\220\344\270\2721\345\233\236\345\220\210\357\274\211\346\227\266\357\274\214\n"
"    \347\246\273\345\274\200\346\234\254\350\220\245\347\232\204\346\243\213\345\255\220\346\225\260\345\277\205\351\241\273\345\210\206"
                        "\345\210\253\350\276\276\345\210\260 5\343\200\201 8\343\200\201 10\351\242\227\346\210\226\344\273\245\344\270\212\357\274\214\345\220\246\345\210\231\344\274\232\350\242\253\345\210\244\350\264\237\343\200\202\n"
"4. \346\200\273\345\233\236\345\220\210\346\225\260\350\276\276\345\210\26020\344\273\245\345\220\216\346\211\215\345\217\257\344\273\245\346\212\225\351\231\215\343\200\202\n"
"", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HelpDialog: public Ui_HelpDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPDIALOG_H
