#ifndef CONST_DATA_H
#define CONST_DATA_H

constexpr double lambda = -1;

constexpr double R = 100.0;
constexpr double L = 0.1;
constexpr double C = 0.001;

constexpr double w0 = 1.0 / sqrt(L * C);
constexpr double T0 = (2 * M_PI) / w0;

#endif
