#include<stdio.h>

#define LMAX  3
#define CMAX  3

int main(){
	
	float notas[LMAX][CMAX], no_menor[LMAX];
	int i, j, pr_menor[LMAX], qt_menor[CMAX]={0};
	
	printf("*** NOTAS DOS ALUNOS ***\n");
	for(i=0; i<LMAX; i++){
		printf("\n==> Aluno: %d\n",i+1);
		for(j=0; j<CMAX; j++){
			printf("Nota %d = ",j+1);
			scanf("%f",&notas[i][j]);
		}
		if(notas[i][0]<notas[i][1] &&
		   notas[i][0]<notas[i][2]){
		      no_menor[i] = notas[i][0];
		      pr_menor[i] = 1;
		}
		else if(notas[i][1]<notas[i][2]){
		      	no_menor[i] = notas[i][1];
		      	pr_menor[i] = 2;
			 }
			 else{
			 	no_menor[i] = notas[i][2];
		      	pr_menor[i] = 3;
			 }
			 qt_menor[pr_menor[i]-1]++;
	}
	
	printf("*** RELATÓRIO DE MENORES NOTAS ***\n");
	for(i=0; i<LMAX; i++){
		printf("\n==> Aluno: %d\n",i+1);
		printf("Menor nota: %.1f\n",no_menor[i]);
		printf("Prova: %d",pr_menor[i]);
	}
	
	printf("\n\n*** RESUMO DE PROVAS***\n");
	for(i=0; i<CMAX; i++){
		printf("\n==> Prova %d = %d",i+1,qt_menor[i]);
	}
	
	return 0;
}
