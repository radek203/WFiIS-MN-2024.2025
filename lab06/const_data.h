#ifndef CONST_DATA_H
#define CONST_DATA_H

constexpr double delta = 0.1;
int nx;
int ny;
int e1;
int e2;
int V1;
int V2;
int V3;
int V4;
int N;

double xMax;
double yMax;
double sigma;

void setData(int nxNew, int nyNew, int e1New, int e2New, int V1New, int V2New, int V3New, int V4New) {
    nx = nxNew;
    ny = nyNew;
    N = (nx + 1) * (ny + 1);
    xMax = delta * nx;
    yMax = delta * ny;
    sigma = xMax / 10.0;
    e1 = e1New;
    e2 = e2New;
    V1 = V1New;
    V2 = V2New;
    V3 = V3New;
    V4 = V4New;
}

double ro1(double xi, double yi) {
    return exp(- (pow(xi - 0.25 * xMax, 2) / (sigma * sigma)) - (pow(yi - 0.5 * yMax, 2) / (sigma * sigma)));
}

double ro2(double xi, double yi) {
    return -exp(- (pow(xi - 0.75 * xMax, 2) / (sigma * sigma)) - (pow(yi - 0.5 * yMax, 2) / (sigma * sigma)));
}

double roZ3(int i, int j) {
    return 0.0;
}

double roZ6(int i, int j) {
    double xi = delta * i;
    double yi = delta * j;

    return -(ro1(xi, yi) + ro2(xi, yi));
}

double el(int i) {
    if (i <= nx/2) {
        return e1;
    }
    return e2;
}

double a1(int i) {
    return el(i) / (delta * delta);
}

double a2(int i) {
    return el(i) / (delta * delta);
}

double a3(int i) {
    return - (2 * el(i) + el(i) + el(i)) / (delta * delta);
}

double a4(int i) {
    return el(i) / (delta * delta);
}

double a5(int i) {
    return el(i) / (delta * delta);
}

#endif
