/*
Faça um programa que realize o cadastro de contas bancárias
com as seguintes informações: 
- número da conta, nome do cliente e saldo. 
O banco permitirá o cadastramento de apenas 15 contas e não 
poderá haver mais que uma conta com o mesmo número. 
Crie o menu de opções a seguir.
Menu de opções:
1. Cadastrar contas.
2. Visualizar todas as contas de determinado cliente.
3. Excluir a conta com menor saldo (supondo a não existência de saldos iguais).
4. Sair.
*/
#include <stdio.h>
#include <locale.h>

#define TAM 15

struct str_conta{
	int num;
	float saldo;
	char cliente[20];
};

typedef struct str_conta conta;

int menu(){
	int op;
	
	setlocale(LC_ALL,"");
	system("CLS");
	printf("1. Cadastrar contas.\n");
    printf("2. Visualizar todas as contas de determinado cliente.\n");
	printf("3. Excluir a conta com menor saldo.\n");
	printf("4. Sair.\n\n");
	printf("Sua opção: ");
	scanf("%d",&op);

	return op;
}

conta cadastro(){
	conta reg;
	
	system("CLS");
	printf("Digite os dados da conta.\n");
	printf("Nome do cliente: ");
	scanf("%s",&reg.cliente);
	printf("Número da conta: ");
	scanf("%d",&reg.num);
	printf("Saldo: ");
	scanf("%f",&reg.saldo);
	
	return reg;
}

void consulta(int tot,conta reg[]){
	char nome[20];
	int i;
	
	system("CLS");
	printf("Nome do cliente: ");
	scanf("%s",&nome);
	
	for(i=0; i<tot; i++){
		if(strcmp(nome,reg[i].cliente)==0){
			printf("Conta: %d",reg[i].num);
			printf("\tSaldo: %.2f\n",reg[i].saldo);
		}
	}
}

int excluir(int tot,conta reg[]){
	int i, im;
	float menor;
	
	im=0;
	menor = reg[im].saldo;
	for(i=1; i<tot; i++){
		if(reg[i].saldo<menor){
			menor = reg[i].saldo;
			im = i;
		}
	}
	
	for(i=im; i<tot-1; i++){
		reg[i] = reg[i+1];
	}
	
	printf("Registro excluído com sucesso.\n")
	return --tot;
}
int main(){
	
	int op, tot=0;
	conta reg[TAM];
	
	do{
		op = menu();
		switch(op){
			case 1:
				if(tot<TAM){
					reg[tot] = cadastro();
					tot++;
					printf("Registro cadastrado com sucesso.\n");
				}
				else
					printf("Memória está cheia!\n");
				system("PAUSE");
				break;
			case 2:
				consulta(tot,reg);
				system("PAUSE");
				break;
			case 3:
				if(tot!=0){
					tot = excluir(tot,reg);
				}
				break;
		}
	}while(op!=4);
	
	return 0;
}
