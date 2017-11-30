// Subarray Máximo - Linear

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