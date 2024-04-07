#include<stdio.h>
#include<string.h>
#include<locale.h>

#define MAX1 5
#define DIST 1000

int main(){
	char modelo[MAX1][10];
	float consumo[MAX1], mais_economico=-1;
	float litro[MAX1];
	int i;
	char economico[10];
	
	setlocale(LC_ALL,"");
	printf("*** DADOS DOS VEÍCULOS ***\n");
	for(i=0; i<MAX1; i++){
		printf("\nModelo...........: "); 
		scanf("%s",&modelo[i]);
		
		printf("Consumo...........: "); 
		scanf("%f",&consumo[i]);
		
		litro[i] = DIST/consumo[i];
		printf("Litros para 1000km: %.1f\n",litro[i]);
	}
	
	for(i=0; i<MAX1; i++){
		if(mais_economico < consumo[i]){
			mais_economico = consumo[i];
			strcpy(economico,modelo[i]);
		}
	}
	
	printf("\nModelo mais economico: %s",economico);
	
	
	
	
}
