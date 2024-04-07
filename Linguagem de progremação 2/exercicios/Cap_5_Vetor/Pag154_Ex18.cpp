#include<stdio.h>
#include<locale.h>
#define MAX 8
#define MAX2 6
int main(){
	
	int dado[MAX],freq[MAX2];
	int i;	
		setlocale(LC_ALL,"Portuguese");
		
		printf("* VALORES DO DADO *\n");
		
		for (i=0 ; i<MAX ; i++){
			printf("\n %d:",i+1);
			scanf("%d",&dado[i]);
		}
		
		for (i=0 ; i<6 ; i++) freq[i]=0;
		
		for (i=0 ; i<MAX ; i++){
			freq[dado[i]-1]++;
		}
		
		for (i=0 ; i<6 ; i++){
			printf("\n %d: %d",i+1,freq[i]);
		}
}
		
		
