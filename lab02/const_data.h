#ifndef CONST_DATA_H
#define CONST_DATA_H

constexpr double N = 500;
constexpr double B = 0.001;
constexpr double gammaz = 0.1;

constexpr double u0 = 1;

constexpr double deltaT = 0.1;
constexpr double Tmax = 100;
constexpr double TOL = 1e-6;

constexpr double L = B * N - gammaz;

constexpr double a11 = 1.0 / 4.0;
constexpr double a12 = 1.0 / 4.0 - sqrt(3) / 6.0;
constexpr double a21 = 1.0 / 4.0 + sqrt(3) / 6.0;
constexpr double a22 = 1.0 / 4.0;
constexpr double b1 = 0.5;
constexpr double b2 = 0.5;
constexpr double c1 = 0.5 - sqrt(3) / 6.0;
constexpr double c2 = 0.5 + sqrt(3) / 6.0;

#endif
