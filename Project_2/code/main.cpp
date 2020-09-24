#include <iostream>
#include <armadillo>
#include "eigenvalues.hpp"

using namespace arma;
using namespace std;

int main(int argc, char const *argv[]) {
  int n = 4;
  int N = n+1;
  float h = 1./N;
  float a = -1*1./pow(h,2);
  float d = 2*1./pow(h,2);


  mat A = zeros(n,n);
  for(int i=0;i<n;i++){
    if (i!=0){
        A(i,i-1) = a;
      }
    A(i,i) = d;
    if(i!=n-1){
        A(i,i+1) = a;
      }
    }

  double tolerance = 1.0E-10;
  int maxiter = 1000;

  eigenvalues test(A,n);
  test.solve(tolerance,maxiter);
  /*
  for(int j=0;j<n;j++){
    cout << test.get_eigenvalues(j) << endl;
  }
  */

  /*
  for(int i =0;i<n;i++){
    cout << "\n";
    vec v = test.get_eigenvectors(i);
    v.print();
  }
  */

}
