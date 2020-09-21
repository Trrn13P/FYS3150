#ifndef TEST_CLASS_HPP
#define TEST_CLASS_HPP

#include <armadillo>

using namespace arma;

class eigenvalues{
private:
  int n;
  void Initialize(int n_){
    n = n_;
  }

public:
double offdiag(mat A, int *p, int *q, int n);
void Jacobi_rotate ( mat A, mat R, int k, int l, int n );
void solve(mat A, mat R, double maxiter, double tolerance);


eigenvalues(int n_){
  Initialize(n_);
}
};

#endif
