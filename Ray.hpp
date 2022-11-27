//
// Created by dimac on 27.11.22.
//

#ifndef TECHARENA2022_RAY_H
#define TECHARENA2022_RAY_H

#include "Segment.hpp"

class Ray {
public:
    Point p, u;

    Ray(Point a, Point b) {
        p = a;
        u = b - a;
    }

    Line to_line() {
        return Line(p, p + u);
    }

    Point intersect_line(Line line) {
        Point x = to_line().intersect(line);
        if (x.x == -LD_INF && x.y == -LD_INF) return x;
        if ((x - p) * u > 0 - EPS) return x;
        return Point(-LD_INF, -LD_INF);
    };

    Point intersect_seg(Segment seg) {
        Line line = seg.get_line();
        Point x = intersect_line(line);
        if (x.x == -LD_INF && x.y == -LD_INF) return x;
        if (seg.contains(x)) return x;
        return Point(-LD_INF, -LD_INF);
    }
};


#endif //TECHARENA2022_RAY_H
