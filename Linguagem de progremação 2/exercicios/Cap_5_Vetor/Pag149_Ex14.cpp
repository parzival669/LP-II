#include<stdio.h>
#include<locale.h>
#include<string.h>

#define MAX 5

int main(){
	
	float salario[MAX], tempo[MAX], novo_salario;
	char nome[MAX][10];
	int i;
	
	printf ("Nome dos funcionarios : \n");
	
	for (i=0; i<MAX; i++){
		printf ("\n %d:", i+1);
		scanf("%s", &nome[i]);
	}
	
	printf ("\nSalario dos funcionarios : \n");
	
	for (i=0; i<MAX; i++){
		printf ("\n %d:", i+1);
		scanf("%f", &salario[i]);
	}
	
	printf ("tempo de trabalho : \n");
	
	for (i=0; i<MAX; i++){
		printf ("\n %d:", i+1);
		scanf("%f", &tempo[i]);
	}
	
	for (i=0; i<MAX; i++){
		if (salario[i] > 200 && tempo[i] < 5){ 
			printf ("\n%s", nome[i]);
			printf ("\nSem direito a aumento\n");
		}
		
		if (salario[i] < 200 && tempo[i] > 5){
			printf ("\n%s", nome[i]);
			printf ("\nTem direito a aumento");
			novo_salario = salario[i] * 1.35;
			printf ("\nNovo salario :%.2f\n", novo_salario);
		}
		
		else{
			if (salario[i] < 200){
			printf ("\n%s", nome[i]);
			printf ("\nTem direito a aumento");
			novo_salario = salario[i] * 1.15;
			printf ("\nNovo salario :%.2f\n", novo_salario);
			}
		
		else{
			if (tempo[i] > 5){
			printf ("\n%s", nome[i]);
			printf ("\nTem direito a aumento");
			novo_salario = salario[i] * 1.25;
			printf ("\nNovo salario :%.2f\n", novo_salario);
			}	
		}
	}
}
}
	
