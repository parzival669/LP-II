#include<stdio.h>

#define MAX 10

int main(){
	
	int a[MAX], b[MAX], c[2*MAX];
	int i, j;
	
	printf("*** Primeiro vetor ***\n");
	for(i=0; i<MAX; i++){
		printf("Posicao %d: ",i);
		scanf("%d",&a[i]);
	}
	
	printf("*** Segundo vetor ***\n");
	for(i=0; i<MAX; i++){
		printf("Posicao %d: ",i);
		scanf("%d",&b[i]);
	}
	
	j = 0;
	for(i=0; i<2*MAX; i+=2){
		c[i] = a[j];
		j++;	
	} 
	j = 0;
	for(i=1; i<2*MAX; i+=2){
		c[i] = b[j];
		j++;	
	}
	
	for(i=0; i<2*MAX; i++){
		printf("%d ",c[i]);	
	}
	return 0;
}
