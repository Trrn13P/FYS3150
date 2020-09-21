#include <iostream>
#include <armadillo>
#include "test_class.hpp"

using namespace arma;
using namespace std;

//  the offdiag function, using Armadillo

// more statements



int main(int argc, char const *argv[]) {
  int n = 4;
  mat R = zeros(n,n);
  for(int i=0;i<n;i++){
    R(i,i) = 1;
  }
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
  eigenvalues test(n);
  int maxiter = 1000;
  double tolerance = 1.0E-10;
  test.solve( A, R, maxiter,  tolerance);


}
