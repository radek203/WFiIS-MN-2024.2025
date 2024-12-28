#ifndef ZADANIE1_H
#define ZADANIE1_H
#include "../utils.h"

constexpr double alpha = 5.0;
constexpr double delta = 1e-10;

constexpr double tMax = 40.0;
constexpr double S = 0.75;
constexpr double p = 2.0;

double f(double x, double v) {
    return v;
}

double g(double x, double v) {
    return alpha * (1.0 - x * x) * v - x;
}

double *trapezow(double x, double v, double deltaT) {
    double xNew = x;
    double vNew = v;

    while (true) {
        double F = xNew - x - (deltaT / 2.0) * (f(x, v) + f(xNew, vNew));
        double G = vNew - v - (deltaT / 2.0) * (g(x, v) + g(xNew, vNew));

        double a11 = 1.0;
        double a12 = -deltaT / 2.0;
        double a21 = -(deltaT / 2.0) * (-2.0 * alpha * xNew * vNew - 1.0);
        double a22 = 1.0 - (deltaT / 2.0) * alpha * (1.0 - xNew * xNew);

        double deltaX = ((-F) * a22 - (-G) * a12) / (a11 * a22 - a12 * a21);
        double deltaV = (a11 * (-G) - a21 * (-F)) / (a11 * a22 - a12 * a21);

        xNew += deltaX;
        vNew += deltaV;

        if (fabs(deltaX) < delta && fabs(deltaV) < delta) {
            break;
        }
    }

    return new double[2]{xNew, vNew};
}

double *rk2(double x, double v, double deltaT) {
    double k1x = f(x, v);
    double k1v = g(x, v);

    double k2x = v + deltaT * k1v;
    double k2v = alpha * (1.0 - pow(x + deltaT * k1x, 2.0)) * (v + deltaT * k1v) - (x + deltaT * k1x);

    double xNew = x + (deltaT / 2.0) * (k1x + k2x);
    double vNew = v + (deltaT / 2.0) * (k1v + k2v);

    return new double[2]{xNew, vNew};
}

void alg(std::string name, double TOL, double *f(double, double, double)) {
    std::vector<std::string> do_pliku = {};

    double t = 0.0;
    double deltaT = 1.0;
    double x = 0.01;
    double v = 0.0;

    while (t < tMax) {
        double *result = f(x, v, deltaT);
        double *result2 = f(result[0], result[1], deltaT);

        double *result3 = f(x, v, 2 * deltaT);

        double Ex = (result2[0] - result3[0]) / (pow(2.0, p) - 1.0);
        double Ev = (result2[1] - result3[1]) / (pow(2.0, p) - 1.0);

        if (fmax(fabs(Ex), fabs(Ev)) < TOL) {
            t = t + 2.0 * deltaT;
            x = result2[0];
            v = result2[1];

            do_pliku.push_back(std::to_string(t) + " " + std::to_string(deltaT) + " " + std::to_string(x) + " " + std::to_string(v));
        }

        delete []result;
        delete []result2;
        delete []result3;

        deltaT = pow((S * TOL) / fmax(fabs(Ex), fabs(Ev)), 1.0 / (p + 1.0)) * deltaT;
    }

    saveToFile(name, do_pliku, do_pliku.size());
}

void zadanie() {
    alg("zad01_M2.txt", 1e-2, rk2);
    alg("zad01_M5.txt", 1e-5, rk2);

    alg("zad02_M2.txt", 1e-2, trapezow);
    alg("zad02_M5.txt", 1e-5, trapezow);
}

#endif
