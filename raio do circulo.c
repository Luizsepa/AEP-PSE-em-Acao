#include <stdio.h>
#include <stdlib.h>
#define pi 3.14159

int main(int argc, char *argv[]) {
	
	float raio, area, raioQuadrado;
	
	printf("Insira o valor de R: \n");
	scanf("%f", &raio);
	
	raioQuadrado = raio*raio;
	area= pi * raioQuadrado;
	
	printf("A Area do circulo de raio %f = %f", raio, area);
	
	return 0;
}
