#include<stdio.h>
#include<locale.h>

#define MESES  12
#define MAX2  10

int main(){
	char mes[MESES][MAX2] = {"JANEIRO","FEVEREIRO","MARÇO","ABRIL",
	                         "MAIO","JUNHO","JULHO","AGOSTO",
				             "SETEMBRO","OUTUBRO","NOVEMBRO","DEZEMBRO"};
	float temp[MESES];
	float t_maior, t_menor;
	int m_maior, m_menor;
	int i, j;
	
	setlocale(LC_ALL,"");
	for(i=0; i<MESES; i++){
		printf("Temperatura média do mês %s: ",mes[i]);
		scanf("%f",&temp[i]);
	}
	
	t_maior = t_menor = temp[0];
	m_maior = m_menor = 0;
	for(i=1; i<MESES; i++){
		if(temp[i]>t_maior){
			t_maior = temp[i];
			m_maior = i;
		}
		if(temp[i]<t_menor){
			t_menor = temp[i];
			m_menor = i;
		}
	}
	printf("\n\nMaior temperatura: %.1f ",t_maior);
	printf("Mês: %s",mes[m_maior]);	
	printf("\nMenor temperatura: %.1f ",t_menor);
	printf("Mês: %s",mes[m_menor]);
	
	return 0;
}
