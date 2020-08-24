#include "msolver.hpp"
#include <iostream>
#include <cmath>
#include <armadillo>

using namespace std;
using namespace arma;

void test(mat A_a){
  cout << A_a << endl;
}


int main(int argc, char const *argv[]){
  int n = 5;

  mat A_a = randu<mat>(n,n);
  vec b = randu<vec>(n);
  vec x = solve(A_a,b);
}
