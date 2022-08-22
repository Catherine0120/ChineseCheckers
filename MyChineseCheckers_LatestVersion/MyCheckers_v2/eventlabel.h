#ifndef EVENTLABEL_H
#define EVENTLABEL_H

#include <QLabel>
#include <QMouseEvent>


class eventlabel : public QLabel
{
public:
    eventlabel();

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

};

#endif // EVENTLABEL_H
