#include<iostream>
#define N 21
using namespace std;

int n, p[N], b[N], d = 0;

void Init(){
	cout<<"\nNhap vao n: "; cin >> n;
	for(int i = 0; i<=n; i++){
		b[i] = 1;
	}	
}
void Process(){
	d++;
	cout<<"\nHoan vi thu "<<d<<endl;
	for(int i = 1; i<=n; i++){
		cout<<p[i]<<" ";
	}	
}
void HoanVi(int k){
	for(int j = 1; j <=n; j++){
		if(b[j]){
			p[k] = j;
			b[j] = 0;
			cout<<" - "<<p[k]<<" = "<< j << " -";
			if(k  == n ) Process();
			else HoanVi(k +1);
			b[j] = 1;
		}
	}	
}
int main(){
	cout<<"\nHello Word";
	Init();
	HoanVi(1);
	return 0;
}
