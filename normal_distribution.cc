// normal_distribution
#include <iostream>

#include <string>
#include <random>
using namespace std;
double return_a_number_from_normal_d(){

  	default_random_engine generator;
  	normal_distribution<double> distribution(4.0,1.0);
        //for (int i=0; i<20; i++) {
        double number = distribution(generator)  ;
        //cout << number<< endl ; 

  return d;
}

