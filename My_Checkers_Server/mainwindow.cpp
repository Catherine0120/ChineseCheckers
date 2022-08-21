#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QList>
#include <QHostAddress>
#include <QNetworkInterface>
#include <QTime>
#include <QTimer>
#include <QtGlobal>
#include <QJsonObject>
#include <QJsonDocument>

const quint16 PORT = 8888;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString myIP = getLocalIP();
    ui->IPLabel->setText(myIP);
    ui->portLabel->setText(QString::number(PORT));

    earlyTimer = new QTimer(this);
    lateTimer = new QTimer(this);

    connect(this, SIGNAL(startTiming()), this, SLOT(timeMachineRunning()));

    connect(this, SIGNAL(startEarlyTimer()), this, SLOT(earlyTimerStart()));
    connect(earlyTimer, SIGNAL(timeout()), this, SLOT(earlyLCDCount()));
    connect(this, SIGNAL(startLateTimer()), this, SLOT(lateTimerStart()));
    connect(lateTimer, SIGNAL(timeout()), this, SLOT(lateLCDCount()));
    connect(this, SIGNAL(earlyLCDupdate()), this, SLOT(earlyClientTimeUpdate()));
    connect(this, SIGNAL(lateLCDupdate()), this, SLOT(lateClientTimeUpdate()));

    connect(this, SIGNAL(increaseRoundNumber()), this, SLOT(roundLCDUpdate()));

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
    QWebSocket *socket = (QWebSocket *)sender();

    if (str.left(14) == "Ready to Start") {
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

        if (webSocket_2 == nullptr) {
            assert(webSocket_1 == socket);
            colorClient_1 = str.mid(16).toInt();
        }
        else if (webSocket_2 != nullptr) { //两个Clients都已经连接上了
            if (socket == webSocket_2) colorClient_2 = str.mid(16).toInt();
            else colorClient_1 = str.mid(16).toInt();

            if (colorClient_1 != colorClient_2 && colorClient_1 != -1 && colorClient_2 != -1) {
                gameStarted = true;
                ui->textEdit->append("GAME STARTED!");

                QTime randtime;
                randtime = QTime::currentTime();
                srand(randtime.msec() + randtime.second() * 1000);

                int n = rand() % 2;

                webSocket_1->sendTextMessage(QString("Enemy's BallColor=") + QString::number(colorClient_2));
                webSocket_2->sendTextMessage(QString("Enemy's BallColor=") + QString::number(colorClient_1));

                if (n == 0) {
                    goFirst = 1;
                    webSocket_1->sendTextMessage("Start Permitted, you go first");
                    webSocket_2->sendTextMessage("Start Permitted, enemy goes first");
                }
                else {
                    goFirst = 2;
                    assert(n == 1);
                    webSocket_2->sendTextMessage("Start Permitted, you go first");
                    webSocket_1->sendTextMessage("Start Permitted, enemy goes first");
                }
                emit startTiming();
            }
            else if (colorClient_1 == colorClient_2) {
                socket->sendTextMessage("Please select another color");
                ui->textEdit->append("Asking client to select another color...");
            }
        }


    }

    else if (str == "My Round Ends") {
        if ((goFirst == 1 && socket == webSocket_1)
                || (goFirst == 2 && socket == webSocket_2)) {
            earlyTimer->stop();
            earlyLCD = 0;
            lateLCD = 20;
            emit earlyLCDupdate();
            emit lateLCDupdate();
            emit startLateTimer();
        }
        else {
            lateTimer->stop();
            LCDRoundNumber++;
            emit increaseRoundNumber();
            lateLCD = 0;
            earlyLCD = 20;
            emit earlyLCDupdate();
            emit lateLCDupdate();
            emit startEarlyTimer();
        }
    }

    else if (str.left(11) == "[Package]: ") {
        QString message = str.mid(11);
        ui->textEdit->append("[Package from Client]: " + message);

        if (socket == webSocket_1) {
            webSocket_2->sendTextMessage(str);
        }
        else webSocket_1->sendTextMessage(str);
    }

    else if (str == "I WIN!") {
        lateTimer->stop();
        earlyTimer->stop();
        ui->textEdit->append("Game Ended");
    }

    else if (str == "I admit defeat") {
        lateTimer->stop();
        earlyTimer->stop();
        if (socket == webSocket_1) webSocket_2->sendTextMessage("Enemy admit defeat. You win!");
        else webSocket_1->sendTextMessage("Enemy admit defeat. You win!");
        ui->textEdit->append("Game Ended");
    }

    else if (str.left(5) == "Round") {
        ui->textEdit->append("[Client]: " + str);
        lateTimer->stop();
        earlyTimer->stop();
        if (socket == webSocket_1) webSocket_2->sendTextMessage("Enemy admit defeat. You win!");
        else webSocket_1->sendTextMessage("Enemy admit defeat. You win!");
        ui->textEdit->append("Game Ended");
    }

    else if (str == "[Sender]: Pause") {
        if (socket == webSocket_1) webSocket_2->sendTextMessage("Enemy Pause");
        else webSocket_1->sendTextMessage("Enemy Pause");

        earlyTimer->stop();
        lateTimer->stop();
        ui->textEdit->append("Game Pauses...");
    }

    else if (str == "[Sender]: Stop Pause") {
        if (socket == webSocket_1) webSocket_2->sendTextMessage("Enemy Stop Pause");
        else webSocket_1->sendTextMessage("Enemy Stop Pause");

        if (earlyLCD != 0) emit startEarlyTimer();
        else {
            assert(lateLCD != 0);
            emit startLateTimer();
        }
    }
}

void MainWindow::onDisconnected() {
    QWebSocket *socket = (QWebSocket *)sender();

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


//time machine running...
void MainWindow::timeMachineRunning() {
    ui->textEdit->append("TimeMachineRunning...");
    earlyLCD = 20;
    lateLCD = 0;

    QTime dieTime = QTime::currentTime().addMSecs(2000);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

    emit earlyLCDupdate();
    emit lateLCDupdate();
    emit startEarlyTimer();
}

void MainWindow::earlyTimerStart() {
    earlyTimer->start(1000);
}

void MainWindow::lateTimerStart() {
    lateTimer->start(1000);
}

void MainWindow::earlyLCDCount() {
    if (earlyLCD != 1) {
        earlyLCD--;
        emit earlyLCDupdate();
        emit startEarlyTimer();
    }
    else {
        earlyLCD = 0;
        lateLCD = 20;
        emit earlyLCDupdate();
        emit lateLCDupdate();
        emit startLateTimer();
        earlyTimer->stop();
    }
}

void MainWindow::lateLCDCount() {
    if (lateLCD != 1) {
        lateLCD--;
        emit lateLCDupdate();
        emit startLateTimer();
    }
    else {
        lateLCD = 0;
        earlyLCD = 20;
        LCDRoundNumber++;
        emit increaseRoundNumber();
        emit earlyLCDupdate();
        emit lateLCDupdate();
        emit startEarlyTimer();
        lateTimer->stop();
    }
}

void MainWindow::earlyClientTimeUpdate() {
    if (goFirst == 1) {
        webSocket_1->sendTextMessage("Set YourTime = " + QString::number(earlyLCD));
        webSocket_2->sendTextMessage("Set EnemyTime = " + QString::number(earlyLCD));
    }
    else {
        webSocket_2->sendTextMessage("Set YourTime = " + QString::number(earlyLCD));
        webSocket_1->sendTextMessage("Set EnemyTime = " + QString::number(earlyLCD));
    }
}

void MainWindow::lateClientTimeUpdate() {
    if (goFirst == 1) {
        webSocket_1->sendTextMessage("Set EnemyTime = " + QString::number(lateLCD));
        webSocket_2->sendTextMessage("Set YourTime = " + QString::number(lateLCD));
    }
    else {
        webSocket_2->sendTextMessage("Set EnemyTime = " + QString::number(lateLCD));
        webSocket_1->sendTextMessage("Set YourTime = " + QString::number(lateLCD));
    }
}

void MainWindow::roundLCDUpdate() {
    webSocket_1->sendTextMessage("Set Round = " + QString::number(LCDRoundNumber));
    webSocket_2->sendTextMessage("Set Round = " + QString::number(LCDRoundNumber));
}
