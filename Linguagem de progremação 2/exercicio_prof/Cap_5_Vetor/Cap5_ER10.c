#include<stdio.h>
#include<locale.h>

#define MAX1  10
#define MAX2   2

int main(){
	char gab[MAX1];
	int aluno[MAX2], nota[MAX2];
	char resp[MAX2][MAX1]; 
	int i, j, aprovado=0;
		
	setlocale(LC_ALL,"");
	printf("*** GABARITO DA PROVA ***\n");
	printf("*** RESPOSTAS: A, B, C, D ou E\n");
	for(i=0; i<MAX1; i++){
		printf("Questão %d: ",i+1);
		scanf("%s",&gab[i]);
		gab[i] = toupper(gab[i]);
	}
	
	printf("*** RESPOSTAS DOS ALUNOS ***\n");
	for(i=0; i<MAX2; i++){
		system("CLS");
		printf("Aluno %d: ",i+1);
		scanf("%d",&aluno[i]);
		for(j=0; j<MAX1; j++){
			printf("Questão %d: ",j+1);
			scanf("%s",&resp[i][j]);
			resp[i][j] = toupper(resp[i][j]);
		}
	}
	
	for(i=0; i<MAX2; i++){
		nota[i]=0;
		for(j=0; j<MAX1; j++){
			if(gab[j]==resp[i][j]){
				nota[i]++;
			}
		}
		printf("\nNota do aluno: %d",nota[i]);
	}
	
	for(i=0; i<MAX2; i++){
		if(nota[i]>=6) aprovado++;
	}
	
	printf("\nPercentual de aprovados: %.1f",(100.*aprovado)/MAX2);
	return 0;
}
