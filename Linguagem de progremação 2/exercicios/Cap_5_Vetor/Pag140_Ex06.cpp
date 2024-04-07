#include<stdio.h>
#include<locale.h>
#define MAX 10

int main(){
	
	int V[MAX], j, i, aux;

	
	for(i=0; i<MAX; i++){
		printf("\nValor %d: ",i+1);
		scanf("%d",&V[i]);
	}
		
	for(i=0; i<MAX; i++){
		for(j=i+1; j<MAX; j++){
			if(V[i] < V[j]){
				
				int aux = V[i];
				V[i] = V[j];
				V[j] = aux;
			}
		}
	}
	
		for(i=0; i<MAX; i++){
		printf("\nOrdem decrescente : %d ", V[i]);
}
}

