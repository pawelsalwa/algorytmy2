#include<iostream>

using namespace std;

typedef int elementtype;
typedef struct celltype
{
 	elementtype element;
	celltype * next;
};
typedef celltype * position;

class Queue
{
	protected:
		position Front; // wskaznik do glowy listy
		position Rear; // wskaznik do ostatniego elementu
	public:
		Queue(){ //konstruktor
			this-> Front = new celltype;
			this-> Rear = this-> Front;
			this-> Front-> next = NULL;
		}		
		~Queue(){ //destruktor
			position tmp;

			while (this-> Front-> next != NULL){
				tmp = this-> Front;
				this-> Front = this-> Front-> next;
				delete tmp;
			}
			delete this-> Front;
		}
		void Enqueue(elementtype x){
			position p = new celltype;
			p-> element = x;
			p-> next = NULL;
			this-> Rear-> next = p;
			this-> Rear = p;
		}
		void Dequeue(){
			if(!Empty()){
				position p = this-> Front;
				this-> Front = this-> Front -> next;
				delete p;
			}
		}
		elementtype FrontElem(){
			if(!Empty()){
				return this-> Front-> next-> element;
			}
		}
		bool Empty(){
			return ( this-> Front-> next == NULL);
		}
};

int main(){
	cout <<"asd"<< endl;
	Queue *k1 = new Queue;
	cout <<"asd"<< endl;	
	if(k1 -> Empty()) cout<< "pusta"<< endl;
	k1 -> Enqueue(3);
	cout << k1 -> FrontElem()<< endl;
	k1 -> Enqueue(2);
	cout << k1 -> FrontElem()<< endl;
	k1 -> Dequeue();
	cout << k1 -> FrontElem()<< endl;
	if(!k1 -> Empty()) cout<< "niepusta"<< endl;
	return 0;
}
