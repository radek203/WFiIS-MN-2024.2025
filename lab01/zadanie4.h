#ifndef ZADANIE4_H
#define ZADANIE4_H
#include "../utils.h"
#include "const_data.h"

void oblicz4(double deltaT, double wVwsp) {
    std::vector<std::string> do_plikuQ = {};
    std::vector<std::string> do_plikuI = {};

    std::vector<double> wynikiQ = {};
    std::vector<double> wynikiI = {};

    wynikiQ.push_back(0);
    wynikiI.push_back(0);

    do_plikuQ.push_back("0 " + std::to_string(wynikiQ.back()));
    do_plikuI.push_back("0 " + std::to_string(wynikiI.back()));

    for (double t = deltaT; t <= (4 * T0 + 0.001); t += deltaT) {
        double lastQ = wynikiQ.back();
        double lastI = wynikiI.back();
        double V = 10 * sin(wVwsp * w0 * t);
        double VN1 = 10 * sin(wVwsp * w0 * (t + deltaT));
        double VN12 = (V + VN1) / 2.0;

        double k1Q = lastI;
        double k1I = (V - lastQ / C - R * lastI) / L;

        double k2Q = lastI + (deltaT / 2.0) * k1I;
        double k2I = (VN12 - (lastQ + (deltaT / 2.0) * k1Q) / C - R * (lastI + (deltaT / 2.0) * k1I)) / L;

        double k3Q = lastI + (deltaT / 2.0) * k2I;
        double k3I = (VN12 - (lastQ + (deltaT / 2.0) * k2Q) / C - R * (lastI + (deltaT / 2.0) * k2I)) / L;

        double k4Q = lastI + deltaT * k3I;
        double k4I = (VN1 - (lastQ + deltaT * k3Q) / C - R * (lastI + deltaT * k3I)) / L;

        wynikiQ.push_back(lastQ + (deltaT / 6.0) * (k1Q + 2 * k2Q + 2 * k3Q + k4Q));
        wynikiI.push_back(lastI + (deltaT / 6.0) * (k1I + 2 * k2I + 2 * k3I + k4I));

        do_plikuQ.push_back(std::to_string(t) + " " + std::to_string(wynikiQ.back()));
        do_plikuI.push_back(std::to_string(t) + " " + std::to_string(wynikiI.back()));
    }

    saveToFile("zad04Q_" + std::to_string(wVwsp) + ".txt", do_plikuQ, do_plikuQ.size());
    saveToFile("zad04I_" + std::to_string(wVwsp) + ".txt", do_plikuI, do_plikuI.size());
}

void zadanie4() {
    oblicz4(0.0001, 0.5);
    oblicz4(0.0001, 0.8);
    oblicz4(0.0001, 1.0);
    oblicz4(0.0001, 1.2);
}

#endif
