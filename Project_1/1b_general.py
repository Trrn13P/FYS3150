# Project 1, b) General algorithm.

"""
A tridiagonal matrix is a special form of banded matrix where all the elements
are zero except for those on and immediately above and below the leading diagonal.
Develop a general algorithm first which does not assume that we have a matrix
with the same elements along the diagonal and the non-diagonal elements.
The algorithm for solving this set of equations is rather simple and requires two steps only,
a decomposition and forward substitution and finally a backward substitution.
"""

# Solving the equation: Av = B.

"""
Your first task is to set up the general algorithm (assuming different values
for the matrix elements) for solving this set of linear equations.
Find also the precise number of floating point operations needed to solve the above equations.
For the general algorithm you need to specify
the values of the array elements a, b and c by inserting their explicit values.
"""

import numpy as np
import matplotlib.pyplot as plt

def func(n,C,D,uC,uD):
    # Solves the matrix equation Av=B, including boundaries (u(C) and u(D)).
    # A is a special case nxn tridiagonal matrix.

    x = np.linspace(C,D,n+1)
    h = (C-D)/(n+1)
    f = 100*np.exp(-10*x)

    B = h**2*f

    # Elements in the nxn matrix A (special case):
    a = np.ones(n)*(-1)
    b = np.ones(n)*2
    c = np.ones(n)*(-1)

    v = np.zeros(n+1)         # numerical solution.
    v[0]  = uC                # initial condition at x = C.
    v[n]  = uD                # initial condition at x = D.

    # Row reduction. First step:
    y = np.zeros(n) ; y[0] = b[0]
    z = np.zeros(n) ; z[0] = c[0]
    g = np.zeros(n) ; g[0] = B[1]

    # Forward substitution:
    for i in range(1,n):
        y[i] = y[i-1]*b[i]/a[i-1] - z[i-1]
        g[i] = y[i-1]*B[i]/a[i-1] - g[i-1]
        z[i] = y[i-1]*c[i]/a[i-1]

    # Solving final set of equations:
    v[n-1] = g[n-1]/y[n-1]
    # Backward substitution:
    for i in range(2,n):
        j = n - i
        v[j] = (g[j] - z[j]*v[j+1])/y[j]

    FLOPS = 11*n   # approximatly the number of floating point operations.

    return x,v,FLOPS

n = np.asarray([10, 100, 1000])

p = np.linspace(0,1,n[-1])

u = 1 - (1 - np.exp(-10))*p - np.exp(-10*p)   # analytic solution.

for i in range(len(n)):
    x,v,FLOPS = func(n=n[i],C=0,D=1,uC=0,uD=0)
    plt.plot(x,v,label=r"Numerical solution, $n={:}$ steps".format(n[i]))
    plt.plot(p,u,label="Analytic solution")
    plt.xlabel("x") ; plt.ylabel("u")
    plt.title(r"Project 1b - $FLOPS={:}$".format(FLOPS))
    plt.legend() ; plt.grid()
    #plt.savefig("1b_{:}.png".format(n[i]))
    plt.show()
