#include <stdio.h>

#define TAB_SIZE 10   // Tamanho do tabuleiro
#define SHIP_SIZE 3   // Tamanho fixo dos navios

int main() {
    int tabuleiro[TAB_SIZE][TAB_SIZE];
    int i, j;

    // 1. Inicializar o tabuleiro com 0 (água)
    for (i = 0; i < TAB_SIZE; i++) {
        for (j = 0; j < TAB_SIZE; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2. Definir coordenadas iniciais dos navios
    // Navios horizontais e verticais
    int navioH_linha = 1, navioH_coluna = 2; // horizontal
    int navioV_linha = 5, navioV_coluna = 7; // vertical

    // Navios diagonais
    int navioD1_linha = 0, navioD1_coluna = 0; // diagonal descendente (↘)
    int navioD2_linha = 7, navioD2_coluna = 0; // diagonal ascendente (↗)

    // 3. Posicionar navio horizontal
    for (i = 0; i < SHIP_SIZE; i++) {
        tabuleiro[navioH_linha][navioH_coluna + i] = 3;
    }

    // 4. Posicionar navio vertical
    for (i = 0; i < SHIP_SIZE; i++) {
        tabuleiro[navioV_linha + i][navioV_coluna] = 3;
    }

    // 5. Posicionar navio diagonal descendente (linha e coluna aumentam)
    for (i = 0; i < SHIP_SIZE; i++) {
        tabuleiro[navioD1_linha + i][navioD1_coluna + i] = 3;
    }

    // 6. Posicionar navio diagonal ascendente (linha diminui, coluna aumenta)
    for (i = 0; i < SHIP_SIZE; i++) {
        tabuleiro[navioD2_linha - i][navioD2_coluna + i] = 3;
    }

    // 7. Exibir o tabuleiro
    printf("Tabuleiro de Batalha Naval (0=água, 3=navio):\n\n");
    for (i = 0; i < TAB_SIZE; i++) {
        for (j = 0; j < TAB_SIZE; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
