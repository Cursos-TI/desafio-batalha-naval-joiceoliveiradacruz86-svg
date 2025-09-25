#include <stdio.h>

#define TAB_SIZE 10   // Tamanho do tabuleiro
#define SHIP_SIZE 3   // Tamanho dos navios
#define SKILL_SIZE 5  // Tamanho das matrizes de habilidades (5x5)

// Função para sobrepor a habilidade no tabuleiro
void aplicarHabilidade(int tab[TAB_SIZE][TAB_SIZE], int habilidade[SKILL_SIZE][SKILL_SIZE], int origemLinha, int origemColuna, int valor) {
    int i, j;
    int meio = SKILL_SIZE / 2; // Centro da matriz de habilidade

    for (i = 0; i < SKILL_SIZE; i++) {
        for (j = 0; j < SKILL_SIZE; j++) {
            // Calcular posição correspondente no tabuleiro
            int linhaTab = origemLinha - meio + i;
            int colunaTab = origemColuna - meio + j;

            // Verificar se está dentro dos limites do tabuleiro
            if (linhaTab >= 0 && linhaTab < TAB_SIZE && colunaTab >= 0 && colunaTab < TAB_SIZE) {
                if (habilidade[i][j] == 1) {
                    // Marcar área afetada (5) sem sobrescrever navios (3)
                    if (tab[linhaTab][colunaTab] != 3) {
                        tab[linhaTab][colunaTab] = valor;
                    }
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAB_SIZE][TAB_SIZE];
    int i, j;

    // 1. Inicializar o tabuleiro com 0 (água)
    for (i = 0; i < TAB_SIZE; i++)
        for (j = 0; j < TAB_SIZE; j++)
            tabuleiro[i][j] = 0;

    // 2. Posicionar navios (horizontal, vertical e diagonais)
    // Horizontal
    int navioH_linha = 1, navioH_coluna = 2;
    for (i = 0; i < SHIP_SIZE; i++)
        tabuleiro[navioH_linha][navioH_coluna + i] = 3;

    // Vertical
    int navioV_linha = 5, navioV_coluna = 7;
    for (i = 0; i < SHIP_SIZE; i++)
        tabuleiro[navioV_linha + i][navioV_coluna] = 3;

    // Diagonal descendente (↘)
    int navioD1_linha = 0, navioD1_coluna = 0;
    for (i = 0; i < SHIP_SIZE; i++)
        tabuleiro[navioD1_linha + i][navioD1_coluna + i] = 3;

    // Diagonal ascendente (↗)
    int navioD2_linha = 7, navioD2_coluna = 0;
    for (i = 0; i < SHIP_SIZE; i++)
        tabuleiro[navioD2_linha - i][navioD2_coluna + i] = 3;

    // 3. Definir matrizes de habilidade
    int cone[SKILL_SIZE][SKILL_SIZE] = {0};
    int cruz[SKILL_SIZE][SKILL_SIZE] = {0};
    int octaedro[SKILL_SIZE][SKILL_SIZE] = {0};

    int meio = SKILL_SIZE / 2;

    // Construir Cone (expande para baixo)
    for (i = 0; i <= meio; i++) { // linhas
        for (j = meio - i; j <= meio + i; j++) { // colunas
            cone[i][j] = 1;
        }
    }

    // Construir Cruz
    for (i = 0; i < SKILL_SIZE; i++) {
        cruz[meio][i] = 1; // linha central
        cruz[i][meio] = 1; // coluna central
    }

    // Construir Octaedro (losango)
    for (i = 0; i < SKILL_SIZE; i++) {
        int dist = (i <= meio) ? meio - i : i - meio;
        for (j = dist; j < SKILL_SIZE - dist; j++)
            octaedro[i][j] = 1;
    }

    // 4. Aplicar habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 2, 7, 5);      // Cone com origem (2,7)
    aplicarHabilidade(tabuleiro, cruz, 5, 2, 5);      // Cruz com origem (5,2)
    aplicarHabilidade(tabuleiro, octaedro, 7, 7, 5);  // Octaedro com origem (7,7)

    // 5. Exibir o tabuleiro
    printf("Tabuleiro com Navios e Habilidades (0=água, 3=navio, 5=habilidade):\n\n");
    for (i = 0; i < TAB_SIZE; i++) {
        for (j = 0; j < TAB_SIZE; j++)
            printf("%d ", tabuleiro[i][j]);
        printf("\n");
    }

    return 0;
}
