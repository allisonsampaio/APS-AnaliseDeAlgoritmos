// Subarray Máximo - Linear

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <math.h>

unsigned int pseudorand()
{

    static unsigned int seed = 2048;

    seed = (8253729 * seed + 2396403);

    return seed  % 32767;
}

int max(int a, int b)
{
    if(a>b)
        return a;

	else
        return b;

}

int max_subarray(int array[], int n)
{
	int i;
	int aux = array[0];
	int sum = 0;

	for(i = 1; i<n; i++) //Verifique se todos são negativos
	{
		aux = max(aux, array[i]);
	}

	if(aux<0){ //se max < 0 retorna max
		return aux;
	}

	aux = 0;

	for(i = 0 ; i<n; i++)
	{
		if(sum + array[i] > 0)
			sum= sum + array[i];

		else
			sum  = 0;

		aux = max(aux,sum);
	}

	return aux;
}

int main(int argc, char const *argv[])
{
	float tempo_inicial = clock();

	int tam = atoi(argv[1]);

	int array[tam];
	srand (1);

	int i;

	for (i = 0; i<tam; i++)
	{
		array[i] = pseudorand()%200 - 100;
	}

    int sum = 0;

	sum = max_subarray(array,4);

	float tempo_final = clock();

	for (i = 0; i<tam; i++){
		printf("[%d]: %d\n", i, array[i]);
	}

	float resultado = tempo_final - tempo_inicial;

	printf(" SOMA = %d \n",sum);
	printf(" TEMPO =  %f\n", resultado);

	return 0;
}
