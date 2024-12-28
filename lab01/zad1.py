import numpy as np
import matplotlib.pyplot as plt

def zad1():
    plt.figure()

    file = "zad01_0.010000.txt"
    data001 = np.loadtxt(file)
    file = "zad01_0.100000.txt"
    data010 = np.loadtxt(file)
    file = "zad01_1.000000.txt"
    data100 = np.loadtxt(file)

    file = "zad01_blad_0.010000.txt"
    data001_blad = np.loadtxt(file)
    file = "zad01_blad_0.100000.txt"
    data010_blad = np.loadtxt(file)
    file = "zad01_blad_1.000000.txt"
    data100_blad = np.loadtxt(file)

    x001 = data001[:, 0]
    y001blad = data001_blad
    y001 = data001[:, 1]

    x010 = data010[:, 0]
    y010blad = data010_blad[0:51]
    y010 = data010[:, 1]

    x100 = data100[:, 0]
    y100blad = data100_blad[0:6]
    y100 = data100[:, 1]

    y_an = data001[:, 2]

    plt.title("Z1 - Metoda Eulera - rozwiazanie")

    plt.plot(x001, y001, 'bo', markersize=5, label='dt=0.01')
    plt.plot(x010, y010, 'ro', markersize=5, label='dt=0.10')
    plt.plot(x100, y100, 'go', markersize=5, label='dt=1.00')
    plt.plot(x001, y_an, 'k-', lw=3, label='analityczne')

    plt.legend()

    plt.xlabel('t')
    plt.ylabel('y(t)')

    plt.savefig("zad1.png",bbox_inches='tight')

    plt.figure()

    plt.title("Z1 - Metoda Eulera - blad globalny")

    plt.plot(x001, y001blad, 'b-', markersize=5, label='dt=0.01')
    plt.plot(x010, y010blad, 'r-', markersize=5, label='dt=0.10')
    plt.plot(x100, y100blad, 'g-', markersize=5, label='dt=1.00')

    plt.legend()

    plt.xlabel('t')
    plt.ylabel('y_num(t)-y_dok(t)')

    plt.savefig("zad1blad.png",bbox_inches='tight')
