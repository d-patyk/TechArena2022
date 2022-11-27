#include "commondf.h"
#include "Point.hpp"
#include "Rect.hpp"
#include "Line.hpp"
#include "Segment.hpp"

using namespace std;

void polygon_maker(const string &filename) {
    ifstream fin(filename);
    cout << filename << endl;

    int n; fin >> n;
    ld c1, c2; fin >> c1 >> c2;
    vector<Point> poly(n);
    for (int i = 0; i < n; ++i) fin >> poly[i].x >> poly[i].y;

    string answ = "Polygon(";
    for (int i = 0; i < n; i++)
        answ += poly[i].to_string() + ((i + 1 != n) ? ", " : "");
    answ += ")";

    cout << answ << endl << endl;
}

Rect shit_solver_rect(const string &filename) {
    ifstream fin(filename);
    cout << filename << endl;

    int n; fin >> n;
    ld c1, c2; fin >> c1 >> c2;
    vector<Point> poly(n);
    for (int i = 0; i < n; ++i) fin >> poly[i].x >> poly[i].y;

    ld x_min = INFINITY, y_min = ;
    ld x_max = -INFINITY, y_max = -INFINITY;

    for (auto&& p : poly) {
        x_min = min(x_min, p.x);
        y_min = min(y_min, p.y);

        x_max = max(x_max, p.x);
        y_max = max(y_max, p.y);
    }

    return Rect(Point(x_min, y_min), Point(x_max, y_max));
}

void shit_solver(const string &filename) {
    cout << "1" << "\n";
    cout << shit_solver_rect(filename).to_raw() << "\n\n";
}

void solver1(const string &filename) {
    ifstream fin(filename);
    cout << filename << endl;

    int n; fin >> n;
    ld c1, c2; fin >> c1 >> c2;
    vector<Point> poly(n);
    for (int i = 0; i < n; ++i) fin >> poly[i].x >> poly[i].y;

    Point a(poly[5].x, poly[1].y),
          b(poly[6].x, poly[1].y);

//    vector<Rect> rectangles{
//            Rect(poly[2], poly[4]),
//            Rect(a, poly[6]),
//            Rect(poly[0], b),
//            Rect(poly[10], poly[8])
//    };

    vector<Rect> rectangles{
            Rect(poly[2], poly[4]),
            Rect(poly[0], poly[6]),
            Rect(poly[10], poly[8])
    };


    cout << rectangles.size() << "\n";
    for (auto&& rect : rectangles) {
        cout << rect.to_raw() << "\n";
    }
}

int main() {
    vector<string> tests{
        "no_tests",
        "tests/01.txt",
        "tests/02.txt",
        "tests/03.txt",
        "tests/04.txt",
        "tests/05.txt",
        "tests/06.txt",
        "tests/07.txt"
    };

    // shit
    cout.precision(20);
    ios_base::sync_with_stdio(0);

    // polygons for geogebra
    polygon_maker(tests[1]);
//    polygon_maker("tests/02.txt");
//    polygon_maker("tests/03.txt");

    //
    solver1(tests[1]);

    for (int i = 1; i <= 7; i++) {
        shit_solver(tests[i]);
    }
}
