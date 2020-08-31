
import numpy as np
import matplotlib.pyplot as plt

def func(n,C,D,uC,uD):


    x = np.linspace(C,D,n+1)
    h = (C-D)/(n+1)
    f = 100*np.exp(-10*x)

    g = h**2*f

    # Elements in the nxn matrix A (special case):
    a = np.ones(n)*(-1)
    b = np.ones(n)*2
    c = np.ones(n)*(-1)

    v = np.zeros(n+1)         # numerical solution.
    v[0]  = uC                # initial condition at x = C.
    v[n]  = uD                # initial condition at x = D.

    # Row reduction. First step:
    b_tilde = np.zeros(n) ; b_tilde[0] = b[0]
    c_tilde = np.zeros(n) ; c_tilde[0] = c[0]
    g_tilde = np.zeros(n) ; g_tilde[0] = g[1]

    # Forward substitution:
    for i in range(1,n):
        b_tilde[i] = b_tilde[i-1]*b[i]/a[i-1] - c_tilde[i-1]
        g_tidle[i] = b_tilde[i-1]*g_tilde[i]/a[i-1] - g[i-1]
        c_tilde[i] = b_tilde[i-1]*c[i]/a[i-1]

    # Solving final set of equations:
    v[n-1] = g[n-1]/b_tilde[n-1]
    # Backward substitution:
    for i in range(2,n):
        j = n - i
        v[j] = (g[j] - c_tilde[j]*v[j+1])/b_tilde[j]

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
