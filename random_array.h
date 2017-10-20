#include<iostream>
#include<string>
#include<vector>
using namespace std;

class random_array {

      //  friend class Linked_List_C              ;//class Linked_List_C has access here
//      friend class hash;
        private:
                int random_int[10000];
        public :
                random_array(void);
                void print();
		int return_random (int);
};

