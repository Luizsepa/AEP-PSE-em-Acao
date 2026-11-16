#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
	
	int num1, num2, inversor;
	
	printf("========== Exercicio 1 ==========\n");
	
	printf("Digite o primeiro valor: ");
	scanf("%d", &num1);	
	
	printf("Digite o segundo valor: ");
	scanf("%d", &num2);	
	
	inversor = num1;
	num1 = num2;
	num2 = inversor;
	
	printf("\nValores invertidos: ");
	printf("\nPrimeiro valor: %d", num1);
	printf("\nSegundo valor: %d", num2);
	
	printf("\n\n========== Exercicio 2 ==========\n");
	
    double valorInicial, numNotacao;
    int expoente;
    
    printf("OBS: importei a biblioteca <math.h> nao sabia se podia ou nao, mas sem laco nao da pra fazer bencao\n\n");

    printf("Digite um valor: ");
    scanf("%lf", &valorInicial);

    expoente = (int)floor(log10(valorInicial));
    numNotacao = valorInicial / pow(10, expoente);

    printf("\nNumero na forma de notacao cientifica: %.2lf x 10^%d\n", numNotacao, expoente);
    
    printf("\n\n========== Exercicio 3 ==========\n");
	
	 int n, res;
	 int bit_64, bit_32, bit_16, bit_8, bit_4, bit_2;
	 printf("insira o valor a ser convertido <= 64: ");
	 scanf("%d",&n);
	 
	 bit_64 = n%2;
	 res = n/2;
	 bit_32 = res%2;
 	 res = res/2;
	 bit_16 = res%2;
	 res = res/2;
	 bit_8 = res%2;
	 res = res/2;
	 bit_4 = res%2;
	 res = res/2;
	 bit_2 = res%2;
	 res = res/2;
	 
 	printf("O numero %d em binario = %d%d%d%d%d%d%d", n, res%2, bit_2, bit_4, bit_8, bit_16, bit_32, bit_64);
	
    printf("\n\n========= Exercicio 4 ========\n");
    
    double salarioFixo, vendasTotais, total;
    
    printf("Digite o salario fixo valor: ");
	scanf("%lf", &salarioFixo);
	
	printf("Digite o valor total de vendas: ");
	scanf("%lf", &vendasTotais);
	
	total = vendasTotais * 0.15;
	
	printf("Total a receber: %.2lf", total + salarioFixo);
	
	printf("\n\n========== Exercicio 5 ==========\n");
	
	 int n, res;
	 int bit_64, bit_32, bit_16, bit_8, bit_4, bit_2;
	 printf("insira o valor a ser convertido: ");
	 scanf("%d",&n); /// -> 41
	 
	 bit_64 = n%2; // -> 1
	 res = n/2; //-> 20
	 
	 bit_32 = res%2; // -> 0
 	 res = res/2; //-> 10
	 
	 bit_16 = res%2; // -> 0
	 res = res/2;
	 
	 bit_8 = res%2;
	 res = res/2;
	 
	 bit_4 = res%2;
	 res = res/2;
	 
	 bit_2 = res%2;
	 res = res/2;
	 
	 printf("o numero %d em bin = %d%d%d%d%d%d%d", n, res%2, bit_2, bit_4, bit_8, bit_16, bit_32, bit_64);
	 
	 return 0;
}
	
	printf("\n\n========== Exercicio 6 ==========\n");
	
	int idadeDias, anos, meses, dias;
	
	printf("Digite sua idade em dias: ");
	scanf("%d", &idadeDias);
	
	anos = idadeDias / 365;
	idadeDias = idadeDias % 365;
	
	meses = idadeDias / 30;
	dias = idadeDias % 30;
	
	printf("Sua idade em Ano(s), Mese(s) e Dia(s) e: %d ano(s) - %d mese(s) - %d dia(s)", anos, meses, dias);
	
	printf("\n\n========== Exercicio 7 ==========\n");
	
	double R, volume;
	
	printf("Digite o raio(R) de uma esfera: ");
	scanf("%lf", &R);
	
	volume = (4.0/3)* 3.14159 *pow(R, 3);
	
	printf("O volume da esfera e de: %.2lf", volume);
	
	printf("\n\n========== Exercicio 8 ==========\n");
	
	double x1, y1, x2, y2, distancia;
	
	printf("Digite o valor de P1\n");
	printf("x1 = ");
	scanf("%lf", &x1);
	printf("y1 = ");
	scanf("%lf", &y1);
	
	printf("Digite o valor de P2\n");
	printf("x2 = ");
	scanf("%lf", &x2);
	printf("y2 = ");
	scanf("%lf", &y2);
	
	distancia = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)); 
	
	printf("Distancia, aplicando a distancia euclidiana: %.2lf", distancia);
	
	return 0;
}
