import numpy as np
import matplotlib.pyplot as plt


files = ["zad01", "zad02", "zad03"]
names = ["Metoda Picarda", "Iteracja Newtona", "Niejawna RK2"]

for file in files:
    plt.figure()

    data1 = np.loadtxt(file + ".txt")

    t = data1[:, 0]
    u = data1[:, 1]
    z = data1[:, 2]

    plt.title(names[files.index(file)])

    plt.plot(t, u, 'b-', markersize=1, label='u(t)')
    plt.plot(t, z, 'r-', markersize=1, label='z(t)')

    plt.legend()

    plt.xlabel("t")
    plt.ylabel("u(t), z(t)")

    plt.savefig(file + ".png", bbox_inches='tight')