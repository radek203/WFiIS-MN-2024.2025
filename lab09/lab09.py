import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("T.txt")
data2 = np.loadtxt("dT.txt")

iters = [100, 200, 500, 1000, 2000]

for i, iter_s in enumerate(iters):
    filtered_data = data[data[:, 0] == iter_s]

    if filtered_data.size == 0:
        continue

    x1 = filtered_data[:, 1]
    y1 = filtered_data[:, 2]
    b1 = filtered_data[:, 3]

    x1U = np.unique(x1)
    y1U = np.unique(y1)

    x1ind = np.searchsorted(x1U, x1)
    y1ind = np.searchsorted(y1U, y1)

    b1grid = np.zeros((len(y1U), len(x1U)))
    b1grid[y1ind, x1ind] = b1

    #plt.figure(figsize=(40, 40))
    plt.title(f"Iteration = {iter_s}")
    plt.imshow(b1grid, extent=[x1U[0], x1U[-1], y1U[0], y1U[-1]], origin='lower', aspect='auto')
    plt.colorbar(label="T")
    plt.xlabel("x")
    plt.ylabel("y")
    plt.savefig(f"zad_iter_{iter_s}.png", bbox_inches="tight")
    plt.close()

for i, iter_s in enumerate(iters):
    filtered_data = data2[data2[:, 0] == iter_s]

    if filtered_data.size == 0:
        continue

    x1 = filtered_data[:, 1]
    y1 = filtered_data[:, 2]
    b1 = filtered_data[:, 3]

    x1U = np.unique(x1)
    y1U = np.unique(y1)

    x1ind = np.searchsorted(x1U, x1)
    y1ind = np.searchsorted(y1U, y1)

    b1grid = np.zeros((len(y1U), len(x1U)))
    b1grid[y1ind, x1ind] = b1

    #plt.figure(figsize=(40, 40))
    plt.title(f"Iteration = {iter_s}")
    plt.imshow(b1grid, extent=[x1U[0], x1U[-1], y1U[0], y1U[-1]], origin='lower', aspect='auto')
    plt.colorbar(label="T")
    plt.xlabel("x")
    plt.ylabel("y")
    plt.savefig(f"zad_iter_d_{iter_s}.png", bbox_inches="tight")
    plt.close()
