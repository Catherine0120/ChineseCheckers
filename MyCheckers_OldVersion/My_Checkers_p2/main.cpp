#include "mainwindow.h"

#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w1;
    w1.resize(1060, 720);
    w1.show();

    return a.exec();
}
