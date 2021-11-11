#include<iostream>
#include<fstream>
#define MAX 100
using namespace std;
void docDoThi(int A[][MAX], int &n){
	fstream file("ToMau.txt", ios::in);
	file >> n;
	for(int i  = 1; i<=n; i++){
		for(int j = 1; j<=n ; j++){
			file >> A[i][j];
		}
	}
	file.close();
}
void XuatFile(int A[][MAX], int n){
	for(int i  = 1; i<=n; i++){
		for(int j = 1; j<=n ; j++){
			cout<<A[i][j]<<" ";
		}
		cout<<"\n";
	}
}
void XuatMau(int A[], int n){
	for(int i =1; i<=n; i++){
		cout<<A[i]<<" ";
	}
}

void ToMau(int A[][MAX], int n, int MAU[]){
	int BangMau[MAX][MAX] = {0};
	int mauvuato;
	for(int i = 1; i<=n ; i++){
		for(int k = 1; k<=n; k++ ){
			if(BangMau[i][k] == 0){
				MAU[i] = k;
				mauvuato = k;
				break;
			}
			
		}
		
		for(int j =1; j<=n; j++){
			if(A[i][j] > 0)
				BangMau[j][mauvuato] = 1;
		}
		
	}	
}
int main(){
	int A[MAX][MAX], n, MAU[MAX];
	docDoThi(A, n);
	XuatFile(A, n);
	ToMau(A, n , MAU);	
	cout<<"\nTo mau tu dinh 1: \n";
	XuatMau(MAU, n);
}
