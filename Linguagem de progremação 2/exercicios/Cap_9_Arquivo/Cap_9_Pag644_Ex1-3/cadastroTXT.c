#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


struct str_clientes{
	
	int cli_cod;
	char cli_nome[20];
	char cli_ende[20];
};

typedef struct str_clientes clientes;

struct str_recibimentos{
	
	int num_doc;
	int valor_doc;
	int data_emissao;
	int data_vencimento;
	int cod_cli;
};

typedef struct str_recebimentos recebimentos;

void criar_arquivo ();
int menu1();
int menu2();
void cadastro_cli ();
void consultar_cli ();
void exibir_cli ();

void criar_arquivo (){
	FILE *c ,*r;
	c = fopen ("cliente.txt","rt");
	if (c == NULL){
		c = fopen ("cliente.txt","wt");
		printf ("Arquivo criado com sucesso");
		system("PAUSE");
		fclose (c);
	}
		

	r = fopen ("recebimentos.txt","rt");
	if (r == NULL){
		r = fopen ("recebimentos.txt","wt");
		printf ("Arquivo criado com sucesso");
		system("PAUSE");
		fclose (r);
	}
}

int menu1(){
	int op;
	system("CLS");
	printf ("1. Cadastro Clientes\n");
	printf ("2. Cadastro recibimentos\n");
	printf ("3. Sair\n");
	scanf ("%d",&op);
	return op;
}

int menu2(){
	int op;
	system("CLS");
	printf ("1. Cadastrar\n");
	printf ("2. Consultar\n");
	printf ("3. Exibir Todos\n");
	printf ("4. Voltar\n");
	scanf ("%d",&op);
	return op;
}

void cadastro_cli (){
	
	FILE *c;
	clientes reg;
	
	system ("CLS");
	printf ("***INSIRA OS DADOS DO CLIENTE***\n");

	printf ("Nome :\n");scanf("%s",&reg.cli_nome);
	printf ("Endereço :\n");scanf("%s",&reg.cli_ende);
	printf ("Código :\n");scanf("%d",&reg.cli_cod);
	
	c = fopen ("clientes.txt","at");
	if (c == NULL){
		printf ("Arquivo não existe");
		return;
	}
	fprintf (c,"%s %s %d",reg.cli_nome,reg.cli_ende,reg.cli_cod);
	fclose (c);
	printf ("Cadastro relizado");
}

void consultar_cli (){
	FILE *c;
	int cod;
	clientes reg;
	
	printf ("Escreva o codigo do cliente :");
	scanf ("%d",&cod);
	
	c = fopen ("clientes.txt","rt");
	if ( c == NULL){ 		
		printf ("!!! Arquivo não existe !!!");
		return;
	}
	while (!feof(c)){
		fscanf (c,"%s",&reg.cli_nome);
		fscanf (c,"%s",&reg.cli_ende);
		fscanf (c,"%d",&reg.cli_cod);
		
		if (cod == reg.cli_cod){
			printf ("\nNome: %s",reg.cli_nome); 
			printf ("\nEndereço: %s",reg.cli_ende);
			printf ("\nCodigo: %d\n",reg.cli_cod);
			fclose (c);
			system ("PAUSE");
			return;
		}
	}
	
}

void exibir_cli (){
	FILE *c;
	clientes reg;
	
	
	c = fopen ("clientes.txt","rt");
	if ( c == NULL){ 				// Confere se o arquivo existe
		printf ("!!! Arquivo não existe !!!");
		return;
	}
	while (!feof(c)){
		fscanf (c,"%s",&reg.cli_nome);
		fscanf (c,"%s",&reg.cli_ende);
		fscanf (c,"%d",&reg.cli_cod);
		
	
			printf ("\nNome: %s",reg.cli_nome); 
			printf ("\nEndereço: %s",reg.cli_ende);
			printf ("\nCodigo: %d\n",reg.cli_cod);
			fclose (c);
			system ("PAUSE");
			return;
		
	}
	
}

int main(){	
	int op1,op2;
	
	setlocale(LC_ALL,"portuguese");
	
	criar_arquivo();
	
	do{
		op1 = menu1();
		
		switch (op1){
			
			case 1:
				
				op2 = menu2();
				switch (op2){
					case 1:
						cadastro_cli();
						break;
					case 2:
						consultar_cli();
						break;
					case 3:
						exibir_cli();	
						break;
					case 4:
						break;
				}
			
			case 2:
			break;
		}
		
	}while (op1!= 3);
	return 0;
}
