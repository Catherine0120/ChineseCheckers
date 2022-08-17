#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "createconnection.h"
#include "connectserver.h"
#include <algorithm>
#include <QPainter>
#include <QPixmap>
#include <QGroupBox>
#include <QString>
#include <QLabel>
#include <QDebug>
#include <QTime>
#include <QMenuBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置MouseTracking
    connect(this, SIGNAL(mouseMove(QMouseEvent *)), this, SLOT(drawMouse(QMouseEvent *)));
    QMainWindow::setMouseTracking(true);
    QMainWindow::centralWidget()->setMouseTracking(true);

    //菜单栏信号与槽
    connect(ui->actionCreate_the_connection, SIGNAL(triggered()), this, SLOT(on_open_start_collection()));
    connect(ui->actionConnect_to_Server, SIGNAL(triggered()), this, SLOT(on_open_connect_server()));

    ui->ballImage->hide();
    ui->ColorBox->setStyleSheet("QGroupBox{border:none}");
    ui->ColorBox->hide();
    ui->startButton->hide();
    ui->GameInfoBox->hide();
    ui->loadLabel->hide();

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

void MainWindow::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing, false);
    p.setRenderHint(QPainter::SmoothPixmapTransform, false);

    paintEventChessBoard(p);
    paintEventChessesPlayed(p);
}

void MainWindow::mouseMoveEvent(QMouseEvent * event) {
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
    else if (num != -1) {
        this->setCursor(Qt::PointingHandCursor);
    }
    else {
        this->setCursor(Qt::ArrowCursor);
    }

}

void MainWindow::mousePressEvent(QMouseEvent * event) {
    int screen_x = event->pos().x();
    int screen_y = event->pos().y();
    double grid_x = get_grid_x(screen_x);
    double grid_y = get_grid_y(screen_y);

    int num = mouse_on_chess(grid_x, grid_y);

    if (num != -1) {
        this->setCursor(Qt::PointingHandCursor);
        chessbeingmoved = &chessesplayed[num];
        chessesplayed[num].beingpressed = true;
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent * event) {
    if (chessbeingmoved == nullptr) qDebug() << "mouseReleaseEvent triggered but no chess being moved!";

    int screen_x = event->pos().x();
    int screen_y = event->pos().y();
    double grid_x = get_grid_x(screen_x);
    double grid_y = get_grid_y(screen_y);

    int num = mouse_on_chessboard(grid_x, grid_y);

    if (num == -1 || chessboard[num].haschess) { //不在棋盘上或棋盘位置有棋子
        qDebug() << "Ooops!";
        chessbeingmoved->x = chessboard[chessbeingmoved->chessboardlabel].x;
        chessbeingmoved->y = chessboard[chessbeingmoved->chessboardlabel].y;
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
        chessbeingmoved = nullptr;
    }
}

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

void MainWindow::on_open_start_collection() {
    createconnection * p = new createconnection();
    p->setWindowModality(Qt::ApplicationModal);
    p->show();
}

void MainWindow::on_open_connect_server() {
    connectserver *p = new connectserver();
    p->setWindowModality(Qt::ApplicationModal);
    p->show();
}

void MainWindow::on_startButton_clicked()
{
    buttonstart = true;

    ui->startButton->setStyleSheet(
                "color:#aad6fe;"
                "background-color: transparent;");

    ui->loadLabel->show();

    QTime dieTime = QTime::currentTime().addMSecs(2000);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

    ui->selectButton->hide();
    ui->ColorBox->hide();
    ui->ballImage->hide();
    ui->startButton->hide();

    ui->loadLabel->hide();
    ui->GameInfoBox->show();

    d = d * 1.1;
    switch(myColor) {
        case(0):
            ui->MyBall->setPixmap(QPixmap(QString("../images/%1_small.png").arg("red")));
            ui->EnemyBall->setPixmap(QPixmap(QString("../images/%1_small.png").arg("blue")));
            pm_me = QPixmap("../images/red.png").scaled(d, d, Qt::KeepAspectRatio);
            pm_enemy = QPixmap("../images/blue.png").scaled(d, d, Qt::KeepAspectRatio);
            break;
        case(1):
            ui->MyBall->setPixmap(QPixmap(QString("../images/%1_small.png").arg("yellow")));
            ui->EnemyBall->setPixmap(QPixmap(QString("../images/%1_small.png").arg("purple")));
            pm_me = QPixmap("../images/yellow.png").scaled(d, d, Qt::KeepAspectRatio);
            pm_enemy = QPixmap("../images/purple.png").scaled(d, d, Qt::KeepAspectRatio);
            break;
        case(2):
            ui->MyBall->setPixmap(QPixmap(QString("../images/%1_small.png").arg("green")));
            ui->EnemyBall->setPixmap(QPixmap(QString("../images/%1_small.png").arg("pink")));
            pm_me = QPixmap("../images/green.png").scaled(d, d, Qt::KeepAspectRatio);
            pm_enemy = QPixmap("../images/pink.png").scaled(d, d, Qt::KeepAspectRatio);
            break;
        case(3):
            ui->MyBall->setPixmap(QPixmap(QString("../images/%1_small.png").arg("blue")));
            ui->EnemyBall->setPixmap(QPixmap(QString("../images/%1_small.png").arg("red")));
            pm_me = QPixmap("../images/blue.png").scaled(d, d, Qt::KeepAspectRatio);
            pm_enemy = QPixmap("../images/red.png").scaled(d, d, Qt::KeepAspectRatio);
            break;
        case(4):
            ui->MyBall->setPixmap(QPixmap(QString("../images/%1_small.png").arg("purple")));
            ui->EnemyBall->setPixmap(QPixmap(QString("../images/%1_small.png").arg("yellow")));
            pm_me = QPixmap("../images/purple.png").scaled(d, d, Qt::KeepAspectRatio);
            pm_enemy = QPixmap("../images/yellow.png").scaled(d, d, Qt::KeepAspectRatio);
            break;
        case(5):
            ui->MyBall->setPixmap(QPixmap(QString("../images/%1_small.png").arg("pink")));
            ui->EnemyBall->setPixmap(QPixmap(QString("../images/%1_small.png").arg("green")));
            pm_me = QPixmap("../images/pink.png").scaled(d, d, Qt::KeepAspectRatio);
            pm_enemy = QPixmap("../images/green.png").scaled(d, d, Qt::KeepAspectRatio);
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

void MainWindow::paintEventChessBoard(QPainter & p) {
    auto real_w = this->centralWidget()->width() - 450; //空闲区width
    auto real_h = this->centralWidget()->height(); //空闲区height
    auto board_h = std::min(real_w, real_h); //棋盘区height
    auto board_w = board_h * 13 / 0.866 / 17; //棋盘区width
    board_w_off = 450 + (real_w - board_w) / 2; //最左侧像素坐标
    board_h_off = (real_h - board_h) / 2 + 2 * (ui->menubar->heightForWidth(this->width())); //最上方像素坐标
    grid_w = board_w / 13; //每一个棋子的width
    grid_h = board_h / 17; //每一个棋子的height
    d = grid_h * 0.9; //直径
    p.drawPixmap(0, 0, width(), height(), QPixmap("../images/BackgroundPlain.png")); //背景图片
    auto pm = QPixmap("../images/white.png").scaled(d, d, Qt::KeepAspectRatio); //每一个棋子的QPixmap

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
            pm_me = QPixmap("../images/red.png").scaled(d, d, Qt::KeepAspectRatio);
            pm_enemy = QPixmap("../images/blue.png").scaled(d, d, Qt::KeepAspectRatio);
            break;
        case(1):
            pm_me = QPixmap("../images/yellow.png").scaled(d, d, Qt::KeepAspectRatio);
            pm_enemy = QPixmap("../images/purple.png").scaled(d, d, Qt::KeepAspectRatio);
            break;
        case(2):
            pm_me = QPixmap("../images/green.png").scaled(d, d, Qt::KeepAspectRatio);
            pm_enemy = QPixmap("../images/pink.png").scaled(d, d, Qt::KeepAspectRatio);
            break;
        case(3):
            pm_me = QPixmap("../images/blue.png").scaled(d, d, Qt::KeepAspectRatio);
            pm_enemy = QPixmap("../images/red.png").scaled(d, d, Qt::KeepAspectRatio);
            break;
        case(4):
            pm_me = QPixmap("../images/purple.png").scaled(d, d, Qt::KeepAspectRatio);
            pm_enemy = QPixmap("../images/yellow.png").scaled(d, d, Qt::KeepAspectRatio);
            break;
        case(5):
            pm_me = QPixmap("../images/pink.png").scaled(d, d, Qt::KeepAspectRatio);
            pm_enemy = QPixmap("../images/green.png").scaled(d, d, Qt::KeepAspectRatio);
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
