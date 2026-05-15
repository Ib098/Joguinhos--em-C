#include <stdio.h>

/* Nível Mestre: Função recursiva para o deslocamento do Bispo */
void moverBispoRecursivo(int casas) {
    if (casas > 0) {
        printf("Cima, Direita\n");
        moverBispoRecursivo(casas - 1);
    }
}

int main() {
    /* ----------------------------------------------------------------------
       NÍVEL NOVATO: Estruturas de repetição fundamentais
       ---------------------------------------------------------------------- */
    printf("--- Nível Novato ---\n");
    
    // Torre: Deslocamento determinístico com 'for' (5 casas para a direita)
    printf("Movimentação da Torre:\n");
    for (int i = 0; i < 5; i++) {
        printf("Direita\n");
    }

    // Bispo: Deslocamento condicional primário com 'while' (5 casas)
    printf("\nMovimentação do Bispo:\n");
    int casasBispo = 5;
    while (casasBispo > 0) {
        printf("Cima, Direita\n");
        casasBispo--;
    }

    // Rainha: Execução garantida de ao menos um ciclo com 'do-while' (8 casas)
    printf("\nMovimentação da Rainha:\n");
    int casasRainha = 8;
    do {
        printf("Esquerda\n");
        casasRainha--;
    } while (casasRainha > 0);


    /* ----------------------------------------------------------------------
       NÍVEL AVENTUREIRO: Estruturas de repetição aninhadas
       ---------------------------------------------------------------------- */
    printf("\n--- Nível Aventureiro ---\n");
    
    // Cavalo: Composição vetorial em "L" (2 casas acima, 1 à direita)
    printf("Movimentação do Cavalo (Loops Aninhados):\n");
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < 2; j++) {
            printf("Cima\n");
        }
        printf("Direita\n");
    }


    /* ----------------------------------------------------------------------
       NÍVEL MESTRE: Recursividade e controle de fluxo complexo
       ---------------------------------------------------------------------- */
    printf("\n--- Nível Mestre ---\n");
    
    // Bispo: Invocação recursiva
    printf("Movimentação do Bispo (Recursivo):\n");
    moverBispoRecursivo(5);

    // Cavalo: Interrupções e múltiplas variáveis de controle
    printf("\nMovimentação do Cavalo (Condições Complexas):\n");
    for (int i = 0, j = 0; i < 3; i++) {
        if (i < 2) {
            printf("Baixo\n");
            continue; // Força a iteração a ignorar as linhas subsequentes até i atingir 2
        }
        while (j < 1) {
            printf("Esquerda\n");
            j++;
        }
    }

    return 0;
}