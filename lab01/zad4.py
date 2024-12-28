import matplotlib.pyplot as plt
import numpy as np

def zad4():
    plt.figure()

    file = "zad04Q_0.500000.txt"
    data050 = np.loadtxt(file)
    file = "zad04Q_0.800000.txt"
    data080 = np.loadtxt(file)
    file = "zad04Q_1.000000.txt"
    data100 = np.loadtxt(file)
    file = "zad04Q_1.200000.txt"
    data120 = np.loadtxt(file)

    x050 = data050[:, 0]
    y050 = data050[:, 1]

    x080 = data080[:, 0]
    y080 = data080[:, 1]

    x100 = data100[:, 0]
    y100 = data100[:, 1]

    x120 = data120[:, 0]
    y120 = data120[:, 1]

    plt.title("Z4 - Metoda RK4, Q(t)")

    plt.plot(x050, y050, 'b-', markersize=2, label='0.5 w0')
    plt.plot(x080, y080, 'r-', markersize=2, label='0.8 w0')
    plt.plot(x100, y100, 'g-', markersize=2, label='1.0 w0')
    plt.plot(x120, y120, 'y-', markersize=2, label='1.2 w0')

    plt.legend()

    plt.xlabel('t')
    plt.ylabel('Q(t)')

    plt.savefig("zad4Q.png",bbox_inches='tight')

    plt.figure()

    file = "zad04I_0.500000.txt"
    data050 = np.loadtxt(file)
    file = "zad04I_0.800000.txt"
    data080 = np.loadtxt(file)
    file = "zad04I_1.000000.txt"
    data100 = np.loadtxt(file)
    file = "zad04I_1.200000.txt"
    data120 = np.loadtxt(file)

    x050 = data050[:, 0]
    y050 = data050[:, 1]

    x080 = data080[:, 0]
    y080 = data080[:, 1]

    x100 = data100[:, 0]
    y100 = data100[:, 1]

    x120 = data120[:, 0]
    y120 = data120[:, 1]

    plt.title("Z4 - Metoda RK4, I(t)")

    plt.plot(x050, y050, 'b-', markersize=2, label='0.5 w0')
    plt.plot(x080, y080, 'r-', markersize=2, label='0.8 w0')
    plt.plot(x100, y100, 'g-', markersize=2, label='1.0 w0')
    plt.plot(x120, y120, 'y-', markersize=2, label='1.2 w0')

    plt.legend()

    plt.xlabel('t')
    plt.ylabel('I(t)')

    plt.savefig("zad4I.png",bbox_inches='tight')
