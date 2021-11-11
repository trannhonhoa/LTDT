#include<iostream>
#include<fstream>
#include<queue>
#include<stack>
#define MAX 20
using namespace std;
typedef struct{
	int A[20][20];
	int n;
}Graph;
bool visited[20];
void make_false(Graph G){
	for(int i =1; i<=G.n; i++){
		visited[i] = false;
	}
}
void Init_Graph(Graph *G, int n){
	int i, j;
	G->n =n;
	for(i = 1; i<=G->n; i++){
		for(j =1; j<=G->n; j++){
			G->A[i][j] = 0;
		}
	}
		
}
void BFS(Graph G, int u){
	make_false(G);
	queue<int> Q;
	Q.push(u);
	visited[u] = true;
	while(!Q.empty()){
		int s = Q.front();
		cout<< s <<" ";
		Q.pop();
		for(int i =1; i<=G.n; i++){
			if(visited[i] == false && G.A[s][i] == 1){
				Q.push(i);
				visited[i] = true;
			}
		}
	}
}
void DFS(Graph G, int u){
	make_false(G);
	stack<int> st;
	st.push(u);
	visited[u] = true;
	cout << u << " ";
	while(!st.empty()){
		int t = st.top();
		
		st.pop();
		for(int i =1; i<=G.n; i++){
			if(visited[i] == false && G.A[t][i] == 1){
				cout<< i <<" ";
				visited[i] = true;
				st.push(t);
				st.push(i);
				break;
			}
		}
	}
}
void add_edge(Graph *G, int x, int y){
	G->A[x][y] = 1;
	G->A[y][x] = 1;
}
void Display(Graph G){
	for(int i = 1; i<=G.n; i++){
		for(int j =1; j<=G.n; j++){
			cout<<G.A[i][j]<<" "; 
		}
		cout<<"\n";
	}
		
}
int Degree(Graph G, int x){
	int deg  = 0;
	for(int i =1; i<=G.n; i++){
		if(G.A[i][x] == 1) deg++;
	}
	return deg;
}
// List NeighBors
typedef struct{
	int data[MAX];
	int n;
}List;
void Make_Null(List *list){
	list->n = 0;
}
void Push_Back(List *list, int x){
	list->data[list->n++] = x;
}
int Element_at(List list, int i){
	return list.data[i];	
}
List Neighbors(Graph G, int x){
	List list;
	Make_Null(&list);
	for(int i =1; i<=G.n; i++){
		if(G.A[x][i] == 1)
			Push_Back(&list, i);
	}
	return list;
}
// BFS

int main(){
	Graph G;
	ifstream file("file.txt", ios::in);
	int n, m;
	file >> n;
	file >> m;
	Init_Graph(&G, n);
	int i, j, u,v;
	for(i =1; i<=m; i++){
		file >> u;
		file >> v;
		add_edge(&G,u,v);
	}
	file.close();
	Display(G);
	cout<<"\n";
	for(int i =1; i<=G.n;i++){
		cout<<"Degree "<<i<<": "<<Degree(G,i)<<endl;
	}
	
	cout<<" \n----- NeighBors -----\n";
	for(int i =1; i<=G.n; i++){
		cout<<"NeighBors: "<<i<<": ";
		List list = Neighbors(G, i);
		for(int j =0; j<list.n; j++){
			cout<<Element_at(list, j) <<" ";
		}
		cout<<"\n";
	}
	
	cout<<"\n----- BFS ----- ";
	
	BFS(G, 1);
	cout<<"\n----- DFS ----- ";
	
	DFS(G, 1);
	return 0;
}
