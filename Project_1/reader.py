import matplotlib.pyplot as plt

infile = open("N10.txt","r")

x = []
u = []
for line in infile:
    x.append(line.split()[0])
    u.append(line.split()[1])

def plotter():
    plt.plot(x,u)
    plt.show()

plotter()
