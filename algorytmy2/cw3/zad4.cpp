#include<iostream>
#include<vector>
#include<cstdio>
#include<sstream>
#include <cstdlib>
#include <time.h> // biblio do randomow
#include<vector>
#include <list>

using namespace std;

int main(){
	srand(time(NULL));
	string line;
    	int number;
	int iloscWezlow=0;
	int iloscPolaczen =0;

	cout<< "podaj ilosc wezlow: "<< endl;
		cin >> iloscWezlow;

	while(1){
		cout<< "podaj ilosc polaczen: "<< endl;
		cin >> iloscPolaczen;
//        	if(iloscPolaczen> ((iloscWezlow ^ 2) - iloscWezlow)){
//           		cout<<"podales za duza ilosc polaczen! musi byc mniej niz n^2 - n"<<endl;
//			continue;
//        	}
		break;
	}

   	int polaczenia[3][iloscPolaczen];

	cout<< "podaj pary wezlow: "<< endl;
	int b =0;
	for(int i =0; i< iloscPolaczen; i++){
        cout << "podaj pare nr " << i +1 <<endl;
		cin>>polaczenia[0][i];
		cin>>polaczenia[1][i];
		//cin>>polaczenia[0][i]<<polaczenia[1][i]; WHY not working lol?
	}

	bool MS[iloscWezlow][iloscWezlow]; //maciez sasiedztwa, wypelniam zerami.

	for(int i =0; i< iloscWezlow; i++){
		for(int j =0; j< iloscWezlow; j++){
			MS[i][j] = 0;
		}
	}
	
	for(int i =0; i< iloscPolaczen; i++){	//wypelniam maciez sasiedztwa jedynkami
		MS[polaczenia[0][i] -1][polaczenia[1][i] -1] =1;
		MS[polaczenia[1][i] -1][polaczenia[0][i] -1] =1;
	}

	cout<< "Wyszla nam taka maciez sasiedztwa:"<< endl;
	for(int i =0; i< iloscWezlow; i++){
		for(int j =0; j< iloscWezlow; j++){
			cout<< MS[i][j]<<"_";
		}
		cout << endl;
	}
	cout<< "A tutaj mamy liste sasiedztwa:" << endl;
	for(int i =0; i< iloscWezlow; i++){
		cout << i+1 << ": ";
		for(int j =0; j< iloscWezlow; j++){
			if (MS[i][j] == 1){ 
				cout << j+1 << ",";		
			}
		}
		cout << endl;
	}
	cout<< "A tutaj mamy sekwencje losowych kolorow przypisanych kazdemu wezlowi:" << endl;
	int przypisanyKolor[iloscWezlow];
	int randInt;
	
	for(int i =0; i< iloscWezlow; i++){
		randInt = rand() % 3;
		przypisanyKolor[i] = randInt;
	}
	for(int i =0; i< iloscWezlow; i++){
		switch(przypisanyKolor[i]){
			case 0:
				cout<<"R, ";
				break;
			case 1:
				cout<<"G, ";
				break;
			case 2:
				cout<<"B, ";
				break;
		}
	}
	cout<< endl;
//=============================================================================================
// 0 = bialy , 1 = szary , 2= czarny , 100= inf
	int odleglosc[iloscWezlow]; //odleglosc od glownego wezla
	int glownyWezel, tmpWezel;
	cout << "===================================zad4===========================" << endl;
	cout << "A teraz prosze podac wezel od ktorego bedziemy przeszukiwac graf: " << endl;
	cin >> glownyWezel;
	vector<int> queue;
	for(int i = 0; i < iloscWezlow ; i++){
		przypisanyKolor[i] = 0;
		odleglosc[i]=0;		
	}
	odleglosc[glownyWezel]=0;
	przypisanyKolor[glownyWezel] = 1;
	queue.push_back(glownyWezel);
	
	while(!queue.empty()){
		
		tmpWezel = queue.back();
		queue.pop_back();

		for(int i =0; i< iloscWezlow; i++){
			for(int j =0; j< iloscWezlow; j++){
				if (MS[i][j] == 1){
					cout<< "sprawdzam wezel nr: " << j << endl;
					if(przypisanyKolor[j] == 0){
						przypisanyKolor[j] = 1;
						odleglosc[j] ++ ;
						queue.push_back(j);
						cout<< "operacje przy nr: " << j << endl;
						cout<< "przypisanyKolor; " << przypisanyKolor[j] << endl;
						
					}
				}
			}
		}
		przypisanyKolor[tmpWezel] = 2;		
	}
	
	while(1){
		int x;
		cout<< "Podaj nr wezla aby sprawdzic jego kolor i ogleglosc od glownego:"<< endl;
		cin >> x;
		cout << "Kolor: " << przypisanyKolor[x] << endl;
		cout << "Odleglosc od glownego: " << odleglosc[x] << "\n==========================" << endl;
	}	
}
























