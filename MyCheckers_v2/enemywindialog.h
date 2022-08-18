#ifndef ENEMYWINDIALOG_H
#define ENEMYWINDIALOG_H

#include <QDialog>

namespace Ui {
class EnemyWinDialog;
}

class EnemyWinDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EnemyWinDialog(QWidget *parent = nullptr);
    ~EnemyWinDialog();

private:
    Ui::EnemyWinDialog *ui;
};

#endif // ENEMYWINDIALOG_H
