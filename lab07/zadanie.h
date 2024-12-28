#ifndef ZADANIE_H
#define ZADANIE_H
#include "../utils.h"
#include "const_data.h"

void oblicz() {
    std::vector<std::vector<double>> S(nx + 1, std::vector<double>(ny + 1, 0.0));
    std::vector<std::vector<double>> W(nx + 1, std::vector<double>(ny + 1, 0.0));

    std::vector<std::vector<double>> u(nx + 1, std::vector<double>(ny + 1, 0.0));
    std::vector<std::vector<double>> v(nx + 1, std::vector<double>(ny + 1, 0.0));

    //Brzeg A
    for (int j = j_1; j <= ny; j++) {
        S[0][j] = WBS_A(j);
    }
    //Brzeg C
    for (int j = 0; j <= ny; j++) {
        S[nx][j] = WBS_C(j);
    }
    //Brzeg B
    for (int i = 1; i <= nx - 1; i++) {
        S[i][ny] = S[0][ny];
    }
    //Brzeg D
    for (int i = i_1; i <= nx - 1; i++) {
        S[i][0] = S[0][j_1];
    }
    //Brzeg E
    for (int j = 1; j <= j_1; j++) {
        S[i_1][j] = S[0][j_1];
    }
    //Brzeg F
    for (int i = 1; i <= i_1; i++) {
        S[i][j_1] = S[0][j_1];
    }

    for (int it = 1; it <= IT_MAX; it++) {
        int omega = it < 2000 ? 0 : 1;

        for (int i = 1; i <= nx - 1; i++) {
            for (int j = 1; j <= ny - 1; j++) {
                if (!is_edge(i, j)) {
                    S[i][j] = 0.25 * (S[i+1][j] + S[i-1][j] + S[i][j+1] + S[i][j-1] - delta * delta * W[i][j]);
                    W[i][j] = 0.25 * (W[i+1][j] + W[i-1][j] + W[i][j+1] + W[i][j-1]) - omega * (ro / (16.0 * mi)) * ((S[i][j+1] - S[i][j-1]) * (W[i+1][j] - W[i-1][j]) - (S[i+1][j] - S[i-1][j]) * (W[i][j+1] - W[i][j-1]));

                    u[i][j] = (S[i][j + 1] - S[i][j - 1]) / (2.0 * delta);
                    v[i][j] = -(S[i + 1][j] - S[i - 1][j]) / (2.0 * delta);
                }
            }
        }

        //Brzeg A
        for (int j = j_1; j <= ny; j++) {
            W[0][j] = WBW_A(j);
        }
        //Brzeg C
        for (int j = 0; j <= ny; j++) {
            W[nx][j] = WBW_C(j);
        }
        //Brzeg B
        for (int i = 1; i <= nx - 1; i++) {
            W[i][ny] = (2 / (delta * delta)) * (S[i][ny-1] - S[i][ny]);
        }
        //Brzeg D
        for (int i = i_1 + 1; i <= nx - 1; i++) {
            W[i][0] = (2 / (delta * delta)) * (S[i][1] - S[i][0]);
        }
        //Brzeg E
        for (int j = 1; j <= j_1 - 1; j++) {
            W[i_1][j] = (2 / (delta * delta)) * (S[i_1 + 1][j] - S[i_1][j]);
        }
        //Brzeg F
        for (int i = 1; i <= i_1; i++) {
            W[i][j_1] = (2 / (delta * delta)) * (S[i][j_1+1] - S[i][j_1]);
        }
        //Wierzcholek E/F
        W[i_1][j_1] = (W[i_1 - 1][j_1] + W[i_1][j_1 - 1]) / 2.0;

        double gamma = 0;
        for (int i = 1; i <= nx - 1; i++) {
            gamma += S[i+1][j_2] + S[i-1][j_2] + S[i][j_2 + 1] + S[i][j_2 - 1] - 4 * S[i][j_2] - delta * delta * W[i][j_2];
        }

        std::cout << "IT: " << it << " Gamma: " << gamma << std::endl;
    }

    std::cout << std::setprecision(4);
    std::vector<std::string> do_pliku;
    for (int j = 0; j <= ny; j++) {
        for (int i = 0; i <= nx; i++) {
            do_pliku.push_back(std::to_string(i * delta) + " " + std::to_string(j * delta) + " " + std::to_string(S[i][j]) + " " + std::to_string(W[i][j]) + " " + std::to_string(u[i][j]) + " " + std::to_string(v[i][j]));
        }
        do_pliku.push_back("");
    }
    saveToFile("zad_" + std::to_string(Qwe) + ".txt", do_pliku, do_pliku.size());
}

void zadanie() {
    std::cout << "Qwe = -1000 ..." << std::endl;
    Qwe = -1000;
    oblicz();
    std::cout << "Qwe = -4000 ..." << std::endl;
    Qwe = -4000;
    oblicz();
    std::cout << "Qwe = 4000 ..." << std::endl;
    Qwe = 4000;
    oblicz();
}

#endif
