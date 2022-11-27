//
// Created by dimac on 27.11.22.
//

#ifndef TECHARENA2022_LINE_H
#define TECHARENA2022_LINE_H

#include "Point.hpp"

class Line {
public:
    Point n, p;

    Line(Point p1, Point p2) {
        this->p = p1;
        this->n = (p2 - p1).normal();
    }

    ld A() {return n.x;}
    ld B() {return n.y;}
    ld C() {return -(p.x * A() + p.y * B());}

    Point intersect(Line line) {
        if (n % line.n < EPS) return Point(-LD_INF, -LD_INF);
        ld x = -(C() * line.B() - line.C() * B()) / (n % line.n);
        ld y = -(C() * line.A() - line.C() * A()) / (n % line.n);
        return Point(x, y);
    }
};


#endif //TECHARENA2022_LINE_H
