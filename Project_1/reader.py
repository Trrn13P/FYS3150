import matplotlib.pyplot as plt
import numpy as np

#Analytic solution
#n = np.asarray([10, 100, 1000])
p = np.linspace(0,1,1000)
u_A = 1 - (1 - np.exp(-10))*p - np.exp(-10*p)

def read_file(filename):
    infile = open(filename,"r")

    x = []
    u = []
    for line in infile:
        x.append(eval(line.split()[0]))
        u.append(eval(line.split()[1]))

    infile.close()
    n = len(u)
    FLOPS = 11*(n-2)
    return x,u, FLOPS



filenames = ["./data/N10.txt","./data/N100.txt","./data/N1000.txt"]

def figures(argv):
    for filename in filenames:
        x,u, FLOPS = read_file(filename)
        n = eval(filename.split(".tx")[0][8:])

        plt.xlabel("x")
        plt.ylabel("u")

        plt.plot(x,u,label=r"Numerical solution, $n={:}$ steps".format(n))
        plt.plot(p,u_A,label="Analytic solution")
        plt.title(r"Project 1b - $FLOPS={:}$".format(FLOPS))
        plt.legend() ; plt.grid()

        if argv == "plot":
            plt.show()
        if argv == "save":
            plt.savefig("./figures/1b_{:}.png".format(n))
        plt.clf()

figures("save")
