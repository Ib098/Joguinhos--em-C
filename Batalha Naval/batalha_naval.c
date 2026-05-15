#include <stdio.h>

/* Definição estrita das dimensões do plano cartesiano */
#define TAMANHO_TABULEIRO 10

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    /* 1. Inicialização: Definição do estado de repouso (Água = 0) */
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    /* 2. Posicionamento Tático (Navios = 3) */
    // Embarcação Horizontal
    tabuleiro[2][3] = 3;
    tabuleiro[2][4] = 3;
    tabuleiro[2][5] = 3;

    // Embarcação Vertical
    tabuleiro[5][7] = 3;
    tabuleiro[6][7] = 3;
    tabuleiro[7][7] = 3;

    /* 3. Interação Dinâmica: Coleta de Coordenadas para o Disparo Especial */
    int centroX, centroY;
    printf("===== CONTROLE DE ARTILHARIA =====\n");
    printf("Informe a coordenada X (linha de 0 a 9) para o disparo em cruz: ");
    scanf("%d", &centroX);
    printf("Informe a coordenada Y (coluna de 0 a 9) para o disparo em cruz: ");
    scanf("%d", &centroY);

    /* 4. Validação Espacial e Aplicação da Área de Efeito (Impacto = 5) */
    // Verifica se a premissa inserida obedece aos limites físicos da matriz
    if (centroX >= 0 && centroX < TAMANHO_TABULEIRO && centroY >= 0 && centroY < TAMANHO_TABULEIRO) {
        int raioEfeito = 2;
        for (int i = -raioEfeito; i <= raioEfeito; i++) {
            
            // Cálculo do eixo vertical (Linhas)
            int linhaImpacto = centroX + i;
            if (linhaImpacto >= 0 && linhaImpacto < TAMANHO_TABULEIRO) {
                tabuleiro[linhaImpacto][centroY] = 5;
            }

            // Cálculo do eixo horizontal (Colunas)
            int colunaImpacto = centroY + i;
            if (colunaImpacto >= 0 && colunaImpacto < TAMANHO_TABULEIRO) {
                tabuleiro[centroX][colunaImpacto] = 5;
            }
        }
        printf("\nDisparo executado com sucesso nas coordenadas (%d, %d).\n", centroX, centroY);
    } else {
        // Exposição factual da inconsistência
        printf("\nERRO LOGICO: Coordenadas (%d, %d) estao fora do limite de operacao.\n", centroX, centroY);
    }

    /* 5. Renderização: Varredura e representação visual dos dados */
    printf("\n===== MAPA TATICO =====\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("~ "); /* Água */
            } else if (tabuleiro[i][j] == 3) {
                printf("N "); /* Navio */
            } else if (tabuleiro[i][j] == 5) {
                printf("X "); /* Área de Impacto */
            }
        }
        printf("\n");
    }

    return 0;
}