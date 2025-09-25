#include <stdio.h>

#define TAB_SIZE 10      // Tamanho do tabuleiro
#define SHIP_SIZE 3      // Tamanho dos navios

int main() {
    int tabuleiro[TAB_SIZE][TAB_SIZE]; // Matriz do tabuleiro
    int i, j;

    // 1. Inicializar o tabuleiro com 0 (água)
    for (i = 0; i < TAB_SIZE; i++) {
        for (j = 0; j < TAB_SIZE; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2. Definir coordenadas iniciais dos navios
    // Navio horizontal
    int navioH_linha = 2; // linha inicial
    int navioH_coluna = 4; // coluna inicial

    // Navio vertical
    int navioV_linha = 5; // linha inicial
    int navioV_coluna = 7; // coluna inicial

    // 3. Posicionar navio horizontal
    for (i = 0; i < SHIP_SIZE; i++) {
        tabuleiro[navioH_linha][navioH_coluna + i] = 3; // valor 3 representa navio
    }

    // 4. Posicionar navio vertical
    for (i = 0; i < SHIP_SIZE; i++) {
        tabuleiro[navioV_linha + i][navioV_coluna] = 3; // valor 3 representa navio
    }

    // 5. Exibir o tabuleiro
    printf("Tabuleiro de Batalha Naval:\n\n");
    for (i = 0; i < TAB_SIZE; i++) {
        for (j = 0; j < TAB_SIZE; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
