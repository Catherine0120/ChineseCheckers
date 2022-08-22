#ifndef STARTBUTTON_H
#define STARTBUTTON_H

#include <QPushButton>
#include <QEvent>
#include <QWidget>


class startbutton : public QPushButton
{
        Q_OBJECT;
public:
    startbutton(QWidget *parent = 0);
    ~startbutton();

    void mouseEvent(QMouseEvent *event);

};

#endif // STARTBUTTON_H
