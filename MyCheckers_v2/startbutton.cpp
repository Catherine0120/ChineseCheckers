#include "startbutton.h"
#include <QWidget>
#include <QMouseEvent>
#include <QEvent>

startbutton::startbutton(QWidget *parent) : QPushButton(parent) {
    this->setStyleSheet("QPushButton:hover{color:#cfe2f3;}"
                        "QPushButton:pressed{color:#8ac0f0}");
}

startbutton::~startbutton() {

}

void startbutton::mouseEvent(QMouseEvent *event) {
    this->setStyleSheet("QPushButton:hover{color:#cfe2f3;}"
                        "QPushButton:pressed{color:#8ac0f0}");
}
