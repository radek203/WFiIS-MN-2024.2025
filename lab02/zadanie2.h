#ifndef ZADANIE2_H
#define ZADANIE2_H
#include "../utils.h"
#include "const_data.h"

void zadanie2() {

    std::vector<std::string> do_pliku = {};
    std::vector<double> uVec = {};
    std::vector<double> zVec = {};
    uVec.push_back(u0);
    zVec.push_back(N - u0);

    for (double t = deltaT; t <= Tmax + 0.01; t += deltaT) {
        double lastU = uVec.back();

        double nextULast = lastU + TOL * 10; // zeby przy pierwszej iteracji nie bylo rowne
        double nextU = lastU;
        for (int mi = 0; mi <= 20; mi++) {
            nextU = nextU - (nextU - lastU - (deltaT / 2.0) * ((L * lastU - B * pow(lastU, 2)) + (L * nextU - B * pow(nextU, 2)))) / (1 - (deltaT / 2.0) * (L - 2 * B * nextU));

            if (fabs(nextU - nextULast) < TOL) {
                break;
            }
            nextULast = nextU;
        }

        uVec.push_back(nextU);
        zVec.push_back(N - nextU);

        do_pliku.push_back(std::to_string(t) + " " + std::to_string(uVec.back()) + " " + std::to_string(zVec.back()));
    }

    saveToFile("zad02.txt", do_pliku, do_pliku.size());
}

#endif
