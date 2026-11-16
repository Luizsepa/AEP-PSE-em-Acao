#include <stdio.h>
#include <stdlib.h>

void enunciadoProva(int modeloProva);

int main(int argc, char *argv[]) {

    int modeloProva;

    printf("Digite qual modelo de prova voce deseja acessar:\n");
    printf("1 - Modelo 1 || 2 - Modelo 2 || 3 - Modelo 3\n");
    scanf("%d", &modeloProva);

    enunciadoProva(modeloProva);

    return 0;
}

void enunciadoProva(int modeloProva) {

    int questao;

    printf("Digite a questao voce deseja resolver ou ver a resolucao:\n");
    printf("1 - Questao 1 || 2 - Questao 2 || 3 - Questao 3\n");
    scanf("%d", &questao);

    switch(questao) {

        case 1: {

            int num1, num2, num3, num4, num5;

            printf("Digite 5 valores nesse formato: x - x - x - x - x\n");
            scanf("%d - %d - %d - %d - %d",
                  &num1, &num2, &num3, &num4, &num5);

            if((num1 + 1) == num2 || (num1 + 1) == num3 || (num1 + 1) == num4 || (num1 + 1) == num5) {

                printf("%d e %d sao consecutivos\n", num1, num1 + 1);

            } if((num2 + 1) == num1 || (num2 + 1) == num3 || (num2 + 1) == num4 || (num2 + 1) == num5) {

                printf("%d e %d sao consecutivos\n", num2, num2 + 1);

            } if((num3 + 1) == num1 || (num3 + 1) == num2 || (num3 + 1) == num4 || (num3 + 1) == num5) {

                printf("%d e %d sao consecutivos\n", num3, num3 + 1);

            } if((num4 + 1) == num1 || (num4 + 1) == num2 || (num4 + 1) == num3 || (num4 + 1) == num5) {

                printf("%d e %d sao consecutivos\n", num4, num4 + 1);

            } if((num5 + 1) == num1 || (num5 + 1) == num2 || (num5 + 1) == num3 || (num5 + 1) == num4) {

                printf("%d e %d sao consecutivos\n", num5, num5 + 1);

			}

            break;
        }

        case 2 :
		 	;
            float IMC, peso, altura; 
            
            	printf("Escreva seu peso: ");
            	scanf("%f", &peso);
            	printf("\nEscreva seu altura: ");
            	scanf("%f", &altura);
            	
            	IMC = peso / (altura *altura);
            	
				if(IMC < 18.5){
					printf("Voce esta abaixo do peso");
				}else if(IMC >= 18.5 && IMC <= 24.9){
					printf("Seu peso esta normal");
				}else if(IMC >= 25 && IMC <= 29.9){
					printf("Voce esta acima do peso");
				}else{
					printf("Voce esta com obesidade!");
				}
				            
            break;

        case 3:
            printf("- Exercicio torre de Hanói -");
            int a, b, c;
            
            a = 6;
			b = 0;
			c = 0;
            
            printf("%d - %d - %d", a, b, c);
            c = 1;
			a -= 1;

			printf("%d - %d - %d", a, b, c);    
			b = 2;
			a -= 2;

			printf("%d - %d - %d", a, b, c); //3 - 2 - 1
			b = 3;
			c -= 1;

			printf("%d - %d - %d", a, b, c); //3 - 3 - 0
			c = 3;
			a -= 3;

			printf("%d - %d - %d", a, b, c); //0 - 3 - 3
			a = 1;
			b -= 1;

			printf("%d - %d - %d", a, b, c); //1 - 2 - 3
			c += b;
			b -= 2;

			printf("%d - %d - %d", a, b, c); //1 - 0 - 5
			c += a;
			a -= 1;

			printf("%d - %d - %d", a, b, c);

			break;

        default:
            printf("Modelo invalido.\n");
    }
}
