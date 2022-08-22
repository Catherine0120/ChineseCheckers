#include "playdialog.h"
#include "ui_playdialog.h"

PlayDialog::PlayDialog(QMainWindow *parent) :
    QDialog(parent),
    ui(new Ui::PlayDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Ready to Play");
    this->setWindowModality(Qt::WindowModal);
}

PlayDialog::~PlayDialog()
{
    delete ui;
}

void PlayDialog::on_yesButton_clicked()
{
    emit start_new_game();
}

