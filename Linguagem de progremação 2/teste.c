#include <stdio.h>
#include <locale.h>

int main(){
	
	int t;
	printf ("Tamanho da matriz: ");
	scanf ("%d",&t);
	
	int M[t][t], i, j, m;
	
	m=(t-1)/2;
	for (i=0; i<t; i++){
		for(j=0; j<t; j++){
			M[i][j] = 0;
			if(i==0 || j==0 || i==t-1 || j==t-1){
				M[i][j] = 1;
			}
			if(i==m && j==m){
				M[i][j] = t;
			}
		}
	}
	
		for (i=0; i<t; i++){
		for(j=0; j<t; j++){
			printf ("%d\t", M[i][j]);
		}
		printf ("\n");
	}
}
