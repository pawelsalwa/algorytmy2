#include<iostream>
#include<vector>

using namespace std;

void set_union(vector<int> A, vector<int> B, vector<int> C){
	C = A;

	bool zawiera = false;

	for ( int i =0; i < A.size() ; i++){
		for ( int j =0; j < B.size() ; j++){

				if (A[i] == B[j])
					zawiera = true;
				if (!zawiera)
					C.push_back(B[j]);

		}
	}
	for ( int i =0; i < C.size() ; i++){
		cout << C[i];
	}
}

int main(){
	
	cout<< "start" << endl;
	
	vector<int> A;
	vector<int> B;
	vector<int> C;
	
	for ( int i =1; i < 7 ; i++)
		A.push_back(i);
	
	for ( int i =5; i < 7 ; i++)
		B.push_back(i);

	
	set_union(A,B,C);


















/*
	n = 12;

	int A[] = {1,2,3,4,5,6};
	int B[] = {5,6};
	int C[n];

	for ( int i =0; i < 6 ; i++)
		C[i] = A[i];

	for ( int i =0; i < 6 ; i++){
		for ( int j =0; j < 2 ; j++){ 		
			if(A[i] != B[j]){
				C[6+i] = A[i];
			}
					
		}
	}*/


	cout<< "end" << endl;
}
