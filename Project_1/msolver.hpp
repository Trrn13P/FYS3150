#ifndef MSOLVER_HPP
#define MSOLVER_HPP


using namespace arma;

class matrix_solver {
private:
  int m_n;
  /* data */

public:
  void Initialize(int n);
  void arma_solver(mat A_a, vec b);
};

#endif
