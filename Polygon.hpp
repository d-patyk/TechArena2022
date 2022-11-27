//
// Created by dimac on 27.11.22.
//

#ifndef TECHARENA2022_POLYGON_H
#define TECHARENA2022_POLYGON_H

#include "Segment.hpp";

class Polygon {
public:
    vector<Point> vertex;

    Polygon(vector<Point> a) {
        vertex = a;
    }

    bool in_polygon(Point p) {
        return true;
    }
};


#endif //TECHARENA2022_POLYGON_H
