#include <locale.h>
#include <stdio.h>
#include <stdlib.h>


struct str_aluno {
	char nome[20];
	char curso[10];
	int num;
	float nota1;
	float nota2;
	float med;
};

typedef struct str_aluno aluno;

int menu1();
void criar_arquivo();
void cadastrar();
void consultar();
void exibir();



int menu1(){
	
	int op;
	
	 
	system("CLS");	
	printf("-------------------------------\n");
	printf("1- Cadastrar aluno.\n");
	printf("2- Consultar número do aluno.\n");
	printf("3- Exibir todos alunos de um curso.\n");
	printf("4- Sair.\n");
	printf("-------------------------------\n");
	printf("Sua opção: ");
	scanf("%d", &op);
	
	return op;

}

void criar_arquivo(){
	FILE *f;
	
	f = fopen("aluno.txt", "rt");
	if(f==NULL){
		f = fopen("aluno.txt", "wt");
		printf("Arquivo criado com sucesso.\n");
		system("PAUSE");
	}

	fclose(f);
}

void cadastrar(){
	
	aluno reg;
	FILE *f;
	
	system("CLS");
	printf("Registro do aluno\n");
	printf("Nome: ");
	scanf("%s", &reg.nome);
	printf("Curso: ");
	scanf("%s", &reg.curso);
	printf("Número: ");
	scanf("%d", &reg.num);
	printf("Nota, prova 1: ");
	scanf("%f", &reg.nota1);
	printf("Nota, prova 2: ");
	scanf("%f", &reg.nota2);
	printf("\n");
	
	reg.med = reg.nota1+reg.nota2;
	
	
	f = fopen("aluno.txt", "at");
	if(f==NULL){
		printf("Arquivo não encontrado. ");
		system("PAUSE");
		return;
	}

	else{
		fprintf(f,"%s %s %d %f %f %f\n",reg.nome,reg.curso,reg.num, reg.nota1, reg.nota2, reg.med);
		fclose(f);
		printf("Aluno registrado.\n");
	}
}

void consultar(){
	
	int num;
	FILE *f;
	aluno reg;
	

	system("CLS");
	printf("Digite o número do aluno: ");
	scanf("%d", &num);
	
	f = fopen("aluno.txt", "rt");
	if(f==NULL){
		printf("Arquivo não encontrado.");
		system("PAUSE");
		return;
	}
	while(!feof(f)){
		
		fscanf(f,"%s",&reg.nome);
		fscanf(f,"%s",&reg.curso);
		fscanf(f,"%d",&reg.num);
		fscanf(f,"%f",&reg.nota1);
		fscanf(f,"%f",&reg.nota2);
		fscanf(f,"%f",&reg.med);
		
		if(num==reg.num){
			printf("Nome do aluno......: %s\n", reg.nome);
			printf("Curso...... %s\n",reg.curso);
			printf("Número do aluno......: %d\n", reg.num);
			printf("Notas...... Prova 1: %.2f Prova 2: %.2f\n", reg.nota1, reg.nota2);
			printf("Média do aluno...... %.2f\n", reg.med/2);
			fclose(f);
			return;
			}
	}
	fclose(f);
	printf("===> Aluno não cadastrado!\n");
}

void exibir(){
	
	FILE *f;
	aluno reg;
	float med;
	
	system("CLS");
	
	med = reg.nota1/reg.nota2;
	
	
	f = fopen("aluno.txt", "rt");
	if(f==NULL){
		printf("Arquivo não encontrado.");
		return;
	}
	while(1){
		if(fscanf(f, "%s %s %d %f %f %f", &reg.nome,&reg.curso,&reg.num,&reg.nota1,&reg.nota2,&reg.med)!=EOF){
			printf("\n\nAluno: %s\n", reg.nome);
			printf("Curso: %s\n", reg.curso);
			printf("Número: %d\n", reg.num);
			printf("Prova 1: %.2f\n", reg.nota1);
			printf("Prova 2: %.2f\n", reg.nota2);
			printf("Média: %.2f", med);
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
	
	setlocale(LC_ALL, "Portuguese");
	criar_arquivo();
	
	
	do{
		
		op=menu1();
		
		switch(op){
			case 1:
				cadastrar();
				break;
			case 2:
				consultar();
				break;
			case 3:
				exibir();
				break;
			case 4:		
				break;
			default:
				printf("opçao inválida!\n");
		}
		system("PAUSE");	
	}while(op!=4);
		
	return 0;	

}
