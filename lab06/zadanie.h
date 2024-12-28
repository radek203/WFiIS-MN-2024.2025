#ifndef ZADANIE_H
#define ZADANIE_H
#include "../utils.h"
#include "const_data.h"
#include "mgmres.h"

void zad_fun(std::string zname, std::function<double(double, double)> ro_function) {
    auto *a = (double*) calloc(5 * N, sizeof(double));
    auto *ja = (int*) calloc(5 * N, sizeof(int));
    auto *ia = (int*) calloc((N + 1), sizeof(int));

    for (int i = 0; i < N + 1; i++) {
        ia[i] = -1;
    }

    auto *b = (double*) calloc(N, sizeof(double));
    auto *V = (double*) calloc(N, sizeof(double));

    std::vector<std::string> do_pliku_b = {};
    std::vector<std::string> do_pliku_a = {};
    std::vector<std::string> do_pliku_V = {};

    int k = -1;

    for (int l = 0; l < N; l++) {
        int j = floor(l / (nx + 1));
        int i = l - j * (nx + 1);

        int brzeg = 0;
        double vb = 0.0;

        if (i == 0) {
            brzeg = 1;
            vb=V1;
        }

        if (j == ny) {
            brzeg = 1;
            vb=V2;
        }

        if (i == nx) {
            brzeg = 1;
            vb=V3;
        }

        if (j == 0) {
            brzeg = 1;
            vb=V4;
        }

        b[l] = ro_function(i, j);

        if (brzeg == 1) {
            b[l] = vb;
        }

        ia[l] = -1;

        if (l - nx - 1 >= 0 && brzeg == 0) {
            k++;
            if (ia[l] < 0) {
                ia[l] = k;
            }
            a[k] = a1(i);
            ja[k] = l - nx - 1;
        }

        if (l - 1 >= 0 && brzeg == 0) {
            k++;
            if (ia[l] < 0) {
                ia[l] = k;
            }
            a[k] = a2(i);
            ja[k] = l - 1;
        }

        k++;
        if (ia[l] < 0) {
            ia[l] = k;
        }
        if (brzeg == 0) {
            a[k] = a3(i);
        } else {
            a[k] = 1;
        }
        ja[k] = l;

        if (l<N && brzeg == 0) {
            k++;
            a[k] = a4(i);
            ja[k] = l + 1;
        }

        if (l < N - nx - 1 && brzeg == 0) {
            k++;
            a[k] = a5(i);
            ja[k] = l + nx + 1;
        }

        do_pliku_b.push_back(std::to_string(l) + " " + std::to_string(i) + " " + std::to_string(j) + " " + std::to_string(b[l]));
    }

    int nz_num = k + 1;
    ia[N] = nz_num;

    for (int i = 0; i < 5 * N; i++) {
        do_pliku_a.push_back(std::to_string(i) + " " + std::to_string(a[i]));
    }

    pmgmres_ilu_cr(N, nz_num, ia, ja, a, V, b, 500, 500, 1e-8, 1e-8);

    for (int l = 0; l < N; l++) {
        int j = floor(l / (nx + 1));
        int i = l - j * (nx + 1);

        do_pliku_V.push_back(std::to_string(i) + " " + std::to_string(j) + " " + std::to_string(V[l]));
    }

    saveToFile("zad_" + zname + "_b.txt", do_pliku_b, do_pliku_b.size());
    saveToFile("zad_" + zname + "_a.txt", do_pliku_a, do_pliku_a.size());
    saveToFile("zad_" + zname + "_V.txt", do_pliku_V, do_pliku_V.size());

    free(a);
    free(ja);
    free(ia);
    free(b);
    free(V);
}

void zadanie() {
    setData(4, 4, 1, 1, 10, -10, 10, -10);
    zad_fun("z1", roZ3);

    setData(50, 50, 1, 1, 10, -10, 10, -10);
    zad_fun("z2a", roZ3);

    setData(100, 100, 1, 1, 10, -10, 10, -10);
    zad_fun("z2b", roZ3);

    setData(200, 200, 1, 1, 10, -10, 10, -10);
    zad_fun("z2c", roZ3);

    setData(100, 100, 1, 1, 0, 0, 0, 0);
    zad_fun("z3a", roZ6);

    setData(100, 100, 1, 2, 0, 0, 0, 0);
    zad_fun("z3b", roZ6);

    setData(100, 100, 1, 10, 0, 0, 0, 0);
    zad_fun("z3c", roZ6);
}

#endif
