#include <stdio.h>
#include <locale.h>

int main(){
	
	int t;
	printf ("Tamanho da matriz: ");
	scanf ("%d",&t);
	
	int M[t][t], i, j, ant;
	
	ant = 0;
	for (i=0; i<t; i++){
		if(ant != 0){
			ant = ant -8;
		}
		for(j=0; j<t; j++){
			M[i][j] = ant + 2;
			ant = M[i][j];
		}
	}
	
		for (i=0; i<t; i++){
		for(j=0; j<t; j++){
			printf ("%d\t", M[i][j]);
		}
		printf ("\n");
	}
}
