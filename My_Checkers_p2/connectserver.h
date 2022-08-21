#ifndef CONNECTSERVER_H
#define CONNECTSERVER_H

#include <QDialog>
#include <QWebSocket>

namespace Ui {
class connectserver;
}

class connectserver : public QDialog
{
    Q_OBJECT

public:
    explicit connectserver(QWidget *parent = nullptr);
    ~connectserver();

    bool connectedToServer = false;

    QWebSocket *webSocket;

    int enemyColor = -1;

    QJsonObject QstringToJson(QString message);

private slots:
    void outputMessageReceived(QString);

    void on_connectButton_clicked();

    void on_disconnectButton_clicked();

    void on_closeButton_clicked();

signals:
    void startPermitted(bool);

    void changeColor();

    void getEnemyColor();

    void endGame();

    void updateMyTime(int);

    void updateEnemyTime(int);

    void updateRound(int);

    void messageReceived(int, int, int);

private:
    Ui::connectserver *ui;
};

#endif // CONNECTSERVER_H
