#ifndef EIGENVALUES_HPP
#define EIGENVALUES_HPP

#include <armadillo>

using namespace arma;

class eigenvalues {

  private:
    int n;
    double m_max;

    int p, q;


    double s, c;
    double t, tau;
    double a_kk, a_ll, a_ik, a_il, r_ik, r_il;


    mat R;
    mat A;

    void Initialize(mat A_, int n_){
      //Initialing stepsize, numbers ect.
      n = n_;
      A = A_;
      R = zeros(n,n);
      for(int i=0;i<n;i++){
        R(i,i) = 1;
      }
    }
      //overload function
      void Initialize(){
        A = randn(4,4);
        n = 4;
        std::cout << "Running on overload function\n" << std::endl;
        Initialize(A,n);
      }


  public:
    void offdiag();
    void Jacobi_rotate();
    void solve(double tolerance,int maxiter);


    //setting up the overload
    eigenvalues(mat A, int n_){
      Initialize(A,n_);
    }
    eigenvalues(){
      Initialize();
    }
};

#endif
