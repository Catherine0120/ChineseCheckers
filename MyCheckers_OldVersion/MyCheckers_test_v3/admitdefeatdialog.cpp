#include "admitdefeatdialog.h"
#include "ui_admitdefeatdialog.h"

AdmitDefeatDialog::AdmitDefeatDialog(QWidget *parent) :
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
