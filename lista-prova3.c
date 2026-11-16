#include <stdio.h>
#include <stdlib.h>

void enunciadoProva(int modeloProva);

void prova3_questao0();
void prova3_questao1();
void prova3_questao2();

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
        case 3:
            printf("\nDigite o numero da questao (0, 1 ou 2): ");
            scanf("%d", &questao);

            switch (questao)
            {
                case 0:
                    prova3_questao0();
                    break;

                case 1:
                    prova3_questao1();
                    break;

                case 2:
                    prova3_questao2();
                    break;

                default:
                    printf("\nERRO: questao invalida.\n");
            }
            break;

        default:
            printf("\nModelo ainda nao foi adicionado.\n");
    }
}

void prova3_questao0()
{
    int total, capacidade;
    int mochilas, sobra;

    printf("\n--- ESOFT-M-B - QUESTAO 0 ---\n");

    printf("Digite a quantidade total de itens: ");
    scanf("%d", &total);

    printf("Digite a capacidade de cada mochila: ");
    scanf("%d", &capacidade);

    mochilas = total / capacidade;
    sobra = total % capacidade;

    printf("\nMochilas totalmente preenchidas: %d\n", mochilas);
    printf("Itens que sobraram: %d\n", sobra);
}

void prova3_questao1()
{
    int a, b, c;

    printf("\n--- ESOFT-M-B - QUESTAO 1 ---\n");

    printf("Digite o valor de a: ");
    scanf("%d", &a);

    printf("Digite o valor de b: ");
    scanf("%d", &b);

    printf("Digite o valor de c: ");
    scanf("%d", &c);

    if ((a == b) || (a == c) || (b == c))
    {
        printf("\nOs numeros tem que ser distintos.\n");
    }
    else
    {
        printf("\nOrdem crescente: ");

        if ((a < b) && (a < c))
        {
            if (b < c)
            {
                printf("%d %d %d\n", a, b, c);
            }
            else
            {
                printf("%d %d %d\n", a, c, b);
            }
        }
        else if ((b < a) && (b < c))
        {
            if (a < c)
            {
                printf("%d %d %d\n", b, a, c);
            }
            else
            {
                printf("%d %d %d\n", b, c, a);
            }
        }
        else
        {
            if (a < b)
            {
                printf("%d %d %d\n", c, a, b);
            }
            else
            {
                printf("%d %d %d\n", c, b, a);
            }
        }
    }
}

void prova3_questao2()
{
    float valor1, valor2;
    int codigo;
    int resultado;

    printf("\n--- ESOFT-M-B - QUESTAO 2 ---\n");

    printf("Digite o primeiro valor: ");
    scanf("%f", &valor1);

    printf("Digite o segundo valor: ");
    scanf("%f", &valor2);

    printf("\nOperacoes:\n");
    printf("1 - Maior que (>)\n");
    printf("2 - Menor que (<)\n");
    printf("3 - Igual a (==)\n");
    printf("4 - Diferente (!=)\n");

    printf("\nDigite o codigo da operacao: ");
    scanf("%d", &codigo);

    switch (codigo)
    {
        case 1:
            resultado = valor1 > valor2;
            printf("\nResultado: %d\n", resultado);
            break;

        case 2:
            resultado = valor1 < valor2;
            printf("\nResultado: %d\n", resultado);
            break;

        case 3:
            resultado = valor1 == valor2;
            printf("\nResultado: %d\n", resultado);
            break;

        case 4:
            resultado = valor1 != valor2;
            printf("\nResultado: %d\n", resultado);
            break;

        default:
            printf("\noperador inválido\n");
    }
}
