#include <stdlib.h>
#include<string>
#include<iostream>
#include<stack>

using namespace std;

int main(){
	stack <string> stos;
	string napis= "1.2";

	stos.push(napis);
	
	double tmp = atof(stos.top().c_str());

	cout<< napis<<endl;
	cout<< "asd  " <<stos.top() <<endl;
	
	return 0;
}
