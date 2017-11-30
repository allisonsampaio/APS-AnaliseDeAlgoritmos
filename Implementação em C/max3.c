/* Subvetor Máximo - Divisão e Conquista
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h> 
#include <sys/time.h> 


typedef struct Subvetor
{
	int inicio;
	int fim;
	int soma;
} subvetor;

subvetor max_cross(int* vetor, int inicio, int meio, int fim);

subvetor subvetor_maximo(int* vetor, int inicio, int fim);

int main( int argc, char *argv[ ] ){
	if (argc != 3)
	{
		printf("Uso: ./algoritmo tam_vetor file\n");
		return 0;
	}

	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int i = 0;

	int tam = atoi(argv[1]); 
	fp = fopen(argv[2], "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);

	int vetor[tam];

	while ((read = getline(&line, &len, fp)) != -1)
	{
		vetor[i] = atoi(line);
		i++;
	}

	struct timeval time1, time2;
    double elapsedTime; // the amount of time that has passed since a particular process started

	clock_t t1=clock();
	gettimeofday(&time1, NULL);

	
	subvetor maxSubVetor = subvetor_maximo(vetor, 0, tam-1);

	clock_t t2=clock();
	gettimeofday(&time2, NULL);
	elapsedTime = (time2.tv_sec - time1.tv_sec) * 1000.0;      // // converte segundos to ms
    elapsedTime += (time2.tv_usec - time1.tv_usec) / 1000.0;   // // converte us to ms

	for (int i = 0; i < tam; i++){
		printf("vetor[%d]: %d\n", i, vetor[i]);
	}
	printf("Soma maxima: %d \ninicio: %d \nfim: %d\n", maxSubVetor.soma, maxSubVetor.inicio, maxSubVetor.fim);
	printf("Tempo de CPU: %lf ms\n", ((double)(1000.0 * (t2-t1) / CLOCKS_PER_SEC)));
	printf("Tempo real: %lf ms\n", elapsedTime);
	
	return 0;	
}

subvetor max_cross(int* vetor, int inicio, int meio, int fim){
	int e_soma = INT_MIN, d_soma = INT_MIN, soma;
	subvetor maxSubVetor;
	int e_max, d_max;

	soma = 0;
	for (int i = meio; i >= inicio; i--) 
	{
		soma += vetor[i];
		if (e_soma < soma){ 
			e_soma = soma;
			e_max = i;
		}
	}
	soma = 0;
	for (int i = meio+1; i <= fim; i++) 
	{
		soma += vetor[i];
		if(soma > d_soma){ 
			d_soma = soma;
			d_max = i;
		}
	}
	
	maxSubVetor.inicio = e_max;
	maxSubVetor.fim = d_max;
	maxSubVetor.soma = (e_soma + d_soma);
	// printf("Soma maxima: %d \ninicio: %d \nfim: %d\n", maxSubVetor.soma, maxSubVetor.inicio, maxSubVetor.fim);
	
	return maxSubVetor;
}

subvetor subvetor_maximo(int* vetor, int inicio, int fim){
	subvetor maxSubVetor;
	subvetor e_maxSubVetor;
	subvetor m_maxSubVetor;
	subvetor d_maxSubVetor;
	
	
	if (inicio == fim){
		
		maxSubVetor.inicio = inicio;
		maxSubVetor.fim = fim;
		maxSubVetor.soma = vetor[inicio];
		
		return maxSubVetor;
	}
	
	int meio = (inicio + fim)/2;
	printf("inicio = %d, fim = %d, meio=%d\n", inicio, fim, meio);
	e_maxSubVetor = subvetor_maximo(vetor, inicio, meio); 
	d_maxSubVetor = subvetor_maximo(vetor, meio+1, fim); 
	m_maxSubVetor = max_cross(vetor, inicio, meio, fim); 

	if(e_maxSubVetor.soma >= d_maxSubVetor.soma && e_maxSubVetor.soma >= m_maxSubVetor.soma){ 
		return e_maxSubVetor;
	} else if (d_maxSubVetor.soma >= e_maxSubVetor.soma && d_maxSubVetor.soma >= m_maxSubVetor.soma){ 
		return d_maxSubVetor;
	} else { 
		return m_maxSubVetor;
	}
}