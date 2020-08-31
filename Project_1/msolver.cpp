#include "msolver.hpp"
#include <iostream>
#include <fstream>

//f(x) test function
double matrix_solver::f(double x){
  return 100 * exp(-10*x);
}


//Setting up random a,b,c vectors
void matrix_solver::random_vectors(){
  //Initializing the uniformly randomly generated a,b,c vectors
  a_vec = arma::randu(n);
  b_vec = arma::randu(n);
  c_vec = arma::randu(n);
  }

  void matrix_solver::specified_vectors(int a_,int b_,int c_){
    a = a_; b = b_; c = c_;
    //Initializing the uniformly randomly generated a,b,c vectors
    a_vec = arma::vec(n);
    b_vec = arma::vec(n);
    c_vec = arma::vec(n);
    for(int i=0;i<n;i++){
      a_vec(i) = a;
      b_vec(i) = b;
      c_vec(i) = c;
    }
    }


//General forward solver
void matrix_solver::forward_solver_general(){
  //Setting inital values for the tilde vectors
  b_tilde(0) = b_vec(0); c_tilde(0) = c_vec(0); g_tilde(0) = g_vec(0);

  //Solving the forward algorythm
  for(int i=1;i<n;i++){
    b_tilde(i) = b_vec(i)*b_tilde(i-1)*1./a_vec(i-1) - c_tilde(i-1);
    c_tilde(i) = c_vec(i)*b_tilde(i-1)*1./a_vec(i-1);
    g_tilde(i) = g_vec(i)*b_tilde(i-1)*1./a_vec(i-1) - g_tilde(i-1);
  }
}

void matrix_solver::forward_solver_specialized(){
}

//General backward_solver
void matrix_solver::backward_solver(){
  //u_vec(n+1) = g_tilde(n-1);
  u_vec(n) = g_tilde(n-1)*1./b_tilde(n-1);

  for(int i=2;i<n+1;i++){
    int j = (n-i);
    //std::cout << j << std::endl;

    //std::cout << (g_tilde(j) - c_tilde(j)*g_tilde(j+1)*1./b_tilde(j+1))*1./b_tilde(j+1) << std::endl;
    u_vec(j+1) = (g_tilde(j) - c_tilde(j) *u_vec(j+2))*1./b_tilde(j);
    //KAN VAERE FEIL MED INDEXERING AV U HER
    //std::cout << u_vec(j) << std::endl;
  }
}

//Writing x,u to outfile
void matrix_solver::write_file(std::string filename_){
  filename = filename_;
  std::ofstream outfile (filename);
  //myfile.open ("./example.txt");
  for(int i=0;i<n+2;i++){
    outfile << x_vec(i) << " " << u_vec(i) << "\n";
  }
  outfile.close();

}
