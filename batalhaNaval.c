#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {

    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Coordenadas iniciais dos navios
    int linhaH = 1, colunaH = 2;     // Navio horizontal
    int linhaV = 5, colunaV = 7;     // Navio vertical
    int linhaD1 = 0, colunaD1 = 0;   // Navio diagonal principal (\)
    int linhaD2 = 6, colunaD2 = 9;   // Navio diagonal secundária (/)

    int i, j;
    int valido = 1;

    /* ==============================
       Inicializa o tabuleiro com água
       ============================== */
    for (i = 0; i < TAM_TABULEIRO; i++) {
        for (j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    /* ==============================
       Valida limites dos navios
       ============================== */
    if (colunaH + TAM_NAVIO > TAM_TABULEIRO) valido = 0;
    if (linhaV + TAM_NAVIO > TAM_TABULEIRO) valido = 0;
    if (linhaD1 + TAM_NAVIO > TAM_TABULEIRO || colunaD1 + TAM_NAVIO > TAM_TABULEIRO) valido = 0;
    if (linhaD2 + TAM_NAVIO > TAM_TABULEIRO || colunaD2 - (TAM_NAVIO - 1) < 0) valido = 0;

    /* ==============================
       Posiciona navio horizontal
       ============================== */
    if (valido) {
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaH][colunaH + i] != AGUA) valido = 0;
            tabuleiro[linhaH][colunaH + i] = NAVIO;
        }
    }

    /* ==============================
       Posiciona navio vertical
       ============================== */
    if (valido) {
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] != AGUA) valido = 0;
            tabuleiro[linhaV + i][colunaV] = NAVIO;
        }
    }

    /* ==============================
       Posiciona navio diagonal (\)
       ============================== */
    if (valido) {
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaD1 + i][colunaD1 + i] != AGUA) valido = 0;
            tabuleiro[linhaD1 + i][colunaD1 + i] = NAVIO;
        }
    }

    /* ==============================
       Posiciona navio diagonal (/)
       ============================== */
    if (valido) {
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaD2 + i][colunaD2 - i] != AGUA) valido = 0;
            tabuleiro[linhaD2 + i][colunaD2 - i] = NAVIO;
        }
    }

    /* ==============================
       Exibição do tabuleiro
       ============================== */
    if (valido) {
        printf("\nTabuleiro Batalha Naval (0 = Agua | 3 = Navio)\n\n");

        for (i = 0; i < TAM_TABULEIRO; i++) {
            for (j = 0; j < TAM_TABULEIRO; j++) {
                printf("%d ", tabuleiro[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("\nErro: Navios fora do limite ou sobrepostos.\n");
    }

    return 0;
}




