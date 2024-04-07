#include<stdio.h>

#define LMAX 3
#define CMAX 4 

int main(){
	
	int a[LMAX][CMAX];
	int i, j, maior;
	
	printf("*** Valores da matriz ***\n");
	for(i=0; i<LMAX; i++){
		for(j=0; j<CMAX; j++){
			printf("A[%d][%d] = ",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	
	maior = a[0][0];
	for(i=0; i<LMAX; i++){
		for(j=0; j<CMAX; j++){
			if(maior<a[i][j]) maior = a[i][j]; 
		}
	}
	printf("\n\n => MAIOR VALOR: %d\n\n",maior);
	
	printf("*** Matriz Resultante ***\n");
	for(i=0; i<LMAX; i++){
		for(j=0; j<CMAX; j++){
			a[i][j] = maior*a[i][j];
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
		
	return 0;
}
