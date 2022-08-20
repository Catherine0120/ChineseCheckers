#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebSocket>
#include <QWebSocketServer>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString getLocalIP();

    bool gameStarted = false;

private slots:
    void onNewConnection();

    void onTextMessageReceived(QString str="");

    void onDisconnected();

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
