#include <stdio.h>
#include <stdlib.h>

void atividade1();
void atividade2();
void atividade3();
void atividade4();
void atividade5();
void atividade6();
void atividade7();
void atividade8();
void atividade9();
void atividade10();

int main() {

    int opcao;

    printf("\n========== MENU DE ATIVIDADES ==========\n");
    printf("1 - Idade e ano de nascimento\n");
    printf("2 - Conversao de km/h para m/s\n");
    printf("3 - Conversao de reais para dolares\n");
    printf("4 - Celsius para Fahrenheit\n");
    printf("5 - Graus para radianos\n");
    printf("6 - Sucessor e antecessor\n");
    printf("7 - Divisao de premio\n");
    printf("8 - Conversao de segundos\n");
    printf("9 - Consumo de combustivel\n");
    printf("10 - Maior entre tres valores\n");
    printf("0 - Sair\n");
    printf("=========================================\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch(opcao) {

        case 1:
            atividade1();
            break;
        case 2:
            atividade2();
            break;
        case 3:
            atividade3();
            break;
        case 4:
            atividade4();
            break;
        case 5:
            atividade5();
            break;
        case 6:
            atividade6();
            break;
        case 7:
            atividade7();
            break;
        case 8:
            atividade8();
            break;
        case 9:
            atividade9();
            break;
        case 10:
            atividade10();
            break;
        default:
            printf("Ok, ate mais...");
    }

    return 0;
}
void atividade1() {

    int idade, anoAtual, anoNasci;

    printf("\n========== Atividade 1 ==========\n");

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    printf("Digite o ano atual: ");
    scanf("%d", &anoAtual);

    anoNasci = anoAtual - idade;

    printf("Voce nasceu aproximadamente no ano de %d.\n", anoNasci);
}
void atividade2() {

    float quilometrosHora, metrosSegundo;

    printf("\n========== Atividade 2 ==========\n");

    printf("Digite a velocidade em km/h: ");
    scanf("%f", &quilometrosHora);

    metrosSegundo = quilometrosHora / 3.6;

    printf("A velocidade em m/s e %.2f.\n", metrosSegundo);
}
void atividade3() {

    float reais, dolares, cotacao_dolar;

    printf("\n========== Atividade 3 ==========\n");

    printf("Escreva o valor em reais: ");
    scanf("%f", &reais);

    printf("Escreva a cotacao do dolar: ");
    scanf("%f", &cotacao_dolar);

    dolares = reais / cotacao_dolar;

    printf("O valor em dolares e U$ %.2f.\n", dolares);
}
void atividade4() {

    float celsius, fahrenheit;

    printf("\n========== Atividade 4 ==========\n");

    printf("Digite a temperatura em graus celsius: ");
    scanf("%f", &celsius);

    fahrenheit = celsius * (9.0 / 5.0) + 32.0;

    printf("A temperatura em fahrenheit e %.2f.\n", fahrenheit);
}
void atividade5() {

    float graus, radianos;
    const float PI = 3.141592;

    printf("\n========== Atividade 5 ==========\n");

    printf("Digite o angulo em graus: ");
    scanf("%f", &graus);

    radianos = graus * (PI / 180.0);

    printf("O angulo em radianos e %.3f.\n", radianos);
}
void atividade6() {

    int a;

    printf("\n========== Atividade 6 ==========\n");

    printf("Escreva um numero inteiro: ");
    scanf("%d", &a);

    printf("\nO valor sucessor e: %d", a + 1);
    printf("\nO valor antecessor e: %d", a - 1);
}
void atividade7() {

    double valor = 780000;

    printf("\n========== Atividade 7 ==========\n");

    printf("O valor recebido pelo primeiro ganhador e: %.2lf",
           (valor / 100) * 46);

    printf("\nO valor recebido pelo segundo ganhador e: %.2lf",
           (valor / 100) * 32);

    printf("\nO valor recebido pelo terceiro ganhador e: %.2lf",
           (valor / 100) * 22);
}
void atividade8() {

    int duracaoSegundos, horas, minutos, segundos;

    printf("\n========== Atividade 8 ==========\n");

    printf("Escreva a duracao de um evento em segundos: ");
    scanf("%d", &duracaoSegundos);

    horas = duracaoSegundos / 3600;
    duracaoSegundos = duracaoSegundos % 3600;

    minutos = duracaoSegundos / 60;
    segundos = duracaoSegundos % 60;

    printf("O tempo desse evento sera de: %d:%d:%d",
           horas, minutos, segundos);
}
void atividade9() {

    int tempoGasto, veloMedia, distancia;
    double litros;

    printf("\n========== Atividade 9 ==========\n");

    printf("Escreva quantas horas foram necessarias para essa viagem: ");
    scanf("%d", &tempoGasto);

    printf("Escreva a media de velocidade durante a viagem: ");
    scanf("%d", &veloMedia);

    distancia = tempoGasto * veloMedia;

    litros = distancia / 12.0;

    printf("Seriam necessarios %.3lf litros para completar a viagem.",
           litros);
}
void atividade10() {

    int x, y, z, maiorAB, maiorABC;

    printf("\n========== Atividade 10 ==========\n");

    printf("Escreva o primeiro valor: ");
    scanf("%d", &x);

    printf("Escreva o segundo valor: ");
    scanf("%d", &y);

    printf("Escreva o terceiro valor: ");
    scanf("%d", &z);

    maiorAB = (x + y + abs(x - y)) / 2;

    maiorABC = (maiorAB + z + abs(maiorAB - z)) / 2;

    printf("Eh o maior: %d", maiorABC);
}
