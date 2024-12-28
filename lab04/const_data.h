#ifndef CONST_DATA_H
#define CONST_DATA_H

constexpr double eps = 1;
constexpr double delta = 0.1;
constexpr double nx = 150;
constexpr double ny = 100;
constexpr double V1 = 10;
constexpr double V2 = 0;
constexpr double xMax = delta * nx;
constexpr double yMax = delta * ny;
constexpr double sigmaX = 0.1 * xMax;
constexpr double sigmaY = 0.1 * yMax;
constexpr double tol = 1e-8;

double ro1(double x, double y) {
    return exp(- (pow(x - 0.35 * xMax, 2) / pow(sigmaX, 2)) - (pow(y - 0.5 * yMax, 2) / pow(sigmaY, 2)));
}

double ro2(double x, double y) {
    return -exp(- (pow(x - 0.65 * xMax, 2) / pow(sigmaX, 2)) - (pow(y - 0.5 * yMax, 2) / pow(sigmaY, 2)));
}

double ro(double x, double y) {
    return ro1(x, y) + ro2(x, y);
}

#endif
