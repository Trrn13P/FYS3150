#include <armadillo>
#include "test_class.hpp"
#include <iostream>

using namespace std;
using namespace arma;

void eigenvalues::solve(mat A_, mat R_ , double maxiter, double tolerance){
  A = A_;
  R = R_;

  int p, q;
  double maxnondiag = offdiag(A, &p, &q, n);
  Jacobi_rotate(A, R, p, q, n);
  int iterations = 1;
  while ( maxnondiag > tolerance && iterations <= maxiter)
  {
    //cout << "hey" << endl;
     int p, q;
     maxnondiag = offdiag(A, &p, &q, n);
     Jacobi_rotate(A, R, p, q, n);
     iterations++;
  }
  R.print();
  A.print();
}


double eigenvalues::offdiag(mat A, int *p, int *q, int n)
{
   double max;
   for (int i = 0; i < n; ++i)
   {
       for ( int j = i+1; j < n; ++j)
       {
           double aij = fabs(A(i,j));
           if ( aij > max)
           {
              max = aij;  *p = i; *q = j;
           }
       }
   }
   return max;
}

void eigenvalues::Jacobi_rotate (int k, int l, int n )
{
  double s, c;
  if ( A(k,l) != 0.0 ) {
    double t, tau;
    tau = (A(l,l) - A(k,k))/(2*A(k,l));

    if ( tau >= 0 ) {
      t = 1.0/(tau + sqrt(1.0 + tau*tau));
    } else {
      t = -1.0/(-tau +sqrt(1.0 + tau*tau));
    }

    c = 1/sqrt(1+t*t);
    s = c*t;
  } else {
    c = 1.0;
    s = 0.0;
  }
  double a_kk, a_ll, a_ik, a_il, r_ik, r_il;
  a_kk = A(k,k);
  a_ll = A(l,l);
  A(k,k) = c*c*a_kk - 2.0*c*s*A(k,l) + s*s*a_ll;
  A(l,l) = s*s*a_kk + 2.0*c*s*A(k,l) + c*c*a_ll;
  A(k,l) = 0.0;  // hard-coding non-diagonal elements by hand
  A(l,k) = 0.0;  // same here
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
  return;
} // end of function jacobi_rotate
