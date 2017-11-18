// Subarray Máximo - Interativo


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

unsigned int PseudoRand()
{
   
    static unsigned int seed = 2048;

    // Garantindo que haja números negativos
    seed = (8253729 * seed + 2396403); 

    return seed  % 32767;
}

int main( int argc, char *argv[ ] ){
	
	float tempo_inicial = clock();

	
	int tam = atoi(argv[1]); 

	int v[tam];
	srand (1); 

	
	int i;
	for (i = 0; i < tam; i++)
	{
		v[i] = PseudoRand()%200 - 100;
	}
	int soma;
	int Msoma = INT_MIN, inicio, fim;
	int j, k, a;
	
	for (a = 0; a < tam; a++) 
	{
		for (j = a; j < tam; j++) 
		{
			soma = 0;
			for (k = a; k <= j; k++) 
			{
				soma += v[k];
			}
			if (soma > Msoma) 
			{
				Msoma = soma;
				inicio = a;
				fim = j;
			}
		}
	}
	
	
	float tempo_final = clock();

	float resultado = tempo_final - tempo_inicial;
	
	
	int b;
	
	for (b = 0; b < tam; b++){
		printf("vetor[%d]: %d\n", b, v[b]);
	}
	printf("Maior soma: %d \ninicio: %d \nfim: %d\n", Msoma, inicio, fim);
	printf("\n");
	printf("Tempo de relógio: %3.f\n", resultado);

	return 0;	
}
