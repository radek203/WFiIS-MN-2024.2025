#ifndef ZADANIE1_H
#define ZADANIE1_H
#include "../utils.h"
#include "const_data.h"

double analityczne1(double lambda, double t) {
    return pow(M_E, lambda * t);
}

void oblicz1(double deltaT) {
    std::vector<std::string> do_pliku = {};

    std::vector<double> wyniki = {};
    std::vector<double> blad = {};

    wyniki.push_back(1);
    do_pliku.push_back("0 " + std::to_string(wyniki.back()) + " " + std::to_string(analityczne1(lambda, 0)));
    blad.push_back(wyniki.back() - analityczne1(lambda, 0));

    for (double t = deltaT; t <= 5.001; t += deltaT) {
        double wynikiLast = wyniki.back();
        wyniki.push_back(wynikiLast + deltaT * lambda * wynikiLast);

        double a = analityczne1(lambda, t);
        blad.push_back(wyniki.back() - a);
        do_pliku.push_back(std::to_string(t) + " " + std::to_string(wyniki.back()) + " " + std::to_string(a));
    }

    saveToFile("zad01_" + std::to_string(deltaT) + ".txt", do_pliku, do_pliku.size());
    saveToFile("zad01_blad_" + std::to_string(deltaT) + ".txt", blad, blad.size());
}

void zadanie1() {
    oblicz1(0.01);
    oblicz1(0.1);
    oblicz1(1.0);
}

#endif
