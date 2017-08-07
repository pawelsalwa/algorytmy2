#include <iostream>
#include <string>
#include<stack>
#include<stdlib.h>
using namespace std;

stack < string > stos;
stack < string > stos2;
string wyrazenie;

int dlugosc;
	
string wyjscie = "";

string znak;

int priorytet(string znak){ //nadaje wartosc liczbowa kazdemu dzialaniu w zaleznosci od priorytetu
	if ( (znak =="+")  || (znak =="-"))
		return 1;
	if ((znak =="*") || (znak =="/"))
		return 2;
	if ((znak =="^"))
		return 3;
	if ((znak =="~"))
		return 4;
	else
		return 0;
}

void infDoOnp(){
//==============================================================konwersja infiksowej do ONP:
	cout << "Podaj wyrazenie w zwyklej infiksowej notacji: " << endl;
	cin >> wyrazenie;

	dlugosc = wyrazenie.length();
	
	
	for (int i = 0; i < dlugosc; i++){
		znak = wyrazenie[i];
	
		if(znak == "("){ //Jezeli symbol jest lewym nawiasem to wloz go na stos
			stos.push(znak);
		}	
		else if(znak == ")"){  //Jezeli symbol jest prawym nawiasem to ...
			while(stos.top() != "(" ){
					wyjscie += stos.top() + "_";
					stos.pop();
			}
			stos.pop();
		}
		else if ( (znak =="+")  || (znak =="-") || (znak =="*") || (znak =="/") || (znak =="^") || (znak =="~")){
			while(!stos.empty() && (priorytet(stos.top()) >= priorytet(znak ) ) ) {
				wyjscie += stos.top() + "_";
				stos.pop();
			}
			stos.push(znak);
		}else{ //Jesli symbol jest liczba dodaj go do wyjscia
			wyjscie += znak + "_";
		}
	}
	while (!stos.empty()){
		wyjscie += stos.top() + "_";
		stos.pop();
	}
	
	cout << "Podane wyrazenie skonwertowane na ONP: "<<endl << wyjscie <<endl<<endl;
}
/*
void obliczanie(){
//======================================================a teraz obliczanie wartosci wyrazenia w ONP:

	
	for(int i =0; i<wyjscie.length(); i++){
		znak = wyjscie[i];
		if ( (znak =="+")  || (znak =="-") || (znak =="*") || (znak =="/") || (znak =="^") ){ //jezeli jest operatorem to zdejmujemy 2 elem
			double w1 = strtod( stos2.top(),NULL );
			stos.pop();
			double w2 = strtod( stos2.top(),NULL );
			stos.pop();
			
			if(znak == "+")
				stos2.push(w2+w1);
			if(znak == "-")
				stos2.push(w2-w1);
			if(znak == "*")
				stos2.push(w2*w1);
			if(znak == "/")
				stos2.push(w2/w1);
			if(znak == "^")
				stos2.push(w2^w1);
		}	
		
		if(znak == "~"){
			double w1 = stos2.top();
			stos2.pop();
			stos2.push(-w1);
		}
		if(znak == "_"){
			continue;
		}
		else{
			double liczba =  strtod(znak , NULL);
			stos.push(liczba);
		}
		cout<< znak <<endl;
	}
	
	double wynik = strtod( stos2.top(),NULL );
	cout << "wynik = " <<wynik <<endl;
}*/



int main()
{
	infDoOnp();
	//obliczanie(); nie dziala funkcja strtod()- dlaczego? moze zla wersja cpp?
	return 0;
}
