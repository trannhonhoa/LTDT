#include<iostream>
#include<fstream>
#include<stack>
using namespace std;
int n, matrix[1001][1001];
bool visited[1001];
int forward_point[1001];
void init(){
	ifstream file("lienthong.txt", ios::in);
	file >> n;
	for(int i = 1;i <=n; i++){
		for(int j = 1; j<=n; j++){
			file >> matrix[i][j];
		}
		visited[i] = false;
		forward_point[i] = 0;
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
void DFS(int u ){
	stack<int> st;
	st.push(u);
	visited[u] = true;
	cout << u << " ";
	while(!st.empty())
	{
		int v = st.top();
		st.pop();
		for(int t =1; t<=n; t++){
			if(visited[t] == false && matrix[v][t] == 1){
				cout << t << " ";
				forward_point[t] = v;
				visited[t] = true;
				st.push(v);
				st.push(t);
				break;
			}
		}
		
	}
}
void PrintPath(int s, int e){
	if(forward_point[e] == 0){
		cout<<"There is no path";
	}
	else
	{
		cout<<"PATH: ";
		cout<<e;
		int u = forward_point[e];
		while(u != s){
			cout<<" <- "<<u;
			u = forward_point[u];
		}
		cout<<" <- " <<s;
	}
}
int main(){
	init();
	XuatMang();
	DFS(1);
	PrintPath(1, 7);
	return 0;
}
