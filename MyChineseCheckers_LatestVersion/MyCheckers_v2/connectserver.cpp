#include "connectserver.h"
#include "ui_connectserver.h"

#include <QUrl>
#include <QMessageBox>
#include <QTime>
#include <QCoreApplication>
#include <QString>
#include <QJsonObject>
#include <QJsonDocument>
#include <QStringList>

connectserver::connectserver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::connectserver)
{
    ui->setupUi(this);
    this->setWindowTitle("Connect to Server");
    this->setWindowModality(Qt::WindowModal);

    ui->IPInput->setText("127.0.0.1");

    webSocket = new QWebSocket();

    connect(webSocket, SIGNAL(textMessageReceived(QString)), this, SLOT(outputMessageReceived(QString)));
}

connectserver::~connectserver()
{
    delete ui;
}


void connectserver::on_connectButton_clicked() {
    QString ip = ui->IPInput->text();
    QString port = ui->portInput->text();
    ui->textEdit->setText("Connecting...");
    webSocket->open(QUrl(QString("ws://%1:%2").arg(ip).arg(port)));
}

void connectserver::outputMessageReceived(QString str) {
    //preparation for the game
    if (str == "Connected Successfully") {
        ui->textEdit->append("[Server]: " + str);
        connectedToServer = true;
    }

    else if (str.left(15) == "Start Permitted") {
        ui->textEdit->append("[Server]: Game Starts Now!");
        if (str == "Start Permitted, you go first") emit startPermitted(true);
        else {
            assert (str == "Start Permitted, enemy goes first");
            emit startPermitted(false);
        }
    }

    else if (str == "Please select another color") {
        emit changeColor();
        ui->textEdit->append("[Server]: Select another color, please");
    }

    else if (str.left(18) == "Enemy's BallColor=") {
        enemyColor = str.mid(18).toInt();
        emit getEnemyColor();
    }

    else if (str == "Enemy disconnected") {
        ui->textEdit->append("[Server]: Enemy disconnected");
        QMessageBox::warning(this, "Warning", "Enemy disconnected");
        emit endGame();
    }

    //timer
    else if (str.left(3) == "Set") {
//        ui->textEdit->append("[Timing/Round]: " + str);
        if (str.left(15) == "Set YourTime = ") {
            emit updateMyTime(str.mid(15).toInt());
        }
        else if (str.left(16) == "Set EnemyTime = ") {
           emit updateEnemyTime(str.mid(16).toInt());
        }
        else if (str.left(12) == "Set Round = ") {
            emit updateRound(str.mid(12).toInt());
        }
    }

    //package
    else if (str.left(11) == "[Package]: ") {
        int origin_pos = -1;
        int arrival_pos = -1;
        int chess_label = -1;
        QString message = str.mid(11);
        QJsonObject jsonMessage = QstringToJson(message);
        const QStringList &keys = jsonMessage.keys();
        for (const QString &key : keys) {
            if (key == "origin_pos") origin_pos = jsonMessage.value(key).toInt();
            else if (key == "arrival_pos") arrival_pos = jsonMessage.value(key).toInt();
            else if (key == "chess_label") chess_label = jsonMessage.value(key).toInt();
            }
        assert(origin_pos != -1 && arrival_pos != -1 && chess_label != -1);
        emit messageReceived(origin_pos, arrival_pos, chess_label);
        }

    else if (str == "Enemy admit defeat. You win!") {
        emit EnemyAdmitDefeat();
    }

    else if (str == "Enemy Pause") {
        ui->textEdit->append("Enemy Pause...Please wait...");
        emit enemyPause();
    }

    else if (str == "Enemy Stop Pause") {
        ui->textEdit->append("Enemy Stop Pause...Please continue...");
        emit enemyStopPause();
    }

    else if (str == "3 RunOutOfTime!") {
        emit runOutOfTime();
    }
    else if (str == "Enemy 3 RunOutOfTime!") {
        emit enemyRunOutOfTime();
    }
}

void connectserver::on_disconnectButton_clicked()
{
    if (webSocket == nullptr) return;

    QMessageBox::warning(this, "Warning", "Disconnection from Server will force stop the game");
    ui->textEdit->append("Disconnected from server");
    connectedToServer = false;
    webSocket->close();
    webSocket = nullptr;

    QTime dieTime = QTime::currentTime().addMSecs(1000);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

    emit endGame();
}

void connectserver::on_closeButton_clicked()
{
    this->close();
}

QJsonObject connectserver::QstringToJson(QString message) {
    QJsonDocument jsonDocument = QJsonDocument::fromJson(message.toLocal8Bit().data());
    if (jsonDocument.isNull()) {
        ui->textEdit->append("[Error]: package from client is empty");
    }
    QJsonObject json_obj = jsonDocument.object();
    return json_obj;
}
