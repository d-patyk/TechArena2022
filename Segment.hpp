//
// Created by dimac on 27.11.22.
//

#ifndef TECHARENA2022_SEGMENT_H
#define TECHARENA2022_SEGMENT_H

#include "Line.hpp"

class Segment {
public:
    Point p1, p2;

    Segment(Point p1, Point p2) : p1(p1), p2(p2) {

    }

    bool contains(const Point &p) {
        
    }

    bool intersect(const Segment &other) {
        Line l1(p1, p2), l2(other.p1, other.p2);
    }
};


#endif //TECHARENA2022_SEGMENT_H
