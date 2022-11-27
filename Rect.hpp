//
// Created by dimac on 27.11.22.
//

#ifndef TECHARENA2022_RECT_H
#define TECHARENA2022_RECT_H

#include "Segment.hpp"

class Rect {
public:
    Point left, right;

    Rect(Point left, Point right) : left(left), right(right) {}

    bool inRect(Point a) {
        return (left.x <= a.x && a.x <= right.x
            && left.y <= a.y && a.y <= right.y);
    }

    ld width() const {
        return abs(left.x - right.x);
    }

    ld height() const {
        return abs(left.y - right.y);
    }

    ld square() const {
        return width() * height();
    }

    string to_raw() {
        stringstream stream;
        stream << fixed << setprecision(20);

        stream << left.x << " " << left.y << " "
            << right.x << " " << right.y;

        return stream.str();

//        return std::to_string(left.x) +  " " + std::to_string(left.y) + " "
//             + std::to_string(right.x) + " " + std::to_string(right.y);
    }

    string to_geogebra() {
        vector<Point> points{
            left,
            Point(right.x, left.y),
            right,
            Point(left.x, right.y)
        };

        string answ = "Polygon(";
        for (int i = 0; i < points.size(); i++) {
            if (i != 0)
                answ += ", ";
            answ += points[i].to_string();
        }
        answ += ")";

        return answ;
    }

    [[nodiscard]] vector<Segment> get_segments() const {
        const Point
            &p1 = left,
            p2(left.x, right.y),
            &p3 = right,
            p4(right.x, left.y);

        return vector<Segment>{
            Segment(p1, p2),
            Segment(p2, p3),
            Segment(p3, p4),
            Segment(p4, p1)
        };
    }

    [[nodiscard]] vector<Point> get_points() const {
        return vector<Point>{
            left,
            Point(left.x, right.y),
            right,
            Point(right.x, left.y)
        };
    }
};


#endif //TECHARENA2022_RECT_H
