#include "eventlabel.h"
#include <QMouseEvent>
#include <QString>

eventlabel::eventlabel()
{

}

void eventlabel::mouseMoveEvent(QMouseEvent *event) {
    this->setText(QString("<center><h1>Move: (%1, %2)</h1></center>")
                  .arg(QString::number(event->x()),QString::number(event->y())));
}

void eventlabel::mousePressEvent(QMouseEvent *event) {
    this->setText(QString("<center><h1>Press:(%1, %2)</h1></center>")
                  .arg(QString::number(event->x()),QString::number(event->y())));
}

