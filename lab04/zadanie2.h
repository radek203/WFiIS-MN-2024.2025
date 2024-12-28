#ifndef ZADANIE2_H
#define ZADANIE2_H
#include "../utils.h"
#include "const_data.h"

void relLokalna(double wL) {
    std::cout << "Start: wL = " << wL << std::endl;
    int iter = 0;
    double sumaStara = 0;
    std::vector<std::string> do_pliku = {};

    //Nowa macierz
    std::vector<std::vector<double>> V(ny + 1, std::vector<double>(nx + 1, 0.0));

    for (int i = 0; i <= nx; i++) {
        V[0][i] = V1; // dla dolnej krawedzi - V1
        V[ny][i] = V2; // dla gornej krawedzi - V2
    }

    while (true) {

        for (int j = 1; j <= ny - 1; j++) {
            for (int i = 1; i <= nx - 1; i++) {
                V[j][i] = (1.0 - wL) * V[j][i] + wL * 0.25 * (V[j][i+1] + V[j][i-1] + V[j+1][i] + V[j-1][i] + (pow(delta, 2) / eps) * ro(i * delta, j * delta));
            }
        }

        //WB von Neumanna
        for (int j = 1; j <= ny - 1; j++) { // dla kazdego wiersza
            V[j][0] = V[j][1]; // lewa krawedz
            V[j][nx] = V[j][nx - 1]; // prawa krawedz
        }

        //Zdyskretyzowane calkowanie - suma
        double suma = 0;
        for (int i = 0; i <= nx - 1; i++) {
            for (int j = 0; j <= ny - 1; j++) {
                suma += pow(delta, 2) * (0.5 * pow((V[j][i+1] - V[j][i]) / delta, 2) + 0.5 * pow((V[j+1][i] - V[j][i]) / delta, 2) - ro(i * delta, j * delta) * V[j][i]);
            }
        }

        do_pliku.push_back(std::to_string(iter) + " " + std::to_string(suma));
        //Warunek stopu
        if (iter > 0 && fabs((suma - sumaStara) / sumaStara) < tol) {
            break;
        }

        sumaStara = suma;
        iter++;
    }

    saveToFile("zad02_" + std::to_string(wL) + ".txt", do_pliku, do_pliku.size());
}

void zadanie2() {

    relLokalna(1.0);
    relLokalna(1.4);
    relLokalna(1.8);
    relLokalna(1.9);

}

#endif
