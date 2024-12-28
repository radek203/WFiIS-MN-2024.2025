#ifndef ZADANIE3_H
#define ZADANIE3_H
#include "../utils.h"
#include "const_data.h"

double analityczne3(double lambda, double t) {
    return pow(M_E, lambda * t);
}

void oblicz3(double deltaT) {
    std::vector<std::string> do_pliku = {};

    std::vector<double> wyniki = {};
    std::vector<double> blad = {};

    wyniki.push_back(1);
    do_pliku.push_back("0 " + std::to_string(wyniki.back()) + " " + std::to_string(analityczne3(lambda, 0)));
    blad.push_back(wyniki.back() - analityczne3(lambda, 0));

    for (double t = deltaT; t <= 5.001; t += deltaT) {
        double wynikiLast = wyniki.back();
        double k1 = lambda * wynikiLast;
        double k2 = lambda * (wynikiLast + (deltaT / 2.0) * k1);
        double k3 = lambda * (wynikiLast + (deltaT / 2.0) * k2);
        double k4 = lambda * (wynikiLast + deltaT * k3);
        wyniki.push_back(wynikiLast + (deltaT / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4));

        double a = analityczne3(lambda, t);
        blad.push_back(wyniki.back() - a);
        do_pliku.push_back(std::to_string(t) + " " + std::to_string(wyniki.back()) + " " + std::to_string(a));
    }

    saveToFile("zad03_" + std::to_string(deltaT) + ".txt", do_pliku, do_pliku.size());
    saveToFile("zad03_blad_" + std::to_string(deltaT) + ".txt", blad, blad.size());
}

void zadanie3() {
    oblicz3(0.01);
    oblicz3(0.1);
    oblicz3(1.0);
}

#endif
