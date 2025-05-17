#include <stdio.h>
#include <stdlib.h>

// Converte a letra da coluna (A-H) para um número (1-8)
int converterColuna(char letra) {
    return letra - 'A' + 1;
}

// ------------------- TORRE -------------------
// Função recursiva que simula o movimento da torre em linha reta (verticalmente)
void moverTorre(int atual, int destino) {
    if (atual == destino) return; // Caso base: chegou ao destino
    printf("Movendo na linha: %d\n", atual);
    moverTorre(atual + 1, destino); // Chamada recursiva incrementando linha
}

// ------------------- BISPO -------------------
// Função recursiva que simula movimento em diagonal do bispo
void moverBispo(int linhaAtual, int colunaAtual, int linhaFinal, int colunaFinal) {
    if (linhaAtual == linhaFinal && colunaAtual == colunaFinal) return; // Caso base
    printf("Movendo para: %c%d\n", colunaAtual + 'C' - 1, linhaAtual);
    moverBispo(linhaAtual + 1, colunaAtual + 1, linhaFinal, colunaFinal); // Move na diagonal
}

// ------------------- RAINHA -------------------
// Função que mostra os movimentos possíveis da rainha
void moverRainha(char coluna, int linha) {
    printf("\nMovimentos possíveis da RAINHA a partir de %c%d:\n", coluna, linha);

    // Movimento horizontal e vertical
    for (char c = 'A'; c <= 'H'; c++) {
        if (c != coluna)
            printf("Coluna: %c%d\n", c, linha);
    }
    for (int l = 1; l <= 8; l++) {
        if (l != linha)
            printf("Linha: %c%d\n", coluna, l);
    }

    // Movimento diagonal
    for (int i = 1; i <= 8; i++) {
        if (coluna + i <= 'H' && linha + i <= 8)
            printf("Diagonal: %c%d\n", coluna + i, linha + i);
        if (coluna - i >= 'A' && linha + i <= 8)
            printf("Diagonal: %c%d\n", coluna - i, linha + i);
        if (coluna + i <= 'H' && linha - i >= 1)
            printf("Diagonal: %c%d\n", coluna + i, linha - i);
        if (coluna - i >= 'A' && linha - i >= 1)
            printf("Diagonal: %c%d\n", coluna - i, linha - i);
    }
}

// ------------------- CAVALO -------------------
// Lista todos os movimentos válidos do cavalo a partir de uma posição
void movimentosCavalo(int linha, int coluna) {
    int movLin[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int movCol[] = {1, 2, 2, 1, -1, -2, -2, -1};

    printf("\nCAVALO - Movimentos possiveis a partir de %c%d:\n", coluna + 'A' - 1, linha);

    for (int i = 0; i < 8; i++) {
        int novaLinha = linha + movLin[i];
        int novaColuna = coluna + movCol[i];

        if (novaLinha >= 1 && novaLinha <= 8 && novaColuna >= 1 && novaColuna <= 8) {
            printf("-> %c%d\n", novaColuna + 'A' - 1, novaLinha);
        }
    }
}

int main() {
    char colunaInicial, colunaFinal;
    int linhaInicial, linhaFinal;

    printf("=== Nivel Mestre: Movimento das Peças com Recursividade ===\n");

    // ------------------- TORRE -------------------
    printf("\nTORRE\nPosicao inicial da torre (linha): ");
    scanf("%d", &linhaInicial);
    printf("Posicao final da torre (linha): ");
    scanf("%d", &linhaFinal);
    moverTorre(linhaInicial, linhaFinal);

    // ------------------- BISPO -------------------
    printf("\nBISPO\nColuna inicial (A-H): ");
    scanf(" %c", &colunaInicial);
    printf("Linha inicial: ");
    scanf("%d", &linhaInicial);
    printf("Coluna final (A-H): ");
    scanf(" %c", &colunaFinal);
    printf("Linha final: ");
    scanf("%d", &linhaFinal);
    moverBispo(linhaInicial, converterColuna(colunaInicial), linhaFinal, converterColuna(colunaFinal));

    // ------------------- RAINHA -------------------
    printf("\nRAINHA\n");

    char colunaRainha;
    int linhaRainha;
    printf("Informe a coluna (A a H): ");
    scanf(" %c", &colunaRainha);
    printf("Informe a linha (1 a 8): ");
    scanf("%d", &linhaRainha);
    moverRainha(colunaRainha, linhaRainha);

    // ------------------- CAVALO -------------------
    printf("\nCAVALO\nColuna inicial (A-H): ");
    scanf(" %c", &colunaInicial);
    printf("Linha inicial: ");
    scanf("%d", &linhaInicial);
    movimentosCavalo(linhaInicial, converterColuna(colunaInicial));

    return 0;
}
