#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int compara (int a, int b){
	if(a>b)return a;
	else return b;
}

int main(int argc, char *argv[]) {
	
	int valor[10];
	int maior, menor, i;
	
	printf("Leia os numeros:\n");
	
	for(i=0; i<10; i++){
		scanf("%d",&valor[i]);
	}
	
	for(i = 9; i >= 0; i--){
		printf("%d", valor[i]);
		if(i > 0){
			printf(" - ");
		}
	}
	
	for(i=1, maior=valor[0]; i<5; i=i+2){
		int comp_temp = compara(valor[i], valor[i + 1]);
		maior = compara(maior, comp_temp);
	}
	
	printf("\n %d", maior);
	
	return 0;
}
