#!/usr/bin/env bash
# Executa os casos de teste do PSE em Ação.
# Cada caso envia entradas ao programa (como se fossem digitadas), salva a
# saída em tests/saidas/<ID>.txt e confere se os trechos esperados aparecem.
#
# Uso (a partir da raiz do repositório):  bash tests/executar_testes.sh

set -u
RAIZ="$(cd "$(dirname "$0")/.." && pwd)"
BIN="$RAIZ/pse_em_acao"
SAIDAS="$RAIZ/tests/saidas"

gcc -Wall -Wextra -std=c11 -o "$BIN" "$RAIZ/src/pse_em_acao.c" || exit 1
mkdir -p "$SAIDAS"
rm -f "$SAIDAS"/*.txt

TOTAL=0
FALHAS=0

# rodar <ID> <descrição> <entrada> <trecho esperado>...
rodar() {
    local id="$1" desc="$2" entrada="$3"
    shift 3
    local saida="$SAIDAS/$id.txt" ok=1 trecho
    printf '%b' "$entrada" | "$BIN" > "$saida" 2>&1
    for trecho in "$@"; do
        if ! grep -qF -- "$trecho" "$saida"; then
            ok=0
            echo "   trecho não encontrado: $trecho"
        fi
    done
    TOTAL=$((TOTAL + 1))
    if [ "$ok" -eq 1 ]; then
        echo "[PASSOU] $id - $desc"
    else
        echo "[FALHOU] $id - $desc"
        FALHAS=$((FALHAS + 1))
    fi
}

# Cadastros fictícios reutilizados nos casos (opção 1 do menu + 7 campos).
A1="1\n1\nEscola Municipal Aurora\nAlimentação saudável\n15/03/2027\n6º ano\nMaria Souza\n40\n"
A2="1\n2\nEscola Estadual Horizonte\nSaúde mental\n22/03/2027\n8º ano\nCarlos Lima\n60\n"
A3="1\n3\nEscola Municipal Aurora\nAtividade física\n05/04/2027\n5º ano\nAna Paula\n20\n"

rodar CT01 "Cadastrar e listar ação válida" \
    "${A1}2\n0\n" \
    "Ação cadastrada com sucesso" "Escola Municipal Aurora" "Situação...........: Planejada" "Total de ações: 1"

rodar CT02 "Rejeitar código duplicado" \
    "${A1}${A1}0\n" \
    "Erro: código já cadastrado."

rodar CT03 "Rejeitar campo obrigatório vazio (e não gravar)" \
    "1\n10\n\nSaúde bucal\n10/04/2027\n7º ano\nJoão\n30\n2\n0\n" \
    "todos os campos são obrigatórios" "Nenhuma ação cadastrada."

rodar CT04 "Rejeitar quantidade prevista negativa" \
    "1\n11\nEscola X\nSaúde bucal\n10/04/2027\n7º ano\nJoão\n-5\n0\n" \
    "a quantidade prevista não pode ser negativa"

rodar CT05 "Rejeitar quantidade prevista não numérica" \
    "1\n12\nEscola X\nSaúde bucal\n10/04/2027\n7º ano\nJoão\nabc\n0\n" \
    "a quantidade prevista deve ser um número inteiro"

rodar CT06 "Rejeitar data inexistente (31/02)" \
    "1\n13\nEscola X\nSaúde bucal\n31/02/2027\n7º ano\nJoão\n10\n0\n" \
    "Erro: data inválida"

rodar CT07 "Rejeitar código zero ou não numérico" \
    "1\n0\n1\nabc\n0\n" \
    "o código deve ser um número inteiro positivo"

rodar CT08 "Pesquisar por código (existente e inexistente)" \
    "${A1}3\n1\n1\n3\n1\n99\n0\n" \
    "Ações encontradas: 1" "Nenhuma ação encontrada."

rodar CT09 "Pesquisar por escola e tema (parcial, sem diferenciar caixa)" \
    "${A1}${A2}3\n2\naurora\n3\n3\nMENTAL\n3\n2\nxyz\n0\n" \
    "Escola Municipal Aurora" "Escola Estadual Horizonte" "Nenhuma ação encontrada."

rodar CT10 "Rejeitar opção de pesquisa inválida" \
    "3\n5\n0\n" \
    "Opção de pesquisa inválida."

rodar CT11 "Atualizar para Realizada com participantes efetivos" \
    "${A1}4\n1\n2\n35\n2\n0\n" \
    "Situação atualizada com sucesso: Realizada." "Participantes efet.: 35" "Situação...........: Realizada"

rodar CT12 "Atualizar ação inexistente" \
    "4\n77\n0\n" \
    "Ação não encontrada."

rodar CT13 "Rejeitar quantidade efetiva negativa" \
    "${A1}4\n1\n2\n-3\n0\n" \
    "a quantidade efetiva não pode ser negativa"

rodar CT14 "Rejeitar situação inexistente" \
    "${A1}4\n1\n7\n0\n" \
    "Situação inválida."

rodar CT15 "Cancelar ação zera os participantes efetivos" \
    "${A1}4\n1\n2\n35\n4\n1\n3\n2\n0\n" \
    "Situação atualizada com sucesso: Cancelada." "Participantes efet.: 0" "Situação...........: Cancelada"

rodar CT16 "Resumo geral com ações nas três situações" \
    "${A1}${A2}${A3}4\n1\n2\n30\n4\n2\n3\n5\n0\n" \
    "Ações planejadas.....................: 1" \
    "Ações realizadas.....................: 1" \
    "Ações canceladas.....................: 1" \
    "Total previsto (todas as ações)......: 120" \
    "Total de participantes efetivos......: 30" \
    "Participação sobre o total previsto..: 25.0%" \
    "Participação nas ações realizadas....: 75.0%"

rodar CT17 "Resumo sem ações cadastradas" \
    "5\n0\n" \
    "O resumo está zerado." "Participação sobre o total previsto..: 0.0%"

rodar CT18 "Evitar divisão por zero (previsto igual a 0)" \
    "1\n1\nEscola Z\nCultura de paz\n10/05/2027\n9º ano\nRita\n0\n4\n1\n2\n0\n5\n0\n" \
    "Total previsto (todas as ações)......: 0" "Participação sobre o total previsto..: 0.0%"

rodar CT19 "Listar sem ações cadastradas" \
    "2\n0\n" \
    "Nenhuma ação cadastrada."

rodar CT20 "Opções inexistentes no menu" \
    "9\nabc\n\n0\n" \
    "Opção inválida. Escolha um número do menu."

rodar CT21 "Encerrar ao fim da entrada (sem digitar 0)" \
    "" \
    "Encerrando o PSE em Ação."

# CT22 - limite de armazenamento: 100 cadastros válidos + 1 tentativa extra.
ENTRADA_LIMITE=""
for i in $(seq 1 101); do
    ENTRADA_LIMITE="${ENTRADA_LIMITE}1\n${i}\nEscola ${i}\nTema ${i}\n01/06/2027\nPúblico ${i}\nResp ${i}\n10\n"
done
rodar CT22 "Limite de armazenamento atingido (101º cadastro)" \
    "${ENTRADA_LIMITE}2\n0\n" \
    "limite de armazenamento atingido (100 ações)" "Total de ações: 100"

echo
echo "Casos executados: $TOTAL | Falhas: $FALHAS"
[ "$FALHAS" -eq 0 ]
