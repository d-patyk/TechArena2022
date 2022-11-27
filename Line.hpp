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

    ld A() {return n.x}

    Point intersect(Line line) {

    }
};


#endif //TECHARENA2022_LINE_H
