#include<stdio.h>
#include<locale.h>

#define MESES  12
#define MAX2  10

int main(){
	char mes[MESES][MAX2] = {"Janeiro","Fevereiro","Marco","Abril",
	                         "Maio","Junho","Julho","Agosto",
				             "Setembro","Outubro","Novembro","Dezembro"};
	float temp[MESES];
	float t_maior, t_menor;
	int m_maior, m_menor;
	int i, j;

	for (i=0; i<MESES; i++){
	printf("\nTemperatura media de %s:", mes[i]);
	scanf ("%f", &temp[i]);
	}
	
t_maior = t_menor = temp[0];
m_maior = m_menor = 0;
	for (i=1; i<MESES; i++){
		if (temp[i] > t_maior){
			t_maior = temp[i];
			m_maior = i;
		}	
		
		if (temp[i] < t_menor){
			t_menor = temp[i];
			m_menor = i;
		}
	}
	printf ("\nA maior temperatura :%f", t_maior);
	printf ("\nMes - %s", mes[m_maior]);
	printf ("\nA menor temperatura :%f", t_menor);
	printf ("\nMes - %s", mes[m_menor]);
	
	return 0;
}

