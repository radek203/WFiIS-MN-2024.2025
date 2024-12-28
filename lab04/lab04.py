import numpy as np
import matplotlib.pyplot as plt

zadanie = "01"
data1 = np.loadtxt("zad" + zadanie + "_0.600000.txt")
data2 = np.loadtxt("zad" + zadanie + "_1.000000.txt")

i1 = data1[:, 0][1:]
S1 = data1[:, 1][1:]

i2 = data2[:, 0][1:]
S2 = data2[:, 1][1:]

plt.figure()
plt.xscale('log')
plt.title("Relaksacja globalna")

plt.plot(i1, S1, 'b-', markersize=1, label='w = 0.6 iter: ' + str(len(data1) - 1))
plt.plot(i2, S2, 'r-', markersize=1, label='w = 1.0 iter: ' + str(len(data2) - 1))

plt.xlim(1, 100000)
plt.ylim(0, 5000)

plt.xlabel("nr iteracji")
plt.ylabel("S")

plt.legend()

plt.savefig("zad" + zadanie + "rg.png", bbox_inches='tight')





data1blad = np.loadtxt("zad" + zadanie + "_blad_0.600000.txt")
data2blad = np.loadtxt("zad" + zadanie + "_blad_1.000000.txt")

x1 = data1blad[:, 0][1:]
y1 = data1blad[:, 1][1:]
b1 = data1blad[:, 2][1:]

x2 = data2blad[:, 0][1:]
y2 = data2blad[:, 1][1:]
b2 = data2blad[:, 2][1:]

x1U = np.unique(x1)
y1U = np.unique(y1)
x2U = np.unique(x2)
y2U = np.unique(y2)

x1ind = np.searchsorted(x1U, x1)
y1ind = np.searchsorted(y1U, y1)
x2ind = np.searchsorted(x2U, x2)
y2ind = np.searchsorted(y2U, y2)

b1grid = np.zeros((len(y1U), len(x1U)))
b1grid[y1ind, x1ind] = b1
b2grid = np.zeros((len(y2U), len(x2U)))
b2grid[y2ind, x2ind] = b2

plt.figure(figsize=(10, 5))
plt.title("Relaksacja globalna w = 0.6")
plt.imshow(b1grid, extent=[x1U[0], x1U[-1], y1U[0], y1U[-1]])
plt.colorbar()
plt.xlabel("x")
plt.ylabel("y")
plt.savefig("zad" + zadanie + "blad_0.6.png", bbox_inches="tight")

plt.figure(figsize=(10, 5))
plt.title("Relaksacja globalna w = 1.0")
plt.imshow(b2grid, extent=[x2U[0], x2U[-1], y2U[0], y2U[-1]])
plt.colorbar()
plt.xlabel("x")
plt.ylabel("y")
plt.savefig("zad" + zadanie + "blad_1.0.png", bbox_inches="tight")







data1pot = np.loadtxt("zad" + zadanie + "_potencjal_0.600000.txt")
data2pot = np.loadtxt("zad" + zadanie + "_potencjal_1.000000.txt")

x1 = data1pot[:, 0][1:]
y1 = 10 - data1pot[:, 1][1:]
b1 = data1pot[:, 2][1:]

x2 = data2pot[:, 0][1:]
y2 = 10 - data2pot[:, 1][1:]
b2 = data2pot[:, 2][1:]

x1U = np.unique(x1)
y1U = np.unique(y1)
x2U = np.unique(x2)
y2U = np.unique(y2)

x1ind = np.searchsorted(x1U, x1)
y1ind = np.searchsorted(y1U, y1)
x2ind = np.searchsorted(x2U, x2)
y2ind = np.searchsorted(y2U, y2)

b1grid = np.zeros((len(y1U), len(x1U)))
b1grid[y1ind, x1ind] = b1
b2grid = np.zeros((len(y2U), len(x2U)))
b2grid[y2ind, x2ind] = b2

plt.figure(figsize=(10, 5))
plt.title("Relaksacja globalna w = 0.6")
plt.imshow(b1grid, extent=[x1U[0], x1U[-1], y1U[0], y1U[-1]])
plt.colorbar()
plt.xlabel("x")
plt.ylabel("y")
plt.savefig("zad" + zadanie + "pot_0.6.png", bbox_inches="tight")

plt.figure(figsize=(10, 5))
plt.title("Relaksacja globalna w = 1.0")
plt.imshow(b2grid, extent=[x2U[0], x2U[-1], y2U[0], y2U[-1]])
plt.colorbar()
plt.xlabel("x")
plt.ylabel("y")
plt.savefig("zad" + zadanie + "pot_1.0.png", bbox_inches="tight")









zadanie = "02"
data1 = np.loadtxt("zad" + zadanie + "_1.000000.txt")
data2 = np.loadtxt("zad" + zadanie + "_1.400000.txt")
data3 = np.loadtxt("zad" + zadanie + "_1.800000.txt")
data4 = np.loadtxt("zad" + zadanie + "_1.900000.txt")

i1 = data1[:, 0][1:]
S1 = data1[:, 1][1:]

i2 = data2[:, 0][1:]
S2 = data2[:, 1][1:]

i3 = data3[:, 0][1:]
S3 = data3[:, 1][1:]

i4 = data4[:, 0][1:]
S4 = data4[:, 1][1:]

plt.figure()
plt.xscale('log')
plt.title("Relaksacja lokalna")

plt.plot(i1, S1, 'b-', markersize=1, label='w = 1.0 iter: ' + str(len(data1) - 1))
plt.plot(i2, S2, 'r-', markersize=1, label='w = 1.4 iter: ' + str(len(data2) - 1))
plt.plot(i3, S3, 'g-', markersize=1, label='w = 1.8 iter: ' + str(len(data3) - 1))
plt.plot(i4, S4, 'y-', markersize=1, label='w = 1.9 iter: ' + str(len(data4) - 1))

plt.xlim(1, 100000)
plt.ylim(0, 3000)

plt.xlabel("nr iteracji")
plt.ylabel("S")

plt.legend()

plt.savefig("zad" + zadanie + "rl.png", bbox_inches='tight')