#include <armadillo>
#include <iostream>
#include <cmath>
#include "msolver.cpp"



int main() {

  //Setting up variables
  int n = 100;

  int a = -1;
  int b = 2;
  int c = -1;

  //Making a filename
  std::string filename = "./N" + std::to_string(n) + ".txt";


  matrix_solver test(n);
  //test.random_vectors();
  test.specified_vectors(a,b,c);
  test.forward_solver_general();
  test.backward_solver();


  test.write_file(filename);

  return 0;
}
