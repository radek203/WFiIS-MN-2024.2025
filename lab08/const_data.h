#ifndef CONST_DATA_H
#define CONST_DATA_H

constexpr int nx = 400;
constexpr int ny = 90;
constexpr int i_1 = 200;
constexpr int i_2 = 210;
constexpr int j_1 = 50;
constexpr double delta = 0.01;
constexpr double sigma = 10 * delta;
constexpr double xa = 0.45;
constexpr double ya = 0.45;
constexpr int IT_MAX = 10000;
constexpr double tMax = IT_MAX * delta;

double u(double x, double y) {
    return 1 / (2 * M_PI * sigma * sigma) * exp(-((x-xa) * (x-xa) + (y-ya) * (y-ya)) / (2 * sigma * sigma));
}

bool is_zastawka(int i, int j) {
    return i >= i_1 && i <= i_2 && j >= 0 && j <= j_1;
}

#endif
