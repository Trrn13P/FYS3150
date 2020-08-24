#include "msolver.hpp"
#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

void matrix_solver :: Initialize(int n){
  m_n = n;

}

void matrix_solver :: arma_solver(vec b){
  //vec x = solve(A_a,b);
}
