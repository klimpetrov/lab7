#include <iostream>
#include <cmath>
#include <fstream>


using namespace std;


void f(double* ys, double* y, const double eta){
  
ys[0] = y[1];
ys[1] = (eta-y[0]*y[0])*y[0];

  
}


int main(){
  double y[2];
  double k1[2];
  double k2[2];
  double k3[2];
  double eta = 0.5;
  double dx = 0.01;
  double temp[2];
  y[0] = 0.00001;
  y[1] = sqrt(eta)*y[0];
  int N=100/dx;
  ofstream out("data.txt");
  for(int i=0; i<N; i++){
    
  f(k1,y,eta);
  
  temp[0]= y[0] + dx*0.5*k1[0];
  temp[1]= y[1] + dx*0.5*k1[1];
  
  f(k2, temp, eta);
  
  temp[0]= y[0] + dx*(-k1[0]+2*k2[0]);
  temp[1]= y[1] + dx*(-k1[1]+2*k2[1]);
  
  f(k3, temp , eta);
  
  y[0]= y[0] + (dx/6)*(k1[0]+4*k2[0]+k3[0]);
  y[1]= y[1] + (dx/6)*(k1[1]+4*k2[1]+k3[1]);
  
  out << i*dx << "\t" << y[0] << "\t" << y[1] << endl;
  //cout << k1[0] << endl;
  }
  out.close();
  return 0;
}