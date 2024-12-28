#ifndef ZADANIE_H
#define ZADANIE_H
#include <thread>

#include "../utils.h"
#include "const_data.h"

void oblicz(double deltaT, double D, const std::vector<std::vector<double>> &vx, const std::vector<std::vector<double>> &vy) {
    std::vector<std::vector<double>> u0(nx + 1, std::vector<double>(ny + 1, 0.0));
    std::vector<std::vector<double>> u1(nx + 1, std::vector<double>(ny + 1, 0.0));

    for (int i = 0; i <= nx; i++) {
        for (int j = 0; j <= ny; j++) {
            u0[i][j] = u(i * delta, j * delta);
        }
    }

    std::vector<std::string> do_pliku_c;
    std::vector<std::string> do_pliku_xsr;
    for (int it = 1; it <= IT_MAX; it++) {
        //u1 = u0
        for (int i = 0; i <= nx; i++) {
            for (int j = 0; j <= ny; j++) {
                u1[i][j] = u0[i][j];
            }
        }

        for (int k = 1; k <= 20; k++) {
            for (int i = 0; i <= nx; i++) {
                for (int j = 1; j <= ny-1; j++) {
                    if (is_zastawka(i, j)) {
                        continue;
                    } else {
                        if (i == 0) {
                            u1[i][j] = (1 / (1 + (2 * D * deltaT) / (delta * delta))) * (u0[i][j] - (deltaT / 2) * vx[i][j] * (((u0[i+1][j] - u0[nx][j]) / (2 * delta)) + ((u1[i+1][j] - u1[nx][j]) / (2 * delta)))
                            - (deltaT / 2) * vy[i][j] * (((u0[i][j+1] - u0[i][j-1]) / (2 * delta)) + ((u1[i][j+1] - u1[i][j-1]) / (2 * delta)))
                            + (deltaT / 2) * D * ((u0[i+1][j] + u0[nx][j] + u0[i][j+1] + u0[i][j-1] - 4 * u0[i][j]) / (delta * delta)
                            + ((u1[i+1][j] + u1[nx][j] + u1[i][j+1] + u1[i][j-1]) / (delta * delta))));
                        } else if (i == nx) {
                            u1[i][j] = (1 / (1 + (2 * D * deltaT) / (delta * delta))) * (u0[i][j] - (deltaT / 2) * vx[i][j] * (((u0[0][j] - u0[i-1][j]) / (2 * delta)) + ((u1[0][j] - u1[i-1][j]) / (2 * delta)))
                            - (deltaT / 2) * vy[i][j] * (((u0[i][j+1] - u0[i][j-1]) / (2 * delta)) + ((u1[i][j+1] - u1[i][j-1]) / (2 * delta)))
                            + (deltaT / 2) * D * ((u0[0][j] + u0[i-1][j] + u0[i][j+1] + u0[i][j-1] - 4 * u0[i][j]) / (delta * delta)
                            + ((u1[0][j] + u1[i-1][j] + u1[i][j+1] + u1[i][j-1]) / (delta * delta))));
                        } else {
                            u1[i][j] = (1 / (1 + (2 * D * deltaT) / (delta * delta))) * (u0[i][j] - (deltaT / 2) * vx[i][j] * (((u0[i+1][j] - u0[i-1][j]) / (2 * delta)) + ((u1[i+1][j] - u1[i-1][j]) / (2 * delta)))
                            - (deltaT / 2) * vy[i][j] * (((u0[i][j+1] - u0[i][j-1]) / (2 * delta)) + ((u1[i][j+1] - u1[i][j-1]) / (2 * delta)))
                            + (deltaT / 2) * D * ((u0[i+1][j] + u0[i-1][j] + u0[i][j+1] + u0[i][j-1] - 4 * u0[i][j]) / (delta * delta)
                            + ((u1[i+1][j] + u1[i-1][j] + u1[i][j+1] + u1[i][j-1]) / (delta * delta))));
                        }
                    }
                }
            }
        }

        //u0 = u1
        for (int i = 0; i <= nx; i++) {
            for (int j = 0; j <= ny; j++) {
                u0[i][j] = u1[i][j];
            }
        }

        double c = 0.0;
        for (int i = 0; i <= nx; i++) {
            for (int j = 0; j <= ny; j++) {
                c += u1[i][j] * delta * delta;
            }
        }

        double xsr = 0.0;
        for (int i = 0; i <= nx; i++) {
            for (int j = 0; j <= ny; j++) {
                xsr += i * delta * u1[i][j] * delta * delta;
            }
        }

        double tn = it * deltaT;
        do_pliku_c.push_back(std::to_string(tn) + " " + std::to_string(c));
        do_pliku_xsr.push_back(std::to_string(tn) + " " + std::to_string(xsr));
        if (it % 200 == 0) {
            std::cout << "Iteracja: " << it << " D: " << D << std::endl;
            std::vector<std::string> do_pliku_u;
            for (int j = 0; j <= ny; j++) {
                for (int i = 0; i <= nx; i++) {
                    do_pliku_u.push_back(std::to_string(i * delta) + " " + std::to_string(j * delta) + " " + std::to_string(u1[i][j]));
                }
                do_pliku_u.push_back("");
            }
            saveToFile("zad_it_" + std::to_string(D) + "=" + std::to_string(it / 200) + ".txt", do_pliku_u, do_pliku_u.size());
        }
    }

    saveToFile("c_" + std::to_string(D) + ".txt", do_pliku_c, do_pliku_c.size());
    saveToFile("xsr_" + std::to_string(D) + ".txt", do_pliku_xsr, do_pliku_xsr.size());
}

void zadanie() {
    std::ifstream fileA;
    fileA.open("psi.dat");

    if (!fileA) {
        std::cerr << "Failed to open file!" << std::endl;
        return;
    }

    std::vector<std::vector<double>> S(nx + 1, std::vector<double>(ny + 1, 0.0));

    for (int i = 0; i <= nx; i++) {
        for (int j = 0; j <= ny; j++) {
            int temp = 0;
            fileA >> temp;
            fileA >> temp;
            double value = 0.0;
            fileA >> value;
            S[i][j] = value;
            //std::cout << i << " " << j << " " << S[i][j] << std::endl;
        }
    }

    fileA.close();

    std::vector<std::vector<double>> vx(nx + 1, std::vector<double>(ny + 1, 0.0));
    std::vector<std::vector<double>> vy(nx + 1, std::vector<double>(ny + 1, 0.0));

    for (int i = 1; i <= nx - 1; i++) {
        for (int j = 1; j <= ny - 1; j++) {
            vx[i][j] = (S[i][j + 1] - S[i][j - 1]) / (2 * delta);
            vy[i][j] = - (S[i + 1][j] - S[i - 1][j]) / (2 * delta);
        }
    }

    //Na zastawce
    for (int i = i_1; i <= i_2; i++) {
        for (int j = 0; j <= j_1; j++) {
            vx[i][j] = vy[i][j] = 0;
        }
    }

    //Na dolnym i gornym brzegu
    for (int i = 1; i <= nx - 1; i++) {
        vx[i][0] = vy[i][ny] = 0;
    }

    //Na lewym i prawym brzegu
    for (int j = 0; j <= ny; j++) {
        vx[0][j] = vx[1][j];
    }
    for (int j = 0; j <= ny; j++) {
        vx[nx][j] = vx[nx-1][j];
    }

    double vmax = 0.0;
    for (int i = 0; i <= nx; i++) {
        for (int j = 0; j <= ny; j++) {
            double v = sqrt(vx[i][j] * vx[i][j] + vy[i][j] * vy[i][j]);
            if (v > vmax) {
                vmax = v;
            }
        }
    }

    double deltaT = delta / (4 * vmax);

    std::vector<std::string> do_pliku_vx;
    std::vector<std::string> do_pliku_vy;

    for (int i = 0; i <= nx; i++) {
        for (int j = 0; j <= ny; j++) {
            do_pliku_vx.push_back(std::to_string(i * delta) + " " + std::to_string(j * delta) + " " + std::to_string(vx[i][j]));
            do_pliku_vy.push_back(std::to_string(i * delta) + " " + std::to_string(j * delta) + " " + std::to_string(vy[i][j]));
        }
    }

    saveToFile("vx.txt", do_pliku_vx, do_pliku_vx.size());
    saveToFile("vy.txt", do_pliku_vy, do_pliku_vy.size());

    std::thread t1(oblicz, deltaT, 0.0, std::ref(vx), std::ref(vy));
    std::thread t2(oblicz, deltaT, 0.1, std::ref(vx), std::ref(vy));

    t1.join();
    t2.join();
}

#endif
