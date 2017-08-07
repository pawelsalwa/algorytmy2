#include<iostream>
#include<list>
#include<vector>
 
using namespace std;

class Graph
{
    int v;
    
    vector< vector <int> > edges;
    vector<int> kolor;
    vector<int> tmp;
	    
public:
	bool cykliczny;
	//===========================================
    Graph(int v)
	{
	    this->v = v;
	    this->cykliczny = false;
	    for(int i =0; i< v; i++){
	    	kolor.push_back(0);
		}
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
	void DFS()
	{
		for(int i =0; i< v; i++){
			if (kolor[i] == 0 || kolor[i] == 1){
				cout<< "odwiedzam : " << i << endl;
				visit(i);
				kolor[i] = 2;	
			}
		}		
	}
	//===========================================
	void visit(int u){
		
		kolor[u] = 1;
		
		for(int i =0; i< v; i++){
				if( edges[i][0] == u && kolor[ edges[i][1] ] == 0 ){
					cout<< "ide dalej do  : " << edges[i][1] << endl;
					visit( edges[i][1] );
					kolor[ edges[i][1] ] = 2;
				}
				if( edges[i][0] == u && kolor[ edges[i][1] ] == 1 ){
					cout<< "znalazlem cykl przy krawedzi: " << edges[i][0]<<" -> " << edges[i][1] << endl;
					this->cykliczny = true;
				}
		}
			
	}
};

//=========================================================================
int main()
{
	int x,y;
    cout <<"ile wierzcholkow?" << endl;
    cin >> x;
    cout <<"ile krawedzi?" << endl;
    cin >> y;
    int a,b;
    Graph G(x);
    
    for(int i=1; i<= y; i++){
    	cout <<"podaj krawedz skierowana nr: " << i<< endl;
    	cin >> a;
    	cin >> b;
    	G.addEdge(a, b);
    }
 
    cout << "=============zaczynamy============="<< endl;
    G.DFS();
    if (G.cykliczny)
 		cout << "\nGraf okazuje sie byc grafem cyklicznym"<< endl;
    else
    	cout << "\nGraf okazuje sie byc grafem acyklicznym"<< endl;
	return 0;
}

































