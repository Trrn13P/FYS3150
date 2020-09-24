#include "eigenvalues.hpp"
#include <iostream>
#include <fstream>
#include "time.h"
#define TRUE 1
#define FALSE 0

void eigenvalues::solve(double tolerance, int maxiter){
offdiag();
Jacobi_rotate();
int iterations = 1;
while ( m_max > tolerance && iterations <= maxiter)
{
   offdiag();
   Jacobi_rotate();
   iterations++;
}
}


void eigenvalues::offdiag(){
   double max;
   for (int i = 0; i < n; ++i)
   {
       for ( int j = i+1; j < n; ++j)
       {
           double aij = fabs(A(i,j));
           if ( aij > max)
           {
              max = aij;  p = i; q = j;
           }
       }
   }
   m_max = max;
   }

void eigenvalues::Jacobi_rotate()
{
  int k = p;
  int l = q;

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


void eigenvalues::order_eigenvalues(){
  running = TRUE;
  col_swap = TRUE;
  while(running==TRUE){
    for(int i=0;i<n-1;i++){
      if(A(i+1,i+1)<A(i,i)){
        float a_ip1ip1 = A(i+1,i+1);
        float a_ii = A(i,i);
        A(i,i) = a_ip1ip1;
        A(i+1,i+1) = a_ii;
        R.swap_cols(i+1,i);
        col_swap = TRUE;
      }
      }
    if(col_swap == FALSE){
      running = FALSE;
    }
    col_swap = FALSE;
    }
}


vec eigenvalues::get_eigenvectors(int n_){
  vec v = zeros(n);
  for(int i=0;i<n;i++){
    v(i) = R(i,n_);
  }
  return v;
}

float eigenvalues::get_eigenvalues(int n_){
  return A(n_,n_);
}
