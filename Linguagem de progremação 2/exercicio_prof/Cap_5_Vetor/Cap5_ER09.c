#include<stdio.h>
#include<locale.h>

#define MAX1  2
#define MAX2  2

int menu1();
int menu2();
void consulta_voo(int,int[MAX1],int[MAX1],char[MAX1][10],char[MAX1][10]);
void consulta_origem(char[10],int[MAX1],int[MAX1],char[MAX1][10],char[MAX1][10]);
void consulta_destino(char[10],int[MAX1],int[MAX1],char[MAX1][10],char[MAX1][10]);
void reserva(int,int[MAX1],int[MAX1]);


int menu1(){
	int op;
	
	printf("1. CONSULTAR\n");
	printf("2. EFETUAR RESERVA\n");
	printf("3. SAIR\n\n");
	printf("Sua opção: ");
	scanf("%d",&op);
	return op;
}

int menu2(){
	int op;
	
	printf("1. POR NUMERO DO VOO\n");
	printf("2. POR ORIGEM\n");
	printf("3. DESTINO\n\n");
	printf("SUA OPÇÃO: ");
	scanf("%d",&op);
	return op;
}

void consulta_voo(int num, int voo[MAX1],int lugares[MAX1],
                  char origem[MAX1][10],char destino[MAX1][10]){
	int i;
	for(i=0; i<MAX1; i++){
		if(num==voo[i]){
			printf("Voo: %d\n",voo[i]);
			printf("Origem: %s\n",origem[i]);
			printf("Destino: %s\n",destino[i]);
			printf("Lugares: %d\n",lugares[i]);
			system("PAUSE");
			return;
		}
	}
	printf("Voo não encontrado!\n");
	system("PAUSE");
}

void consulta_origem(char ori[10], int voo[MAX1],int lugares[MAX1],
                  char origem[MAX1][10],char destino[MAX1][10]){
	int i;
	for(i=0; i<MAX1; i++){
		if(strcmp(ori,origem[i])==0){
			printf("Voo: %d\n",voo[i]);
			printf("Origem: %s\n",origem[i]);
			printf("Destino: %s\n",destino[i]);
			printf("Lugares: %d\n",lugares[i]);
			system("PAUSE");
			return;
		}
	}
	printf("Voo não encontrado!\n");
	system("PAUSE");
}

void consulta_destino(char dest[10], int voo[MAX1],int lugares[MAX1],
                  char origem[MAX1][10],char destino[MAX1][10]){
	int i;
	for(i=0; i<MAX1; i++){
		if(strcmp(dest,destino[i])==0){
			printf("Voo: %d\n",voo[i]);
			printf("Origem: %s\n",origem[i]);
			printf("Destino: %s\n",destino[i]);
			printf("Lugares: %d\n",lugares[i]);
			system("PAUSE");
			return;
		}
	}
	printf("Voo não encontrado!\n");
	system("PAUSE");
}

void reserva(int num,int voo[MAX1],int lugares[MAX1]){
	int i;
	for(i=0; i<MAX1; i++){
		if(num==voo[i]){
			if(lugares[i]>MAX2){
				printf("\nVoo lotado\n");
			}
			else{
				lugares[i]++;
				printf("\nReserva confirmada\n");
			}
			system("PAUSE");
			return;
		}
	}
	printf("\nVoo inexistente");
	system("PAUSE");
}

int main(){
	
	int voo[MAX1], lugares[MAX1];
	char origem[MAX1][10], destino[MAX1][10];
	char ori[10], dest[10];
	int op1, op2, num;
	int i, j, k, m;
	
	
	setlocale(LC_ALL,"");
	printf("*** DADOS DOS VOOS ***\n");
	for(i=0; i<MAX1; i++){
		printf("Numero do voo: ");
		scanf("%d",&voo[i]);
		printf("Origem: ");
		scanf("%s",&origem[i]);
		printf("Destino: ");
		scanf("%s",&destino[i]);
		lugares[i]=0;
	}
	
	
	do{
		system("CLS");
		op1 = menu1();
		switch(op1){
			case 1:
				system("CLS");
				op2 = menu2();
				switch(op2){
					case 1:
						printf("\nDigite o numero de voo: ");
						scanf("%d",&num);
						consulta_voo(num,voo,lugares,origem,destino);
						break;
					case 2:
						printf("\nDigite a origem: ");
						scanf("%s",&ori);
						consulta_origem(ori,voo,lugares,origem,destino);
						break;
					case 3:
						printf("\nDigite o destino: ");
						scanf("%s",&dest);
						consulta_destino(dest,voo,lugares,origem,destino);
						break;
						break;
				}
				break;
			case 2:
				printf("Digite o voo: ");
				scanf("%d",&num);
				reserva(num,voo,lugares);
				break;
		}
	}while(op1!=3);
	
	
	return 0;
}
