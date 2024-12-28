import numpy as np
import matplotlib.pyplot as plt

data1 = np.loadtxt("zad_z2a_V.txt")
data2 = np.loadtxt("zad_z2b_V.txt")
data3 = np.loadtxt("zad_z2c_V.txt")
data4 = np.loadtxt("zad_z3a_V.txt")
data5 = np.loadtxt("zad_z3b_V.txt")
data6 = np.loadtxt("zad_z3c_V.txt")

titles = ["nx=ny=50, e1=1, e2=1", "nx=ny=100", "nx=ny=200", "nx=ny=100, e1=1, e2=1", "e1=1, e2=2", "e1=1, e2=10"]
sizes = [(5, 5), (10, 10), (20, 20), (10, 10), (10, 10), (10, 10)]

i = 0
for data in [data1, data2, data3, data4, data5, data6]:
    x1 = data[:, 0]
    y1 = data[:, 1]
    b1 = data[:, 2]

    x1U = np.unique(x1)
    y1U = np.unique(y1)

    x1ind = np.searchsorted(x1U, x1)
    y1ind = np.searchsorted(y1U, y1)

    b1grid = np.zeros((len(y1U), len(x1U)))
    b1grid[y1ind, x1ind] = b1

    plt.figure(figsize=sizes[i])
    plt.title(titles[i])
    plt.imshow(b1grid, extent=[x1U[0], x1U[-1], y1U[0], y1U[-1]])
    plt.colorbar()
    plt.xlabel("x")
    plt.ylabel("y")
    plt.savefig("zad_" + str(i + 1) + ".png", bbox_inches="tight")

    i += 1
