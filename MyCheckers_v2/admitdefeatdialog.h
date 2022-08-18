#ifndef ADMITDEFEATDIALOG_H
#define ADMITDEFEATDIALOG_H

#include <QDialog>
#include <QMainWindow>

namespace Ui {
class AdmitDefeatDialog;
}

class AdmitDefeatDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AdmitDefeatDialog(QMainWindow *parent = nullptr);
    ~AdmitDefeatDialog();

    void emitswitchFlag();

signals:
    void switchFlag();

private slots:
    void on_yesButton_clicked();

private:
    Ui::AdmitDefeatDialog *ui;
};

#endif // ADMITDEFEATDIALOG_H
