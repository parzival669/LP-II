#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

#define LMAX  4
#define PMAX  2

int main(){
	
	char loja[LMAX][10], prod[PMAX][10];
	int i, j;
	float preco[LMAX][PMAX];
	
	setlocale(LC_ALL,"");
	printf("*** LISTA DE LOJAS ***\n");
	for(i=0; i<LMAX; i++){
		printf("\n==> Loja %d: ",i+1);
		scanf("%s",&loja[i]);
	}
	
	printf("\n\n*** LISTA DE PRODUTOS ***\n");
	for(i=0; i<PMAX; i++){
		printf("\n==> Produto %d: ",i+1);
		scanf("%s",&prod[i]);
	}
	
	system("CLS");
	printf("*** LISTA DE LOJAS/PRODUTOS ***\n");
	for(i=0; i<LMAX; i++){
		printf("\n==> Loja: %s\n",loja[i]);
		for(j=0; j<PMAX; j++){
			printf("Preço do produto %s: ",prod[j]);
			scanf("%f",&preco[i][j]);
		}
	}
	
	system("CLS");
	printf("*** LISTA DE LOJAS/PRODUTOS NÃO SUPERIOR A R$120,00***\n");
	for(i=0; i<LMAX; i++){
		for(j=0; j<PMAX; j++){
			if(preco[i][j]<=120){
				printf("\nProduto %s / ",prod[j]);
				printf("Loja %s / ",loja[i]);
				printf("Preço: %.2f",preco[i][j]);
			}
		}
	}
	return 0;
}
