#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QList>
#include <QHostAddress>
#include <QNetworkInterface>
#include <qDebug>
#include <QTime>
#include <QtGlobal>

const quint16 PORT = 8888;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString myIP = getLocalIP();
    ui->IPLabel->setText(myIP);
    ui->portLabel->setText(QString::number(PORT));

    webSocketServer = new QWebSocketServer("My_Checkers_Server", QWebSocketServer::NonSecureMode, this);
    webSocketServer->listen(QHostAddress::Any, PORT);
    connect(webSocketServer, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onNewConnection() {
    assert(!(webSocket_1 == nullptr && webSocket_2 != nullptr));
    if (webSocket_1 == nullptr) {
        webSocket_1 = webSocketServer->nextPendingConnection();
        webSocket = webSocket_1;
    }
    else if (webSocket_2 == nullptr) {
        webSocket_2 = webSocketServer->nextPendingConnection();
        webSocket = webSocket_2;
    }
    ui->textEdit->append(QString("Connected to Client[%1:%2]")
                         .arg((webSocket->localAddress().toString()))
                         .arg(webSocket->localPort()));
    webSocket->sendTextMessage("Connected Successfully");

    if (webSocket == webSocket_1) {
        connect(webSocket_1, SIGNAL(textMessageReceived(QString)), this, SLOT(onTextMessageReceived(QString)));
        connect(webSocket_1, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
    }

    else if (webSocket == webSocket_2) {
        connect(webSocket_2, SIGNAL(textMessageReceived(QString)), this, SLOT(onTextMessageReceived(QString)));
        connect(webSocket_2, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
    }
}

void MainWindow::onTextMessageReceived(QString str) {
    bool flag = false;
    QWebSocket *socket = (QWebSocket *)sender();
    if (str.left(14) == "Ready to Start") {
        if (webSocket_2 == nullptr) {
            assert(webSocket_1 == socket);
            colorClient_1 = str.mid(16).toInt();
        }
        else if (webSocket_2 != nullptr) { //两个Clients都已经连接上了
            if (socket == webSocket_2) colorClient_2 = str.mid(16).toInt();
            else colorClient_1 = str.mid(16).toInt();

            if (colorClient_1 != colorClient_2 && colorClient_1 != -1 && colorClient_2 != -1) {
                gameStarted = true;
                QTime randtime;
                randtime = QTime::currentTime();
                srand(randtime.msec() + randtime.second() * 1000);

                int n = rand() % 2;

                webSocket_1->sendTextMessage(QString("Enemy's BallColor=") + QString::number(colorClient_2));
                webSocket_2->sendTextMessage(QString("Enemy's BallColor=") + QString::number(colorClient_1));
                if (n == 0) {
                    webSocket_1->sendTextMessage("Start Permitted, you go first");
                    webSocket_2->sendTextMessage("Start Permitted, enemy goes first");
                }
                else {
                    assert(n == 1);
                    webSocket_2->sendTextMessage("Start Permitted, you go first");
                    webSocket_1->sendTextMessage("Start Permitted, enemy goes first");
                }
            }
            else if (colorClient_1 == colorClient_2) {
                socket->sendTextMessage("Please select another color");
                flag = true;
            }
        }
    }

    QString tmpColor;
    switch(str.mid(16).toInt()) {
        case(0):
            tmpColor = "RED";
            break;
        case(1):
            tmpColor = "YELLOW";
            break;
        case(2):
            tmpColor = "GREEN";
            break;
        case(3):
            tmpColor = "BLUE";
            break;
        case(4):
            tmpColor = "PURPLE";
            break;
        case(5):
            tmpColor = "PINK";
            break;
    }

    ui->textEdit->append(QString("Client[%1:%2]: ")
                         .arg(socket->localAddress().toString())
                         .arg(socket->localPort()) + "Ready to Start, BallSelected=" + tmpColor);
    if (gameStarted) ui->textEdit->append("GAME STARTED!");
    if (flag) ui->textEdit->append("Asking client to select another color...");
}

void MainWindow::onDisconnected() {
    QWebSocket *socket = (QWebSocket *)sender();
    qDebug() << "[1] " << socket << " " << webSocket_1 << " " << webSocket_2;
    //assert(socket == webSocket_1 || socket == webSocket_2);
    ui->textEdit->append(QString("Disconnected to Client[%1:%2]")
                         .arg(socket->localAddress().toString())
                         .arg(socket->localPort()));

    if (socket == webSocket_1) {
        webSocket_1->close();
        webSocket_1 = nullptr;
        colorClient_1 = -1;
        gameStarted = false;
    }
    else if (socket == webSocket_2) {
        webSocket_2->close();
        webSocket_2 = nullptr;
        colorClient_2 = -1;
        gameStarted = false;
    }


    qDebug() << "[2] " << socket << " " << webSocket_1 << " " << webSocket_2;
    assert(webSocket_1 == nullptr || webSocket_2 == nullptr);
    if (webSocket_1 != nullptr) {
        webSocket_1->sendTextMessage("Enemy disconnected");
    }
    else if (webSocket_2 != nullptr) {
        webSocket_2->sendTextMessage("Enemy disconnected");
    }
}

QString MainWindow::getLocalIP() {
    QList<QHostAddress> list = QNetworkInterface::allAddresses();
        foreach(QHostAddress address, list)
        {
            if(address.protocol()==QAbstractSocket::IPv4Protocol)
            {
                return address.toString();
            }
        }
        return "";
}
