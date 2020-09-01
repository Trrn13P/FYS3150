#include <armadillo>
#include <iostream>
#include <cmath>
#include "msolver.cpp"
#include "time.h"

int main() {

  //Setting up variables
  int n[3] = {10,100,1000};

  int a = -1;
  int b = 2;
  int c = -1;

std::string filename;

    for(int i=0; i< 3;i++){
      matrix_solver run_(n[i]);
      run_.specified_vectors(a,b,c);
      run_.forward_solver_general();
      run_.backward_solver();
      run_.error();

      //Making a filename
      filename = "./data/genN" + std::to_string(n[i]) + ".txt";
      run_.write_file(filename);
    }

    for(int i=0; i< 3;i++){
      matrix_solver run_(n[i]);
      run_.specified_vectors(a,b,c);
      run_.forward_solver_specialized();
      run_.backward_solver();
      run_.error();


      //Making a filename
      filename = "./data/speN" + std::to_string(n[i]) + ".txt";
      run_.write_file(filename);
    }

  return 0;
}
