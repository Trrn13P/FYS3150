import numpy as np

n = 10
matr = np.zeros((n,n))

a = np.ones(n)*(-1)
b = np.ones(n)*2
c = np.ones(n)*(-1)


for i in range(n):
    #print(i)
    if not i==0:
        matr[i][i-1] = a[i]
    matr[i][i] = b[i]
    if not i==n-1:
        matr[i][i+1] = c[i]


A = matr;
b = np.linspace(0,n,n)


def RowReduce(A):




void RowReduce(float A[][4])
{
    const int nrows = 3; // number of rows
    const int ncols = 4; // number of columns

    int lead = 0;

    while (lead < nrows) {
        float d, m;

        for (int r = 0; r < nrows; r++) { // for each row ...
            /* calculate divisor and multiplier */
            d = A[lead][lead];
            m = A[r][lead] / A[lead][lead];

            for (int c = 0; c < ncols; c++) { // for each column ...
                if (r == lead)
                    A[r][c] /= d;               // make pivot = 1
                else
                    A[r][c] -= A[lead][c] * m;  // make other = 0
            }
        }

        lead++;
        printmatrix(A);
    }
}
