#ifndef CHESS_H
#define CHESS_H

#include <QRect>

enum side_set {ENEMY = 0, ME = 1};

struct Chess {
    double x;
    double y;
    int color;
    enum side_set side;

    //chessboard:
    bool mouseon = false;
    bool haschess = false;
    int chessboardlabel = -1; //0-120
    bool feasibility = false;

    //chessesplayed:
    bool beingpressed = false;
    int chesslabel = -1; //enemy:0-9, me:10-19

    Chess(double x_, double y_, int color_) : x(x_), y(y_), color(color_) {}
};

#endif // CHESS_H
