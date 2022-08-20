#ifndef MEWINDIALOG_H
#define MEWINDIALOG_H

#include <QDialog>
#include <QMainWindow>

namespace Ui {
class MeWinDialog;
}

class MeWinDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MeWinDialog(QMainWindow *parent = nullptr);
    ~MeWinDialog();

private:
    Ui::MeWinDialog *ui;

private slots:
    void on_playAgainButton_clicked();

signals:
    void winagain();
};

#endif // MEWINDIALOG_H
