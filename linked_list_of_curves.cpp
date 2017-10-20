#include <iostream>
#include <cstddef>
#include "linked_list_of_curves.h"


using namespace std;
////////////////////////////////CONSTRUCTORS//////////////////////////
Linked_List_C :: Linked_List_C(void)//Default definition of the list with no elements only the root(head->default)
        : Size_of_list(0){ 
        Head = new Curve();
        //cout << "I just constructed a list with Head \n";
        //cout << Head->Start << "\n" ;
}

/////////////////////////////////////////////////////////////

Linked_List_C :: Linked_List_C( int dim ,string onoma_kampulhs,vector< vector <double> > coors, vector <vector <double> > coors_in_grid)
        : Size_of_list(1),dimensions(2){//definition of a list with one element(head) 
        /* Create a new node, acting as both the head and tail node */
      
	Head = new Curve(onoma_kampulhs ,coors,coors_in_grid);
        cout << "I just constructed a list of edges with Head \n";
        //cout << Head->coordinates ;
        cout << endl;
}
 
////////////////////////////////DESTRUCTOR///////////////////////////////

Linked_List_C :: ~Linked_List_C(){
        Delete_all_the_curves(); //call the function which del;etes the list
        cout <<"I just delete a List of edges\n" ;
}
//////////////////////////////////////////////////////////////////////////




/////////////////////////////   FUNCTIONS  /////////////////////////////

//Just return the size of the list 
int Linked_List_C  :: size_of_list_C() {
	cout << Size_of_list;
        return (Size_of_list);
}


////////////////////////////////////////////////////////////////////////////
void Linked_List_C ::  Add_curve_on_tail_C(string onoma,vector<vector <double> > New_Curve,vector<vector <double> > New_Curve_in_grid){
	Curve* new_curve =  new Curve(onoma,New_Curve,New_Curve_in_grid);//new  curve(class construction)
	Curve* Tail = Head;//make this connection equal to the head of the list(memory-position)
        while(Tail-> Next_Curve)//While this new connection points to a an other connection(Not NULL)
		Tail = Tail->Next_Curve;//go on the list

	Tail->Next_Curve = new_curve;//make the end of the list our new curve 
	new_curve->Next_Curve = NULL ;//make the next curve of  tsil  be a NULL ptr
	Size_of_list++; //Just make our list of connections bigger by one
}
//////////////////////////////////////////////////////////////////////////////
/*
void Linked_List_E :: Delete_an_edge_E(int Ss,int Ee ){
	if (Is_in_E(Ss ,Ee)==1){//If this connection is in our list
		Edge* Deletor = Head;//create a connection equal to head(memory position)
		if(	(Ss == Head->Start) 	&
			(Ee == Head->End) ){//If our requested connection is our first element of the list
        			Head = Head->Next_edge; //update the head
				delete Deletor;//delete the head(Deletor was pointing to the head)
				Size_of_list--;//update the size of the list
				return;
    		}
		else {
			Edge* Previous = Head;//create a connection(previous) equals to head(memory position)
			while(  (Previous->Next_edge->Start  != Ss)  &
				(Previous->Next_edge->End    != Ee)){//Find the the connection we want to delete and Previous stay to Its Previous Position 
					Previous=Previous->Next_edge;
			}
			Deletor = Previous->Next_edge ;//Deletor become the deleting Connection
			Previous->Next_edge = Deletor->Next_edge ;//Link the List
			delete Deletor ;//delete the connection with Ss-Ee values
			Size_of_list--;//update the size of the list
		}
	}
}
*/
///////////////////////////////////////////////////////////////////////////////
void Linked_List_C :: Delete_all_the_curves(){
	Curve *Deletor = Head;
    	/* Traverse the list and delete the curves one by one from the head */

  	while (Deletor != NULL) {
        	// delete the head 
        	Head = Head-> Next_Curve;
        	delete Deletor;
        	// update the head  
        	Deletor = Head;
    	}
    	/* Reset the head  */
	Size_of_list = 0;//make the size of list 0 as it is
    	Head = NULL;
}

//////////////////////////////////////////////////////////////////////////////
void Linked_List_C :: Traverse_and_print_C(){
        int nn = -1 ;
	Curve *Conductor = Head;       //create a conductor of the list

        if (Head == NULL) {           // The list is empty? 
                cout << "No Edges" << endl;//if yes make the user knows about it
                return;
	}
	cout << "Linked List of curves ->";
        while (Conductor != NULL ) { /* while there are some more Curves in the list */

		if (Size_of_list==0){
			break;
		}
		else{   cout << endl;
			int n=-1; 
			//print the curve
			cout  <<"\nNext curve(" << Conductor->onoma_kampulhs << ")"<<endl ;
			//cout <<"   " << Conductor->coordinates << "->" ;
			        for(int  i =0 ; i < Conductor->coordinates.size(); i++){
                	//		cout << "num:" << n++;
					for(int j = 0; j< Conductor->coordinates[i].size(); j++ ){
                        			cout<< Conductor->coordinates[i][j] ;
						if(j % 2 == 0 ){cout << ",";}
						if(j % 2 == 1 ){cout << "-";}
                			}
                	//		cout  <<"\n";
					 //cout << "next point of curve:";
        			}
				cout << "IN CON IN GRID\n\n\n";
				for(int  i =0 ; i < Conductor->coordinates_in_grid.size(); i++){
                        //              cout << "num:" << n++;
                                        for(int j = 0; j< Conductor->coordinates_in_grid[i].size(); j++ ){
                                                cout<< Conductor->coordinates_in_grid[i][j] ;
                                                if(j % 2 == 0 ){cout << ",";}
                                                if(j % 2 == 1 ){cout << "-";}
                                        }
                        //              cout  <<"\n";
                                         //cout << "next point of curve:";
                                }

	
			// The pointer moves along to the next curve 
                	Conductor = Conductor->Next_Curve;
        	}

	}

}
//////////////////////////////////////////////////////////////////////////////

Curve* Linked_List_C :: Return_a_curve_C(  vector<vector <double> > coors){
        Curve* Conductor = Head;//create a conductor
              	if (Is_in_C(coors) == 1){//If requested curve is in the list
			if(Conductor!=NULL){
                        	while(Conductor!= NULL){//find the requsted curve an return the memory position
			//		if(Conductor->coordinates == coors){
                        	                return Conductor ;
                          //      	}
						Conductor = Conductor->Next_Curve;//go on
                        	}
                	}
		}
		else{
			cout << "There is not Such an Edge" ;//if there is not the requested curve make the user know 
		}
}
//////////////////////////////////////////////////////////////////////////////

bool Linked_List_C :: Is_in_C(  vector<vector <double> > K_grided ){
	bool idio ;
	Curve* Conductor = Head ;//creatae a conductor for our list
	if(Conductor!= NULL){
		while (Conductor!=NULL){//while we wre not at the end of the list
			if((Conductor->coordinates_in_grid.size() == K_grided.size() )){
			  	cout << "Exoun idio megethos!!";
				
				for (int i = 0 ; i < Conductor->coordinates_in_grid.size() ; i++){
					for(int j = 0 ; j < 2 ; j++){
						if(Conductor->coordinates_in_grid[i][j] == K_grided[i][j]){
							idio = 1;
						}
						else if(Conductor->coordinates_in_grid[i][j] != K_grided[i][j]){
							idio = 0 ;
							return 0 ;
						}
					}
				}

				cout << "\nEINAI IDIAAAA!!!!!!!!!!!!!!!!\n" << idio << "naiiiiiiii";
				//KANE FRECHET!!!
				return idio;
			}
			Conductor = Conductor->Next_Curve; //go on
		}
	}
	else{return 0;}//if you dont find the connection be false

}

/////////////////////////////END OF FILE/////////////////////////////////////

