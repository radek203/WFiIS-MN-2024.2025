#ifndef ZADANIE_H
#define ZADANIE_H
#include "../utils.h"
#include "const_data.h"

void zadanie() {

    std::vector<std::vector<double>> V(ny + 1, std::vector<double>(nx + 1, 0.0));

    int k = 1;

    // Warunki brzegowe dla najrzadszej siatki
    for (int i = 0; i <= nx; i += k) {
        V[0][i] = VB4(i * delta, 0); // dolna krawedz
        V[ny][i] = VB2(i * delta, 0); // gorna krawedz
    }

    for (int i = 0; i <= ny; i += k) {
        V[i][0] = VB1(0, i * delta); // lewa krawedz
        V[i][nx] = VB3(0, i * delta); // prawa krawedz
    }

    int iter = 1;
    double sumaStara = 0;
    std::vector<std::string> do_pliku = {};
    std::vector<std::string> do_pliku_iter = {};

    for (k = 16; k >= 1; k /= 2) {
        while (true) {

            for (int j = k; j <= ny - k; j += k) {
                for (int i = k; i <= nx - k; i += k) {
                    V[j][i] = 0.25 * (V[j][i + k] + V[j][i - k] + V[j + k][i] + V[j - k][i]);
                }
            }

            //Zdyskretyzowane calkowanie - suma
            double suma = 0;
            for (int i = 0; i <= nx - k; i += k) {
                for (int j = 0; j <= ny - k; j += k) {
                    suma +=
                        (0.5 * pow(delta * k, 2))
                        * (
                            pow(((V[j][i + k] - V[j][i]) / (2 * k * delta)) + ((V[j+k][i+k] - V[j+k][i]) / (2 * k * delta)), 2)
                            + pow(((V[j+k][i] - V[j][i]) / (2 * k * delta)) + ((V[j+k][i+k] - V[j][i+k]) / (2 * k * delta)), 2)
                        );
                }
            }

            //Warunek stopu
            iter++;
            do_pliku_iter.push_back(std::to_string(iter - 1) + " " + std::to_string(suma) + " " + std::to_string(k));
            if (iter > 0 && fabs((suma - sumaStara) / sumaStara) < tol) {
                for (int j = 0; j <= ny; j+=k) {
                    for (int i = 0; i <= nx; i+=k) {
                        do_pliku.push_back(std::to_string(i * delta) + " " + std::to_string(j * delta) + " " + std::to_string(V[j][i]));
                    }
                }

                saveToFile("zad_pot_" + std::to_string(k) + ".txt", do_pliku, do_pliku.size());
                do_pliku.clear();
                break;
            }

            sumaStara = suma;
        }

        // Interpolacja liniowa, bez warunkow brzegowych
        for (int j = 0; j <= ny - k; j += k) {
            for (int i = 0; i <= nx - k; i += k) {
                V[j + k/2][i + k/2] = 0.25 * (V[j][i] + V[j][i + k] + V[j + k][i] + V[j + k][i + k]);

                if (i != nx - k) {
                    V[j + k/2][i + k] = 0.5 * (V[j][i + k] + V[j + k][i + k]);
                }
                if (j != ny - k) {
                    V[j + k][i + k/2] = 0.5 * (V[j + k][i] + V[j + k][i + k]);
                }
                if (j != 0) {
                    V[j][i + k/2] = 0.5 * (V[j][i] + V[j][i + k]);
                }
                if (i != 0) {
                    V[j + k/2][i] = 0.5 * (V[j][i] + V[j + k][i]);
                }
            }
        }

    }

    saveToFile("zad_iter.txt", do_pliku_iter, do_pliku_iter.size());
}

#endif
