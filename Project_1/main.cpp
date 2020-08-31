#include <armadillo>
#include <iostream>
#include <cmath>
#include "msolver.cpp"



int main() {

  //Setting up variables
  int n[3] = {10,100,1000};

  int a = -1;
  int b = 2;
  int c = -1;

std::string filename;

    int i = 0;
    for(i=0; i< 3;i++){
      matrix_solver run_(n[i]);
      run_.specified_vectors(a,b,c);
      run_.forward_solver_general();
      run_.backward_solver();

      //Making a filename
      filename = "./data/N" + std::to_string(n[i]) + ".txt";

      run_.write_file(filename);

    }

  return 0;
}
