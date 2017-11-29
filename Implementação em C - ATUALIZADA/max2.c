/* Subvetor Máximo - Versão Iterativa
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h> 
#include <sys/time.h> 


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
	
	int soma, Maior_Soma = INT_MIN, inicio, fim;

	struct timeval time1, time2;
    double elapsedTime;

	clock_t t1=clock();
	gettimeofday(&time1, NULL);

	
	for (int i = 0; i < tam; i++) 
	{
		soma = 0;
		for (int j = i; j < tam; j++) 
		{
			soma += vetor[j];
			if (soma > Maior_Soma){ 
				Maior_Soma = soma;
				inicio = i;
				fim = j;
			}
		}
	}

	clock_t t2=clock();
	gettimeofday(&time2, NULL);
	elapsedTime = (time2.tv_sec - time1.tv_sec) * 1000.0;      // converte segundos to ms
    elapsedTime += (time2.tv_usec - time1.tv_usec) / 1000.0;   // converte us to ms


	for (int i = 0; i < tam; i++){
		printf("vetor[%d]: %d\n", i, vetor[i]);
	}
	printf("Soma maxima: %d \ninicio: %d \nfim: %d\n", Maior_Soma, inicio, fim);
	printf("Tempo de CPU: %lf ms\n", ((double)(1000.0 * (t2-t1) / CLOCKS_PER_SEC)));
	printf("Tempo real: %lf ms\n", elapsedTime);

	return 0;	
}
