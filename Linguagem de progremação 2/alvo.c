#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");
    int a, i, k,Co, op=0;

    while(op!=2){
        system("cls");
        printf("Defina o tamanho da Matriz:");scanf("%d",&a);
        if((a-1)%2 == 0 && a>4 && a<10){
            Co = a - ((a - 1)/2);
            int m[a][a];
            for(i=0;i<a;i++){
                for(k=0;k<a;k++){
                    if(i > 0 || i < a-1 && k > 0 || k < a-1)//Interior
                        m[i][k]=0;
                    if(i == 0 && k <= a-1 || i <= a-1 && k == 0 || i == a-1 && k >= 0 || i >= 0 && k == a-1)//Borda
                        m[i][k]=1;}}
            m[Co-1][Co-1]=a;
            for(i=0;i<a;i++){
                printf("\n");
                for(k=0;k<a;k++){
                    printf("%d  ",m[i][k]);}}
            printf("\n\nDeseja ver outra matriz?\n(1)SIM\t(2)Não\n");scanf("%d",&op);}//saida opcional do loop
        else{
            printf("Por favor, defina uma matriz impar entre 5 e 9!\n");
            system("Pause");}}
}