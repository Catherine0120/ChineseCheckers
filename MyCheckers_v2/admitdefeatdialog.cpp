#include "admitdefeatdialog.h"
#include "ui_admitdefeatdialog.h"
#include <QDebug>

AdmitDefeatDialog::AdmitDefeatDialog(QMainWindow *parent) :
    QDialog(parent),
    ui(new Ui::AdmitDefeatDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Admit Defeat Dialog");
    this->setWindowModality(Qt::WindowModal);
}

AdmitDefeatDialog::~AdmitDefeatDialog()
{
    delete ui;
}


void AdmitDefeatDialog::on_yesButton_clicked()
{
    emit switchFlag();
}

