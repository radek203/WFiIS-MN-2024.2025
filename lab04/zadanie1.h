#ifndef ZADANIE1_H
#define ZADANIE1_H
#include "../utils.h"
#include "const_data.h"

void relGlobalna(double wG) {
    std::cout << "Start: wG = " << wG << std::endl;
    //Stara macierz
    std::vector<std::vector<double>> Vs(ny + 1, std::vector<double>(nx + 1, 0.0));

    //ny + 1 - wierszy, nx + 1 - kolumn

    // i - kolumna, j - wiersz
    // i = 0 - dolna krawedz
    // i = nx - gorna krawedz

    //Warunki brzegowe - gora i dol
    for (int i = 0; i <= nx; i++) {
        Vs[0][i] = V1; // dla dolnej krawedzi - V1
        Vs[ny][i] = V2; // dla gornej krawedzi - V2
    }

    int iter = 0;
    double sumaStara = 0;
    std::vector<std::string> do_pliku = {};

    while (true) {
        //Nowa macierz
        std::vector<std::vector<double>> Vn(ny + 1, std::vector<double>(nx + 1, 0.0));

        //Warunki brzegowe - gora i dol
        for (int i = 0; i <= nx; i++) {
            Vn[0][i] = V1; // dla dolnej krawedzi - V1
            Vn[ny][i] = V2; // dla gornej krawedzi - V2
        }

        for (int j = 1; j <= ny - 1; j++) {
            for (int i = 1; i <= nx - 1; i++) {
                Vn[j][i] = 0.25 * (Vs[j][i + 1] + Vs[j][i - 1] + Vs[j + 1][i] + Vs[j - 1][i] + (pow(delta, 2) / eps) * ro(i * delta, j * delta));
            }
        }

        //WB von Neumanna
        for (int j = 1; j <= ny - 1; j++) { // dla kazdego wiersza
            Vn[j][0] = Vn[j][1]; // lewa krawedz
            Vn[j][nx] = Vn[j][nx - 1]; // prawa krawedz
        }

        //Mieszanie rozwiazan
        for (int i = 0; i <= nx; i++) {
            for (int j = 0; j <= ny; j++) {
                Vs[j][i] = (1 - wG) * Vs[j][i] + wG * Vn[j][i];
            }
        }

        //Zdyskretyzowane calkowanie - suma
        double suma = 0;
        for (int i = 0; i <= nx - 1; i++) {
            for (int j = 0; j <= ny - 1; j++) {
                suma += pow(delta, 2) * (0.5 * pow((Vs[j][i + 1] - Vs[j][i]) / delta, 2) + 0.5 * pow((Vs[j+1][i] - Vs[j][i]) / delta, 2) - ro(i * delta, j * delta) * Vs[j][i]);
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

    std::vector<std::vector<double>> blad(ny + 1, std::vector<double>(nx + 1, 0.0));
    for (int j = 1; j <= ny - 1; j++) {
        for (int i = 1; i <= nx - 1; i++) {
            blad[j][i] = (Vs[j][i + 1] - 2 * Vs[j][i] + Vs[j][i - 1]) / pow(delta, 2) + (Vs[j + 1][i] - 2 * Vs[j][i] + Vs[j - 1][i]) / pow(delta, 2) + ro(i * delta, j * delta) / eps;
        }
    }

    std::vector<std::string> do_pliku_blad = {};
    for (int j = 0; j <= ny; j++) {
        for (int i = 0; i <= nx; i++) {
            do_pliku_blad.push_back(std::to_string(i * delta) + " " + std::to_string(j * delta) + " " + std::to_string(blad[j][i]));
        }
    }
    saveToFile("zad01_blad_" + std::to_string(wG) + ".txt", do_pliku_blad, do_pliku_blad.size());

    std::vector<std::string> do_pliku_potencjal = {};
    for (int j = 0; j <= ny; j++) {
        for (int i = 0; i <= nx; i++) {
            do_pliku_potencjal.push_back(std::to_string(i * delta) + " " + std::to_string(j * delta) + " " + std::to_string(Vs[j][i]));
        }
    }
    saveToFile("zad01_potencjal_" + std::to_string(wG) + ".txt", do_pliku_potencjal, do_pliku_potencjal.size());

    saveToFile("zad01_" + std::to_string(wG) + ".txt", do_pliku, do_pliku.size());
}

void zadanie1() {

    relGlobalna(0.6);
    relGlobalna(1.0);

}

#endif
