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

int max_subarray(int array[],int n)
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

int main(int argc, char const *argv[])
{
	int array[] = {3,-2,5,-1};
	printf("%d",max_subarray(array,4));
	return 0;
}