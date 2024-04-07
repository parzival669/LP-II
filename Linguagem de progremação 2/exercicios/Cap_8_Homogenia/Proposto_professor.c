#include <stdio.h>
#include <locale.h>
#include <stdlib.h> 
#include <string.h> 
#define MAX1 5

struct str_loja {
	int cod, qtd;
	float preco;
};

typedef struct str_loja loja;

int menu1();
loja cadastro();
void consultar_loja(loja [MAX1], int);

int menu1(){
	int op;
	system("CLS");
	
	printf("..MENU..\n");
	printf("1. Cadatrar produtos\n");
	printf("2. Consultar por codigo\n");
	printf("3. Exibir todos os produtos\n");
	printf("4. Sair\n");
	printf("\n");
	scanf("%d", &op);
	return op;	
}


loja cadastro(){
	
	
	loja reg;
	
	printf("Regitro da conta\n");
	printf("Codigo: ");
	scanf("%d", &reg.cod);
	printf("Preço: ");
	scanf("%f", &reg.preco);
	printf("Quantidade: ");
	scanf("%d", &reg.qtd);
	printf("\n");
	
	return reg;
}

void consultar_loja(loja reg[MAX1], int total){
	
	int i, cod1;
	system("CLS");
	printf ("Escreva o codigo - ");
	scanf("%d", &cod1);
	
	for(i=0; i<total; i++){
	
	if(reg[i].cod == cod1){
		system("CLS");
		printf("Codigo: %d\n", reg[i].cod);
		printf("Preço: %.2f\n", reg[i].preco);
		printf("Quantidade: %d\n", reg[i].qtd);
		system("PAUSE");
		}
	}
	return; 
}

int main(){
	
int i, op, total=0;	
loja reg[MAX1];

setlocale(LC_ALL, "Portuguese");

system("CLS");

do{
	
op = menu1();
system("CLS");

switch(op){
	
	case 1:
	
	if(total<MAX1){
		
	reg[total++]=cadastro();		
	printf("Cadastro concluído.");
	
	}
	
	else 
	
	printf("Limite de contas registradas atingido.\n");
	system("PAUSE");
	
	break;
	
	case 2:
		if (total == 0){
		printf ("Nenhum registro");	
		}
		else{
			consultar_loja(reg, total);
		}
	break;
		
	case 3:
		
	system("CLS");

	if (total == 0){
		printf ("Nenhum registro");
	}
	for (i=0;i<total;i++){
		printf("Codigo: %d", reg[i].cod);
		printf("\nPreco: %f", reg[i].preco);
		printf("\nQuantidade: %d", reg[i].qtd);
	}
			
	system("PAUSE");
}

}	while (op!=4);

return 0;
}	
