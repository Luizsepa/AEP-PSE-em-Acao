#include <stdio.h>
#include <stdlib.h>
#define tam 10
int calcula_maior (int a, int b){
	return ((a+b+(abs((a-b))))/2);
}

int main(int argc, char *argv[]) {
	int vet[10];
	int i, maior;

	for(i=0; i<10; i++){
		scanf("%d", &vet[i]);
	}
	
	for(i=1, maior=vet[0]; i<10; i++){
		
	}
	return 0;
}
