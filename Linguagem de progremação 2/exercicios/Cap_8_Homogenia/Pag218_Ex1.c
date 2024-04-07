#include <stdio.h>
#include <locale.h>
#include <stdlib.h> 
#include <string.h> 
#define MAX1 2

struct str_conta {
	char nome[20];
	int CPF;
	float saldo;
};

typedef struct str_conta conta;

int menu1();
conta cadastro();
void consultar_conta(conta reg[], int, char[20]);
int excluir(int, conta reg[]);



int menu1(){
	int op;
	
	printf("..MENU..\n");
	printf("1. Cadatrar\n");
	printf("2. Visualizar todas as contas de um determinado cliente\n");
	printf("3. Exluir conta com menor saldo\n");
	printf("4. Sair");
	printf("\n");
	scanf("%d", &op);
	return op;	
}


conta cadastro(){
	
	
	conta reg;
	
	printf("Regitro da conta\n");
	printf("Nome: ");
	scanf("%s", &reg.nome);
	printf("CPF: ");
	scanf("%d", &reg.CPF);
	printf("Saldo: ");
	scanf("%f", &reg.saldo);
	printf("\n");
	
	return reg;
}




void consultar_conta(conta reg[], int total, char nome[20]){
	
	int i;

	if(strcmp(reg[i].nome, nome) == 0){
		printf("Contas registradas %s", reg[i].nome);
		printf("Saldo da conta %d", reg[i].saldo);
		
		
	}
	printf("Conta inexistente.");
	
	return; 
}


int excluir(int total, conta reg[]){
	int i, in;
	float menor;
	
	in=0;
	menor = reg[in].saldo;

	for(i=1; i<total; i++){
		if(reg[i].saldo<menor){
			menor = reg[i].saldo;
			in = i;
		}
	}	
	
	for(i=in; i<total-1; i++){
		reg[i] = reg[i+1];
	}
	
	printf("Conta excluida com sucesso.");
	
	return total--;	
	
} 


int main(){
	
int i, op, total=0;
char nome[20];	
conta reg[MAX1];

setlocale(LC_ALL, "Portuguese");

system("CLS");

op = menu1();
do{

system("CLS");

switch(op){
	
	case 1:
	
	if(total<MAX1){
		
	reg[total]=cadastro();		
	total++;
	printf("Registro concluído.");
	
	}
	
	else 
	
	printf("Limite de contas registradas atingido.\n");
	system("PAUSE");
	
	break;
	
	case 2:
		printf("Digite o nome da pessoa a ser consultada: ");
		scanf("%s", &nome);
		consultar_conta(reg, total, nome);
		
	case 3:
		
	if(total!=0){
		excluir(total, reg);
	}
		
	printf("Nenhuma conta foi registrada ainda.");	
		
		
	break;	
}





}	while (op!=3);

return 0;
}	

