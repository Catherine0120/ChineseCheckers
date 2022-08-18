#include "enemywindialog.h"
#include "ui_enemywindialog.h"

EnemyWinDialog::EnemyWinDialog(QWidget *parent) :
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
