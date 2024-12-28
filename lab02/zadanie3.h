#ifndef ZADANIE3_H
#define ZADANIE3_H
#include "../utils.h"
#include "const_data.h"

double f(double t, double u) {
    return (B * N - gammaz) * u - B * pow(u, 2);
}

void zadanie3() {

    std::vector<std::string> do_pliku = {};
    std::vector<double> uVec = {};
    std::vector<double> zVec = {};

    uVec.push_back(u0);
    zVec.push_back(N - u0);

    for (double t = deltaT; t <= Tmax + 0.01; t += deltaT) {
        double lastU = uVec.back();

        double lastBigU1 = lastU;
        double lastBigU2 = lastU;

        for (int mi = 0; mi <= 20; mi++) {

            double F1 = lastBigU1 - lastU - deltaT * (a11 * (L * lastBigU1 - B * pow(lastBigU1, 2)) + a12 * (L * lastBigU2 - B * pow(lastBigU2, 2)));
            double F2 = lastBigU2 - lastU - deltaT * (a21 * (L * lastBigU1 - B * pow(lastBigU1, 2)) + a22 * (L * lastBigU2 - B * pow(lastBigU2, 2)));

            double m11 = 1 - (deltaT * a11 * (L - 2 * B * lastBigU1));
            double m12 = -deltaT * a12 * (L - 2 * B * lastBigU2);
            double m21 = -deltaT * a21 * (L - 2 * B * lastBigU1);
            double m22 = 1 - (deltaT * a22 * (L - 2 * B * lastBigU2));

            double deltaBigU1 = (F2 * m12 - F1 * m22) / (m11 * m22 - m12 * m21);
            double deltaBigU2 = (F1 * m21 - F2 * m11) / (m11 * m22 - m12 * m21);

            if (fabs(deltaBigU1) < TOL && fabs(deltaBigU2) < TOL) {
                break;
            }

            lastBigU1 = lastBigU1 + deltaBigU1;
            lastBigU2 = lastBigU2 + deltaBigU2;
        }

        double nextU = lastU + deltaT * (b1 * f(t + c1 * deltaT, lastBigU1) + b2 * f(t + c2 * deltaT, lastBigU2));

        uVec.push_back(nextU);
        zVec.push_back(N - nextU);

        do_pliku.push_back(std::to_string(t) + " " + std::to_string(uVec.back()) + " " + std::to_string(zVec.back()));
    }

    saveToFile("zad03.txt", do_pliku, do_pliku.size());
}

#endif
