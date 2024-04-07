#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 4

int main(){
    setlocale(LC_ALL,"Portuguese");
    int a, i, k, mem, op=0;

    while(op!=2){
        system("cls");
            printf("Defina o numero inicial:");scanf("%d",&a);
            int m[a][a];
            for(i=0;i<a;i++){//colocando 0 na matriz completa
                for(k=0;k<a;k++){
                    m[i][k]=0;}}         
            for(i=0;i<a;i++){//calculando a tabela desejada
                mem=i*a;
                for(k=0;k<a;k++){
                        m[i][k] = mem +a;
                        mem = m[i][k];}}
            for(i=0;i<a;i++){//mostrando a matriz
                printf("\n");
                for(k=0;k<a;k++){
                    printf("%2d  ",m[i][k]);}}
            printf("\n\nDeseja ver outra matriz?\n(1)SIM\t(2)Não\n");scanf("%d",&op);}//saida opcional do loop
}
