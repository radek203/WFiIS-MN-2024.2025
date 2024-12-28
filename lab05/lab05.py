import numpy as np
import matplotlib.pyplot as plt

data1 = np.loadtxt("zad_pot_1.txt")
data2 = np.loadtxt("zad_pot_2.txt")
data3 = np.loadtxt("zad_pot_4.txt")
data4 = np.loadtxt("zad_pot_8.txt")
data5 = np.loadtxt("zad_pot_16.txt")

i = 1
for data in [data1, data2, data3, data4, data5]:
    x1 = data[:, 0]
    y1 = 25.6 - data[:, 1]
    b1 = data[:, 2]

    x1U = np.unique(x1)
    y1U = np.unique(y1)

    x1ind = np.searchsorted(x1U, x1)
    y1ind = np.searchsorted(y1U, y1)

    b1grid = np.zeros((len(y1U), len(x1U)))
    b1grid[y1ind, x1ind] = b1

    plt.figure(figsize=(25.6, 25.6))
    plt.title("k=" + str(i))
    plt.imshow(b1grid, extent=[x1U[0], x1U[-1], y1U[0], y1U[-1]])
    plt.colorbar()
    plt.xlabel("x")
    plt.ylabel("y")
    plt.savefig("zad_pot_" + str(i) + ".png", bbox_inches="tight")
    i *= 2


data = np.loadtxt("zad_iter.txt")

i = data[:, 0]
S = data[:, 1]
k = data[:, 2]

plt.figure()
plt.title("S(it)")

unique_k = np.unique(k)
for k_val in unique_k:
    mask = k == k_val
    plt.plot(i[mask], S[mask], '-', markersize=1, label='k = ' + str(k_val) + ' iter: ' + str(i[mask][-1]))

plt.xlim(0, 600)
plt.ylim(4.2, 5.6)

plt.xlabel("it")
plt.ylabel("S")

plt.legend()

plt.savefig("zad_iter.png", bbox_inches='tight')