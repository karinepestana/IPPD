#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void) {

	//int m[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36,37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64};
	int m[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	int tam = 16;
	int i = 0, c = 0;
	float resultado[tam/4];	
	int n = sqrt(tam);
	
	for (int j = 0; j < tam; j+=(2*n))
	{
		int aux = j+n;		
		for (i = j; i < aux; i+=2)
		{
			float soma = 0;
			
			printf("%d\n", m[i]);			
			printf("%d\n", m[i+1]);
			printf("%d\n", m[i+n]);
			printf("%d\n", m[i+n+1]);

			soma += m[i];
			soma += m[i+1];
			soma += m[i+n];
			soma += m[i+n+1];
			soma = soma/4;
			printf("\n");
			resultado[c] = soma;
			c++;
		}		
	}

	for (int k = 0; k < tam/4; k++)
	{
		printf("%.2f\n", resultado[k]);
	}

	
}