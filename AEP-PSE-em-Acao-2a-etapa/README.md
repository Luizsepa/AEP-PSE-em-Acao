# PSE em Ação

**Sistema de Planejamento e Acompanhamento de Ações de Saúde na Escola**

Projeto acadêmico desenvolvido para a **AEP – Atividade de Estudo Programado**, do curso de **Análise e Desenvolvimento de Sistemas**, referente ao **2º semestre de 2026** da UniCesumar.

## Sobre o projeto

O **PSE em Ação** é uma proposta de aplicação simples desenvolvida em linguagem **C**, executada em ambiente de terminal, com o objetivo de auxiliar uma equipe responsável pelo Programa Saúde na Escola (PSE) no planejamento e acompanhamento de ações coletivas realizadas em escolas.

A proposta surgiu a partir da necessidade de organizar informações que poderiam estar registradas em anotações, formulários e planilhas separadas, dificultando a consulta das ações planejadas, realizadas e canceladas, além do acompanhamento da quantidade de participantes.

O sistema será desenvolvido de forma introdutória, utilizando conceitos básicos de programação em C, compatíveis com o nível do segundo semestre do curso.

## Objetivo

Desenvolver uma aplicação simples capaz de auxiliar no registro e acompanhamento de ações coletivas do Programa Saúde na Escola, apresentando informações organizadas e facilitando o acompanhamento das atividades.

## Funcionalidades previstas

O sistema terá como funcionalidades principais:

- Cadastro de ações do PSE;
- Listagem das ações cadastradas;
- Pesquisa de ações por código, escola ou tema;
- Atualização da situação das ações;
- Registro da quantidade efetiva de participantes quando a ação for realizada;
- Geração de um resumo geral das ações e da participação.

## Tecnologias e conceitos

O projeto utilizará:

- Linguagem C;
- `struct`;
- Vetores;
- Funções;
- Estruturas condicionais;
- Estruturas de repetição;
- Entrada e saída de dados;
- Validação de informações;
- Execução em terminal.

## Escopo e limitações

O projeto foi planejado para permanecer simples e compatível com o nível introdutório da disciplina.

O sistema **não** terá:

- login ou cadastro de usuários;
- banco de dados;
- interface gráfica;
- aplicação web;
- API;
- inteligência artificial;
- cadastro individual de estudantes;
- dados clínicos;
- diagnóstico ou triagem médica;
- prescrição ou recomendação de tratamento;
- prontuários.

Serão utilizados somente **dados fictícios e informações coletivas** sobre as ações, respeitando a privacidade dos estudantes.

## Estrutura do projeto

```text
AEP-PSE-em-Acao/
│
├── README.md
│
├── src/                                  (2ª etapa)
│   └── pse_em_acao.c
│
├── tests/                                (2ª etapa)
│   ├── executar_testes.sh
│   └── saidas/
│
└── docs/
    ├── producao-textual.docx
    ├── requisitos.docx
    ├── AEP-PSE-EM-ACAO-1a-ENTREGA-FINAL.docx
    ├── AEP-PSE-EM-ACAO-2a-ENTREGA.docx   (2ª etapa)
    ├── roteiro-video.md                  (2ª etapa)
    │
    ├── fluxogramas/
    │   ├── fluxograma-geral.png
    │   ├── fluxograma-cadastro.png
    │   └── fluxograma-cadastro-revisado.png   (2ª etapa)
    │
    ├── pseudocodigos/
    │   └── pseudocodigos.docx
    │
    ├── planejamento/
    │   └── sprints.docx
    │
    ├── casos-de-uso/                     (2ª etapa)
    │   └── diagrama-casos-de-uso.png
    │
    └── capturas/                         (2ª etapa)
```

Durante a primeira etapa, o repositório concentra principalmente os documentos de **análise e planejamento** do projeto. Na segunda etapa foram adicionados o código-fonte, os testes e a documentação final.

## Primeira entrega

A primeira entrega da AEP contempla:

- Produção textual;
- Contextualização do PSE;
- Questão norteadora;
- Objetivos;
- Justificativa;
- Identificação do usuário;
- Delimitação do escopo;
- Requisitos funcionais e não funcionais;
- Fluxogramas;
- Pseudocódigos;
- Planejamento das sprints semanais.

Nesta etapa, o sistema completo ainda **não está implementado**, pois o objetivo é realizar a análise e o planejamento da solução.

## Segunda entrega

A segunda entrega da AEP contempla:

- Código-fonte em C (`src/pse_em_acao.c`) com o menu e as seis funcionalidades;
- Validações de entrada (código duplicado, campos vazios, data inválida, quantidades negativas, ação inexistente, limite de 100 ações e divisão por zero);
- Testes com dados fictícios (22 casos automatizados);
- Diagrama e descrição dos casos de uso;
- Requisitos atualizados e fluxograma do cadastro revisado;
- Manual do usuário e capturas de tela do programa;
- Considerações finais;
- Roteiro do vídeo de apresentação.

O documento completo da segunda entrega está em `docs/AEP-PSE-EM-ACAO-2a-ENTREGA.docx`.

### Como compilar e executar

Requisito: compilador **gcc** (ou outro compilador C compatível com o padrão C11).

```bash
# a partir da raiz do repositório
gcc -Wall -Wextra -std=c11 -o pse_em_acao src/pse_em_acao.c
./pse_em_acao
```

No Windows (MinGW/MSYS2), compile com `-o pse_em_acao.exe` e execute `pse_em_acao.exe`.

### Menu do sistema

| Opção | Funcionalidade |
|---|---|
| 1 | Cadastrar ação |
| 2 | Listar ações |
| 3 | Pesquisar ações (por código, escola ou tema) |
| 4 | Atualizar situação da ação (e registrar participantes efetivos quando Realizada) |
| 5 | Gerar resumo geral |
| 0 | Encerrar |

Os dados ficam apenas em memória e são perdidos ao encerrar o programa.

### Testes

O script compila o programa, executa os 22 casos de teste e informa `PASSOU` ou `FALHOU` para cada um. As saídas ficam em `tests/saidas/`.

```bash
bash tests/executar_testes.sh
```

## Equipe

**Integrantes:**

- Luiz Augusto Cavalheri
- Guilherme Trepack Teixeira
- Pedro Antonio Rangel

## Instituição

**UniCesumar – Universidade Cesumar**

**Curso:** Análise e Desenvolvimento de Sistemas
**AEP:** 2º semestre de 2026

## Status do projeto

**Primeira entrega:** concluída — análise e planejamento.

**Etapa atual:** Segunda entrega — implementação da aplicação em C, testes e documentação final.
