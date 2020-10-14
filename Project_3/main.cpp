#include "diff_solver.hpp"
#include <iostream>
#include <armadillo>
#include "planet.h"


using namespace std;
using namespace arma;

mat diffEq_(planet *planets[],int len){
  mat dydt = zeros(len,6);
  for(int i=0;i<len;i++){
    for(int j=3;j<6;j++){
      dydt(i,j) = planets[i]->velocity[j-3];
    }
  }

  float Gconst = 4*M_PI*M_PI;
   //float Gconst = 6.67408*1E-11;

  for(int i=0;i<len;i++){
    vec a_i = zeros(3);
    vec r_i = zeros(3);
    vec r_j = zeros(3);
    vec r_ij = zeros(3); //unit length

    for(int k=0;k<3;k++){
      r_i[k] = planets[i]->position[k];
    }

    for(int j=0;j<len;j++){
      for(int k=0;k<3;k++){
        r_j[k] = planets[j]->position[k];
      }

      if(j!=i){
        r_ij = (r_j-r_i)*.1/norm(r_j-r_i,2);
        a_i = planets[i]->Acceleration(*planets[j],Gconst) * r_ij + a_i;
      }
    }
    for(int k=0;k<3;k++){
      dydt(i,k)=a_i(k);
    }
    //cout << a_i << endl;
  }


  cout << dydt << endl;
  return dydt;
}


int main(int argc, char const *argv[]) {
  planet *planets[4];
  planets[0] = new planet();
  planets[1] = new planet(3*1E-6,1,1,4,1,4*M_PI,5.5);
  planets[2] = new planet(3*1E-6,2,0.5,5,3,4*M_PI,5);
  planets[3] = new planet(3*1E-6,3,3,3,4,4*M_PI,6);

  int len = end(planets) - begin(planets);
  //diffEq_ *test;
  //test(planets);
  diffEq_(planets,len);
  //cout << planets << endl;
  //test(planets);


  delete[] *planets;


  return 0;

}
