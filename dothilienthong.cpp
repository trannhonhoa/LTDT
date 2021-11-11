#include<iostream>
#include<fstream>
#include<queue>
using namespace std;
int n, matrix[1001][1001];
bool visited[1001];
void init(){
	ifstream file("lienthong.txt", ios::in);
	file >> n;
	for(int i = 1;i <=n; i++){
		for(int j = 1; j<=n; j++){
			file >> matrix[i][j];
		}
		visited[i] = false;
	}
}
void XuatMang(){
	for(int i = 1;i <=n; i++){
		for(int j = 1; j<=n; j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<"\n";
	}
}
void BFS (int u){
	cout<<"\nBFS("<<u<<"):";
	queue<int > Q;
	Q.push(u);
	visited[u] = true;
	while(!Q.empty()){
		int s = Q.front();
		cout<< s << " ";
		Q.pop();
		for(int t = 1; t<=n; t++){
			if(visited[t] == false && matrix[s][t] == 1){
				Q.push(t);
				visited[t] = true;
			}
		}
	}
}
void TPLT(){
	int slt = 0;
	for(int v =1; v<=n; v++){
	
		if(visited[v] == false){
			BFS(v);
			slt++;
		}
	}
	cout<<"\nSLT: "<<slt;
}
int main(){
	init();
	XuatMang();
	TPLT();
	return 0;
}
