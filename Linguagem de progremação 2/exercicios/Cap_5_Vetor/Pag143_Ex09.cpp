#include<stdio.h>
#include<locale.h>
#include <stdlib.h>
#include <string.h>



#define MAX1 2 //Numero de voo
#define MAX2 4 //Numero de lugares

int menu1 ();
int menu2 ();
void reserva(int,int[MAX1],int[MAX1]);
void consulta_num (int,int[MAX1],int[MAX1],char[MAX1][20],char[MAX1][20]);
void consulta_origem (char[20],int[MAX1],int[MAX1],char[MAX1][20],char[MAX1][20]);
void consulta_destino (char[20],int[MAX1],int[MAX1],char[MAX1][20],char[MAX1][20]);


int menu1 (){
	int op;
	printf ("\n*SELECIONE UMA OP��O*");
	printf ("\n1 - Consultar");
	printf ("\n2 - Efetuar reserva");
	printf ("\n3 - Sair\n");
	scanf("%d",&op);
	return op;
}

int menu2 (){
	int op;
	printf ("\n*SELECIONE UMA OP��O*");
	printf ("\n1 - Por n�mero de v�o");
	printf ("\n2 - Por origem");
	printf ("\n3 - Por destino\n");
	scanf("%d",&op);
	return op;
}

void reserva(int num,int num_voo[MAX1],int num_lugares[MAX1]){
  	
  	int i;
	for (i=0;i<MAX1;i++){
		
		if (num == num_voo[i]){
			if (num_lugares[i]>MAX2) { 
				printf ("\nV�o lotado\n");
			
		}
		else num_lugares[i]++;printf ("\nReserva confirmada\n"); 
			system("PAUSE");
			return;	
		}
			
	}
	printf ("\nV�o inexistente\n"); 
	system("PAUSE");
}

void consulta_num (int num,int num_voo[MAX1],int num_lugares[MAX1],char orig[MAX1][20],char dest[MAX1][20]){
		
		int i;
		for (i=0;i<MAX1;i++){
	
  		if (num == num_voo[i]){
		printf ("\nN�mero do v�o:%d", num_voo[i]);
		printf ("\nOrigem do v�o :%s",orig[i]);
		printf ("\nDestino do v�o :%s",dest[i]);
		printf ("\nN�mero de lugares:%d\n", num_lugares[i]);
		system("PAUSE");
		return;
		}	
	}
		printf ("\nV�o inexistente\n"); 
		system("PAUSE");						
	}
	
void consulta_origem (char ori[20],int num_voo[MAX1],int num_lugares[MAX1],char orig[MAX1][20],char dest[MAX1][20]){
		
		int i;
		for (i=0;i<MAX1;i++){
	
  		if (strcmp(ori,orig[i])==0){
		printf ("\nN�mero do v�o:%d", num_voo[i]);
		printf ("\nOrigem do v�o: %s",orig[i]);
		printf ("\nDestino do v�o: %s",dest[i]);
		printf ("\nN�mero de lugares:%d\n", num_lugares[i]);
		system("PAUSE");
		return;
		}
	}
		printf ("\nV�o inexistente\n"); 							
		system("PAUSE");
	}
	
void consulta_destino (char des[20],int num_voo[MAX1],int num_lugares[MAX1],char orig[MAX1][20],char dest[MAX1][20]){
		
		int i;
		for (i=0;i<MAX1;i++){
	
  		if (strcmp(des,dest[i])==0){
		printf ("\nN�mero do v�o:%d", num_voo[i]);
		printf ("\nOrigem do v�o: %s",orig[i]);
		printf ("\nDestino do v�o: %s",dest[i]);
		printf ("\nN�mero de lugares:%d\n", num_lugares[i]);
		system("PAUSE");
		return;
		
		}		
	}
		printf ("\nV�o inexistente\n"); 								
		system("PAUSE");
	}
	
int main(){
	
	int num_voo[MAX1],num_lugares[MAX1];
	char orig[MAX1][20],dest[MAX1][20],ori[20],des[20];
	int i,num,op1,op2,op;
	
	setlocale(LC_ALL,"portuguese");
	
	printf ("*INSIRA AS INFORMA��ES SOBRE OS V�OS*\n");
	
	for (i=0;i<MAX1;i++){
		printf ("\nN�mero do v�o:");
		scanf("%d",&num_voo[i]);
		printf ("\nOrigem do v�o %d:",num_voo[i]);
		scanf("%s",&orig[i]);
		printf ("\nDestino do v�o %d:",num_voo[i]);
		scanf("%s",&dest[i]);
		num_lugares[i]=0;
	}
	
	do{
	system("CLS");
	op1 = menu1 ();
		switch(op1){
			case 1:
				
				printf ("\n*SELECIONE UMA OP��O*");
					system("CLS");
					op2 = menu2 ();
					switch (op2){
						case 1:
							printf ("\nDigite o n�mero d v�o:");
							scanf("%d",&num);
							consulta_num (num,num_voo,num_lugares,orig,dest);
							break;
						case 2:
							printf ("\nDigite a origem do v�o:");
							scanf("%s",&ori);
							consulta_origem (ori,num_voo,num_lugares,orig,dest);
							break;
						case 3:
							printf ("\nDigite a destino do v�o:");
							scanf("%s",&des);
							consulta_destino (des,num_voo,num_lugares,orig,dest);
							break;
					}
				
				break;
			case 2:
				printf ("*INSIRA O C�DICO DO V�O*\n");
				scanf("%d",&num);
				reserva(num,num_voo,num_lugares);
				break;
		}
} while (op1 !=3);


	return 0;
}


