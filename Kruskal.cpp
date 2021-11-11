#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct edge{
	int u,v,w;
};
int n, m, D = 0;
vector<int> parent;
vector<edge> edges; //luu tru dinh dau vao
vector<edge> T; // Tap canh cua khung

void init(){
	cout<<"Nhap vao so dinh va so canh: ";
	cin >> n >> m;
	parent.resize(n);
	edges.resize(m);
	cout<<"\nNhap vao canh va trong so tuong ung: "<<endl;
	for(edge &e: edges){
		cin >> e.u >> e.v >>e.w;
	}
}
int main(){
	
}
