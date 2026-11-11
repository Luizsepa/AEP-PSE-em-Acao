/*
 * PSE em Ação - Sistema de Planejamento e Acompanhamento de Ações de Saúde na Escola
 * AEP - 2º semestre de 2026 - UniCesumar (Análise e Desenvolvimento de Sistemas)
 *
 * Aplicação em terminal para registrar e acompanhar ações coletivas do
 * Programa Saúde na Escola (PSE). Os dados ficam apenas em memória durante a
 * execução e são sempre fictícios e coletivos (nenhum dado individual de
 * estudante é solicitado ou armazenado).
 *
 * Compilação (Linux/macOS/MinGW):
 *     gcc -Wall -Wextra -std=c11 -o pse_em_acao src/pse_em_acao.c
 */

#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#endif

#define MAX_ACOES        100   /* limite de ações armazenadas em memória */
#define TAM_ESCOLA       60
#define TAM_TEMA         40
#define TAM_DATA         11    /* DD/MM/AAAA + '\0' */
#define TAM_PUBLICO      40
#define TAM_RESPONSAVEL  40
#define TAM_LINHA        128

#define ENTRADA_FIM      (-1)  /* fim da entrada (EOF) ao ler um número */

/* Situações possíveis de uma ação (valores iguais às opções do menu). */
enum Situacao { PLANEJADA = 1, REALIZADA = 2, CANCELADA = 3 };

/* Registro de uma ação coletiva do PSE. */
typedef struct {
    int  codigo;
    char escola[TAM_ESCOLA];
    char tema[TAM_TEMA];
    char data[TAM_DATA];
    char publico[TAM_PUBLICO];
    char responsavel[TAM_RESPONSAVEL];
    int  previstos;   /* quantidade prevista de participantes */
    int  efetivos;    /* quantidade efetiva (só tem valor se REALIZADA) */
    int  situacao;
} Acao;

/* ---------------------------------------------------------------------- */
/* Entrada de dados                                                       */
/* ---------------------------------------------------------------------- */

/* Lê uma linha, remove espaços nas pontas e copia para destino.
 * Retorna 0 se a entrada terminou (EOF), 1 caso contrário. */
static int lerLinha(const char *rotulo, char *destino, int tamanho)
{
    char linha[TAM_LINHA];
    char *inicio;
    size_t n;

    printf("%s", rotulo);
    if (fgets(linha, sizeof linha, stdin) == NULL) {
        destino[0] = '\0';
        return 0;
    }

    n = strlen(linha);
    if (n > 0 && linha[n - 1] == '\n') {
        linha[--n] = '\0';
    } else {
        int c;                                  /* linha maior que o buffer: */
        while ((c = getchar()) != '\n' && c != EOF) {
            ;                                   /* descarta o excedente */
        }
    }

    while (n > 0 && isspace((unsigned char)linha[n - 1])) {
        linha[--n] = '\0';
    }
    inicio = linha;
    while (*inicio != '\0' && isspace((unsigned char)*inicio)) {
        inicio++;
    }

    snprintf(destino, (size_t)tamanho, "%s", inicio);
    return 1;
}

/* Lê um número inteiro. Retorna 1 (ok), 0 (valor inválido) ou ENTRADA_FIM. */
static int lerInteiro(const char *rotulo, int *valor)
{
    char texto[TAM_LINHA];
    char *fim;
    long numero;

    if (!lerLinha(rotulo, texto, (int)sizeof texto)) {
        return ENTRADA_FIM;
    }
    if (texto[0] == '\0') {
        return 0;
    }

    errno = 0;
    numero = strtol(texto, &fim, 10);
    if (*fim != '\0' || errno != 0 || numero > INT_MAX || numero < INT_MIN) {
        return 0;
    }

    *valor = (int)numero;
    return 1;
}

/* ---------------------------------------------------------------------- */
/* Validações e utilitários                                               */
/* ---------------------------------------------------------------------- */

/* Valida uma data no formato DD/MM/AAAA (considera anos bissextos). */
static int dataValida(const char *data)
{
    static const int diasNoMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int i, dia, mes, ano, limite;

    if (strlen(data) != 10 || data[2] != '/' || data[5] != '/') {
        return 0;
    }
    for (i = 0; i < 10; i++) {
        if (i != 2 && i != 5 && !isdigit((unsigned char)data[i])) {
            return 0;
        }
    }

    dia = (data[0] - '0') * 10 + (data[1] - '0');
    mes = (data[3] - '0') * 10 + (data[4] - '0');
    ano = (data[6] - '0') * 1000 + (data[7] - '0') * 100 +
          (data[8] - '0') * 10 + (data[9] - '0');

    if (mes < 1 || mes > 12 || ano < 2000 || ano > 2100) {
        return 0;
    }
    limite = diasNoMes[mes - 1];
    if (mes == 2 && ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0)) {
        limite = 29;
    }
    return dia >= 1 && dia <= limite;
}

/* Retorna a posição da ação com o código informado, ou -1 se não existir. */
static int localizarAcao(const Acao acoes[], int total, int codigo)
{
    int i;
    for (i = 0; i < total; i++) {
        if (acoes[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

static int codigoExiste(const Acao acoes[], int total, int codigo)
{
    return localizarAcao(acoes, total, codigo) != -1;
}

static const char *nomeSituacao(int situacao)
{
    switch (situacao) {
    case PLANEJADA: return "Planejada";
    case REALIZADA: return "Realizada";
    case CANCELADA: return "Cancelada";
    default:        return "Desconhecida";
    }
}

/* Verifica se 'texto' contém 'busca', sem diferenciar maiúsculas/minúsculas. */
static int contemTexto(const char *texto, const char *busca)
{
    size_t i, j, tamTexto = strlen(texto), tamBusca = strlen(busca);

    if (tamBusca == 0 || tamBusca > tamTexto) {
        return 0;
    }
    for (i = 0; i + tamBusca <= tamTexto; i++) {
        for (j = 0; j < tamBusca; j++) {
            if (tolower((unsigned char)texto[i + j]) !=
                tolower((unsigned char)busca[j])) {
                break;
            }
        }
        if (j == tamBusca) {
            return 1;
        }
    }
    return 0;
}

/* ---------------------------------------------------------------------- */
/* Saída de dados                                                         */
/* ---------------------------------------------------------------------- */

static void exibirMenu(void)
{
    printf("\n========================================\n");
    printf("   PSE EM AÇÃO - MENU PRINCIPAL\n");
    printf("========================================\n");
    printf(" 1 - Cadastrar ação\n");
    printf(" 2 - Listar ações\n");
    printf(" 3 - Pesquisar ações\n");
    printf(" 4 - Atualizar situação da ação\n");
    printf(" 5 - Gerar resumo geral\n");
    printf(" 0 - Encerrar\n");
    printf("========================================\n");
}

static void mostrarAcao(const Acao *a)
{
    printf("----------------------------------------\n");
    printf("Código.............: %d\n", a->codigo);
    printf("Escola.............: %s\n", a->escola);
    printf("Tema...............: %s\n", a->tema);
    printf("Data prevista......: %s\n", a->data);
    printf("Público-alvo.......: %s\n", a->publico);
    printf("Responsável........: %s\n", a->responsavel);
    printf("Participantes prev.: %d\n", a->previstos);
    printf("Participantes efet.: %d\n", a->efetivos);
    printf("Situação...........: %s\n", nomeSituacao(a->situacao));
}

/* ---------------------------------------------------------------------- */
/* Funcionalidades                                                        */
/* ---------------------------------------------------------------------- */

/* RF01 - Cadastrar ação. */
static void cadastrarAcao(Acao acoes[], int *total)
{
    Acao nova;
    int codigo, previstos, lido;

    printf("\n--- Cadastrar ação ---\n");

    if (*total >= MAX_ACOES) {
        printf("Erro: limite de armazenamento atingido (%d ações). "
               "Não há espaço para novo cadastro.\n", MAX_ACOES);
        return;
    }

    lido = lerInteiro("Código da ação (número inteiro positivo): ", &codigo);
    if (lido != 1 || codigo <= 0) {
        printf("Erro: o código deve ser um número inteiro positivo.\n");
        return;
    }
    if (codigoExiste(acoes, *total, codigo)) {
        printf("Erro: código já cadastrado.\n");
        return;
    }

    lerLinha("Escola: ", nova.escola, TAM_ESCOLA);
    lerLinha("Tema (ex.: alimentação saudável): ", nova.tema, TAM_TEMA);
    lerLinha("Data prevista (DD/MM/AAAA): ", nova.data, TAM_DATA);
    lerLinha("Público-alvo (ex.: 6º ano): ", nova.publico, TAM_PUBLICO);
    lerLinha("Responsável: ", nova.responsavel, TAM_RESPONSAVEL);
    lido = lerInteiro("Quantidade prevista de participantes: ", &previstos);

    if (nova.escola[0] == '\0' || nova.tema[0] == '\0' || nova.data[0] == '\0' ||
        nova.publico[0] == '\0' || nova.responsavel[0] == '\0') {
        printf("Erro: todos os campos são obrigatórios e não podem ficar vazios.\n");
        return;
    }
    if (!dataValida(nova.data)) {
        printf("Erro: data inválida. Use o formato DD/MM/AAAA com uma data existente.\n");
        return;
    }
    if (lido != 1) {
        printf("Erro: a quantidade prevista deve ser um número inteiro.\n");
        return;
    }
    if (previstos < 0) {
        printf("Erro: a quantidade prevista não pode ser negativa.\n");
        return;
    }

    nova.codigo = codigo;
    nova.previstos = previstos;
    nova.efetivos = 0;
    nova.situacao = PLANEJADA;
    acoes[*total] = nova;
    (*total)++;

    printf("Ação cadastrada com sucesso (situação inicial: Planejada).\n");
}

/* RF02 - Listar ações. */
static void listarAcoes(const Acao acoes[], int total)
{
    int i;

    printf("\n--- Ações cadastradas ---\n");
    if (total == 0) {
        printf("Nenhuma ação cadastrada.\n");
        return;
    }

    for (i = 0; i < total; i++) {
        mostrarAcao(&acoes[i]);
    }
    printf("----------------------------------------\n");
    printf("Total de ações: %d\n", total);
}

/* RF03 - Pesquisar ações por código, escola ou tema. */
static void pesquisarAcoes(const Acao acoes[], int total)
{
    int opcao, codigo, i, encontradas = 0;
    char valor[TAM_LINHA];

    printf("\n--- Pesquisar ações ---\n");
    printf("1 - Código\n2 - Escola\n3 - Tema\n");

    if (lerInteiro("Pesquisar por: ", &opcao) != 1 || opcao < 1 || opcao > 3) {
        printf("Opção de pesquisa inválida.\n");
        return;
    }

    if (opcao == 1) {
        if (lerInteiro("Código: ", &codigo) != 1) {
            printf("Erro: informe um código numérico.\n");
            return;
        }
        i = localizarAcao(acoes, total, codigo);
        if (i != -1) {
            mostrarAcao(&acoes[i]);
            encontradas = 1;
        }
    } else {
        lerLinha(opcao == 2 ? "Nome (ou parte do nome) da escola: "
                            : "Tema (ou parte do tema): ",
                 valor, (int)sizeof valor);
        if (valor[0] == '\0') {
            printf("Erro: o valor da pesquisa não pode ficar vazio.\n");
            return;
        }
        for (i = 0; i < total; i++) {
            const char *campo = (opcao == 2) ? acoes[i].escola : acoes[i].tema;
            if (contemTexto(campo, valor)) {
                mostrarAcao(&acoes[i]);
                encontradas++;
            }
        }
    }

    if (encontradas == 0) {
        printf("Nenhuma ação encontrada.\n");
    } else {
        printf("----------------------------------------\n");
        printf("Ações encontradas: %d\n", encontradas);
    }
}

/* RF04 e RF05 - Atualizar situação e registrar participantes efetivos. */
static void atualizarSituacao(Acao acoes[], int total)
{
    int codigo, posicao, novaSituacao, efetivos = 0;

    printf("\n--- Atualizar situação ---\n");

    if (lerInteiro("Código da ação: ", &codigo) != 1) {
        printf("Erro: informe um código numérico.\n");
        return;
    }
    posicao = localizarAcao(acoes, total, codigo);
    if (posicao == -1) {
        printf("Ação não encontrada.\n");
        return;
    }

    printf("Situação atual: %s\n", nomeSituacao(acoes[posicao].situacao));
    printf("1 - Planejada\n2 - Realizada\n3 - Cancelada\n");
    if (lerInteiro("Nova situação: ", &novaSituacao) != 1 ||
        novaSituacao < PLANEJADA || novaSituacao > CANCELADA) {
        printf("Situação inválida.\n");
        return;
    }

    if (novaSituacao == REALIZADA) {
        if (lerInteiro("Quantidade efetiva de participantes: ", &efetivos) != 1) {
            printf("Erro: a quantidade efetiva deve ser um número inteiro.\n");
            return;
        }
        if (efetivos < 0) {
            printf("Erro: a quantidade efetiva não pode ser negativa.\n");
            return;
        }
    }

    /* Só chega aqui com entradas válidas; efetivos fica 0 se não for Realizada. */
    acoes[posicao].situacao = novaSituacao;
    acoes[posicao].efetivos = efetivos;
    printf("Situação atualizada com sucesso: %s.\n", nomeSituacao(novaSituacao));
}

/* RF06 - Gerar resumo geral. */
static void gerarResumo(const Acao acoes[], int total)
{
    int i, planejadas = 0, realizadas = 0, canceladas = 0;
    long totalPrevistos = 0, previstosRealizadas = 0, totalEfetivos = 0;
    double percentualGeral = 0.0, percentualRealizadas = 0.0;

    printf("\n--- Resumo geral ---\n");
    if (total == 0) {
        printf("Nenhuma ação cadastrada. O resumo está zerado.\n");
    }

    for (i = 0; i < total; i++) {
        totalPrevistos += acoes[i].previstos;
        if (acoes[i].situacao == PLANEJADA) {
            planejadas++;
        } else if (acoes[i].situacao == REALIZADA) {
            realizadas++;
            previstosRealizadas += acoes[i].previstos;
            totalEfetivos += acoes[i].efetivos;
        } else if (acoes[i].situacao == CANCELADA) {
            canceladas++;
        }
    }

    /* Evita divisão por zero quando o total previsto é 0. */
    if (totalPrevistos > 0) {
        percentualGeral = (double)totalEfetivos / (double)totalPrevistos * 100.0;
    }
    if (previstosRealizadas > 0) {
        percentualRealizadas = (double)totalEfetivos / (double)previstosRealizadas * 100.0;
    }

    printf("Ações planejadas.....................: %d\n", planejadas);
    printf("Ações realizadas.....................: %d\n", realizadas);
    printf("Ações canceladas.....................: %d\n", canceladas);
    printf("Total previsto (todas as ações)......: %ld\n", totalPrevistos);
    printf("Total de participantes efetivos......: %ld\n", totalEfetivos);
    printf("Participação sobre o total previsto..: %.1f%%\n", percentualGeral);
    printf("Participação nas ações realizadas....: %.1f%%\n", percentualRealizadas);
}

/* ---------------------------------------------------------------------- */
/* Programa principal                                                     */
/* ---------------------------------------------------------------------- */

int main(void)
{
    Acao acoes[MAX_ACOES];
    int total = 0;
    int opcao = -1;
    int leitura;

#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    printf("PSE em Ação - Planejamento e Acompanhamento de Ações de Saúde na Escola\n");
    printf("Use apenas dados fictícios e coletivos (sem dados individuais de estudantes).\n");

    do {
        exibirMenu();
        leitura = lerInteiro("Escolha uma opção: ", &opcao);
        if (leitura == ENTRADA_FIM) {
            opcao = 0;
        } else if (leitura != 1) {
            opcao = -1;
        }

        switch (opcao) {
        case 1: cadastrarAcao(acoes, &total);      break;
        case 2: listarAcoes(acoes, total);         break;
        case 3: pesquisarAcoes(acoes, total);      break;
        case 4: atualizarSituacao(acoes, total);   break;
        case 5: gerarResumo(acoes, total);         break;
        case 0: printf("\nEncerrando o PSE em Ação. Até logo!\n"); break;
        default: printf("Opção inválida. Escolha um número do menu.\n");
        }
    } while (opcao != 0);

    return 0;
}
