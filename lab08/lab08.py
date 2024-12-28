import numpy as np
import matplotlib.pyplot as plt

data1 = np.loadtxt("vx.txt")
data2 = np.loadtxt("vy.txt")
data3 = np.loadtxt("c_0.000000.txt")
data4 = np.loadtxt("xsr_0.000000.txt")
data5 = np.loadtxt("c_0.100000.txt")
data6 = np.loadtxt("xsr_0.100000.txt")

titles = ["vx", "vy"]

i = 0
for data in [data1, data2]:
    x1 = data[:, 0]
    y1 = 0.9 - data[:, 1]
    b1 = data[:, 2]

    x1U = np.unique(x1)
    y1U = np.unique(y1)

    x1ind = np.searchsorted(x1U, x1)
    y1ind = np.searchsorted(y1U, y1)

    b1grid = np.zeros((len(y1U), len(x1U)))
    b1grid[y1ind, x1ind] = b1

    plt.figure(figsize=(8, 2))
    plt.title(titles[i])
    plt.imshow(b1grid, extent=[x1U[0], x1U[-1], y1U[0], y1U[-1]])
    plt.colorbar()
    plt.xlabel("x")
    plt.ylabel("y")
    plt.savefig("zad_" + str(i + 1) + ".png", bbox_inches="tight", dpi=100)

    i += 1


x1 = data3[:, 0]
y1 = data3[:, 1]
x2 = data5[:, 0]
y2 = data5[:, 1]
plt.figure()
plt.ylim(0.5, 1.05)
plt.title("c(tn)")

plt.plot(x1, y1, 'b-', markersize=1, label='D=0.0')
plt.plot(x2, y2, 'r-', markersize=1, label='D=0.1')

plt.legend()

plt.savefig("zad_c.png", bbox_inches='tight')

x1 = data4[:, 0]
y1 = data4[:, 1]
x2 = data6[:, 0]
y2 = data6[:, 1]
plt.figure()
plt.title("xsr(tn)")

plt.plot(x1, y1, 'b-', markersize=1, label='D=0.0')
plt.plot(x2, y2, 'r-', markersize=1, label='D=0.1')

plt.legend()

plt.savefig("zad_xsr.png", bbox_inches='tight')