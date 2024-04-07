#include<stdio.h>
#include<locale.h>

#define MAX 4 // i linha aluno
#define MAX1 2 // j coluna prova

int main(){
	
	int menor[MAX], p_menor[MAX], aluno[MAX][MAX1], i, j, qt[MAX1] = {0};
	
		setlocale(LC_ALL,"Portuguese");
		
		printf("* NOTAS DO ALUNO *\n");
		
		for (i=0 ; i<MAX ; i++){
			for (j=0; j<MAX1; j++){
				printf("\nAluno %d - Prova %d :", i+1, j+1);
				scanf("%d",&aluno[i][j]);
			}
		}
		
		for (i=0 ; i<MAX; i++){
			menor[i] = aluno[i][0];
			p_menor[i] = 0;
			for (j=0; j<MAX1; j++){
				if (aluno[i][j] < menor[i]){
					menor[i] = aluno[i][j];
					p_menor[i] = j;
				}
			}
			printf("\nMenor nota do aluno %d :%d %d", i+1, menor[i], p_menor[i]);
		}
		
		for (i=0 ; i<MAX; i++){
			qt[p_menor[i]]++;
		}
		
		for (i=0 ; i<MAX1; i++){
		printf("\nProva %d:%d\n", i+1, qt[i] );
		}
	}
