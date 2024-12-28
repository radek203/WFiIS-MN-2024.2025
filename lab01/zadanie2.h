#ifndef ZADANIE2_H
#define ZADANIE2_H
#include "../utils.h"
#include "const_data.h"

double analityczne2(double lambda, double t) {
    return pow(M_E, lambda * t);
}

void oblicz2(double deltaT) {
    std::vector<std::string> do_pliku = {};

    std::vector<double> wyniki = {};
    std::vector<double> blad = {};

    wyniki.push_back(1);
    do_pliku.push_back("0 " + std::to_string(wyniki.back()) + " " + std::to_string(analityczne2(lambda, 0)));
    blad.push_back(wyniki.back() - analityczne2(lambda, 0));

    for (double t = deltaT; t <= 5.001; t += deltaT) {
        double wynikiLast = wyniki.back();
        double k1 = lambda * wynikiLast;
        double k2 = lambda * (wynikiLast + deltaT * k1);
        wyniki.push_back(wynikiLast + (deltaT / 2.0) * (k1 + k2));

        double a = analityczne2(lambda, t);
        blad.push_back(wyniki.back() - a);
        do_pliku.push_back(std::to_string(t) + " " + std::to_string(wyniki.back()) + " " + std::to_string(a));
    }

    saveToFile("zad02_" + std::to_string(deltaT) + ".txt", do_pliku, do_pliku.size());
    saveToFile("zad02_blad_" + std::to_string(deltaT) + ".txt", blad, blad.size());
}

void zadanie2() {
    oblicz2(0.01);
    oblicz2(0.1);
    oblicz2(1.0);
}

#endif
