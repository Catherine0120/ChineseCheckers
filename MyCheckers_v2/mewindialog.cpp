#include "mewindialog.h"
#include "ui_mewindialog.h"

MeWinDialog::MeWinDialog(QWidget *parent) :
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
