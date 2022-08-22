#ifndef ADMITDEFEATDIALOG_H
#define ADMITDEFEATDIALOG_H

#include <QDialog>

namespace Ui {
class AdmitDefeatDialog;
}

class AdmitDefeatDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AdmitDefeatDialog(QWidget *parent = nullptr);
    ~AdmitDefeatDialog();

private:
    Ui::AdmitDefeatDialog *ui;
};

#endif // ADMITDEFEATDIALOG_H
