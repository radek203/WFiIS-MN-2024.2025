#ifndef CONST_DATA_H
#define CONST_DATA_H

constexpr int nx = 150;
constexpr int nt = 1000;
constexpr double delta = 0.1;
constexpr double deltaT = 0.05;
constexpr double xA = 7.5;
constexpr double sigma = 0.5;
constexpr double xF = 2.5;
constexpr double tMax = nt * deltaT;

int deltaKron(int i) {
    return (i * delta) == xF;
}

#endif
