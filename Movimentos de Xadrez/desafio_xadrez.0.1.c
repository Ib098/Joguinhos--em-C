#include <stdio.h>

/* Definição de constantes para garantir a integridade espacial */
#define LIMITE_TABULEIRO 8

/* Nível Mestre: Função recursiva com rastreio de coordenadas cartesianas */
void moverBispoRecursivo(int casas, int posX, int posY) {
    /* A condição verifica se há casas a mover e se o limite do tabuleiro não foi violado */
    if (casas > 0 && posX > 0 && posY < LIMITE_TABULEIRO - 1) {
        posX--; /* Cima: decrementa o índice da linha */
        posY++; /* Direita: incrementa o índice da coluna */
        printf("Cima, Direita -> Coordenada: (%d, %d)\n", posX, posY);
        moverBispoRecursivo(casas - 1, posX, posY);
    }
}

int main() {
    /* ----------------------------------------------------------------------
       NÍVEL NOVATO: Iterações primárias com rastreio linear
       ---------------------------------------------------------------------- */
    printf("--- Nível Novato ---\n");
    
    // Torre: Inicia em (7, 0) - Canto inferior esquerdo
    int torreX = 7, torreY = 0;
    printf("Movimentação da Torre (Origem: 7, 0):\n");
    for (int i = 0; i < 5; i++) {
        if (torreY < LIMITE_TABULEIRO - 1) {
            torreY++;
            printf("Direita -> Coordenada: (%d, %d)\n", torreX, torreY);
        }
    }

    // Bispo: Inicia em (7, 2)
    int bispoX = 7, bispoY = 2;
    int casasBispo = 5;
    printf("\nMovimentação do Bispo (Origem: 7, 2):\n");
    while (casasBispo > 0 && bispoX > 0 && bispoY < LIMITE_TABULEIRO - 1) {
        bispoX--;
        bispoY++;
        printf("Cima, Direita -> Coordenada: (%d, %d)\n", bispoX, bispoY);
        casasBispo--;
    }

    // Rainha: Inicia em (3, 7) - Borda direita
    int rainhaX = 3, rainhaY = 7;
    int casasRainha = 8;
    printf("\nMovimentação da Rainha (Origem: 3, 7):\n");
    do {
        if (rainhaY > 0) {
            rainhaY--;
            printf("Esquerda -> Coordenada: (%d, %d)\n", rainhaX, rainhaY);
        }
        casasRainha--;
    } while (casasRainha > 0);


    /* ----------------------------------------------------------------------
       NÍVEL AVENTUREIRO: Composição vetorial em dois eixos
       ---------------------------------------------------------------------- */
    printf("\n--- Nível Aventureiro ---\n");
    
    // Cavalo: Inicia em (7, 1)
    int cavalo1X = 7, cavalo1Y = 1;
    printf("Movimentação do Cavalo (Origem: 7, 1):\n");
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < 2; j++) {
            cavalo1X--; // Duas casas para cima
            printf("Cima -> Coordenada Temporária: (%d, %d)\n", cavalo1X, cavalo1Y);
        }
        cavalo1Y++; // Uma casa para a direita
        printf("Direita -> Coordenada Final: (%d, %d)\n", cavalo1X, cavalo1Y);
    }


    /* ----------------------------------------------------------------------
       NÍVEL MESTRE: Recursão e lógica de interrupção
       ---------------------------------------------------------------------- */
    printf("\n--- Nível Mestre ---\n");
    
    // Bispo: Invocação recursiva com origem em (6, 1)
    printf("Movimentação do Bispo Recursivo (Origem: 6, 1):\n");
    moverBispoRecursivo(5, 6, 1);

    // Cavalo: Múltiplas variáveis de controlo. Inicia em (2, 4)
    int cavalo2X = 2, cavalo2Y = 4;
    printf("\nMovimentação do Cavalo Complexo (Origem: 2, 4):\n");
    for (int i = 0, j = 0; i < 3; i++) {
        if (i < 2) {
            cavalo2X++; // Movimento para Baixo
            printf("Baixo -> Coordenada Temporária: (%d, %d)\n", cavalo2X, cavalo2Y);
            continue; 
        }
        while (j < 1) {
            cavalo2Y--; // Movimento para a Esquerda
            printf("Esquerda -> Coordenada Final: (%d, %d)\n", cavalo2X, cavalo2Y);
            j++;
        }
    }

    return 0;
}