#include <stddef.h>
#include <iostream>
#include <stdio.h>

using namespace std;

typedef int elementtype;

struct celltype {
  elementtype element;
  celltype * next;
};

typedef celltype * position;

class Lista
{
protected :
  	position l; // wskaźnik do głowy listy

public:
	Lista(){
		l = new celltype;
		l-> next = NULL;
	}//konstruktor
	~Lista(); //destruktor

	void Insert(elementtype x, position p){
		position tmp;
	
		tmp = p -> next;
		
		position nowy = new celltype;
		nowy -> element = x;
		nowy -> next = tmp;
		
		p -> next = nowy;

	}

	void Delete(position p){
		position tmp;		
		
		
		tmp = p -> next -> next;
		
		delete p -> next;

		p -> next = tmp;
	}
	elementtype Retrieve(position p){
		if (p -> next != NULL)
			return p-> next -> element;
	}
	position Locate(elementtype x){
		position p = l;
		
		while(1){
			if ( p -> next -> element == x ){
				return p;
			}
			p = p -> next;		
		}
	}
	position First(){
		return l ;

	}
	position Next(position p){
		return p -> next;
	}
	position Previous(position p){
		position tmp = l;
		while(1){
			if (tmp -> next == p)
				return tmp;
			else 
				tmp = tmp -> next;
		}
	}
	position END(){
		position p = l;
		while(1){
			if (p -> next == NULL)
				return p-> next;
			else 
				p = p -> next;
		}
	}
	void print()
	{
		position i = this -> First();
		while (i!= this -> END())
		{
			printf ("  %d,", this -> Retrieve(i));
			i = this -> Next(i);
		}
		printf("\n");
		return;
	}
};


//==================================================================================
int main(){
  	

	Lista *lista = new Lista;
	
	lista -> Insert(102, lista->First());
	lista -> print();

	for (int i=0; i<3;i++)
		lista -> Insert(i, lista -> First());
	lista -> print();

	lista -> Insert (20,lista -> Previous(lista -> END()));
	lista -> print();
	lista -> Delete( lista -> Locate(20));
	lista -> print();
  
	return 0;
  
}
//==================================================================================
/*lista->Insert( 5 , lista->First());
	
	cout<< "start , pierwszy element: " << lista->Retrieve(lista->First()) << endl;
  	
	lista->Insert( 2 , lista->First());
	cout<< "po wstawieniu '2' , pierwszy element: " << lista->Retrieve(lista->First()) << endl;
	cout<< "po wstawieniu '2' , drugi element: " << lista->Retrieve(lista->Next(lista->First())) << endl;

	lista->Insert( 1 , lista->Next(lista->First()));
	cout<< "po wstawieniu '1' , pierwszy element: " << lista->Retrieve(lista->First()) << endl;
	cout<< "po wstawieniu '1' , drugi element: " << lista->Retrieve(lista->Next(lista->First())) << endl;
	cout<< "po wstawieniu '1' , trzeci element: " << lista->Retrieve(lista->Next(lista->Next(lista->First()))) << endl ;*/

	//delete &lista;
	
	//lista -> last=-1;
