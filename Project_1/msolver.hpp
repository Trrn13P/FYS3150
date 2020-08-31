class matrix_solver {

  private:
    int n;
    long double h;
    int a, b, c;
    arma::vec a_vec, b_vec, c_vec, g_vec;
    arma::vec a_tilde, b_tilde, c_tilde, g_tilde;
    arma::vec u_vec, x_vec;

    std::string filename;




    void Initialize(int n_){
      //Initialing stepsize, numbers ect.
      n = n_;
      h = 1./(n+1);

      //Initializing x, u(x), g(x)
      x_vec = arma::linspace(0,1,n+2);
      u_vec = arma::vec(n+2,arma::fill::zeros);
      //DISSE SKAL KANSKJE VAERE N+1 !!!!!

      /*
      for(int i=0;i<n-1;i++){
        x_vec(i) = h*i;
      }*/

      //u_vec = arma::vec(n+1,arma::fill::zeros);
      //u_vec(0) = 0; u_vec(n) = 0;

      g_vec = arma::vec(n,arma::fill::zeros);

      //filling in values for g(x)
      //MULIG FEIL HER VED AA BRUKE X_VEC(i+1)!!!!
      for(int i=0;i<n;i++){
        g_vec(i) = pow(h,2) * f(x_vec(i+1));
      }

      //setting up the tilde vectors
      b_tilde = arma::vec(n,arma::fill::zeros);
      c_tilde = arma::vec(n,arma::fill::zeros);
      g_tilde = arma::vec(n,arma::fill::zeros);

    }

    //overload function
    void Initialize(){
      Initialize(100);
    }


public:
  //setting up functions
  void random_vectors();
  void specified_vectors(int a_,int b_,int c_);

  double f(double x);
  void forward_solver_general();
  void forward_solver_specialized();
  void backward_solver();

  void write_file(std::string filename_);


  //setting up the overload
  matrix_solver(int n_){
    Initialize(n_);
  }
  matrix_solver(){
    Initialize();
  }

};
