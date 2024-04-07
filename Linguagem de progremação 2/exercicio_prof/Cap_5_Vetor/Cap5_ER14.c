#include<stdio.h>
#include<string.h>
#include<locale.h>

#define MAX1 5
#define DIST 1000

int main(){
	char nome[MAX1][10];
	float sal[MAX1], nsal[MAX1];
	int tempo[MAX1];
	int i;
	
	setlocale(LC_ALL,"");
	printf("*** DADOS DOS FUNCIONÁRIOS ***\n");
	for(i=0; i<MAX1; i++){
		printf("Nome............: "); 
		scanf("%s",&nome[i]);
		printf("Salário.........: "); 
		scanf("%f",&sal[i]);
		printf("Tempo na empresa: ");
		scanf("%d",&tempo[i]);
		printf("\n");
		
		if(tempo[i]>5 && sal[i]<200){
			nsal[i] = sal[i]*1.35;
		} 
		else{
			if(tempo[i]>5){
				nsal[i] = sal[i]*1.25;
			} 
		    else{
		    	if(sal[i]<200){
		    		nsal[i] = sal[i]*1.15;
				}
				else{
					nsal[i] = sal[i];
				}
			}
		}        	 
	}
	
	system("CLS");
	printf("*** FUNCIONÁRIOS SEM AUMENTO ***\n");
	for(i=0; i<MAX1; i++){
		if(tempo[i]<=5 && sal[i]>=200){
			printf("Nome: %s\n",nome[i]);	
		}
	}
	
	printf("\n*** FUNCIONÁRIOS COM AUMENTO ***\n");
	for(i=0; i<MAX1; i++){
		if(sal[i]!=nsal[i]){
			printf("Nome: %s\n",nome[i]);
			printf("Salário: %.2f",nsal[i]);
			printf("\n");
		}
	}
	
	return 0;	
}
