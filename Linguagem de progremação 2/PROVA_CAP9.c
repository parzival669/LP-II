#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

struct str_aniversario {
	char nome[20];
	char mes[10];
	int dia;
	
};

typedef struct str_aniversario aniversario;

int menu();
void criar_arquivo();
void cadastrar();
void cadastrar_cinco();
void consultar_dia();
void consultar_nome();
void consultar();
void exibir();



int menu(){
	int op;
	
	system("CLS");	
	printf("-------------------------------\n");
	printf("1- Cadastro na agenda de aniversario.\n");
	printf("2- Cadastro 5 na agenda de aniversario.\n");
	printf("3- Consultar pela data.\n");
	printf("4- Consultar pelo nome.\n");
	printf("5- Exibir toda agenda.\n");
	printf("6- Sair.\n");
	printf("-------------------------------\n");
	printf("Sua opção: ");
	scanf("%d", &op);
	
	return op;

}

void criar_arquivo(){
	FILE *f;
	
	f = fopen("aniversario.dat", "rb");
	if(f==NULL){
		f = fopen("aniversario.dat", "wb");
		printf("Arquivo criado com sucesso.\n");
		system("PAUSE");
	}

	fclose(f);
}

void cadastrar(){
	
	aniversario reg;
	FILE *f;
	
	system("CLS");
	printf("Registro de convidado\n");
	printf("Nome: ");
	scanf("%s", &reg.nome);
	printf("Dia: ");
	scanf("%d", &reg.dia);
	printf("Mes: ");
	scanf("%s", &reg.mes);
	printf("\n");
	
	f = fopen("aniversario.dat", "ab");
	if(f==NULL){
		printf("Arquivo não encontrado. ");
		system("PAUSE");
		return;
	}
	fwrite (&reg,sizeof(aniversario),1,f);
	fclose (f);
	printf ("Cadastro concluido\n");
}

void cadastrar_cinco(){
	
	aniversario reg;
	FILE *f;

	system("CLS");
	printf("Registro de convidado\n");
	printf("Nome: ");
	scanf("%s", &reg.nome);
	printf("Dia: ");
	scanf("%d", &reg.dia);
	printf("Mes: ");
	scanf("%s", &reg.mes);
	printf("\n");
	
	f = fopen("aniversario.dat", "ab");
	if(f==NULL){
		printf("Arquivo não encontrado. ");
		return;
	}
	fwrite (&reg,sizeof(aniversario),5,f);
	fclose (f);
	printf ("Cadastro concluido");
}

void consultar_dia(){
	
	aniversario reg;
	FILE *f;
	int dia;
	char mes[10];

	system("CLS");
	printf("Dia: ");
	scanf("%d", &dia);
	printf("Mes: ");
	scanf("%s", mes);
	
	f = fopen("aniversario.dat", "rb");
	if(f==NULL){
		printf("Arquivo não encontrado.");
		return;
	}
	while(!feof(f)){
		fread(&reg,sizeof(aniversario),2,f);
		if(strcmp(reg.dia,reg.mes, dia, mes)==0){
			printf("Dia.......: %d\n",reg.dia);
			printf("Mes.......: %s\n", reg.mes);
			fclose(f);
			system("PAUSE");
			return;
			}
	}
	fclose(f);
	printf("===> Convidado não cadastrado!\n");
	return;
}

void consultar_nome (){
	aniversario reg;
	FILE *f;
	char nome[20];
		
	system("CLS");
	printf ("Digite o nome: ");
	scanf ("%s", nome);
	
	f = fopen ("aniversario.dat", "rb");
	if (f == NULL){
		printf("!!! Arquivo não existe !!!");
		return;
	}
	while(!feof(f)){
		fread(&reg,sizeof(aniversario),1,f);
			if (strcmp(reg.nome, nome)==0){
				printf("\nNome: %s", reg.nome);
				printf("\nDia: %d", reg.dia);
				printf("\nMes: %s\n", reg.mes);
				fclose(f);
				system("PAUSE");
				return;
			}
	}
	fclose(f);
	printf ("!!! Nome não existe !!!\n");
	return;
}

void exibir(){
	
	aniversario reg;
	FILE *f;
	
	system("CLS");
	
	f = fopen("aniversario.dat", "rb");
	if(f==NULL){
		printf("Arquivo não encontrado.");
		return;
	}
	while(1){
		if(fread(&reg,sizeof(aniversario),1,f)){
			printf("\nNome: %s\n", reg.nome);
			printf("Dia: %d\n", reg.dia);
			printf("Mes: %s\n", reg.mes);
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
	
	int op;
	aniversario reg;
	
	setlocale(LC_ALL, "Portuguese");
	criar_arquivo();
	
	
	do{
		
		op=menu();
		
		switch(op){
			case 1:
				cadastrar();
				break;
			case 2:
				cadastrar_cinco();
				break;
			case 3:
				consultar_dia();
				break;
			case 4:
				consultar_nome();
				break;
			case 5:
				exibir();
				break;
			case 6:		
				break;
			default:
				printf("opçao inválida!\n");
		}
		system("PAUSE");	
	}while(op!=6);
		
	return;	

}
