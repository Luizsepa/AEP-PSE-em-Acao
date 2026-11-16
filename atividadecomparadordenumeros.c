#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
		
	int a,b,c, maior_temp, maior;
	printf("Insira os valores a serem comparados: ");
	scanf("%d %d %d", &a, &b, &c);
	maior_temp = ((a+b)+abs(a-b))/2;
	
    maior = ((maior_temp)+c+abs(maior_temp-c))/2;
    
    printf("o maior entre -%d- -%d- -%d- = %d", a,b,c, maior);
    
	return 0;
}
