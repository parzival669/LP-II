#include<stdio.h>

#define MAX 8

int main(){
	
	float v[MAX], aux;
	int i, j;
	
	printf("*** Digite os 10 números ***\n");
	for(i=0; i<MAX; i++){
		printf("Numero %d: ",i+1);
		scanf("%f",&v[i]);
		for(j=0; j<i; j++){
			if(v[i]<v[j]){
				aux  = v[i];
				v[i] = v[j];
				v[j] = aux; 
			}
		}
	}
	
	printf("\n*** VETOR ORDENADO ***\n");
	for(i=0; i<MAX; i++){
		printf("%.1f ",v[i]);
	}
	
	return 0;
}
