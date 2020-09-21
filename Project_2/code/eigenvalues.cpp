#include "eigenvalues.hpp"
#include <iostream>
#include <fstream>
#include "time.h"

void eigenvalues::solve(double tolerance, int maxiter){
//A.print();

offdiag();
Jacobi_rotate();
int iterations = 1;
while ( m_max > tolerance && iterations <= maxiter)
{
  //cout << "running..." << endl;
   offdiag();
   Jacobi_rotate();
   iterations++;
}
cout << iterations << endl;
//R.print();
//A.print();
}

//  the offdiag function, using Armadillo
void eigenvalues::offdiag(){
   for (int i = 0; i < n; ++i)
   {
       for ( int j = i+1; j < n; ++j)
       {
           double aij = fabs(A(i,j));
           //cout << aij << " " << m_max<< endl;
           if ( aij > m_max)
           {
              m_max = aij;  p = i; q = j;

           }
       }
   }
   }

void eigenvalues::Jacobi_rotate()
{
  //cout << p << q << endl;
  int k = p;
  int l = q;
  //

  if ( A(k,l) != 0.0 ) {
    tau = (A(l,l) - A(k,k))/(2*A(k,l));

    if ( tau >= 0 ) {
      t = 1.0/(tau + sqrt(1.0 + tau*tau));
    }
    else {
      t = -1.0/(-tau +sqrt(1.0 + tau*tau));
    }

    c = 1/sqrt(1+t*t);
    s = c*t;
  }
  else {
    c = 1.0;
    s = 0.0;
  }

  a_kk = A(k,k);
  a_ll = A(l,l);
  A(k,k) = c*c*a_kk - 2.0*c*s*A(k,l) + s*s*a_ll;
  A(l,l) = s*s*a_kk + 2.0*c*s*A(k,l) + c*c*a_ll;
  A(k,l) = 0.0;  // hard-coding non-diagonal elements by hand
  A(l,k) = 0.0;  // same here
  //A.print();
  for ( int i = 0; i < n; i++ ) {
    if ( i != k && i != l ) {
      a_ik = A(i,k);
      a_il = A(i,l);
      A(i,k) = c*a_ik - s*a_il;
      A(k,i) = A(i,k);
      A(i,l) = c*a_il + s*a_ik;
      A(l,i) = A(i,l);
    }
//  And finally the new eigenvectors
    r_ik = R(i,k);
    r_il = R(i,l);

    R(i,k) = c*r_ik - s*r_il;
    R(i,l) = c*r_il + s*r_ik;

  }
  }
