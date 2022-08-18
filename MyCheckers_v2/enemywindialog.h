#ifndef ENEMYWINDIALOG_H
#define ENEMYWINDIALOG_H

#include <QDialog>
#include <QMainWindow>

namespace Ui {
class EnemyWinDialog;
}

class EnemyWinDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EnemyWinDialog(QMainWindow *parent = nullptr);
    ~EnemyWinDialog();

private slots:
    void on_TryAgainButton_clicked();

signals:
    void tryagain();

private:
    Ui::EnemyWinDialog *ui;
};

#endif // ENEMYWINDIALOG_H
