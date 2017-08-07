#include<iostream>
#include<list>
#include<vector>
#include<stack>
#include<set>
 
using namespace std;

class Graph
{
    int v;
    
    vector< vector <int> > edges;
    vector<int> kolor;
    vector<int> tmp;
    vector<int> distance;
    vector<bool> visited;
    
	    
public:
	stack<int> s;
	set<int> nodes;
	bool cykliczny;
	//===========================================
    Graph(int v)
	{
	    this->v = v;
	    this->cykliczny = false;
	    for(int i =0; i< v; i++){
	    	kolor.push_back(0);
	    	visited.push_back(false);
	    	distance.push_back(100);
	    	nodes.insert(i); 
		}
	}
	//===========================================
    void addEdge(int a, int b, int c)
	{
		
		tmp.push_back(a);
		tmp.push_back(b);
		tmp.push_back(c);
	    edges.push_back(tmp);
	    tmp.pop_back();
		tmp.pop_back();
		tmp.pop_back();
	}
	//===========================================
	void dijkstra(int start, int end)
	{
		distance[start] = 0;
		int u = start;
		visited[start] = true;
		int tmpMin=100;
		int odwiedzonych =0;
	

		while( odwiedzonych < v){
			cout<<"1\n";
			tmpMin =100;
			int tmpNextNode;
			for(int i =0; i<v; i++){//decyduje, ktory wierzcholek jest najblizej
				if( (edges[i][0] == u && visited[ edges [i][1] ] == false) && edges[i][2]< tmpMin ){
					tmpMin = edges[i][2];
					tmpNextNode = edges[i][1];
				}
			}
			cout<<"3\n";
			cout<<"4\n";
			for(int i =0; i<v; i++){
				if( edges[i][0] == u && visited[ edges[i][1] ] == false && edges[i][2] == tmpMin ){
					
					cout<< "odwiedzam : " << i << endl;
					if( distance[u] + edges[i][2] < distance[ edges[i][1] ]  ){
						distance[ edges[i][1] ] = distance[u] + edges[i][2];
						visited[ edges[i][1] ] = true;
						odwiedzonych ++;
					}
					kolor[i] = 2;	
				}
			}			
		}		
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
	//===========================================
	void topologicalSort(){
		for(int i =0; i< v; i++){
	    	kolor[i] = 0;
		}
		
		for(int i =0; i< v; i++){
	    	if( kolor[i] == 0 ){
				tVisit(i);
				kolor[i] == 2;
			}
		}
	}
	//===========================================
	void tVisit(int u){
		kolor[u] = 1;
		for(int i =0; i< v; i++){
			if( edges[i][0] == u && kolor[ edges[i][1] ] == 0 ){
				tVisit( edges[i][1] );
				kolor[ edges[i][1] ] = 2;
				
			}
			
		}
		//przeszlo przez petle i nie znalazlo dzieci lub znalazlo odwiedzone dzieci wiec dodajemy do stosu
		s.push(u);
		kolor[u] = 2;
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
    int a,b,c;
    Graph G(x);
    
    for(int i=1; i<= y; i++){
    	cout <<"podaj krawedz skierowana nr: " << i<< endl;
    	cin >> a;
    	cin >> b;
    	cout <<"podaj wage krawedzi skierowanej nr: " << i<< endl;
    	cin >> c;
    	G.addEdge(a, b,c);
    }
 
    cout << "=============zaczynamy zad 7============="<< endl;

	G.dijkstra(0,x-1);

	cout<<"koniec"<< endl;
    	
	return 0;
}

































