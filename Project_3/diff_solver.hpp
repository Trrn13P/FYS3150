#include <armadillo>

using namespace arma;

#ifndef DIFF_SOLVER_HPP
#define DIFF_SOLVER_HPP

class diff_solver {
private:
  //Inputs of init function
  int n;

  //Pointer to the diffEquation
  mat (*diffEq)(int);



public:
  void calcSlope();
  void step();

  diff_solver(mat (*f)(int),int n_){
    n = n_;
    diffEq = f;
  }

};


#endif
