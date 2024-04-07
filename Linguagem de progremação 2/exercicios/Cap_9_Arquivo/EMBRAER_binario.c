#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 5

struct str_embraer{
	char marca[20];
	int modelo;
	int qtd;
};

typedef struct str_embraer embraer;

int menu();

void pedido();
void consultar();
void exibir();

int menu(){
	int op;
	system ("CLS");
	
	printf ("1.Fazer pedido: \n");
	printf ("2.Consultar: \n");
	printf ("3.Exibir todos: \n");
	printf ("4.Sair: \n");
	scanf ("%d", &op);
	return op;
}

void criar_arquivo(){
	FILE *f; //determinar qual vai ser a variavel
	
	f = fopen("embraer.dat", "rb");// variavel f recebe arquivo
	if (f == NULL){
		f = fopen("embraer.dat", "wb");
		printf ("Arquivo criado");
		system("PAUSE");
	}
	fclose (f);
}

void pedido(){
	embraer reg;
	FILE *f;
	
	system("CLS");
	printf("Marca: ");
	scanf ("%s",&reg.marca);
	printf("\nModelo: ");
	scanf ("%d",&reg.modelo);
	printf("\nQuantidade: ");
	scanf ("%d",&reg.qtd);
	
	f = fopen ("embraer.dat", "ab");//abrindo aquivo tipo a
	if (f == NULL){
		printf ("!!! Arquivo não existe !!!");
		return;
	}
	fwrite (&reg,sizeof(embraer),1,f);//quantidades de dados que recebe 
	fclose (f);//fechando arquivo
	printf ("Pedido realizado");
}

void consultar (){
	embraer reg;
	FILE *f;
	char marc[20];
		
	system("CLS");
	printf ("Digite a marca do avião: \n");
	scanf ("%s", marc);
	
	f = fopen ("embraer.dat", "rb");
	if (f == NULL){
		printf("!!! Arquivo não existe !!!");
		return;
	}
	while(!feof(f)){//le ate o fim do codigo
		fread(&reg,sizeof(embraer),1,f);
			if (strcmp(reg.marca, marc)==0){
				printf("\nMarca: %s", reg.marca);
				printf("\nModelo: %d", reg.modelo);
				printf("\nQuantidade: %d\n", reg.qtd);
				fclose(f);
				system("PAUSE");
				return;
			}
	}
	fclose(f);
	printf ("!!! Marca não existe !!!");
	return;
}
	
	
	void exibir (){
	embraer reg;
	FILE *f;
		
	system("CLS");
	
	f = fopen ("embraer.dat", "rb");
	if (f == NULL){
		printf("!!! Arquivo não existe !!!");
		return;
	}
	
	//fscan ebusca dados dentro do arquivo
	//fprintf escreve dados dentro do arquivo
	while(1){//loop infinito
		if(fread(&reg,sizeof(embraer),1,f)){ 
			printf("\nMarca: %s", reg.marca);
			printf("\nModelo: %d", reg.modelo);
			printf("\nQuantidade: %d\n", reg.qtd);
		}
		else{
			break;
		}		
	}
	system("PAUSE");
	fclose(f);
	printf ("----------------------------------------------");
	return;
	}

int main(){
	int op, i, j;
	embraer reg;
	
setlocale (LC_ALL,"Portuguese");

	criar_arquivo();

	do{
		op = menu();
		
		switch (op){
			case 1:
			pedido();
			break;
			
			case 2:
			consultar();
			break;	
			
			case 3:
			exibir();
			break;
		}
		
	}while(op != 4);
	return;
}
