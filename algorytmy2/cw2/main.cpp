#include<iostream>
#include<string>
#include<cstring>
#include <functional>
#include<cstdlib>
#include<ctime>
#define maxrozmiar 100
 
using namespace std;
 
class kolejka{
    public:
     
    int elementy;
    int kopiec[maxrozmiar];
    int rozmiar;
    //================================================================================================== wype³nia zerami
    kolejka(){
        for(int i=0; i<=maxrozmiar;i++){
        kopiec[i]=0;
        }    
    }
    //==================================================================================================
    //spr zaleznosc kopca - heapify z wikipedii- czy rodzice i dzieci sie zgadzaja- synowie musza byc mniejsi od rodzicow
    void Heapify (int i){
        int l = 2*i; //zapisuje indeksy potomkow
        int r = 2*i +1;
        int tmp;
        int najwiekszy = i;
        /*if(kopiec[l]>kopiec[r]){
        	tmp = kopiec[l];
            kopiec[l] = kopiec[r];
            kopiec[r] = tmp;	
        }*/
        
        //jesli lewy jest wiekszy od rodzica to najw =l
        if (( l <= rozmiar) && (kopiec[l] > kopiec[najwiekszy]))
        {
            najwiekszy=l;
        }
         
        if((r <=rozmiar) && (kopiec[r] > kopiec[najwiekszy]))
        {
            najwiekszy = r;
        }
        //w przeciwnym przypadku najw ma obecny index (przypisane wczesniej)
        //jezeli rodzic nie jest najwiekszy w stosunku do potomkow,
        //to ukladamy rodzica i obu synow poprawnie
        if(najwiekszy != i)
        {       //swapping
            tmp = kopiec[najwiekszy];
            kopiec[najwiekszy] = kopiec[i];
            kopiec[i] = tmp;
            Heapify(najwiekszy);
        }   
    }
    //==================================================================================================
    void BudujKopiec(int tablica[], int elementow){ 
        for(int i=0; i<elementow;i++){
            kopiec[i+1] = tablica[i]; //prosciej indeksy liczyc od 1
        }
        rozmiar = elementow;
		//spelnienie wlasnosci kopca T[i] ? T[indeks ojca i]- heapify
        // poniewaz ojciec ma 2 synow to zaczynam od i= rozmiar /2 - indeks ostatniego elementu
        //for(int i=elementow/2; i>=1; i--){
        for(int i=rozmiar; i>=1; i--){
            Heapify( i);
        }
    }
    //==================================================================================================
    int PobierzNajwiekszy(){
        int max;
        max = kopiec[1];
        kopiec[1] = kopiec[rozmiar]; // ostatni lisc na gore
        rozmiar--;
        //HeapSort(kopiec, 1);
        for(int i=rozmiar; i>=1; i--){ //naprawianie struktury kopca
            Heapify( i);
        }
        return max;
    }
    //==================================================================================================
   void WstawElement(int e){
        int i, tmp;     
        rozmiar++;
        i = rozmiar;
        kopiec[i]=e; //prostsze spr struktury kopca
        while(i>1 && e>kopiec[i/2])
        {
            tmp = kopiec[i];
            kopiec[i] = kopiec[i/2];
            kopiec[i/2] = tmp;
            i = i/2;
        }
    }
    //==================================================================================================
    void Wyswietl(){
        for(int i=1; i<rozmiar+1;i++){
            cout << "kopiec[" << i <<"]= " <<kopiec[i] <<" , ";
        }  
        cout << endl;
    }
    //==================================================================================================
    void HeapSort(int tablica[], int rozmiar1){
        BudujKopiec(tablica, rozmiar1);
        int tmp;
        int i;
        for(i=rozmiar; i>1; i--){
            tmp = kopiec[1];
            kopiec[1] = kopiec[i];
            kopiec[i] = tmp;
            rozmiar--;
            Heapify( 1);
        } 
        cout << "Posortowane: ";
        for(int i=1; i<10;i++){
            cout  << kopiec[i] << " ";
        }  
        cout << endl;
    }
};
//==================================================================================================
void sortowanie(){  
	int rozmiar = 10;
    /*srand( time( 0 ) );
    
    int tablica[rozmiar];
    for(int i=0; i<=rozmiar;i++){
        tablica[i] = (rand()%100);
    }*/
    int tablica[10] = { 5, 7,3, 4 ,12, 14, 10, 9 , 16,6};
    kolejka TMP = kolejka();
    TMP.HeapSort(tablica,rozmiar);  
}
//==================================================================================================
int main(int argc, char **argv)
{
    int tablica[5] = {5,3,4,2,6};
    int rozmiar  = sizeof(tablica)/sizeof(tablica[0]); 
    cout << "=================================================================="<< endl;
    cout << "Start>>> rozmiar kopca = "<< rozmiar<< endl;
 
    kolejka Kolejka = kolejka();
    Kolejka.BudujKopiec(tablica,rozmiar);
    Kolejka.Wyswietl();
 
    cout << "Pobieram najwiekszy element: " << Kolejka.PobierzNajwiekszy()<< endl;
 	cout << "Obecny rozmiar kopca = "<< Kolejka.rozmiar<< endl;
    Kolejka.Wyswietl(); 
    cout << "Wstawiam 7"<< endl;
    Kolejka.WstawElement(7);
    cout << "Wstawiam 1"<< endl;
    Kolejka.WstawElement(1);
    Kolejka.Wyswietl();
    
    sortowanie();
}
