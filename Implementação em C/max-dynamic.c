// Subarray Máximo - Dinamico

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <math.h>

int max(int a, int b)
{
    if(a>b)
        return a;

	else
        return b;

}

int max_subarray(int array[], int n)
{
	int ans = INT_MIN;
	int inicio;
	for(inicio = 0; inicio < n; inicio++)	
	{
		int sum = 0;
		int tam;
		for(tam = 1; tam <= n; tam++)
		{
			if(inicio+tam > n)
				break;
			sum = sum + array[inicio + tam-1];
			ans = max(ans,sum);
		}
	}
	return ans;
}

int arquivo1(int tam){

	int i;
	int array[tam];

	FILE *file;
	file = fopen("..\\entradas\\entrada1.txt","r"); //Definir cada arquivo de entrada

	for(i=0;i<tam;i++){
		fscanf(file,"%d",&array[i]);
	}

	fclose(file);

	return(max_subarray(array,tam));
}

int arquivo2(int tam){

	int i;
	int array[tam];

	FILE *file;
	file = fopen("..\\entradas\\entrada2.txt","r"); //Definir cada arquivo de entrada

	for(i=0;i<tam;i++){
		fscanf(file,"%d",&array[i]);
	}

	fclose(file);

	return(max_subarray(array,tam));
}

int arquivo3(int tam){

	int i;
	int array[tam];

	FILE *file;
	file = fopen("..\\entradas\\entrada3.txt","r"); //Definir cada arquivo de entrada

	for(i=0;i<tam;i++){
		fscanf(file,"%d",&array[i]);
	}

	fclose(file);

	return(max_subarray(array,tam));
}

int arquivo4(int tam){

	int i;
	int array[tam];

	FILE *file;
	file = fopen("..\\entradas\\entrada4.txt","r"); //Definir cada arquivo de entrada

	for(i=0;i<tam;i++){
		fscanf(file,"%d",&array[i]);
	}

	fclose(file);

	return(max_subarray(array,tam));
}

int arquivo5(int tam){

	int i;
	int array[tam];

	FILE *file;
	file = fopen("..\\entradas\\entrada5.txt","r"); //Definir cada arquivo de entrada

	for(i=0;i<tam;i++){
		fscanf(file,"%d",&array[i]);
	}

	fclose(file);

	return(max_subarray(array,tam));
}

int main(int argc, char const *argv[])
{
	int tam = 10000; //Tamanho máximo de elementos em cada entrada: 1048576

	printf("%d\n",arquivo1(tam));
	printf("%d\n",arquivo2(tam));
	printf("%d\n",arquivo3(tam));
	printf("%d\n",arquivo4(tam));
	printf("%d\n",arquivo5(tam));

	return 0;
}