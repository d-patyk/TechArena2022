//
// Created by dimac on 27.11.22.
//

#ifndef TECHARENA2022_RAY_H
#define TECHARENA2022_RAY_H

#include "Line.hpp"

class Ray {
public:
    Point p, u;

    Ray(Point a, Point b) {
        p = a;
        u = b - a;
    }

    Line line() {
        return Line()
    }

    Point intersect_line(Line line) {

    }
};


#endif //TECHARENA2022_RAY_H
