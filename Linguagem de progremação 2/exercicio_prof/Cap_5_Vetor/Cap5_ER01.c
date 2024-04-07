#include<stdio.h>

#define MAX 9

int main(){
	
	int num[MAX];
	int i, j, cont;
	
	for(i=0; i<MAX; i++){
		printf("Numero %d: ",i+1);
		scanf("%d",&num[i]);
	}
	printf("\n");
	for(i=0; i<MAX; i++){
		cont = 0;
		for(j=1; j<=num[i]; j++){
			if(num[i]%j==0) cont++;
		}
		if(cont==2){
			printf("\nNumero %d eh primo.",num[i]);
			printf("\nPosicao: %d",i);
		}
	}	

	return 0;
}
