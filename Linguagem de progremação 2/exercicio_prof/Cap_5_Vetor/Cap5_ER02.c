#include<stdio.h>

#define MAX 10

int main(){
	
	int qp[MAX], qt = 0;
	float pr[MAX], tv[MAX];
	int i, j, cont;
	
	printf("*** Quantidade de pecas por vendedor ***\n");
	for(i=0; i<MAX; i++){
		printf("Vendedor %d: ",i+1);
		scanf("%d",&qp[i]);
	}
	
	printf("*** Precod e cada peca ***\n");
	for(i=0; i<MAX; i++){
		printf("Preco da peca %d: ",i+1);
		scanf("%f",&pr[i]);
	}
	
	qt = 0;
	for(i=0; i<MAX; i++) qt += qp[i];
	
	for(i=0; i<MAX; i++){
		tv[i] = qp[i]*pr[i];	
	} 
	
	printf("*** RESULTADOS ***");
	for(i=0; i<MAX; i++){
		printf("Total do vendedor %d: %.2f\n",i+1,tv[i]);
	}
	printf("\nTotal de vendas: %d",qt);	

	return 0;
}
