#include<iostream>
#define maxn 1000
#define maxf 1000000000
#include<fstream>
using namespace std;
int a[maxn][maxn], n, m,s,e;
int f[maxn], trace[maxn], checkt2[maxn];

void readfile(){
	fstream file("txtDijkstra.txt", ios::in);
	file >> n >>m;
	file >> s >>e;
	for(int i =1; i<=n; i++)
		for(int j = 1; j<=n; j++)
			a[i][j] = -1;
	for(int i = 1; i<=m; i++)
	{
		int u, v;
		file>>u>>v;
		file>>a[u][v];
		a[v][u] = a[u][v];
		
	}
	file.close();
}
void dijkstra(){
	for(int i =1; i<=n; i++){
		f[i] = maxf;
		checkt2[i] = true;
	}
	f[s] = 0;
	int v = s, fmin;
	while(v!=e){
		fmin = maxf;
		for(int i =1;i <=n; i++){
			if(checkt2[i] && fmin > f[i]){
				fmin = f[i];
				v = i;
			}
		}
		cout<< v << " ";
		// kiem tra dinh cuoi cung
		if(fmin == maxf) break;
		// xoa dinh v ra khoi t2
		checkt2[v] = false;
		for(int i =1 ; i<=n; i++){
			if(a[v][i] > 0 && f[i]>f[v]+a[v][i] ){
				f[i] = f[v]+a[v][i];
				trace[i] = v;
			}	
		} 
	
	}
}
void output(){
	cout<<"\n";
	cout<<f[e];
}
int main(){
	readfile();
	dijkstra();
	output();
}
