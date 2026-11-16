#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void exec2 (){
	float dola, real, cota;
	scanf("%f", &real);
	scanf("%f", &cota);
	
	printf("%f reais sao %f dolinhos\n ", real, (real/cota));
}
void exec3 (){
	float tempC, tempF;
	scanf("%f", &tempC);
	
	tempF = tempC *(9.0/5.0) + 32.0;
	
	printf("A temperatura maxima de hoje ai dento %f\n ", tempF);
}
void exec8 (){
	int segundos, horas, minutos;
		
	scanf("%d", &segundos);
	
	horas = segundos/3600 ;
	minutos = (segundos-(horas*3600))/60;
	segundos = segundos-((horas*3600)+(minutos*60));
	
	printf("Tempo %d:%d:%d\n", horas , minutos, segundos);
}
int main(int argc, char *argv[]) {
	
	int resposta;
	
	printf("Usuario, qual exercio quer resolver? |2|3|8|: \n");
	scanf("%d", &resposta);
	
	switch (resposta){
		case 2:
			exec2();
		break;
		case 3: 
			exec3();
		break;
		case 8:
			exec8();
		break;

return 0;
				
}
}
