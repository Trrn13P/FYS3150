#include <iostream>
#include <armadillo>
#include "eigenvalues.hpp"

using namespace arma;
using namespace std;

int main(int argc, char const *argv[]) {
  int n = 4;
  mat A = zeros(n,n);
  for(int i=0;i<n;i++){
    if (i!=0){
        A(i,i-1) = -1;
      }
    A(i,i) = 2;
    if(i!=n-1){
        A(i,i+1) = -1;
      }
    }

  double tolerance = 1.0E-10;
  int maxiter = 1000;

  eigenvalues test(A,n);
  test.solve(tolerance,maxiter);

}
