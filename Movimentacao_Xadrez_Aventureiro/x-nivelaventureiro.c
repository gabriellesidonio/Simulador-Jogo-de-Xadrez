#include <stdio.h>
#include <stdlib.h>

// Função para converter letras em colunas (ex: 'A' vira 1, 'H' vira 8)
int converterColuna(char letra) {
    return letra - 'A' + 1;
}

int main() {
    char colunaInicial, colunaFinal;
    int linhaInicial, linhaFinal;

    printf("=== Simulador de Movimentos: Torre, Bispo e Rainha ===\n");

    // Entrada da posição inicial
    printf("Informe a posição inicial (coluna A-H e linha 1-8):\n");
    printf("Coluna: ");
    scanf(" %c", &colunaInicial);
    printf("Linha: ");
    scanf("%d", &linhaInicial);

    // Entrada da posição de destino
    printf("\nInforme a posição de destino (coluna A-H e linha 1-8):\n");
    printf("Coluna: ");
    scanf(" %c", &colunaFinal);
    printf("Linha: ");
    scanf("%d", &linhaFinal);

    // Converter colunas para números
    int coluna1 = converterColuna(colunaInicial);
    int coluna2 = converterColuna(colunaFinal);

    printf("\n--- Resultado ---\n");

    // Verifica movimento da Torre
    if (linhaInicial == linhaFinal || coluna1 == coluna2) {
        printf("Movimento válido para a TORRE.\n");
    } else {
        printf("Movimento inválido para a TORRE.\n");
    }

    // Verifica movimento do Bispo
    if (abs(linhaInicial - linhaFinal) == abs(coluna1 - coluna2)) {
        printf("Movimento válido para o BISPO.\n");
    } else {
        printf("Movimento inválido para o BISPO.\n");
    }

    // Verifica movimento da Rainha
    if ((linhaInicial == linhaFinal || coluna1 == coluna2) ||
        (abs(linhaInicial - linhaFinal) == abs(coluna1 - coluna2))) {
        printf("Movimento válido para a RAINHA.\n");
    } else {
        printf("Movimento inválido para a RAINHA.\n");
    }

    return 0;
}
