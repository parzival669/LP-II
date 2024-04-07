#include<stdio.h>
#include<locale.h>
#define MAX 5

int main(){
	
	int V[MAX], j, i, aux;

	
	for(i=0; i<MAX; i++){
		printf("\nValor %d: ",i+1);
		scanf("%d",&V[i]);
	}
		
	for(i=0; i<MAX; i++){
		for(j=0; j<i; j++){
			if(V[i] < V[j]){
				
				aux = V[i];
				V[i] = V[j];
				V[j] = aux;
				
			}
		}
	}
	
		for(i=0; i<MAX; i++){
		printf("\nOrdem crescente : %d ", V[i]);
		
	}	
}

