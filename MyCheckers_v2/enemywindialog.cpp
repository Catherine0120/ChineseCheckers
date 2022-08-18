#include "enemywindialog.h"
#include "ui_enemywindialog.h"

EnemyWinDialog::EnemyWinDialog(QMainWindow *parent) :
    QDialog(parent),
    ui(new Ui::EnemyWinDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("You Lose");
    this->setWindowModality(Qt::WindowModal);
}

EnemyWinDialog::~EnemyWinDialog()
{
    delete ui;
}

void EnemyWinDialog::on_TryAgainButton_clicked()
{
    emit tryagain();
}

