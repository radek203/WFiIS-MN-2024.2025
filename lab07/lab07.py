import numpy as np
import matplotlib.pyplot as plt

data1 = np.loadtxt("zad_-1000.000000.txt")
data2 = np.loadtxt("zad_-4000.000000.txt")

titles = ["Q=-1000, u(x,y)", "Q=-1000, v(x,y)", "Q=-4000, u(x,y)", "Q=-4000, v(x,y)"]
names = ["zad_1u", "zad_1v", "zad_2u", "zad_2v"]

i = 0
for data in [data1, data2]:
    x1 = data[:, 0]
    y1 = 0.9 - data[:, 1]
    b1 = data[:, 4]
    b2 = data[:, 5]

    b1 = np.nan_to_num(b1, nan=0)
    b2 = np.nan_to_num(b2, nan=0)

    x1U = np.unique(x1)
    y1U = np.unique(y1)

    x1ind = np.searchsorted(x1U, x1)
    y1ind = np.searchsorted(y1U, y1)

    b1grid = np.zeros((len(y1U), len(x1U)))
    b1grid[y1ind, x1ind] = b1

    b2grid = np.zeros((len(y1U), len(x1U)))
    b2grid[y1ind, x1ind] = b2

    plt.figure(figsize=(12, 6))
    plt.title(titles[i])
    plt.imshow(b1grid, extent=[x1U[0], x1U[-1], y1U[0], y1U[-1]])
    plt.colorbar()
    plt.xlabel("x")
    plt.ylabel("y")
    plt.savefig(names[i] + ".png", bbox_inches="tight", dpi=100)

    i += 1

    plt.figure(figsize=(12, 6))
    plt.title(titles[i])
    plt.imshow(b2grid, extent=[x1U[0], x1U[-1], y1U[0], y1U[-1]])
    plt.colorbar()
    plt.xlabel("x")
    plt.ylabel("y")
    plt.savefig(names[i] + ".png", bbox_inches="tight", dpi=100)

    i += 1
