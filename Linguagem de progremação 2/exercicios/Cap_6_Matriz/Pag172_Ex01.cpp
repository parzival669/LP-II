#include<stdio.h>
#include<locale.h>

#define MAX 2

int main(){
	
	int A[MAX][MAX], R[MAX][MAX];
	int i, j, maior;	
	
		setlocale(LC_ALL,"Portuguese");
		
		printf("* VALOR DA MATRIZ *\n");
		
		for (i=0 ; i<MAX ; i++){
			for (j=0; j<MAX; j++){
				printf("\nA %d-%d :", i, j);
				scanf("%d",&A[i][j]);
			}
		}
		
		maior = A[0][0];
		for (i=0 ; i<MAX-1 ; i++){
			for (j=0; j<MAX; j++){
				if (A[i][j] > maior){
					maior = A[i][j];
				}
			}
		}
		
		for (i=0 ; i<MAX ; i++){
			for (j=0; j<MAX; j++){
				R[i][j] = maior * A[i][j];
				printf ("\nA %d-%d: %d", i, j, R[i][j]);
			}
		}
		
		printf ("\nO maior valor da matriz :%d", maior);
		
}	
