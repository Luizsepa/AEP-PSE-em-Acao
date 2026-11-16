#include <stdio.h>
#include <stdlib.h>

void enunciadoProva(int modeloProva);

void prova2_questao0();
void prova2_questao1();
void prova2_questao2();

int main(int argc, char *argv[]) {

    int modeloProva;

    printf("Digite qual modelo de prova voce deseja acessar:\n");
    printf("1 - Modelo 1 || 2 - Modelo 2 || 3 - Modelo 3\n");
    scanf("%d", &modeloProva);

    enunciadoProva(modeloProva);

    return 0;
}

void enunciadoProva(int modeloProva)
{
    int questao;

    switch (modeloProva)
    {
        case 1:
            printf("\nModelo 1 ainda nao foi adicionado.\n");
            break;

        case 2:
            printf("\nDigite o numero da questao (0, 1 ou 2): ");
            scanf("%d", &questao);

            switch (questao)
            {
                case 0:
                    prova2_questao0();
                    break;

                case 1:
                    prova2_questao1();
                    break;

                case 2:
                    prova2_questao2();
                    break;

                default:
                    printf("\nERRO: questao invalida.\n");
            }
            break;

        case 3:
            printf("\nModelo 3 ainda nao foi adicionado.\n");
            break;

        default:
            printf("\nERRO: modelo de prova invalido.\n");
    }
}

void prova2_questao0()
{
    int n1, n2, n3, n4;

    printf("\n--- ESOFT-M-A - QUESTAO 0 ---\n");

    printf("Digite o 1º numero: ");
    scanf("%d", &n1);

    printf("Digite o 2º numero: ");
    scanf("%d", &n2);

    printf("Digite o 3º numero: ");
    scanf("%d", &n3);

    printf("Digite o 4º numero: ");
    scanf("%d", &n4);

    printf("\nNumeros impares:\n");

    if (n1 % 2 != 0)
    {
        printf("%d\n", n1);
    }

    if (n2 % 2 != 0)
    {
        printf("%d\n", n2);
    }

    if (n3 % 2 != 0)
    {
        printf("%d\n", n3);
    }

    if (n4 % 2 != 0)
    {
        printf("%d\n", n4);
    }

    printf("\nMultiplos de 5:\n");

    if (n1 % 5 == 0)
    {
        printf("%d\n", n1);
    }

    if (n2 % 5 == 0)
    {
        printf("%d\n", n2);
    }

    if (n3 % 5 == 0)
    {
        printf("%d\n", n3);
    }

    if (n4 % 5 == 0)
    {
        printf("%d\n", n4);
    }
}

void prova2_questao1()
{
    int total, capacidade;
    int mochilas, sobra;

    printf("\n--- ESOFT-M-A - QUESTAO 1 ---\n");

    printf("Digite a quantidade total de itens: ");
    scanf("%d", &total);

    printf("Digite a capacidade de cada mochila: ");
    scanf("%d", &capacidade);

    mochilas = total / capacidade;
    sobra = total % capacidade;

    printf("\nQuantidade de mochilas totalmente preenchidas: ");
    printf("%d\n", mochilas);

    printf("Quantidade de itens que sobraram: ");
    printf("%d\n", sobra);
}

void prova2_questao2()
{
    float valor, resultado;
    int codigo;

    printf("\n--- ESOFT-M-A - QUESTAO 2 ---\n");

    printf("Digite o valor: ");
    scanf("%f", &valor);

    printf("\nCodigos disponiveis:\n");
    printf("1 - Celsius para Fahrenheit\n");
    printf("2 - Fahrenheit para Celsius\n");
    printf("3 - Celsius para Kelvin\n");
    printf("4 - Metro para Milha\n");
    printf("5 - Milha para Metro\n");
    printf("8 - Quilograma para Libra\n");
    printf("9 - Libra para Quilograma\n");
    printf("10 - km/h para mph\n");
    printf("11 - mph para km/h\n");

    printf("\nDigite o codigo da conversao: ");
    scanf("%d", &codigo);

    switch (codigo)
    {
        case 1:
            resultado = valor * 1.8 + 32;
            printf("\nResultado em Fahrenheit: %.2f\n", resultado);
            break;

        case 2:
            resultado = (valor - 32) / 1.8;
            printf("\nResultado em Celsius: %.2f\n", resultado);
            break;

        case 3:
            resultado = valor + 273.15;
            printf("\nResultado em Kelvin: %.2f\n", resultado);
            break;

        case 4:
            resultado = valor / 1609.34;
            printf("\nResultado em milhas: %.4f\n", resultado);
            break;

        case 5:
            resultado = valor * 1609.34;
            printf("\nResultado em metros: %.2f\n", resultado);
            break;

        case 8:
            resultado = valor * 2.205;
            printf("\nResultado em libras: %.2f\n", resultado);
            break;

        case 9:
            resultado = valor / 2.205;
            printf("\nResultado em quilogramas: %.2f\n", resultado);
            break;

        case 10:
            resultado = valor / 1.609;
            printf("\nResultado em mph: %.2f\n", resultado);
            break;

        case 11:
            resultado = valor * 1.609;
            printf("\nResultado em km/h: %.2f\n", resultado);
            break;

        default:
            printf("\nERRO: codigo de unidade invalido.\n");
    }
}
