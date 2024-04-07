#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct str_clientes{
	int cod_cli;
	char nome[20], endereco[20];
};
typedef struct str_clientes clientes;

struct str_recebimentos{
	int num_doc;
	int valor_doc;
	int data_emissao;
	int data_vencimento;
	int cod_cli;
};
typedef struct str_recebimentos recebimentos;

void criar_arquivo();
int menu1();
int menu2();
void cadastro_clientes();
void consulta_clientes();
void exibir_clientes();

void criar_arquivo(){
	
	FILE *c, *r;
	
	c = fopen ("cliente.txt", "rt");
	if(c == NULL){
		c = fopen("cliente.txt","wt");
		printf("Arquivo criado com sucesso!\n");
		system("PAUSE");
		fclose(c);
	}

	r = fopen ("recebimentos.txt", "rt");
	if(r == NULL){
		r = fopen("recebimentos.txt","wt");
		printf("Arquivo criado com sucesso!\n");
		system("PAUSE");
		fclose(r);
	}
}

int menu1(){
	int op;
	printf("1. Cadastro cliente\n");
	printf("2. Cadastro recebimentos\n");
	printf("3. Sair\n\n");
	scanf ("&d", op);
	return op;
}

int menu2(){
	int op;
	
	system("CLS");
	printf("1. CADASTRAR CLIENTE\n");
	printf("2. CONSULTAR POR CODIGO\n");
	printf("3. EXIBIR TODOS\n");
	printf("4. VOLTAR\n\n");
	printf("Sua opção: ");
	scanf("%d",&op);
	return op;
}

void cadastro_clientes(){
	clientes reg;
	FILE *c;
	
	system("CLS");
	printf("**** Digite os dados do produto ****\n\n");
	printf("Código do cliente....: ");	scanf("%d",&reg.cod_cli);
	printf("Nome.................: ");	scanf("%s",&reg.nome);
	printf("Endereço.............: "); scanf("%s",&reg.endereco);
	
	c = fopen("clientes.txt","at");
	if(c==NULL){
		printf("Erro ao tentar abrir o arquivo!\n");
		return;
	}
	fprintf(c,"%d %s %s\n",reg.cod_cli,reg.nome,reg.endereco);
	fclose(c);
	printf("\n===> Registro cadastrado com sucesso!\n");
}

void consulta_clientes(){
	int cod;
	FILE *c;
	clientes reg;
	
	system("CLS");
	printf("Digite o código do produto: ");
	scanf("%d",&cod);
	
	c = fopen("produtos.txt","rt");
	if(c==NULL){
		printf("Erro ao tentar abrir o arquivo!\n");
		return;
	}
	while(!feof(c)){
		fscanf(c,"%d",&reg.cod_cli);
		fscanf(c,"%s",&reg.nome);
		fscanf(c,"%s",&reg.endereco);
		if(cod==reg.cod_cli){
			printf("Código do cliente....: %d\n",reg.cod_cli);
			printf("Nome.................: %f\n",reg.nome);
			printf("Endereço.............: %f\n",reg.endereco);
			fclose(c);
			return;
		}
	}
	fclose(c);
	printf("===> Produto não cadastrado!\n");
}

void exibe_clientes(){
	int i;
	clientes reg;
	FILE *c;
	
	system("CLS");
	printf("**** LISTA DE PRODUTOS **** \n\n");
	c = fopen("produtos.txt","rt");
	if(c==NULL){
		printf("Erro ao tentar abrir o arquivo!\n");
		return;
	}
	printf(" -------------------------------\n");
	printf("| Código | Quantidade |  Preço   |\n");
	printf(" -------------------------------\n");
	while(!feof(c)){ //le ate o fim do codigo
		if(fscanf(c,"%d %s %s\n",&reg.cod_cli,&reg.nome,&reg.endereco)){
			printf("| %3d   ",reg.cod_cli);
			printf("|    %3s     ",reg.nome);
			printf("| %7s  |\n",reg.endereco);
		}
		else{
			
			break;
		}	
	}
	fclose(c);
	printf(" -------------------------------\n");
}

int main(){
	int op1, op2, op3;
	setlocale(LC_ALL,"Portuguese");
	
	criar_arquivo();
	
	do{
		op1 = menu1();
		switch(op1){
			
			case 1:
				
				op2 = menu1();
				switch(op2){
					case 1:
						cadastro_clientes();
						break;
					case 2:
						consulta_clientes();
						break;
					case 3:
						exibir_clientes();
						break;
					}
				break;
			case 3:
				return;
				break;
			default:
				printf("\n===> Opção inválida!");
		op1 = menu1();	
		}
		system("PAUSE");
	}while (op1!=3);
	
	return 0;
}
