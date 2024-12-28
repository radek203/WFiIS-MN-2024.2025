#ifndef CONST_DATA_H
#define CONST_DATA_H

constexpr double delta = 0.01;
constexpr double ro = 1;
constexpr double mi = 1;
constexpr int nx = 200;
constexpr int ny = 90;
constexpr int i_1 = 50;
constexpr int j_1 = 55;
constexpr int j_2 = j_1 + 2;
constexpr double yj1 = delta * j_1;
constexpr double yny = delta * ny;
constexpr int IT_MAX = 20000;
double Qwe = 0;

constexpr bool is_edge(int i, int j) {
    if ((i == 0 && j >= j_1 && j <= ny)) return true;   // A
    if ((j == ny)) return true;                        // B
    if ((i == nx)) return true;                        // C
    if ((i >= i_1 && i <= nx && j == 0)) return true;  // D
    if ((i == i_1 && j >= 0 && j <= j_1)) return true;  // E
    if ((i >= 0 && i <= i_1 && j == j_1)) return true;  // F

    return false;
}

double Qwy(double Qwe) {
    return Qwe * (yny * yny * yny - yj1 * yj1 * yj1 - 3 * yj1 * yny * yny + 3 * yj1 * yj1 * yny) / (yny * yny * yny);
}

double WBS_A(int j) {
    double y = delta * j;
    return (Qwe / (2 * mi)) * (((y*y*y) / 3) - ((y*y) / 2) * (yj1 + yny) + y * yj1 * yny);
}

double WBS_C(int j) {
    double y = delta * j;
    return (Qwy(Qwe) / (2 * mi)) * (((y*y*y) / 3) - ((y*y) / 2) * yny) + (Qwe * yj1 * yj1 * (-yj1 + 3 * yny) / (12 * mi));
}

double WBW_A(int j) {
    double y = delta * j;
    return (Qwe / (2 * mi)) * (2 * y - yj1 - yny);
}

double WBW_C(int j) {
    double y = delta * j;
    return (Qwy(Qwe) / (2 * mi)) * (2 * y - yny);
}


#endif
