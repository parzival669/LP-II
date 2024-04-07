#include<stdio.h>

#define LMAX 2
#define CMAX 2 

int main(){
	
	int a[LMAX][CMAX], b[LMAX][CMAX], c[LMAX][CMAX];
	int i, j;
	
	printf("*** Primeira da matriz ***\n");
	for(i=0; i<LMAX; i++){
		for(j=0; j<CMAX; j++){
			printf("A[%d][%d] = ",i,j);
			scanf("%d",&a[i][j]);
		}
	}  
	
	printf("*** Segunda da matriz ***\n");
	for(i=0; i<LMAX; i++){
		for(j=0; j<CMAX; j++){
			printf("B[%d][%d] = ",i,j);
			scanf("%d",&b[i][j]);
		}
	}	
	
	
	printf("\n*** Matriz Resultante ***\n");
	for(i=0; i<LMAX; i++){
		for(j=0; j<CMAX; j++){
			c[i][j] = a[i][j] + b[i][j];
			printf("%d\t",c[i][j]);
		}
		printf("\n");
	}
		
	return 0;
}
