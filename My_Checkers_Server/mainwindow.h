#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebSocket>
#include <QWebSocketServer>
#include <QString>
#include <QTime>
#include <QTimer>
#include <QJsonObject>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool gameStarted = false;

    QTimer *earlyTimer;
    QTimer *lateTimer;

    int goFirst = -1;

    int earlyLCD, lateLCD;
    int earlyClientRunTime = 0;
    int lateClientRunTime = 0;

    int LCDRoundNumber = 1;

    QString getLocalIP();

//    QJsonObject QstringToJson(QString message);

private slots:
    void onNewConnection();

    void onTextMessageReceived(QString str="");

    void onDisconnected();

    void earlyTimerStart();

    void earlyLCDCount();

    void lateTimerStart();

    void lateLCDCount();

    void roundLCDUpdate();

//    void earlyLCDend();

//    void lateLCDend();

    void earlyClientTimeUpdate();

    void lateClientTimeUpdate();

    void timeMachineRunning();

signals:
    void startTiming();

    void startEarlyTimer();

    void startLateTimer();

    void increaseRoundNumber();

//    void endEarlyRound();

//    void endLateRound();

    void earlyLCDupdate();

    void lateLCDupdate();

private:
    Ui::MainWindow *ui;

    QWebSocket *webSocket = nullptr;
    QWebSocketServer *webSocketServer;

    QWebSocket *webSocket_1 = nullptr;
    QWebSocket *webSocket_2 = nullptr;

    int colorClient_1 = -1;
    int colorClient_2 = -1;

};
#endif // MAINWINDOW_H
