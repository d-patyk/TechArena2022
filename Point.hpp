//
// Created by dimac on 27.11.22.
//

#include "commondf.h"

#ifndef TECHARENA2022_POINT_HPP
#define TECHARENA2022_POINT_HPP


class Point {
public:
    ld x, y;

    Point() : Point(0, 0) {}

    Point(ld x, ld y) : x(x), y(y) {}

    string to_string() {
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }

    Point operator+(const Point &other) const {
        return Point(this->x + other.x, this->y + other.y);
    }

    Point operator-(const Point &other) const {
        return Point(this->x - other.x, this->y - other.y);
    }

    ld operator*(const Point &other) const {
        return this->x * other.x + this->y * other.y;
    }

    ld operator%(const Point &other) const {
        return this->x * other.y - this->y * other.x;
    }

    Point normal() {
        return Point(-y, x);
    }

    ld dist2(const Point &other) const {
        return (this->x - other.x) * (this->x - other.x) +
                (this->y - other.y) * (this->y - other.y);
    }

    ld dist(const Point &other) const {
        return sqrt(dist2(other));
    }
};

#endif //TECHARENA2022_POINT_HPP
