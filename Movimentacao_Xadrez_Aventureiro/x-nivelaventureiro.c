#include <stdio.h>
#include <stdlib.h>

// Função para converter letras em colunas (ex: 'A' vira 1, 'H' vira 8)
// Isso facilita a comparação entre colunas usando números
int converterColuna(char letra) {
    return letra - 'A' + 1;
}

int main() {
    char colunaInicial, colunaFinal;
    int linhaInicial, linhaFinal;

    // Exibe título do simulador
    printf("=== Simulador de Movimentos: Torre, Bispo e Rainha ===\n");

    // Entrada da posição inicial da peça
    printf("Informe a posição inicial (coluna A-H e linha 1-8):\n");
    printf("Coluna: ");
    scanf(" %c", &colunaInicial); // Espaço antes de %c para ignorar quebra de linha
    printf("Linha: ");
    scanf("%d", &linhaInicial);

    // Entrada da posição final (de destino)
    printf("\nInforme a posição de destino (coluna A-H e linha 1-8):\n");
    printf("Coluna: ");
    scanf(" %c", &colunaFinal);
    printf("Linha: ");
    scanf("%d", &linhaFinal);

    // Converte colunas (letras) em números para facilitar os cálculos
    int coluna1 = converterColuna(colunaInicial);
    int coluna2 = converterColuna(colunaFinal);

    printf("\n--- Resultado ---\n");

    // ------------------ Verificação da TORRE ------------------
    // A torre se move somente em linha reta: mesma linha ou mesma coluna
    if (linhaInicial == linhaFinal || coluna1 == coluna2) {
        printf("Movimento válido para a TORRE.\n");
    } else {
        printf("Movimento inválido para a TORRE.\n");
    }

    // ------------------ Verificação do BISPO ------------------
    // O bispo se move em diagonal: a diferença entre linhas deve ser igual à diferença entre colunas
    if (abs(linhaInicial - linhaFinal) == abs(coluna1 - coluna2)) {
        printf("Movimento válido para o BISPO.\n");
    } else {
        printf("Movimento inválido para o BISPO.\n");
    }

    // ------------------ Verificação da RAINHA ------------------
    // A rainha se move como torre ou como bispo: linha/coluna igual ou diagonal
    if ((linhaInicial == linhaFinal || coluna1 == coluna2) ||
        (abs(linhaInicial - linhaFinal) == abs(coluna1 - coluna2))) {
        printf("Movimento válido para a RAINHA.\n");
    } else {
        printf("Movimento inválido para a RAINHA.\n");
    }

    return 0;
}
