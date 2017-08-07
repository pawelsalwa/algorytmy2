#include<iostream>
#include<list>
#include<vector>
#include<stack>
#include <cstdlib>
#include <ctime>
#include <algorithm>
  
using namespace std;

class Graph
{
public:
    int v;
     
    vector< vector <int> > edges;
    vector<int> tmp;
     
         
public:
    stack<int> s;
    bool cykliczny;
    //===========================================
    Graph(int v)
    {
        this->v = v;
        this->cykliczny = false;
    }
    //===========================================
    void addEdge(int a, int b)
    {
         
        tmp.push_back(a);
        tmp.push_back(b);
        edges.push_back(tmp);
        tmp.pop_back();
        tmp.pop_back();
    }
    //===========================================
};

class Klient
{
public:
	bool etykieta;
	int luksus;
	int pojazd;
	int nr;
	
	Klient(int luksus, int nr){
		this->luksus = luksus;
		this->etykieta = false;
		this->nr = nr;
	}
};

class Auto
{
public:
	bool etykieta;
	int luksus;
	int pojazd;
	int nr;
	
	Auto(int luksus, int nr){
		this->luksus = luksus;
		this->etykieta = false;
		this->nr = nr;
	}
};
//=====================================================================================
int main()
{
    int x,y;
    cout <<"Witaj w programie zarzadzania Twoja wyporzyczalnia samochodow. \nIle obecnie posiadasz pojazdow do wyporzyczenia?" <<endl;
    cin >> x;
    cout <<"Ile klientow chce wyporzyczyc Twoje samochody?" << endl;
    cin >> y;
    int a,b;
    Graph G(x + y);
    
    vector<Auto> auta;
    vector<Klient> klienci;
    
    srand((unsigned)time(0));
    
	int rng;

    for(int i=0; i<= x; i++){
    	rng = rand()%10 + 1;
        auta.push_back(Auto(rng , i)); 
    }
    
    for(int i=0; i<= y; i++){
    	rng = rand()%10 + 1;
        klienci.push_back(Klient(rng , i)); 
    }
    cout<< "=================Obecny stan:===========================\n          nr Klienta | wymagany luksus pojazdu  " << endl;
    for(int i=0; i<= y; i++){
    	cout << "              "<<klienci[i].nr << "      |     " <<klienci[i].luksus <<endl;
    }    
    cout<< "\n          nr pojazdu | luksus pojazdu  " << endl;
    for(int i=0; i<= x; i++){
    	cout << "              "<<auta[i].nr << "      |     " <<auta[i].luksus <<endl;
    }   
    
    cout<< "Wybierz sposob przypisania aut klientom:\n1- priorytetem sa klienci z bardziej luksusowymi autami\n2- priorytetem jest czas zgloszenia sie do wyporzyczalni" << endl;
    int s;
	cin >> s;
	 
	if(s==1){
		cout << "Parowanie aut z klientami- priorytet- luksus..." << endl;
		int n = x;
    
 	   do{
 	   	for (int i = 0; i < n-1; i++)
 	   		if ( klienci[i].luksus > klienci[i+1].luksus ){
 	   			swap( klienci[i] , klienci[i+1]);
				}
			n--;
	    	
	    }while (n >=1);
	    n=x;
	    do{
	    	for (int i = 0; i < n-1; i++)
	    		if ( auta[i].luksus > auta[i+1].luksus ){
	    			swap( auta[i] , auta[i+1]);
				}
			n--;
	    	
	    }while (n >=1);	
		
	}
	
	if(s==2){
		cout << "Parowanie aut z klientami- priorytet- czas zglaszania..." << endl;
		
	}
	cout<< "=================Obecny stan:===========================\n          nr Klienta | wymagany luksus pojazdu  " << endl;
    	for(int i=0; i<= y; i++){
    		cout << "              "<<klienci[i].nr << "      |     " <<klienci[i].luksus <<endl;
    	}    
    	cout<< "\n          nr pojazdu | luksus pojazdu  " << endl;
    	for(int i=0; i<= x; i++){
    		cout << "              "<<auta[i].nr << "      |     " <<auta[i].luksus <<endl;
    	} 	
    for(int i=0; i<= y; i++){
    	G.addEdge(  auta[i].nr , klienci[i].nr  ) ;
	}
    cout<< "=================przypisane auta do klientow:=================\n          nr Klienta (luksus) | nr pojazdu (luksus)  \n" << endl;
    	for(int i=0; i<= y; i++){
    		cout << "                        "<< klienci[ G.edges[i][0] ].nr << " (" << klienci [G.edges[i][0] ].luksus << ") | " <<auta[ G.edges[i][1] ].nr << " (" << auta [G.edges[i][1] ].luksus << ")" << endl;
    	}
	
    return 0;
}



















