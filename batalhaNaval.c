#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define AGUA 0
#define NAVIO 3


    int main() {  
        
    // Matriz que representa o tabuleiro 10x10
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

                                                    // Vetores que representam os navios (tamanho fixo 3)
    int navioHorizontal[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navioVertical[TAM_NAVIO]   = {NAVIO, NAVIO, NAVIO};

                                 // Coordenadas iniciais dos navios (definidas diretamente no código)
    int linhaH = 2, colunaH = 3; // Navio horizontal
    int linhaV = 5, colunaV = 6; // Navio vertical

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

    /* ==========================================
       Validação do navio horizontal (limites)
       ========================================== */
    if (colunaH + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: Navio horizontal fora dos limites do tabuleiro.\n");
        valido = 0;
    }

    /* ==========================================
       Validação do navio vertical (limites)
       ========================================== */
    if (linhaV + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: Navio vertical fora dos limites do tabuleiro.\n");
        valido = 0;
    }

    /* ==========================================
       Verifica sobreposição - navio horizontal
       ========================================== */
    for (i = 0; i < TAM_NAVIO && valido; i++) {
        if (tabuleiro[linhaH][colunaH + i] == NAVIO) {
            printf("Erro: Sobreposição detectada no navio horizontal.\n");
            valido = 0;
        }
    }

    /* ==========================================
       Posiciona navio horizontal
       ========================================== */
    if (valido) {
        for (i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
        }
    }

    /* ==========================================
       Verifica sobreposição - navio vertical
       ========================================== */
    for (i = 0; i < TAM_NAVIO && valido; i++) {
        if (tabuleiro[linhaV + i][colunaV] == NAVIO) {
            printf("Erro: Sobreposição detectada no navio vertical.\n");
            valido = 0;
        }
    }

    /* ==========================================
       Posiciona navio vertical
       ========================================== */
    if (valido) {
        for (i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaV + i][colunaV] = navioVertical[i];
        }
    }

    /* ==============================
       Exibição do tabuleiro
       ============================== */
    if (valido) {
        printf("\nTabuleiro Batalha Naval (0 = Agua, 3 = Navio)\n\n");

        for (i = 0; i < TAM_TABULEIRO; i++) {
            for (j = 0; j < TAM_TABULEIRO; j++) {
                printf("%d ", tabuleiro[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}



