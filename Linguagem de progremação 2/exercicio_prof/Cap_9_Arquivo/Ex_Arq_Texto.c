#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct str_produtos{
	int codigo;
	int qtdade;
	float preco;
};

typedef struct str_produtos produto;

int menu();

void cria_arquivo();
void cadastro();
void consulta();
void exibe();

int menu(){
	int op;
	
	system("CLS");
	printf("1. CADASTRAR PRODUTOS\n");
	printf("2. CONSULTAR POR CÓDIGO\n");
	printf("3. EXIBIR TODOS OS PRODUTOS\n");
	printf("4. SAIR\n\n");
	printf("Sua opção: ");
	scanf("%d",&op);
	return op;
}

void cria_arquivo(){
	FILE *f;
	
	f = fopen("produtos.txt","rt");
	if(f==NULL){
		f = fopen("produtos.txt","wt");
		printf("Arquivo criado com sucesso!\n");
		system("PAUSE");
		fclose(f);
	}
}

void cadastro(){
	produto reg;
	FILE *f;
	
	system("CLS");
	printf("**** Digite os dados do produto ****\n\n");
	printf("Código....: ");	scanf("%d",&reg.codigo);
	printf("Quantidade: "); scanf("%d",&reg.qtdade);
	printf("Preço.....: ");	scanf("%f",&reg.preco);
	
	f = fopen("produtos.txt","at");
	if(f==NULL){
		printf("Erro ao tentar abrir o arquivo!\n");
		return;
	}
	fprintf(f,"%d %d %.2f\n",reg.codigo,reg.qtdade,reg.preco);
	fclose(f);
	printf("\n===> Registro cadastrado com sucesso!\n");
}

void consulta(){
	int cod;
	FILE *f;
	produto reg;
	
	system("CLS");
	printf("Digite o código do produto: ");
	scanf("%d",&cod);
	
	f = fopen("produtos.txt","rt");
	if(f==NULL){
		printf("Erro ao tentar abrir o arquivo!\n");
		return;
	}
	while(!feof(f)){
		fscanf(f,"%d",&reg.codigo);
		fscanf(f,"%d",&reg.qtdade);
		fscanf(f,"%f",&reg.preco);
		if(cod==reg.codigo){
			printf("Código do produto....: %d\n",reg.codigo);
			printf("Preço Unitário.......: %.2f\n",reg.preco);
			printf("Quantidade no estoque: %d\n",reg.qtdade);
			fclose(f);
			return;
		}
	}
	fclose(f);
	printf("===> Produto não cadastrado!\n");
}

void exibe(){
	int i;
	produto reg;
	FILE *f;
	
	system("CLS");
	printf("**** LISTA DE PRODUTOS **** \n\n");
	f = fopen("produtos.txt","rt");
	if(f==NULL){
		printf("Erro ao tentar abrir o arquivo!\n");
		return;
	}
	printf(" -------------------------------\n");
	printf("|Código | Quantidade |  Preço   |\n");
	printf(" -------------------------------\n");
	while(!feof(f)){ //le ate o fim do codigo
		if(fscanf(f,"%d %d %f\n",&reg.codigo,&reg.qtdade,&reg.preco)){
			printf("| %3d   ",reg.codigo);
			printf("|    %3d     ",reg.qtdade);
			printf("| %7.2f  |\n",reg.preco);
		}
		else{
			
			break;
		}	
	}
	fclose(f);
	printf(" -------------------------------\n");
}

int main(){
	int op;
	produto reg;
	
	setlocale(LC_ALL,"");
	
	cria_arquivo();	
	
	do{
		op = menu();
		switch(op){
			case 1:
				cadastro();
				break;
			case 2:
				consulta();
				break;
			case 3:
				exibe();
				break;
			case 4:
				break;
			default:
				printf("\n===> Opção inválida!");
		}
		system("PAUSE");
	}while(op!=4);
	
	return 0;
}
