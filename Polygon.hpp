//
// Created by dimac on 27.11.22.
//

#ifndef TECHARENA2022_POLYGON_H
#define TECHARENA2022_POLYGON_H

#include "Ray.hpp"
#include "Rect.hpp"

class Polygon {
public:
    vector<Point> vertex;

    Polygon() {}

    Polygon(vector<Point> a) {
        vertex = a;
    }

    bool in_polygon(Point p) const {
        Point x = Point(rand() % 32000, rand() % 32000);
        Ray ray = Ray(p, x);
        int cnt = 0;
        for (int i = 0; i < vertex.size(); ++i) {
            Point k = ray.intersect_seg(Segment(vertex[i], vertex[(i + 1) % vertex.size()]));
            cnt += !(k.x == -LD_INF && k.y == -LD_INF);
        }
        return (cnt % 2);
    }

    size_t size() const {
        return vertex.size();
    }

    bool intersects(const Rect rect) const {
        size_t n = size();

        bool seg_intersection = false;
        bool one_point_in_poly = false;

        for (auto&& p : rect.get_points()) {
            if (in_polygon(p)) {
                one_point_in_poly = true;
                break;
            }
        }

        for (size_t i = 0; i < n; i++) {
            Segment poly_s(vertex[i], vertex[(i + 1) % n]);

            for (auto&& rect_s : rect.get_segments()) {
                if (poly_s.intersect(rect_s)) {
                    seg_intersection = true;
                    goto nya;
                }
            }
        }
        nya:

        return one_point_in_poly || seg_intersection;
    }
};


#endif //TECHARENA2022_POLYGON_H
