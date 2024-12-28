#ifndef ZADANIE_H
#define ZADANIE_H

#include "../utils.h"
#include "const_data.h"

void oblicz(double alfa, double beta, bool pocz = true) {
    std::vector<std::vector<double>> u0(nx + 1, std::vector<double>(nt + 1, 0.0));
    std::vector<std::vector<double>> u(nx + 1, std::vector<double>(nt + 1, 0.0));
    std::vector<std::vector<double>> v(nx + 1, std::vector<double>(nt + 1, 0.0));
    std::vector<double> vp(nx, 0.0);
    std::vector<std::vector<double>> a(nx + 1, std::vector<double>(nt + 1, 0.0));
    std::vector<double> e(nt + 1, 0.0);

    if (pocz) {
        for (int i = 0; i <= nx; i++) {
            double x = i * delta;
            u[i][0] = exp(- ((x - xA) * (x - xA)) / (2 * sigma * sigma));
        }
    }

    //u0 = u
    for (int i = 0; i <= nx; i++) {
        for (int j = 0; j <= nt; j++) {
            u0[i][j] = u[i][j];
        }
    }

    for (int i = 1; i < nx; i++) {
        for (int n = 1; n <= nt; n++) {
            a[i][n] = ((u[i+1][n] - 2 * u[i][n] + u[i-1][n]) / (delta * delta)) - beta * ((u[i][n] - u[i][n-1]) / deltaT) + alfa * (cos((50.0 * n * deltaT) / tMax) * deltaKron(i));
        }
    }

    for (int n = 1; n <= nt; n++) {
        //vp = v + (deltaT / 2) * a
        for (int i = 0; i <= nx; ++i) {
            vp[i] = v[i][n - 1] + (deltaT / 2.0) * a[i][n - 1];
        }

        //u0 = u
        for (int i = 0; i <= nx; ++i) {
            u0[i][n] = u[i][n - 1];
        }

        //u = u0 + deltaT * vp
        for (int i = 0; i <= nx; i++) {
            u[i][n] = u0[i][n] + deltaT * vp[i];
        }

        //a
        for (int i = 1; i < nx; i++) {
            a[i][n] = ((u[i+1][n] - 2 * u[i][n] + u[i-1][n]) / (delta * delta)) - beta * ((u[i][n] - u[i][n-1]) / deltaT) + alfa * (cos((50.0 * n * deltaT) / tMax) * deltaKron(i));
        }

        //v = vp + (deltaT / 2) * a
        for (int i = 0; i <= nx; i++) {
            v[i][n] = vp[i] + (deltaT / 2.0) * a[i][n];
        }

        double eSkladowa = 0.0;
        for (int i = 1; i <= nx - 1; i++) {
            eSkladowa += pow(v[i][n], 2) + pow((u[i+1][n] - u[i-1][n]) / (2 * delta), 2);
        }
        e[n] = (delta / 4.0) * (pow((u[1][n] - u[0][n]) / delta, 2) + pow((u[nx][n] - u[nx-1][n]) / delta, 2)) + (delta / 2.0) * eSkladowa;

        std::cout << "n: " << n << " e: " << e[n] << std::endl;
    }

    std::vector<std::string> do_pliku_u;
    std::vector<std::string> do_pliku_e;

    for (int n = 0; n <= nt; n++) {
        for (int i = 0; i <= nx; i++) {
            do_pliku_u.push_back(std::to_string(i * delta) + " " + std::to_string(n * deltaT) + " " + std::to_string(u[i][n]));
        }
        do_pliku_u.push_back("");
        do_pliku_e.push_back(std::to_string(n * deltaT) + " " + std::to_string(e[n]));
    }

    saveToFile("U_" + std::to_string(alfa) + "_" + std::to_string(beta) + ".txt", do_pliku_u, do_pliku_u.size());
    saveToFile("E_" + std::to_string(alfa) + "_" + std::to_string(beta) + ".txt", do_pliku_e, do_pliku_e.size());
}

void zadanie() {
    oblicz(0, 0);
    oblicz(0, 0.1);
    oblicz(0, 1);
    oblicz(1, 1, false);
}

#endif
