#  Simulador de Movimentação de Peças de Xadrez em C

Este projeto simula o movimento das peças de xadrez (Torre, Bispo, Rainha e Cavalo), desenvolvido em linguagem C, dividido em três níveis de dificuldade: Novato, Aventureiro e Mestre. É um desafio prático proposto na disciplina de Programação em C.

##  Níveis do Desafio

### Nível Novato
- Simula os movimentos das peças com estruturas de repetição:
  - Torre (FOR)
  - Bispo (WHILE)
  - Rainha (DO-WHILE)

### Nível Aventureiro
- Pede ao usuário posições iniciais e finais (coluna e linha).
- Verifica se os movimentos são válidos para Torre, Bispo e Rainha.
- Utiliza estruturas condicionais `if` e `switch`.

### Nível Mestre
- Implementa a simulação usando **recursividade**.
- Mostra possíveis caminhos da Rainha e movimentos do Cavalo com lógica avançada.
- Cada peça tem seu comportamento recriado com função recursiva.

## Como Compilar

No terminal, dentro da pasta do projeto, use:

gcc x-nivelnovato.c -o novato
./novato

gcc x-nivelaventureiro.c -o aventureiro
./aventureiro

gcc x-nivelmestre.c -o mestre
./mestre
