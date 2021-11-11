#include<iostream>
#include<fstream>
#include<queue>
using namespace std;
int n;
int matrix[1001][1001];
bool visited[1001];
void Init(){
	ifstream file("matrix.txt", ios::in);
	file >> n;
	for(int i =1; i<=n;i++){
		for(int j = 1; j<=n; j++)
			file >> matrix[i][j];
		visited[i] == false;
	}		
}
int BFS (int u){
	int count = 0;
	queue<int > Q;
	Q.push(u);
	visited[u] = true;
	while(!Q.empty()){
		int s = Q.front();
		count++;
		Q.pop();
		for(int t = 1; t<=n; t++){
			if(visited[t] == false && matrix[s][t] == 1){
				Q.push(t);
				visited[t] = true;
			}
		}
	}
	return count;
}
void reinit(){
	for(int v =	1; v<=n; v++){
		visited[v] = false;
	}
}
bool isStrongConnection(){
	for(int v = 1; v<=n; v++){
		if(BFS(v) != n){
			return false; break;
		}
		reinit();
	}
	return true;
}
int main(){
	int u;
	Init();
	if(isStrongConnection() == true){
		cout<<"The Graph is strong connection";
	}
	else{
		cout<<"The Graph is weak connection";
	}
	return 0;
}
