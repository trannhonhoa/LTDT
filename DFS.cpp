#include<stdio.h>
#define MAX_Vetices 20
#define MAX_LENGTH 20
#define Max_element 40
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
List neighbors(Graph *G, int x){
	List L;
	make_null(&L);
	for(int i=1; i<=G->n; i++)
		if(G->A[i][x] == 1)
			push_back(&L, i);
	return L;
}
// Stack
typedef struct{
	int data[Max_element];
	int size; 
}Stack;
void make_null_stack(Stack *stack){
	stack->size = 0;
}
// them 1 phan tu bao trong phan xep
void push_Stack(Stack * stack, int x){
	stack->data[stack->size] = x;
	stack->size++;
}
// lay mot phan tu trong stack
int top(Stack * stack){
	return stack->data[stack->size - 1];
}
void pop(Stack *stack){
	stack->size--;
}
// kiem tra stack rong
int Empty(Stack *stack){
	return stack->size == 0;
}

// DFS
void depth_first_search(Graph *G, int x){
	Stack S;
	make_null_stack(&S);
	push_Stack(&S, x);
	int mark[MAX_Vetices];
	// khoi tao cac dinh chua duoc duyet
	int i, j;
	for(i =1; i<=G->n; i++)
		mark[i] = 0;
	while(!Empty(&S)){
		int u = top(&S);
		pop(&S);
		if(mark[u] == 1)
			continue;
		printf("Duyet: %d\n", u);
		mark[u] = 1;
		List list = neighbors(G, u);
		for(i=1; i<=list.size; i++){ 
			int v = element_at(list, i);
			if(mark[v] == 0){
				push_Stack(&S, v);
			}
		}
	}
	
} 	
int main(){
	Graph G;
	FILE *file = fopen("DFS.txt","r");
	int n, m;
	fscanf(file, "%d%d", &n, &m);
	printf("%d %d", n, m);
	inti_Graph(&G, n);
	int u, v, e, i ,j;
	for(e = 1; e <= m; e++){
		fscanf(file, "%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	depth_first_search(&G, 1);
	return 0;
}
