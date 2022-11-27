#include "commondf.h"
#include "Point.hpp"
#include "Rect.hpp"
#include "Line.hpp"
#include "Segment.hpp"
#include "Polygon.hpp"
#include "Test.hpp"

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

Rect shit_solver_rect(const Test &test) {
    int n = test.poly.vertex.size();
    vector<Point> poly = test.poly.vertex;

    ld x_min = LD_INF, y_min = LD_INF;
    ld x_max = -LD_INF, y_max = -LD_INF;

    for (auto&& p : poly) {
        x_min = min(x_min, p.x);
        y_min = min(y_min, p.y);

        x_max = max(x_max, p.x);
        y_max = max(y_max, p.y);
    }

    return Rect(Point(x_min, y_min), Point(x_max, y_max));
}

bool eval_points(const Test &test, const vector<Rect> &rects) {
//    ld square;

//    for (int i = 0; i < )

    return 100;
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

vector<Rect> div(Test &test, int k) {
    vector<Rect> res;
    Rect big_rect = shit_solver_rect(test);
    Point u = (big_rect.right - big_rect.left) / k;
    for (int i = 0; i < k; ++i) {
        Rect rect = Rect(big_rect.left + u * i, big_rect.right + u * (i + 1));
        if (test.poly.intersects(rect)) res.push_back(rect);
    }
    return res;
}

void print(const string &filename, const vector<Rect> &rects){
    cout << "filename" << "\n";
    cout << rects.size() << "\n";

    for (auto rect : rects)
        cout << rect.left.x << " " << rect.left.y << " " << rect.right.x << " " << rect.right.y << "\n";

    cout << "\n";
}

int main() {
    vector<string> filenames{
        "tests/01.txt",
        "tests/02.txt",
        "tests/03.txt",
        "tests/04.txt",
        "tests/05.txt",
        "tests/06.txt",
        "tests/07.txt"
    };

    vector<Test> tests;

    for (auto&& filename : filenames)
        tests.emplace_back(filename);

    // shit
    cout.precision(20);
    ios_base::sync_with_stdio(0);

    for (int i = 0; i < 7; i++) {
        print(filenames[i], div(tests[i], 10));
    }

//    for (int i = 1; i <= 7; i++) {
//        shit_solver(tests[i]);
//    }
}
