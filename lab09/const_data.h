#ifndef CONST_DATA_H
#define CONST_DATA_H

constexpr int nx = 40;
constexpr int ny = 40;
constexpr int N = (nx + 1) * (ny + 1);
constexpr double delta = 1;
constexpr double deltaT = 1;
constexpr double TA = 40;
constexpr double TB = 0;
constexpr double TC = 30;
constexpr double TD = 0;
constexpr double kB = 0.1;
constexpr double kD = 0.6;
constexpr int IT_MAX = 2000;

int calcL(int i, int j) {
    return i + j * (nx + 1);
}

std::string to_string_with_precision(double value, int precision = 10) {
    std::ostringstream out;
    out << std::fixed << std::setprecision(precision) << value;
    return out.str();
}

#endif
