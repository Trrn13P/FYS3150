import matplotlib.pyplot as plt
import numpy as np

"""
def read_file_1(filename):
    infile = open(filename,"r")
    infile.readline()

    x = []
    u = []
    for line in infile:
        x.append(eval(line.split()[0]))
        u.append(eval(line.split()[1]))

    infile.close()
    n = len(u)
    FLOPS = 11*(n-2)
    return x,u, FLOPS



def figures_1(filenames_,argv):
    for filename in filenames_:
        x,u, FLOPS = read_file_1(filename)
        n = eval(filename.split(".tx")[0][11:])
        print(filename.split(".tx")[0][11:])

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

"""
def read_file(filename):
    infile = open(filename,"r")
    first_line = infile.readline()
    if first_line[0] == "|":
        N = eval(first_line.split()[1][2:])
        epsilon_max = eval(first_line.split()[3][12:])
        epsilon_tot = eval(first_line.split()[5][12:])
        cpu_time = eval(first_line.split()[7][9:])
        log_10_h = eval(first_line.split()[9][10:])

        x = []; v = []; u = []
        infile.readline()
        for line in infile:
            inline = line.split()
            x.append(eval(inline[0]))
            v.append(eval(inline[1]))
            u.append(eval(inline[2]))
        if filename[7:10] == "spe":
            FLOPS = 7*N
        if filename[7:10] == "gen":
            FLOPS = N*11
        infile.close()
        return x,v,u,FLOPS,N,epsilon_max,epsilon_tot,cpu_time,log_10_h

    if first_line[0] == "N":
        N = []; epsilon_max = []; log_10_h = []; cpu_time = [];
        for line in infile:
            N.append(eval(line.split()[0][2:]))
            epsilon_max.append(eval(line.split()[1][12:]))
            log_10_h.append(eval(line.split()[2][10:]))
            cpu_time.append(eval(line.split()[3][9:]))
        return N, epsilon_max, log_10_h, cpu_time


filenames_1 = ["./data/genN10.txt","./data/genN100.txt","./data/genN1000.txt",\
"./data/speN10.txt","./data/speN100.txt","./data/speN1000.txt"]

filenames_2 = ["./data/gen_stats.txt","./data/spe_stats.txt"]


for filename in filenames_1:

    x,v,u,FLOPS,N,epsilon_max,epsilon_tot,cpu_time,log_10_h = read_file(filename)
    plt.xlabel("x")
    plt.ylabel("u")

    plt.plot(x,v,label=r"Numerical solution, $n={:}$ steps".format(N))
    plt.plot(x,u,label="Analytic solution")
    if filename[7:10] == "spe":
        type = "Special algo"
    if filename[7:10] == "gen":
        type = "General algo"
    plt.title(r"{:} $FLOPS={:}$".format(type,FLOPS))
    plt.legend() ; plt.grid()
    argv = "save"
    if argv == "plot":
        plt.show()
    if argv == "save":
        plt.savefig("./figures/1b_{:}_{:}.png".format(type[0:3],N))
    plt.clf()



#figures("plot")
"""
x,u, FLOPS = read_file("./data/speN1000.txt")
plt.xlabel("x")
plt.ylabel("u")
n = 1000
plt.plot(x,u,label=r"Numerical solution, $n={:}$ steps".format(n))
plt.plot(p,u_A,label="Analytic solution")
plt.title(r"Project 1b - $FLOPS={:}$".format(FLOPS))
plt.legend() ; plt.grid()
plt.show()
"""


"""
filename = "./data/gen_stats.txt"
infile = open(filename, "r")


N = []
epsilon_max = []
log_10_h = []
cpu_time = []

for line in infile:
    N.append(eval(line.split()[0][2:]))
    epsilon_max.append(eval(line.split()[1][12:]))
    log_10_h.append(eval(line.split()[2][10:]))
    cpu_time.append(eval(line.split()[3][9:]))

import matplotlib.pyplot as plt
print(epsilon_max)
plt.plot(log_10_h,epsilon_max)
plt.show()
"""
