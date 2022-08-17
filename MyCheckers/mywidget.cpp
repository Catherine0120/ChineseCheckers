#include "mywidget.h"
#include "ui_mywidget.h"
#include <QPainter>
#include <QPixmap>
#include <QGroupBox>
#include <QString>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    ui->startButton->setStyleSheet(
                "background:transparent; "
                "color:white;"
                "border:2px solid white;");

    ui->ColorBox->setStyleSheet("QGroupBox{border:none}");
    ui->ColorBox->hide();

}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.drawPixmap(0, 0, width(), height(), QPixmap("../images/Background.png"));
}

void MyWidget::showBall(enum color_set color) {
    switch(color) {
        case RED:
            ui->ballImage->setPixmap(QPixmap("../images/red.png"));
            break;
        case YELLOW:
            ui->ballImage->setPixmap(QPixmap("../images/yellow.png"));
            break;
        case GREEN:
            ui->ballImage->setPixmap(QPixmap("../images/green.png"));
            break;
        case BLUE:
            ui->ballImage->setPixmap(QPixmap("../images/blue.png"));
            break;
        case PURPLE:
            ui->ballImage->setPixmap(QPixmap("../images/purple.png"));
            break;
        case PINK:
            ui->ballImage->setPixmap(QPixmap("../images/pink.png"));
            break;
    };


}


void MyWidget::on_startButton_clicked()
{
    ui->startButton->setStyleSheet(
                "background:#173A5B; "
                "color:white;"
                "border:2px solid black;");
}


void MyWidget::on_startButton_pressed()
{
    ui->startButton->setStyleSheet(
                "background:#276399; "
                "color:#ABD2F3;"
                "border:2px solid #276399;");
}

void MyWidget::on_redColor_clicked()
{
    showBall(RED);
}


void MyWidget::on_yellowColor_clicked()
{
    showBall(YELLOW);
}


void MyWidget::on_greenColor_clicked()
{
    showBall(GREEN);
}


void MyWidget::on_blueColor_clicked()
{
    showBall(BLUE);
}


void MyWidget::on_purpleColor_clicked()
{
    showBall(PURPLE);
}


void MyWidget::on_pinkColor_clicked()
{
    showBall(PINK);
}

