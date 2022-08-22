#include "mewindialog.h"
#include "ui_mewindialog.h"

MeWinDialog::MeWinDialog(QMainWindow *parent) :
    QDialog(parent),
    ui(new Ui::MeWinDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("You Win");
    this->setWindowModality(Qt::WindowModal);
}

MeWinDialog::~MeWinDialog()
{
    delete ui;
}

void MeWinDialog::on_playAgainButton_clicked()
{
    emit winagain();
}

