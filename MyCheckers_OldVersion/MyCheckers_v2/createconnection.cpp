#include "createconnection.h"
#include "ui_createconnection.h"

createconnection::createconnection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createconnection)
{
    ui->setupUi(this);
    this->setWindowTitle("Create the connection");
    this->setWindowModality(Qt::WindowModal);
}

createconnection::~createconnection()
{
    delete ui;
}

