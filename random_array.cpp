#include"random_array.h"
#include<string>
#include<cstring>
#include<random>
#include<iomanip>
using namespace std;

random_array :: random_array(void){
	random_device rd;
         mt19937 gen(rd());
        normal_distribution<> d(60,2);
        for (int i = 0 ; i <9999 ; i++  ){
                int number = round(d(gen));
                this->random_int[i] = number ;
        }

	
}
void  random_array :: print(){
	for (int i = 0 ; i < 9999 ; i++){
	cout << this->random_int[i] << endl ; 
	}

}

int random_array :: return_random (int keli){
	return (this->random_int[keli]);

}
