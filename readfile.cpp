#include<stdio.h>
#define MAX_Vetices 20
#define MAX_LENGTH 20
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
typedef struct {
	int data[MAX_LENGTH];
	int size;
}List;
void make_null(List *list){
	list->size = 0;
}
void push_back(List *list, int x){
	list->data[list->size] = x;
	list->size++;
}
int element_at(List list, int i){
	return list.data[i-1];
}
// Tim lang gieng cua dinh x
List neighbors(Graph G, int x){
	List L;
	make_null(&L);
	for(int i=1; i<=G.n; i++)
		if(G.A[i][x] == 1)
			push_back(&L, i);
	return L;
}
int main(){
	Graph G;
	FILE *file = fopen("file.txt","r");
	int n, m;
	fscanf(file, "%d%d", &n, &m);
	inti_Graph(&G, n);
	int u, v, e, i ,j;
	for(e = 1; e <= m; e++){
		fscanf(file, "%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	fclose(file);
	printf("%d\n", G.n);
	for(i=1; i<=G.n; i++){
		printf("degree(%d) = %d\n", i, degree(&G, i));
	}
	for(i=1; i<=G.n; i++){
		List list = neighbors(G, i);
		printf("Neighbors(%d): ", i);
		for(j =1; j <= list.size; j++ )
			printf("%d, ", element_at(list, j));
		printf("\n");
	}
		
	return 0;
}
