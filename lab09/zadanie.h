#ifndef ZADANIE_H
#define ZADANIE_H

#include "utilsGsl.h"
#include "const_data.h"

void zadanie() {

    std::vector<std::vector<double>> A(N, std::vector<double>(N, 0.0));
    std::vector<std::vector<double>> B(N, std::vector<double>(N, 0.0));
    std::vector<double> C(N, 0.0);
    std::vector<double> T(N, 0.0);

    //Wnetrze obszaru
    for (int i = 1; i <= nx-1; i++) {
        for (int j = 1; j <=ny-1; j++) {
            int l = calcL(i, j);
            A[l][l-nx-1] = A[l][l-1] = A[l][l+1] = A[l][l+nx+1] = deltaT / (2 * delta * delta);
            A[l][l] = -(2 * deltaT / (delta * delta)) - 1;
            B[l][l-nx-1] = B[l][l-1] = B[l][l+1] = B[l][l+nx+1] = -deltaT / (2 * delta * delta);
            B[l][l] = (2 * deltaT / (delta * delta)) - 1;
        }
    }

    //WB Dirichleta (lewy i prawy brzeg)
    for (int i = 0; i <= nx; i += nx) {
        for (int j = 0; j <= ny; j++) {
            int l = calcL(i, j);
            A[l][l] = 1;
            B[l][l] = 1;
            C[l] = 0;
        }
    }

    //WB von Neumanna (gorny brzeg)
    int j = ny;
    for (int i = 1; i <= nx-1; i++) {
        int l = calcL(i, j);
        A[l][l-nx-1] = -1 / (kB * delta);
        A[l][l] = 1 + 1 / (kB * delta);
        C[l] = TB;
        for (j = 0; j < N; j++) {
            B[l][j] = 0.0;
        }
        j = ny;
    }
    //WB von Neumanna (dolny brzeg)
    j = 0;
    for (int i = 1; i <= nx-1; i++) {
        int l = calcL(i, j);
        A[l][l] = 1 + 1 / (kD * delta);
        A[l][l+nx+1] = -1 / (kD * delta);
        C[l] = TD;
        for (j = 0; j < N; j++) {
            B[l][j] = 0.0;
        }
        j = 0;
    }
    //Warunki poczatkowe
    std::vector<double> T0(N, 0.0);
    int i = 0;
    for (int j = 0; j <= ny; j++) {
        int l = calcL(i, j);
        T0[l] = TA;
    }
    i = nx;
    for (int j = 0; j <= ny; j++) {
        int l = calcL(i, j);
        T0[l] = TC;
    }

    gsl_matrix *a_mat = gsl_matrix_calloc(N,N);
    gsl_matrix *b_mat = gsl_matrix_calloc(N, N);
    gsl_vector *c_vec = gsl_vector_calloc(N);
    gsl_vector *t_vec = gsl_vector_calloc(N);

    gsl_vector *t_vec_copy = gsl_vector_calloc(N);

    arrayToMatrixGsl<N,N>(A, a_mat);
    arrayToMatrixGsl<N,N>(B, b_mat);
    arrayToVectorGsl<N>(C, c_vec);
    arrayToVectorGsl<N>(T0, t_vec);

    gsl_vector_memcpy(t_vec_copy, t_vec);

    int s;
    gsl_permutation *p_vec = gsl_permutation_calloc(N);
    gsl_linalg_LU_decomp(a_mat, p_vec, &s);

    gsl_vector *d_vec = gsl_vector_alloc(N);

    std::vector<int> iters = {100, 200, 500, 1000, 2000};

    std::vector<std::string> do_pliku;
    std::vector<std::string> do_pliku_d;
    for (int it = 0; it <= IT_MAX; it++) {
        gsl_vector_memcpy(d_vec, c_vec);
        gsl_blas_dgemv(CblasNoTrans, 1.0, b_mat, t_vec, 1.0, d_vec); // d = B*T + c
        gsl_linalg_LU_solve(a_mat, p_vec, d_vec, t_vec);

        if (std::ranges::find(iters, it) != iters.end()) {
            std::cout << "Iteracja: " << it << std::endl;

            for (j = 0; j <= ny; j++) {
                for (i = 0; i <= nx; i++) {
                    int l = calcL(i, j);
                    do_pliku.push_back(std::to_string(it) + " " + std::to_string(i * delta) + " " + std::to_string(j * delta) + " " + to_string_with_precision(gsl_vector_get(t_vec, l)));
                    do_pliku_d.push_back(std::to_string(it) + " " + std::to_string(i * delta) + " " + std::to_string(j * delta) + " " + to_string_with_precision(gsl_vector_get(t_vec, l) - gsl_vector_get(t_vec_copy, l)));
                }
                do_pliku.push_back("");
                do_pliku_d.push_back("");
            }
        }

        gsl_vector_memcpy(t_vec_copy, t_vec);
    }

    saveToFile("T.txt", do_pliku, do_pliku.size());
    saveToFile("dT.txt", do_pliku_d, do_pliku_d.size());

    gsl_permutation_free(p_vec);
    gsl_matrix_free(a_mat);
    gsl_matrix_free(b_mat);
    gsl_vector_free(c_vec);
    gsl_vector_free(t_vec);
    gsl_vector_free(d_vec);
}

#endif
