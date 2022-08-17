#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QPainter>
#include <QLabel>
#include <QMouseEvent>
#include <QVector>
#include <QTimer>
#include "chess.h"


enum color_set {RED = 0, YELLOW = 1, GREEN = 2, BLUE = 3, PURPLE = 4, PINK = 5};


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void paintEvent(QPaintEvent *);
    void paintEventChessBoard(QPainter & p);
    void paintEventChessesPlayed(QPainter & p);


    void showBall(enum color_set color);
    void showStart();

    void mouseMoveEvent(QMouseEvent * event);
    void mousePressEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent * event);

    int get_grid_screen_x(Chess chess);
    int get_grid_screen_y(Chess chess);
    double get_grid_x(int screen_x);
    double get_grid_y(int screen_y);

    int mouse_on_chess(double grid_x, int grid_y);
    int mouse_on_chessboard(double grid_x, int grid_y);

    bool disobeyRules(int start, int destination);

private slots:
    void on_redColor_clicked();

    void on_yellowColor_clicked();

    void on_greenColor_clicked();

    void on_blueColor_clicked();

    void on_purpleColor_clicked();

    void on_pinkColor_clicked();

    void on_selectButton_pressed();

    void on_selectButton_clicked();

    void drawMouse(QMouseEvent *event);

    void on_open_start_collection();

    void on_open_connect_server();

    void on_startButton_clicked();

    void myTimerSlotStart();

    void myLCMCount();

    void enemyTimerSlotStart();

    void enemyLCMCount();

signals:
    void mouseMove(QMouseEvent *event);

    void startMyTimer();

    void startEnemyTimer();

private:
    Ui::MainWindow *ui;
    int myColor;
    QVector<Chess> chessboard;
    QVector<Chess> chessesplayed;

    int board_w_off, board_h_off; //左上像素点坐标
    int grid_w, grid_h; //每一个棋子的宽和高，grid_h为棋子直径
    double d_chessboard; //棋盘棋坑的直径
    double d_chess; //棋盘棋子的直径

    bool buttonstart = false;
    QPixmap pm_enemy, pm_me;

    Chess * chessbeingmoved = nullptr;

    static constexpr int num_chesses[]= {
        1, 2, 3, 4, 13, 12, 11, 10, 9, 10, 11, 12, 13, 4, 3, 2, 1
    };

    QTimer * myTimer;
    QTimer * enemyTimer;

    int MyTimerId, EnemyTimerId;

};


#endif // MAINWINDOW_H
