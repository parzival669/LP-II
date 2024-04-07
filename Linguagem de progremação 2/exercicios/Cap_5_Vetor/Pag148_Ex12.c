#include<stdio.h>
#include<locale.h>
#define MAX 5

int main(){
	
	float km1[MAX],km2[MAX],mil[MAX];
	char c[MAX][10];
	int i,j,car[MAX];
		
		setlocale(LC_ALL,"Portuguese");
		printf("* MODELOS DOS CARROS *\n");
		for (i=0 ; i<MAX ; i++){
			printf("\n %d:",i+1);
			scanf("%s",&c[i]);
		}
		
		printf("\n *KM POR LITRO *\n");
		for (i=0 ; i<MAX ; i++){
			printf("\n %d:",i+1);
			scanf("%f",&km1[i]);
			km2[i]=km1[i];
		}
		
		for (i=0 ; i<MAX-1 ; i++){
			for (j=i+1 ; j<MAX ; j++){
				if (km1[i]<km1[j]){
				
				km1[i]=km1[j];
				car[i]= j;
				}
			}
		}
		printf("\n CARRO MAIS ECONÔMICO: %s",c[car[0]]);
		
		printf("\n *LITROS CONSUMIDOS EM 1000 KM *\n");
		
		for (i=0 ; i<MAX ; i++){
			mil[i] = km2[i] * 1000;
			printf("\n %s : %.2f",c[i],mil[i]);
		}
		
		
