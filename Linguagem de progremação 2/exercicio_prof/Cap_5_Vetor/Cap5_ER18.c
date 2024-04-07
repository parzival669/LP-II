#include<stdio.h>
#include<string.h>
#include<locale.h>
#include<stdlib.h>

#define MAX_JOG 20

int main(){
	int num[MAX_JOG];
	float freq[6];
	int cont[6];
	int i;
	
	setlocale(LC_ALL,"");
	
	for(i=0; i<6; i++) cont[i]=0;
	
	printf("*** SORTEIO DOS N�MEROS DO DADO ***\n");
	for(i=0; i<MAX_JOG; i++){
		printf("N�mero %2d --> ",i+1); 
		scanf("%d",&num[i]);
		#num[i] = 1+rand()%6;
		#printf("%d\n",num[i]);
		cont[num[i]-1]++;       	 
	}
	
	system("PAUSE");
	system("CLS");
	printf("*** FREQU�NCIA DOS N�MEROS ***\n");
	for(i=0; i<6; i++){
		printf("N�mero %d: ",i+1);
		printf("Frequ�ncia: %5.1f",100.*cont[i]/MAX_JOG);	
		printf("\n");
	}
	
	return 0;	
}
