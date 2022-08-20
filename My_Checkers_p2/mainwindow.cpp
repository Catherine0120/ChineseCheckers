#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "createconnection.h"
#include "connectserver.h"
#include "playdialog.h"
#include "admitdefeatdialog.h"
#include "enemywindialog.h"
#include "mewindialog.h"

#include <algorithm>
#include <QPainter>
#include <QPixmap>
#include <QGroupBox>
#include <QString>
#include <QLabel>
#include <QDebug>
#include <QTime>
#include <QTimer>
#include <QMenuBar>
#include <vector>
#include <assert.h>
#include <queue>
#include <QMessageBox>
#include <QProcess>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pD = new AdmitDefeatDialog(this);
    pS = new PlayDialog(this);
    pE = new EnemyWinDialog(this);
    pM = new MeWinDialog(this);

    pServer = new connectserver(this);

    background = QPixmap("../images/BackgroundPlain.png");

    ui->lcdRoundNumber->display(1);

    //设置计时器
    myTimer = new QTimer(this);
    enemyTimer = new QTimer(this);
    connect(this, SIGNAL(startMyTimer()), this, SLOT(myTimerSlotStart()));
    connect(myTimer, SIGNAL(timeout()), this, SLOT(myLCDCount()));
    connect(this, SIGNAL(startEnemyTimer()), this, SLOT(enemyTimerSlotStart()));
    connect(enemyTimer, SIGNAL(timeout()), this, SLOT(enemyLCDCount()));

    connect(this, SIGNAL(increaseRoundNumber()), this, SLOT(roundLCDIncrease()));
    connect(this, SIGNAL(endMyRound()), this, SLOT(myLCDend()));
    connect(this, SIGNAL(endEnemyRound()), this, SLOT(enemyLCDend()));

    //判断回合走棋规则
    connect(this, SIGNAL(EnemyWin()), this, SLOT(displayEnemyWin()));
    connect(this, SIGNAL(MeWin()), this, SLOT(displayMeWin()));

    //设置MouseTracking
    connect(this, SIGNAL(mouseMove(QMouseEvent *)), this, SLOT(drawMouse(QMouseEvent *)));
    QMainWindow::setMouseTracking(true);
    QMainWindow::centralWidget()->setMouseTracking(true);

    //菜单栏信号与槽
    connect(ui->actionCreate_the_connection, SIGNAL(triggered()), this, SLOT(on_open_start_collection()));
    connect(ui->actionConnect_to_Server, SIGNAL(triggered()), this, SLOT(on_open_connect_server()));
    connect(ui->actionStart, SIGNAL(triggered()), this, SLOT(on_open_start_action()));
    connect(ui->actionAdmit_defeat, SIGNAL(triggered()), this, SLOT(on_open_admit_defeat_action()));

    connect(pD, SIGNAL(switchFlag()), this, SLOT(judge_admit_defeat()));
    connect(pS, SIGNAL(start_new_game()), this, SLOT(start_new_page()));
    connect(pE, SIGNAL(tryagain()), this, SLOT(start_new_page()));
    connect(pM, SIGNAL(winagain()), this, SLOT(start_new_page()));

    connect(pServer, SIGNAL(startPermitted()), this, SLOT(startGame()));
    connect(pServer, SIGNAL(changeColor()), this, SLOT(onChangeColor()));
    connect(pServer, SIGNAL(getEnemyColor()), this, SLOT(setEnemyColor()));
    connect(pServer, SIGNAL(endGame()), this, SLOT(start_new_page()));

    ui->ballImage->hide();
    ui->ColorBox->setStyleSheet("QGroupBox{border:none}");
    ui->ColorBox->hide();
    ui->startButton->hide();
    ui->GameInfoBox->hide();
    ui->loadLabel->hide();
    ui->roundCountBox->hide();

    for (size_t i = 0; i < sizeof(num_chesses) / sizeof(int); ++i) {
        double start = -(num_chesses[i] - 1) / 2.0;
        for (int j = 0; j < num_chesses[i]; ++j) {
            chessboard.push_back(Chess(start + j, i, color_set::RED));
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Events：
void MainWindow::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing, false);
    p.setRenderHint(QPainter::SmoothPixmapTransform, false);

    paintEventChessBoard(p);
    paintEventChessesPlayed(p);
}

void MainWindow::paintEventChessBoard(QPainter & p) {
    auto real_w = this->centralWidget()->width() - 450; //空闲区width
    auto real_h = this->centralWidget()->height(); //空闲区height
    auto board_h = std::min(real_w, real_h); //棋盘区height
    auto board_w = board_h * 13 / 0.866 / 17; //棋盘区width
    board_w_off = 450 + (real_w - board_w) / 2; //最左侧像素坐标
    board_h_off = (real_h - board_h) / 2 + 2 * (ui->menubar->heightForWidth(this->width())); //最上方像素坐标
    grid_w = board_w / 13; //每一个棋子的width
    grid_h = board_h / 17; //每一个棋子的height
    d_chessboard = grid_h * 0.9; //直径
    d_chess = d_chessboard * 1.1;
    p.drawPixmap(0, 0, width(), height(), background); //背景图片
    auto pm = QPixmap("../images/white.png").scaled(d_chessboard, d_chessboard, Qt::KeepAspectRatio); //每一个棋子的QPixmap

    for (int i = 0; i < chessboard.size(); ++i) {
        Chess &chess = chessboard[i];
        chessboard[i].chessboardlabel = i;
        //每个棋子坐标对应的屏幕像素坐标
        int grid_screen_x = get_grid_screen_x(chess);
        int grid_screen_y = get_grid_screen_y(chess);
        //p.setPen(Qt::red);
        //p.drawRect(QRect(grid_screen_x, grid_screen_y, grid_w, grid_h));
        p.drawPixmap(grid_screen_x, grid_screen_y, pm);
    }
}

void MainWindow::paintEventChessesPlayed(QPainter & p) {
    switch(myColor) {
        case(0):
            pm_me = QPixmap("../images/red.png").scaled(d_chess, d_chess, Qt::KeepAspectRatio);
            pm_enemy = QPixmap("../images/blue.png").scaled(d_chess, d_chess, Qt::KeepAspectRatio);
            break;
        case(1):
            pm_me = QPixmap("../images/yellow.png").scaled(d_chess, d_chess, Qt::KeepAspectRatio);
            pm_enemy = QPixmap("../images/purple.png").scaled(d_chess, d_chess, Qt::KeepAspectRatio);
            break;
        case(2):
            pm_me = QPixmap("../images/green.png").scaled(d_chess, d_chess, Qt::KeepAspectRatio);
            pm_enemy = QPixmap("../images/pink.png").scaled(d_chess, d_chess, Qt::KeepAspectRatio);
            break;
        case(3):
            pm_me = QPixmap("../images/blue.png").scaled(d_chess, d_chess, Qt::KeepAspectRatio);
            pm_enemy = QPixmap("../images/red.png").scaled(d_chess, d_chess, Qt::KeepAspectRatio);
            break;
        case(4):
            pm_me = QPixmap("../images/purple.png").scaled(d_chess, d_chess, Qt::KeepAspectRatio);
            pm_enemy = QPixmap("../images/yellow.png").scaled(d_chess, d_chess, Qt::KeepAspectRatio);
            break;
        case(5):
            pm_me = QPixmap("../images/pink.png").scaled(d_chess, d_chess, Qt::KeepAspectRatio);
            pm_enemy = QPixmap("../images/green.png").scaled(d_chess, d_chess, Qt::KeepAspectRatio);
            break;
    }

    if (buttonstart) {
        for (int i = 0; i < chessesplayed.size(); ++i) {
            int grid_screen_x = get_grid_screen_x(chessesplayed[i]);
            int grid_screen_y = get_grid_screen_y(chessesplayed[i]);
            if (chessesplayed[i].side == ENEMY)
                p.drawPixmap(grid_screen_x, grid_screen_y, pm_enemy);
            else if (chessesplayed[i].side == ME)
                p.drawPixmap(grid_screen_x, grid_screen_y, pm_me);
        }
    }
    this->update();

}

void MainWindow::mouseMoveEvent(QMouseEvent * event) {
//    qDebug() << "mouseMoveEvent";
    emit mouseMove(event);

    int screen_x = event->pos().x();
    int screen_y = event->pos().y();
    double grid_x = get_grid_x(screen_x);
    double grid_y = get_grid_y(screen_y);

    int num = mouse_on_chess(grid_x, grid_y);

    if (chessbeingmoved != nullptr) {
        chessbeingmoved->x = grid_x - 0.4;
        chessbeingmoved->y = grid_y - 0.4;
    }
    else if (num != -1 && chessesplayed[num].side == ME
             && (chessselected == num || chessselected == -1)
             && ui->lcdNumberYour->value() > 0) {
        this->setCursor(Qt::PointingHandCursor);
    }
    else if(num == -1 || chessesplayed[num].side == ME) {
        this->setCursor(Qt::ArrowCursor);
    }
    else if (num != -1 && chessesplayed[num].side == ENEMY
             && (chessselected == num || chessselected == -1)
             && ui->lcdNumberEnemy->value() > 0) {
        this->setCursor(Qt::PointingHandCursor);
    }
    else {
        this->setCursor(Qt::ArrowCursor);
    }

}

void MainWindow::mousePressEvent(QMouseEvent * event) {
    qDebug() << "mousePressEvent";
    int screen_x = event->pos().x();
    int screen_y = event->pos().y();
    double grid_x = get_grid_x(screen_x);
    double grid_y = get_grid_y(screen_y);

    int num = mouse_on_chess(grid_x, grid_y);

    //我的回合
    if (num != -1 && chessesplayed[num].side == ME
            && (chessselected == num || chessselected == -1)
            && ui->lcdNumberYour->value() > 0) {
        this->setCursor(Qt::PointingHandCursor);
        chessselected = num;
        chessbeingmoved = &chessesplayed[num];
        chessesplayed[num].beingpressed = true;
    }
    else if (num != -1 && chessesplayed[num].side == ENEMY
             && (chessselected == num || chessselected == -1)
             && ui->lcdNumberEnemy->value() > 0) {
         this->setCursor(Qt::PointingHandCursor);
         chessselected = num;
         chessbeingmoved = &chessesplayed[num];
         chessesplayed[num].beingpressed = true;
     }
}

void MainWindow::mouseReleaseEvent(QMouseEvent * event) {
    qDebug() << "mouseReleaseEvent";

    if (chessbeingmoved == nullptr) {
//        qDebug() << "mouseReleaseEvent triggered but no chess being moved!";
        return;
    }

    int screen_x = event->pos().x();
    int screen_y = event->pos().y();
    double grid_x = get_grid_x(screen_x);
    double grid_y = get_grid_y(screen_y);

    int num = mouse_on_chessboard(grid_x, grid_y);

    assert(num >= -1 && num <= 120);
    assert(chessbeingmoved->chessboardlabel != -1);
    if (num == -1 || chessboard[num].haschess || disobeyRules(chessbeingmoved->chessboardlabel, num)) {
//        qDebug() << "[wrong]: " << bool(num == -1) << " " << bool(chessboard[num].haschess) << " " << bool(disobeyRules(chessbeingmoved->chessboardlabel, num));
        chessbeingmoved->x = chessboard[chessbeingmoved->chessboardlabel].x;
        chessbeingmoved->y = chessboard[chessbeingmoved->chessboardlabel].y;
        chessselected = -1;
        chessbeingmoved->beingpressed = false;
        chessbeingmoved = nullptr;
    }
    else {
        chessboard[chessbeingmoved->chessboardlabel].haschess = false;
        chessboard[chessbeingmoved->chessboardlabel].chesslabel = -1;
        chessbeingmoved->beingpressed = false;
        chessbeingmoved->chessboardlabel = num;
        chessbeingmoved->x = chessboard[num].x;
        chessbeingmoved->y = chessboard[num].y;
        chessboard[num].haschess = true;
        chessboard[num].chesslabel = chessbeingmoved->chesslabel;
        chessselected = -1;
        if (chessbeingmoved->side == ME) emit endMyRound();
        if (chessbeingmoved->side == ENEMY) emit endEnemyRound();
        chessbeingmoved = nullptr;
    }

    if (countMyChessEnemyCamp()) emit MeWin();
    if (countEnemyChessMyCamp()) emit EnemyWin();
}


//UI paintings：
void MainWindow::showBall(enum color_set color) {
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
    ui->ballImage->show();
}

void MainWindow::on_selectButton_clicked()
{
    ui->selectButton->setStyleSheet(
                "background:#173A5B; "
                "color:white;"
                "border:2px solid black;");
}

void MainWindow::on_selectButton_pressed()
{
    ui->selectButton->setStyleSheet(
                "background:#276399; "
                "color:#ABD2F3;"
                "border:2px solid #276399;");
}

void MainWindow::on_redColor_clicked()
{
    showBall(RED);
    showStart();
    myColor = 0;
}

void MainWindow::on_yellowColor_clicked()
{
    showBall(YELLOW);
    showStart();
    myColor = 1;
}

void MainWindow::on_greenColor_clicked()
{
    showBall(GREEN);
    showStart();
    myColor = 2;
}

void MainWindow::on_blueColor_clicked()
{
    showBall(BLUE);
    showStart();
    myColor = 3;
}

void MainWindow::on_purpleColor_clicked()
{
    showBall(PURPLE);
    showStart();
    myColor = 4;
}

void MainWindow::on_pinkColor_clicked()
{
    showBall(PINK);
    showStart();
    myColor = 5;
}

void MainWindow::showStart() {
    ui->startButton->show();
}

void MainWindow::drawMouse(QMouseEvent * event) {
    int screen_x = event->pos().x();
    int screen_y = event->pos().y();
    double grid_x = get_grid_x(screen_x);
    double grid_y = get_grid_y(screen_y);

    ui->coordinateLabel->setText("(" + QString::number(event->pos().x()) + ", " + QString::number(event->pos().y()) + ")"
                                 + "\n(" + QString::number(grid_x, 'f', 1) + ", " + QString::number(grid_y, 'f', 1) + ")");
}


//Signals and Slots:
void MainWindow::on_open_start_collection() {
    createconnection * p = new createconnection();
    p->setWindowModality(Qt::ApplicationModal);
    p->show();
}

void MainWindow::on_open_connect_server() {
    pServer->setWindowModality(Qt::NonModal);
    pServer->show();
}

void MainWindow::on_open_start_action() {
    pS->show();
}

void MainWindow::start_new_page() {
    QApplication::closeAllWindows();
    QProcess::startDetached(QApplication::applicationFilePath(), QStringList());
}

void MainWindow::on_open_admit_defeat_action() {
    pD->show();
}

void MainWindow::judge_admit_defeat() {
    if ((int)(ui->lcdRoundNumber->value()) < 20) {
        QMessageBox::warning(this, tr("Warning"), tr("You can only admit defeat after at least 20 rounds"),
                             QMessageBox::Ok, QMessageBox::Ok);
    }
    else {
        pD->close();
        emit EnemyWin();
    }
}

void MainWindow::onChangeColor() {
    QMessageBox::critical(this, "Change Color", "Please select another color");
}

void MainWindow::setEnemyColor() {
    assert(pServer->enemyColor != -1);
    enemyColor = pServer->enemyColor;
}


//StartButton:
void MainWindow::on_startButton_clicked()
{
    ui->startButton->setStyleSheet(
                "color:#aad6fe;"
                "background-color: transparent;");

    if (pServer == nullptr || !pServer->connectedToServer || pServer->webSocket == nullptr) {
        QMessageBox::critical(this, "Connection Failure", "You aren't connected to Server");
        return;
    }
    assert(myColor != -1);

    QString colorSent;

    switch(myColor) {
        case(0):
            colorSent = "RED";
            break;
        case(1):
            colorSent = "YELLOW";
            break;
        case(2):
            colorSent = "GREEN";
            break;
        case(3):
            colorSent = "BLUE";
            break;
        case(4):
            colorSent = "PURPLE";
            break;
        case(5):
            colorSent = "PINK";
            break;
    }

    pServer->webSocket->sendTextMessage(QString("Ready to Start: %1").arg(QString::number(myColor)));

    ui->loadLabel->setText("Waiting...");
    ui->loadLabel->show();

}

void MainWindow::startGame() {
    buttonstart = true;

    ui->loadLabel->setText("Loading...");

    QTime dieTime = QTime::currentTime().addMSecs(2000);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

    ui->selectButton->hide();
    ui->ColorBox->hide();
    ui->ballImage->hide();
    ui->startButton->hide();

    ui->loadLabel->hide();
    ui->GameInfoBox->show();
    ui->roundCountBox->show();
    ui->lcdRoundNumber->show();

    ui->lcdNumberYour->display(20);
    ui->lcdNumberEnemy->display(0);
    emit startMyTimer();

    switch(myColor) {
        case(0):
            ui->MyBall->setPixmap(QPixmap(QString("../images/%1_small.png").arg("red")));
            pm_me = QPixmap("../images/red.png").scaled(d_chess, d_chess, Qt::KeepAspectRatio);
            break;
        case(1):
            ui->MyBall->setPixmap(QPixmap(QString("../images/%1_small.png").arg("yellow")));
            pm_me = QPixmap("../images/yellow.png").scaled(d_chess, d_chess, Qt::KeepAspectRatio);
            break;
        case(2):
            ui->MyBall->setPixmap(QPixmap(QString("../images/%1_small.png").arg("green")));
            pm_me = QPixmap("../images/green.png").scaled(d_chess, d_chess, Qt::KeepAspectRatio);
            break;
        case(3):
            ui->MyBall->setPixmap(QPixmap(QString("../images/%1_small.png").arg("blue")));
            pm_me = QPixmap("../images/blue.png").scaled(d_chess, d_chess, Qt::KeepAspectRatio);
            break;
        case(4):
            ui->MyBall->setPixmap(QPixmap(QString("../images/%1_small.png").arg("purple")));
            pm_me = QPixmap("../images/purple.png").scaled(d_chess, d_chess, Qt::KeepAspectRatio);
            break;
        case(5):
            ui->MyBall->setPixmap(QPixmap(QString("../images/%1_small.png").arg("pink")));
            pm_me = QPixmap("../images/pink.png").scaled(d_chess, d_chess, Qt::KeepAspectRatio);
            break;
    }

    switch(enemyColor) {
        case(0):
            ui->EnemyBall->setPixmap(QPixmap(QString("../images/%1_small.png").arg("red")));
            pm_enemy = QPixmap("../images/red.png").scaled(d_chess, d_chess, Qt::KeepAspectRatio);
            break;
        case(1):
            ui->EnemyBall->setPixmap(QPixmap(QString("../images/%1_small.png").arg("yellow")));
            pm_enemy = QPixmap("../images/yellow.png").scaled(d_chess, d_chess, Qt::KeepAspectRatio);
            break;
        case(2):
            ui->EnemyBall->setPixmap(QPixmap(QString("../images/%1_small.png").arg("green")));
            pm_enemy = QPixmap("../images/green.png").scaled(d_chess, d_chess, Qt::KeepAspectRatio);
            break;
        case(3):
            ui->EnemyBall->setPixmap(QPixmap(QString("../images/%1_small.png").arg("blue")));
            pm_enemy = QPixmap("../images/blue.png").scaled(d_chess, d_chess, Qt::KeepAspectRatio);
            break;
        case(4):
            ui->EnemyBall->setPixmap(QPixmap(QString("../images/%1_small.png").arg("purple")));
            pm_enemy = QPixmap("../images/purple.png").scaled(d_chess, d_chess, Qt::KeepAspectRatio);
            break;
        case(5):
            ui->EnemyBall->setPixmap(QPixmap(QString("../images/%1_small.png").arg("pink")));
            pm_enemy = QPixmap("../images/pink.png").scaled(d_chess, d_chess, Qt::KeepAspectRatio);
            break;
    }

    for (int i = 0; i < 10; ++i) {
        chessesplayed.push_back(chessboard[i]);
        chessesplayed[i].side = ENEMY;
        chessesplayed[i].chesslabel = i;
        chessesplayed[i].chessboardlabel = i;
        chessboard[i].haschess = true;
        chessboard[i].chesslabel = i;
    }

    int j = 10;
    for (int i = chessboard.size() - 1; i > chessboard.size() - 11; --i) {
        chessesplayed.push_back(chessboard[i]);
        chessesplayed[j].side = ME;
        chessesplayed[j].chesslabel = j;
        chessesplayed[j].chessboardlabel = i;
        chessboard[i].chesslabel = j;
        j++;
        chessboard[i].haschess = true;
    }

}

//Functions:
int MainWindow::get_grid_screen_x(Chess chess) {
    return board_w_off + (6 + chess.x) * grid_w;
}

int MainWindow::get_grid_screen_y(Chess chess) {
    return board_h_off + chess.y * grid_h;
}

double MainWindow::get_grid_x(int screen_x) {
    return (screen_x - board_w_off) / double(grid_w) - 6.;
}

double MainWindow::get_grid_y(int screen_y) {
    return (screen_y - board_h_off) / double(grid_h);
}

int MainWindow::mouse_on_chess(double grid_x, int grid_y) {
    int ret = -1;
    for (int i = 0; i < chessesplayed.size(); ++i) {
        if ( grid_x >= chessesplayed[i].x && grid_x <= chessesplayed[i].x + 0.8 && grid_y == chessesplayed[i].y) {
            chessesplayed[i].mouseon = true;
            ret = i;
            break;
        }
        else chessesplayed[i].mouseon = false;
    }
    return ret; //返回棋子编号
}

int MainWindow::mouse_on_chessboard(double grid_x, int grid_y) {
    int ret = -1;
    for (int i = 0; i < chessboard.size(); ++i) {
        if ( grid_x >= chessboard[i].x && grid_x <= chessboard[i].x + 0.8 && grid_y == chessboard[i].y) {
            chessboard[i].mouseon = true;
            ret = i;
            break;
        }
        else chessboard[i].mouseon = false;
    }
    return ret; //返回棋盘编号
}

bool MainWindow::pos_has_chess(double grid_x, int grid_y) {
    for (int i = 0; i < chessesplayed.size(); ++i) {
        if ( grid_x == chessesplayed[i].x && grid_y == chessesplayed[i].y) {
            return true;
        }
    }
    return false;
}

int MainWindow::pos_on_chessboard(double grid_x, int grid_y) {
    for (int i = 0; i < chessboard.size(); ++i) {
        if ( grid_x == chessboard[i].x && grid_y == chessboard[i].y) {
            return i;
        }
    }
    return -1;
}

int MainWindow::countMyChessMyCamp() {
    int cnt = 0;
    for (int i = 111; i < chessboard.size(); ++i) {
        if (chessboard[i].chesslabel != -1 && chessesplayed[chessboard[i].chesslabel].side == ME)
            cnt++;
    }
    return cnt;
}

int MainWindow::countEnemyChessEnemyCamp() {
    int cnt = 0;
    for (int i = 0; i < 10; ++i) {
        if (chessboard[i].chesslabel != -1 && chessesplayed[chessboard[i].chesslabel].side == ENEMY)
            cnt++;
    }
    return cnt;
}


//Judge: obey or disobey Rules? To be continued..
//判断是否符合跳棋规则（相邻挪一步不在此判断之内）
bool MainWindow::disobeyRules(int start, int destination) {
    qDebug() << "disobeyRules";
    //距离为1返回false
    if ((abs(chessboard[start].x - chessboard[destination].x) <= 1) &&
        (abs(chessboard[start].y - chessboard[destination].y) <= 1)) {
        return false;
    }
    else {
        std::vector<int> feasible_set = get_feasible_set(start);
        for (size_t i = 0; i < feasible_set.size(); ++i) {
            if (feasible_set[i] == destination) return false;
        }
    }
    return true;
}

//传入一个start位置，返回所有能通过若干步跳到的位置(包括起点位置)
std::vector<int> MainWindow::get_feasible_set(int start) {
    qDebug() << "get_feasible_set";
    std::vector<int> final_feasible_set;
    for (int i = 0; i < chessboard.size(); ++i) {
        chessboard[i].feasibility = false;
    }
    chessboard[start].feasibility = true;
    bfs(start);
    for (int i = 0; i < chessboard.size(); ++i) {
        if (chessboard[i].feasibility == true)
            final_feasible_set.push_back(i);
    }
    return final_feasible_set;
}

//bfs
void MainWindow::bfs(int pos) {
    qDebug() << "bfs";
    std::queue<int> q;
    q.push(pos);
    while (q.size()) {
        int t = q.front();
        std::vector<int> pos_feasible_set = prepare_bfs_function(t);
//        qDebug() << "pos = " << t << ": ----------";
//        for (size_t i = 0; i < pos_feasible_set.size(); ++i) qDebug() << pos_feasible_set[i];
//        qDebug() << "---------";
        q.pop();
        if (pos_feasible_set.size() == 0) continue;
        for (size_t i = 0; i < pos_feasible_set.size(); ++i) {
            int new_pos = pos_feasible_set[i];
            assert(new_pos >= 0 && new_pos <= 120);
            if (chessboard[new_pos].feasibility == true) continue;
            chessboard[new_pos].feasibility = true;
            q.push(new_pos);
        }
    }
}

//传入一个start位置，返回所有能通过一步跳到的位置
std::vector<int> MainWindow::prepare_bfs_function(int start) {
    qDebug() << "prepare_bfs_function";
    std::vector<int> feasible_set;
    double pos_x = chessboard[start].x;
    double pos_y = chessboard[start].y;
    if (pos_has_chess(pos_x + 1, pos_y)
        && !pos_has_chess(pos_x + 2, pos_y)
        && pos_on_chessboard(pos_x + 2, pos_y) != -1
        && chessboard[pos_on_chessboard(pos_x + 2, pos_y)].feasibility == false) {
        assert(pos_on_chessboard(pos_x + 2, pos_y) == start + 2);
        feasible_set.push_back(start + 2);
    }
    if (pos_has_chess(pos_x + 0.5, pos_y - 1)
        && !pos_has_chess(pos_x + 1, pos_y - 2)
        && pos_on_chessboard(pos_x + 1, pos_y - 2) != -1
        && chessboard[pos_on_chessboard(pos_x + 1, pos_y - 2)].feasibility == false) {
        int tmp_pos = pos_on_chessboard(pos_x + 1, pos_y - 2);
        feasible_set.push_back(tmp_pos);
    }
    if (pos_has_chess(pos_x - 0.5, pos_y - 1)
        && !pos_has_chess(pos_x - 1, pos_y - 2)
        && pos_on_chessboard(pos_x - 1, pos_y - 2) != -1
        && chessboard[pos_on_chessboard(pos_x - 1, pos_y - 2)].feasibility == false) {
        int tmp_pos = pos_on_chessboard(pos_x - 1, pos_y - 2);
        feasible_set.push_back(tmp_pos);
    }
    if (pos_has_chess(pos_x - 1, pos_y)
        && !pos_has_chess(pos_x - 2, pos_y)
        && pos_on_chessboard(pos_x - 2, pos_y) != -1
        && chessboard[pos_on_chessboard(pos_x - 2, pos_y)].feasibility == false) {
        assert(pos_on_chessboard(pos_x - 2, pos_y) == start - 2);
        feasible_set.push_back(start - 2);
    }
    if (pos_has_chess(pos_x - 0.5, pos_y + 1)
        && !pos_has_chess(pos_x - 1, pos_y + 2)
        && pos_on_chessboard(pos_x - 1, pos_y + 2) != -1
        && chessboard[pos_on_chessboard(pos_x - 1, pos_y + 2)].feasibility == false) {
        int tmp_pos = pos_on_chessboard(pos_x - 1, pos_y + 2);
        feasible_set.push_back(tmp_pos);
    }
    if (pos_has_chess(pos_x + 0.5, pos_y + 1)
        && !pos_has_chess(pos_x + 1, pos_y + 2)
        && pos_on_chessboard(pos_x + 1, pos_y + 2) != -1
        && chessboard[pos_on_chessboard(pos_x + 1, pos_y + 2)].feasibility == false) {
        int tmp_pos = pos_on_chessboard(pos_x + 1, pos_y + 2);
        feasible_set.push_back(tmp_pos);
    }
    return feasible_set;
}


//LCD-Timer
void MainWindow::myTimerSlotStart() {
    myTimer->start(1000);
}

void MainWindow::myLCDCount() {
    int nowsec = ui->lcdNumberYour->value();
    if (nowsec != 1) {
        nowsec--;
        ui->lcdNumberYour->display(nowsec);
        emit startMyTimer();
    }
    else {
        meRunTime++;
        if (meRunTime == 3) emit EnemyWin();
        if ((int)(ui->lcdRoundNumber->value()) == 20
            && countMyChessMyCamp() > 5) {
            emit EnemyWin();
            return;
        }
        if ((int)(ui->lcdRoundNumber->value()) == 25
            && countMyChessMyCamp() > 2) {
            emit EnemyWin();
            return;
        }
        if ((int)(ui->lcdRoundNumber->value()) == 30
            && countMyChessMyCamp() != 0) {
            emit EnemyWin();
            return;
        }
        chessselected = -1;
        ui->lcdNumberEnemy->display(20);
        emit startEnemyTimer();
        ui->lcdNumberYour->display(0);
        myTimer->stop();
    }
}

void MainWindow::enemyTimerSlotStart() {
    enemyTimer->start(1000);
}

void MainWindow::enemyLCDCount() {
    int nowsec = ui->lcdNumberEnemy->value();
    if (nowsec != 1) {
        nowsec--;
        ui->lcdNumberEnemy->display(nowsec);
        emit startEnemyTimer();
    }
    else {
        enemyRunTime++;
        if (enemyRunTime == 3) emit MeWin();
        if ((int)(ui->lcdRoundNumber->value()) == 20
            && countEnemyChessEnemyCamp() > 5) {
            emit MeWin();
            return;
        }
        if ((int)(ui->lcdRoundNumber->value()) == 25
            && countEnemyChessEnemyCamp() > 2) {
            emit MeWin();
            return;
        }
        if ((int)(ui->lcdRoundNumber->value()) == 30
            && countEnemyChessEnemyCamp() != 0) {
            emit MeWin();
            return;
        }
        emit increaseRoundNumber();
        chessselected = -1;
        ui->lcdNumberYour->display(20);
        emit startMyTimer();
        ui->lcdNumberEnemy->display(0);
        enemyTimer->stop();
    }
}

void MainWindow::roundLCDIncrease() {
    int getNum = ui->lcdRoundNumber->value();
    getNum++;
    ui->lcdRoundNumber->display(getNum);
}

void MainWindow::myLCDend() {
    if ((int)(ui->lcdRoundNumber->value()) == 20
        && countMyChessMyCamp() > 5) {
        emit EnemyWin();
        return;
    }
    if ((int)(ui->lcdRoundNumber->value()) == 25
        && countMyChessMyCamp() > 2) {
        emit EnemyWin();
        return;
    }
    if ((int)(ui->lcdRoundNumber->value()) == 30
        && countMyChessMyCamp() != 0) {
        emit EnemyWin();
        return;
    }
    ui->lcdNumberYour->display(0);
    myTimer->stop();
    chessselected = -1;
    ui->lcdNumberEnemy->display(20);
    emit startEnemyTimer();
}

void MainWindow::enemyLCDend() {
    if ((int)(ui->lcdRoundNumber->value()) == 20
        && countEnemyChessEnemyCamp() > 5) {
        emit MeWin();
        return;
    }
    if ((int)(ui->lcdRoundNumber->value()) == 25
        && countEnemyChessEnemyCamp() > 2) {
        emit MeWin();
        return;
    }
    if ((int)(ui->lcdRoundNumber->value()) == 30
        && countEnemyChessEnemyCamp() != 0) {
        emit MeWin();
        return;
    }
    ui->lcdNumberEnemy->display(0);
    enemyTimer->stop();
    chessselected = -1;
    ui->lcdNumberYour->display(20);
    emit increaseRoundNumber();
    emit startMyTimer();
}


//Win or Lose
void MainWindow::displayEnemyWin() {
    pE->setWindowModality(Qt::ApplicationModal);
    pE->show();
    myTimer->stop();
    enemyTimer->stop();
    chessselected = -1;
}

void MainWindow::displayMeWin() {
    pM->setWindowModality(Qt::ApplicationModal);
    pM->show();
    myTimer->stop();
    enemyTimer->stop();
    chessselected = -1;
}

bool MainWindow::countMyChessEnemyCamp() {
    for (int i = 0; i < 10; ++i) {
        assert(chessboard[i].chesslabel >= -1 && chessboard[i].chesslabel <= 19);
        if (chessboard[i].chesslabel == -1 || chessesplayed[chessboard[i].chesslabel].side == ENEMY)
            return false;
    }
    return true;
}

bool MainWindow::countEnemyChessMyCamp() {
    for (int i = 111; i < 121; ++i) {
        assert(chessboard[i].chesslabel >= -1 && chessboard[i].chesslabel <= 19);
        if (chessboard[i].chesslabel == -1 || chessesplayed[chessboard[i].chesslabel].side == ME)
            return false;
    }
    return true;
}