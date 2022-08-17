#include "connectserver.h"
#include "ui_connectserver.h"
#include <QValidator>

connectserver::connectserver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::connectserver)
{
    ui->setupUi(this);
    this->setWindowTitle("Connect to server");
    this->setWindowModality(Qt::WindowModal);
}

connectserver::~connectserver()
{
    delete ui;
}

void connectserver::setValidator(const QRegularExpression &re) {
    Validator = new QRegularExpressionValidator(re);
};
