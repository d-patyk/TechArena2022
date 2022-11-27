//
// Created by dimac on 27.11.22.
//

#ifndef TECHARENA2022_TEST_H
#define TECHARENA2022_TEST_H

#include "Polygon.hpp"

class Test {
public:
    Polygon poly;
    ld c1, c2;
    string filename;

    Test(const string& filename) : filename(filename) {
        ifstream fin(filename);

        int n; fin >> n;
        fin >> c1 >> c2;

        poly.vertex.resize(n);
        for (int i = 0; i < n; ++i) fin >> poly.vertex[i].x >> poly.vertex[i].y;
    }
};


#endif //TECHARENA2022_TEST_H
