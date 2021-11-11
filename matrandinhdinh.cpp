#include<stdio.h>
#define MAX_Vetices 20

typedef struct{
	int A[MAX_Vetices][MAX_Vetices];
	int n; // so luong dinh
}Graph;
void inti_Graph(Graph *G, int n){
	int i,j;
	G->n = n;
	for(i = 1; i<= G->n; i++ ){
		for(j=1; j<= G->n; j++){
			G->A[i][j] = 0;
		}
	}
}
void add_edge(Graph *G, int x, int y){
	G->A[x][y] = 1;
	G->A[y][x] = 1;	
}
int adjacent(Graph *G, int x, int y){
	return (G->A[x][y] != 0);
}
// tinh bac do thi
int degree(Graph *G, int x){
	int deg = 0, i;
	for(i = 1; i<=G->n; i++)
		if(G->A[i][x] == 1)
			deg++;
	return deg;
}
int element_at(List *list, int i){
	
}
int main(){
	Graph G;
	inti_Graph(&G, 6);
	add_edge(&G,2,6);
	add_edge(&G,6,4);
	add_edge(&G,5,6);
	add_edge(&G,1,5);
	add_edge(&G,2,3);
	printf("%d\n", G.n);

	return 0;
}
