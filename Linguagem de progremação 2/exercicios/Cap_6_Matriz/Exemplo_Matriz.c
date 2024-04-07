#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

#define MAX 2
#define MAX1 2

int main(){
	
	int A[MAX][MAX1], B[MAX][MAX1], C[MAX][MAX1];
	int i, j;	
	
		setlocale(LC_ALL,"Portuguese");
		
		printf("* Primeira da matriz *\n");
		for (i=0 ; i<MAX ; i++){
			for (j=0; j<MAX1; j++){
				printf("\nA-%d: [%d][%d] :",i+1, i, j);
				scanf("%d",&A[i][j]);
			}
		}
		
		printf("\n* Segunda da matriz *\n");
		for (i=0 ; i<MAX ; i++){
			for (j=0; j<MAX1; j++){
				printf("\nB-%d: [%d][%d] :",i+1, i, j);
				scanf("%d",&B[i][j]);
			}
		}
		
		system("CLS");
		printf("\n* Matriz Resultante *\n");
		for (i=0 ; i<MAX ; i++){
			for (j=0; j<MAX1; j++){
				C[i][j] = A[i][j] + B[i][j];
				printf ("%d \t", C[i][j]);
			}
			printf ("\n");
		}
				
}	
