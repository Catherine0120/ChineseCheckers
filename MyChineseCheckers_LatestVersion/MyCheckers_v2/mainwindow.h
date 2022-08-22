#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QPainter>
#include <QLabel>
#include <QMouseEvent>
#include <QVector>
#include <QTimer>
#include <vector>
#include <QWebSocket>
#include <QJsonDocument>
#include <QJsonObject>

#include "chess.h"
#include "enemywindialog.h"
#include "mewindialog.h"
#include "admitdefeatdialog.h"
#include "playdialog.h"
#include "connectserver.h"
#include "helpdialog.h"


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
    bool pos_has_chess(double grid_x, int grid_y);
    int pos_on_chessboard(double grid_x, int grid_y);

    bool disobeyRules(int start, int destination);
    std::vector<int> get_feasible_set(int start);
    void bfs(int pos);
    std::vector<int> prepare_bfs_function(int start);

    int countMyChessMyCamp();
    int countEnemyChessEnemyCamp();

    bool countMyChessEnemyCamp();
    bool countEnemyChessMyCamp();

    QString JsonToString(QJsonDocument package);

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

    void start_new_page();

    void on_open_admit_defeat_action();

    void judge_admit_defeat();

    void on_open_start_action();

    void on_startButton_clicked();

    void displayEnemyWin();

    void displayMeWin();

    void startGame(bool flag);

    void onChangeColor();

    void setEnemyColor();

    void setMyTime(int);

    void setEnemyTime(int);

    void setRound(int);

    void onMyRoundEnd();

    void sendPackageToServer();

    void parseMessageReceived(int, int, int);

    void onEnemyAdmitDefeat();

    void on_helpButton_clicked();

    void on_pauseButton_clicked();

    void onEnemyPause();

    void onEnemyStopPause();

    void displayRunTimeEnemyWin();

    void displayRunTimeIWin();

signals:
    void mouseMove(QMouseEvent *event);

    void startMyTimer();

    void startEnemyTimer();

    void increaseRoundNumber();

    void endMyRound();

    void EnemyWin();

    void MeWin();

    void packageReady();

private:
    Ui::MainWindow *ui;
    int myColor = -1;
    int enemyColor = -1;
    QVector<Chess> chessboard;
    QVector<Chess> chessesplayed;

    bool IGoFirst;
    bool isPause = false;

    int board_w_off, board_h_off; //左上像素点坐标
    int grid_w, grid_h; //每一个棋子的宽和高，grid_h为棋子直径
    double d_chessboard; //棋盘棋坑的直径
    double d_chess; //棋盘棋子的直径
    QPixmap background;

    bool buttonstart = false;
    QPixmap pm_enemy, pm_me, pm_board;

    Chess * chessbeingmoved = nullptr;
    int chessselected = -1;

    static constexpr int num_chesses[]= {
        1, 2, 3, 4, 13, 12, 11, 10, 9, 10, 11, 12, 13, 4, 3, 2, 1
    };

    EnemyWinDialog * pE;
    MeWinDialog * pM;
    AdmitDefeatDialog * pD;
    PlayDialog * pS;
    HelpDialog * pH;

    connectserver *pServer;

    int meRunTime = 0;
    int enemyRunTime = 0;

    QJsonDocument send_package;
    QJsonObject json_obj;

};


#endif // MAINWINDOW_H
