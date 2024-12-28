import numpy as np
import matplotlib.pyplot as plt

data1 = np.loadtxt("E_0.000000_0.000000.txt")
data2 = np.loadtxt("E_0.000000_0.100000.txt")
data3 = np.loadtxt("E_0.000000_1.000000.txt")
data4 = np.loadtxt("E_1.000000_1.000000.txt")


x11 = data1[:, 0]
y11 = data1[:, 1]
x12 = data2[:, 0]
y12 = data2[:, 1]
x13 = data3[:, 0]
y13 = data3[:, 1]


plt.figure()
plt.ylim(0, 0.9)
plt.xlim(0, 50)
plt.title("E(t)")

plt.plot(x11, y11, 'r-', markersize=1, label='B=0.0, L=0.0')
plt.plot(x12, y12, 'b-', markersize=1, label='B=0.1, L=0.0')
plt.plot(x13, y13, 'g-', markersize=1, label='B=1.0, L=0.0')

plt.legend()

plt.savefig("E1.png", bbox_inches='tight')

x14 = data4[:, 0]
y14 = data4[:, 1]

plt.figure()
#plt.ylim(0, 0.0035)
plt.xlim(0, 50)
plt.title("E(t)")

plt.plot(x14, y14, 'g-', markersize=1, label='B=1.0, L=1.0')

plt.legend()

plt.savefig("E2.png", bbox_inches='tight')

data1 = np.loadtxt("U_0.000000_0.000000.txt")
data2 = np.loadtxt("U_0.000000_0.100000.txt")
data3 = np.loadtxt("U_0.000000_1.000000.txt")
data4 = np.loadtxt("U_1.000000_1.000000.txt")

titles = ['B=0.0, L=0.0', 'B=0.1, L=0.0', 'B=1.0, L=0.0', 'B=1.0, L=1.0']

i = 0
for data in [data1, data2, data3, data4]:
    x1 = data[:, 1]
    y1 = 15 - data[:, 0]
    b1 = data[:, 2]

    x1U = np.unique(x1)
    y1U = np.unique(y1)

    x1ind = np.searchsorted(x1U, x1)
    y1ind = np.searchsorted(y1U, y1)

    b1grid = np.zeros((len(y1U), len(x1U)))
    b1grid[y1ind, x1ind] = b1

    plt.figure()
    plt.title(titles[i])
    plt.imshow(b1grid, extent=[x1U[0], x1U[-1], y1U[0], y1U[-1]])
    plt.colorbar()
    plt.xlabel("t")
    plt.ylabel("x")
    plt.savefig("u_" + str(i + 1) + ".png", bbox_inches="tight")
    i += 1
