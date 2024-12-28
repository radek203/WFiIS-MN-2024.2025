import numpy as np
import matplotlib.pyplot as plt

zadania = ["01", "02"]

for zadanie in zadania:
    data1 = np.loadtxt("zad" + zadanie + "_M2.txt")
    data2 = np.loadtxt("zad" + zadanie + "_M5.txt")

    t1 = data1[:, 0]
    deltaT1 = data1[:, 1]
    x1 = data1[:, 2]
    v1 = data1[:, 3]

    t2 = data2[:, 0]
    deltaT2 = data2[:, 1]
    x2 = data2[:, 2]
    v2 = data2[:, 3]



    plt.figure()
    plt.title("v(t)")

    plt.plot(t1, v1, 'b-', markersize=1, label='tol=1e-2')
    plt.plot(t2, v2, 'r-', markersize=1, label='tol=1e-5')

    plt.legend()

    plt.savefig("zad" + zadanie + "vt.png", bbox_inches='tight')



    plt.figure()
    plt.title("x(t)")

    plt.plot(t1, x1, 'b-', markersize=1, label='tol=1e-2')
    plt.plot(t2, x2, 'r-', markersize=1, label='tol=1e-5')

    plt.legend()

    plt.savefig("zad" + zadanie + "xt.png", bbox_inches='tight')



    plt.figure()
    plt.title("deltaT(t)")

    plt.plot(t1, deltaT1, 'b-', markersize=1, label='tol=1e-2')
    plt.plot(t2, deltaT2, 'r-', markersize=1, label='tol=1e-5')

    plt.legend()

    plt.savefig("zad" + zadanie + "deltaTt.png", bbox_inches='tight')



    plt.figure()

    plt.title("v(x)")

    plt.plot(x1, v1, 'b-', markersize=1, label='tol=1e-2')
    plt.plot(x2, v2, 'r-', markersize=1, label='tol=1e-5')

    plt.legend()

    plt.savefig("zad" + zadanie + "vx.png", bbox_inches='tight')