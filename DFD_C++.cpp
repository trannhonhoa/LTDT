#include<iostream>
#include<fstream>
#include<stack>
using namespace std;
int n;
int maxtrix[1001][1001];
bool visited[1001];
void Init(){
	ifstream file("matrix.txt", ios::in);
	file >> n;
	for(int i =1;i<=n; i++){
		for(int j =1; j<=n;j++){
			file >> maxtrix[i][j];
		}
		visited[i] = false;
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
			if(visited[t] == false && maxtrix[v][t] == 1){
				cout << t << " ";
				visited[t] = true;
				st.push(v);
				st.push(t);
				break;
			}
		}
	}
}

int main(){
	int s;
	Init();
	cout<<"Chon dinh bat dau: ";
	cin >> s;
	DFS(s);
	return 0;
}

