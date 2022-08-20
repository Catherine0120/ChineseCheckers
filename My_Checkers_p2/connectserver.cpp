#include "connectserver.h"
#include "ui_connectserver.h"

#include <QUrl>
#include <QMessageBox>
#include <QTime>
#include <QCoreApplication>

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
        qDebug() << "eneymeColor = " << enemyColor;
        emit getEnemyColor();
    }
    else if (str == "Enemy disconnected") {
        ui->textEdit->append("[Server]: Enemy disconnected");
        QMessageBox::warning(this, "Warning", "Enemy disconnected");
        emit endGame();
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

