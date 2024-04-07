#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

#define MAX 8 // V nome das lojas
#define MAX1 4 // V nome dos produtos

int main(){
	

	char loja[MAX][10], produto[MAX1][10];
	int i, j;
	float preco[MAX][MAX1];	
	
		setlocale(LC_ALL,"Portuguese");
		
		printf("* LISTA DE LOJAS *\n");
		for (i=0 ; i<MAX ; i++){
			printf("\nLoja [%d] :", i+1);
			scanf("%s",&loja[i]);
		}

		printf("\n* LISTA DE PRODUTOS *\n");
			for (j=0; j<MAX1; j++){
			printf("\nProdutos [%d] :", j+1);
			scanf("%s",&produto[j]);
		}

		system("CLS");
		printf("\n* LISTA DE LOJAS/PRODUTOS *");
		for (i=0 ; i<MAX ; i++){
			printf("\n\nLoja :%s\n", loja[i]);
			for (j=0; j<MAX1; j++){
				printf("\nPreço [%d] :", j+1);
				scanf("%f",&preco[i][j]);
			}
			printf("\n--------------------------------------------");
		}
		
		system("CLS");
		printf("\n* LISTA DE LOJAS/PRODUTOS NÃO SUPERIOR A R$120,00 *\n");
		for (i=0 ; i<MAX ; i++){
			for (j=0; j<MAX1; j++){
				if (preco[i][j] <= 120){
				printf ("\nLoja :%s - ", loja[i]);
				printf ("Produto :%s - ", produto[j]);
				printf ("Preço :%.2f\n", preco[i][j]);
				}
			}

		}
		return 0;				
	}	
