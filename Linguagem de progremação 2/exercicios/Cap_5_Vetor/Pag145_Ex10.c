#include<stdio.h>
#include<locale.h>

#define MAX1 10
#define ALU 2 

int main(){
int gab[MAX1], resp[ALU][MAX1], num[ALU], pontos[ALU], tot_ap, j, i ;
float perc_ap;

setlocale(LC_ALL, "Portuguese");
	
	for(i=0; i<MAX1; i++){
		printf("\nDigite a resposta da questão %d: ", i+1);
		scanf("%d",&gab[i]);
	}
	
tot_ap = 0;
	for(i=0; i<ALU; i++){
		printf("\nDigite o número do %d: ", i+1, "aluno");
		scanf("%d",&num[i]);
		printf("\nResposta do aluno\n");
		for(j=0; j<MAX1; j++){
			scanf("%d",&resp[i][j]);
		}
	}
	
	for(i=0; i<ALU; i++){
		pontos[i] = 0;
		for(j=0; j<MAX1; j++){
			if(resp[i][j] == gab[j]){
				pontos[i]++;
			}
		}
		printf("\nA nota do aluno  %d: foi %d",num[i],pontos[i]);
	}
	
	for(i=0; i<ALU; i++){
		if (pontos[i] >= 6){
				tot_ap++;
		}
	}
	perc_ap = (tot_ap * 100.) / ALU;
	printf("\nO percentual de aluno aprovados é %.1f : ",perc_ap);

return 0;

}
