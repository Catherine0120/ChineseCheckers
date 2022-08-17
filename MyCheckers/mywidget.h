#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>

enum color_set {RED, YELLOW, GREEN, BLUE, PURPLE, PINK};

QT_BEGIN_NAMESPACE
namespace Ui { class MyWidget; }
QT_END_NAMESPACE

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

    void paintEvent(QPaintEvent *);
    void showBall(enum color_set color);

private slots:
    void on_redColor_clicked();

    void on_startButton_clicked();

    void on_startButton_pressed();

    void on_yellowColor_clicked();

    void on_greenColor_clicked();

    void on_blueColor_clicked();

    void on_purpleColor_clicked();

    void on_pinkColor_clicked();

private:
    Ui::MyWidget *ui;
};
#endif // MYWIDGET_H
