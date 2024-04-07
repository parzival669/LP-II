#include<stdio.h>
#define MAX 4

int main(){
	
	int v1[MAX], v2[MAX], v3[2*MAX], aux
	int i, j, k, m;
	
	printf("primeiro vetor :\n");
	for(i=0; i<MAX; i++){
		printf("Numero %d: ",i+1);
		scanf("%d",&v1[i]);
		for(j=0; j<i; j++){
			if(v1[i]<v1[j]){
				aux   = v1[i];
				v1[i] = v1[j];
				v1[j] = aux; 
			}
		}
	}
	
	printf("\n\n segudo  vetor :\n");
	for(i=0; i<MAX; i++){
		printf("Numero %d: ",i+1);
		scanf("%d",&v2[i]);
		for(j=0; j<i; j++){
			if(v2[i]<v2[j]){
				aux  = v2[i];
				v2[i] = v2[j];
				v2[j] = aux; 
			}
		}
	}
	
	j = k = 0;
	for(i=0; i<2*MAX; i++){
		if(i%2==0) v3[i] = v1[j++];
		else       v3[i] = v2[k++];
		for(m=0; m<i; m++){
			if(v3[i]<v3[m]){
				aux   = v3[i];
				v3[i] = v3[m];
				v3[m] = aux; 
			}
		}
	}
	
	for(i=0; i<2*MAX; i++){
		printf("%d ",v3[i]);
	}
	
	return 0;
}
