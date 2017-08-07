#include<iostream>

using namespace std;

const int maxlength=50;
typedef int elementtype;
typedef int position;

class Kolejka
	{
	protected :
		elementtype Queue[maxlength];
		position Front; // Indeks elementu czolowego
		position Rear; // Indeks ostatniego elementu
	public:
		Kolejka(){
			Front = 0;
			Rear = maxlength -1;
		}

		int AddOne(int i){
			return (i+1) % maxlength;
		}
		void Enqueue(elementtype x){
			if( this-> AddOne(this-> AddOne(this->Rear)) == this -> Front){
				cout<< "kolejka pelna"<< endl;
			}
			else{
				this-> Rear = this-> AddOne(this-> Rear);
				this-> Queue[this-> Rear] = x;
			}	
		}
		void Dequeue(){
			if(!this-> Empty()){
				this-> Front = this-> AddOne(this-> Front);
			}	
		}
		elementtype FrontElem(){
			if(! (this-> Empty()) ){
				return this-> Queue[this-> Front];
			}
		}
		void Makenul(){
			this-> Front = 0;
			this-> Rear = maxlength - 1;
		}
		bool Empty(){
			if(this-> AddOne(this->Rear) == this-> Front)
				return true;
			else
				return false;
		}
};

int main(){
	cout <<"asd"<< endl;
	Kolejka *k1 = new Kolejka;
	cout <<"asd"<< endl;	
	if(k1 -> Empty()) cout<< "pusta"<< endl;
	k1 -> Enqueue(1);
	cout << k1 -> FrontElem()<< endl;
	k1 -> Enqueue(2);
	cout << k1 -> FrontElem()<< endl;
	k1 -> Dequeue();
	cout << k1 -> FrontElem()<< endl;
	if(!k1 -> Empty()) cout<< "niepusta"<< endl;
	return 0;
}



















