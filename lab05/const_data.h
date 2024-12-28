#ifndef CONST_DATA_H
#define CONST_DATA_H

constexpr double delta = 0.2;
constexpr int nx = 128;
constexpr int ny = 128;
constexpr double xMax = delta * nx;
constexpr double yMax = delta * ny;
constexpr double tol = 1e-8;

double VB1(double x, double y) {
    return sin(std::numbers::pi * (y / yMax));
}

double VB2(double x, double y) {
    return -sin(2.0 * std::numbers::pi * (x / xMax));
}

double VB3(double x, double y) {
    return sin(std::numbers::pi * (y / yMax));
}

double VB4(double x, double y) {
    return sin(2.0 * std::numbers::pi * (x / xMax));
}

#endif
