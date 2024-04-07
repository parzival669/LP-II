#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

#define MAX 5

struct str_aluno{
	char nome[10];
	int ra, falta;
	float media;
};

typedef struct str_aluno aluno;
	
int main(){
	
	int i;
	aluno reg[MAX];
	
	setlocale(LC_ALL, "Portuguese");

	printf("** Dados do aluno **\n");
	for(i=0; i<MAX; i++){
		printf("Nome : ");
		scanf("%s", &reg[i].nome);
		printf("\nRA : ");
		scanf("%d", &reg[i].ra);
		printf("\nMedia : ");
		scanf("%f", &reg[i].media);
		printf("\nFaltas : ");
		scanf("%d", &reg[i].falta);
	}
}
			
	
