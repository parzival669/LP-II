#include<stdio.h>
#include<locale.h>
#define MAX 10

int main(){
	
	int V[MAX], P[MAX];
	int i, totalv=0, valor;
	
	for(i=0; i<MAX; i++){
		printf("\nPecas vendedor %d: ",i+1);
		scanf("%d",&V[i]);
		printf("\nPreco vendedor %d: ",i+1);
		scanf("%d",&P[i]);
		}
		
		for(i=0; i<MAX; i++){
		totalv+=V[i];
		}
		
		printf("\nPecas total %d : %d ",i+1,totalv);
			
		for(i=0; i<MAX; i++){
		valor = V[i] * P[i];
		printf("\nPreco vendas %d : %d ", i+1, valor);
		}


	return 0;
}
