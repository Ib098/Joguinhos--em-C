#include <stdio.h>

/**
 * PROJETO: Super Trunfo - Países
 * NÍVEL: Mestre (Lógica de Comparação e Decisão Avançada)
 */

int main() {
    // Atributos da Carta 1
    char estado1[2], codigo1[4], nome1[50];
    unsigned long int populacao1;
    float area1, pib1, densidade1, pibPerCapita1;
    int pontosTuristicos1;

    // Atributos da Carta 2
    char estado2[2], codigo2[4], nome2[50];
    unsigned long int populacao2;
    float area2, pib2, densidade2, pibPerCapita2;
    int pontosTuristicos2;

    int opcao;

    // --- SEÇÃO DE CADASTRO (INPUT DE DADOS) ---
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado (A-H): "); scanf(" %s", estado1);
    printf("Código: "); scanf("%s", codigo1);
    printf("Nome da Cidade: "); scanf(" %[^\n]", nome1);
    printf("População: "); scanf("%lu", &populacao1);
    printf("Área (km²): "); scanf("%f", &area1);
    printf("PIB (bilhões): "); scanf("%f", &pib1);
    printf("Pontos Turísticos: "); scanf("%d", &pontosTuristicos1);

    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Estado (A-H): "); scanf(" %s", estado2);
    printf("Código: "); scanf("%s", codigo2);
    printf("Nome da Cidade: "); scanf(" %[^\n]", nome2);
    printf("População: "); scanf("%lu", &populacao2);
    printf("Área (km²): "); scanf("%f", &area2);
    printf("PIB (bilhões): "); scanf("%f", &pib2);
    printf("Pontos Turísticos: "); scanf("%d", &pontosTuristicos2);

    // --- CÁLCULOS DE PROPRIEDADES DERIVADAS ---
    densidade1 = (float)populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000) / (float)populacao1; // Ajuste para valor real em moeda

    densidade2 = (float)populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000) / (float)populacao2;

    // --- MENU INTERATIVO DE COMPARAÇÃO ---
    printf("\n--- Escolha o Atributo para Comparação ---\n");
    printf("1. População\n2. Área\n3. PIB\n4. Pontos Turísticos\n5. Densidade Populacional\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    printf("\n--- RESULTADO DA DISPUTA ---\n");

    switch (opcao) {
        case 1:
            printf("Atributo: População\n");
            printf("Carta 1 (%s): %lu\nCarta 2 (%s): %lu\n", nome1, populacao1, nome2, populacao2);
            printf("Vencedor: %s\n", (populacao1 > populacao2) ? "Carta 1" : (populacao1 < populacao2 ? "Carta 2" : "Empate"));
            break;
        case 2:
            printf("Atributo: Área\n");
            printf("Carta 1 (%s): %.2f\nCarta 2 (%s): %.2f\n", nome1, area1, nome2, area2);
            printf("Vencedor: %s\n", (area1 > area2) ? "Carta 1" : (area1 < area2 ? "Carta 2" : "Empate"));
            break;
        case 3:
            printf("Atributo: PIB\n");
            printf("Carta 1 (%s): %.2f\nCarta 2 (%s): %.2f\n", nome1, pib1, nome2, pib2);
            printf("Vencedor: %s\n", (pib1 > pib2) ? "Carta 1" : (pib1 < pib2 ? "Carta 2" : "Empate"));
            break;
        case 4:
            printf("Atributo: Pontos Turísticos\n");
            printf("Carta 1 (%s): %d\nCarta 2 (%s): %d\n", nome1, pontosTuristicos1, nome2, pontosTuristicos2);
            printf("Vencedor: %s\n", (pontosTuristicos1 > pontosTuristicos2) ? "Carta 1" : (pontosTuristicos1 < pontosTuristicos2 ? "Carta 2" : "Empate"));
            break;
        case 5:
            // Regra especial: Na Densidade Populacional, o MENOR valor vence.
            printf("Atributo: Densidade Populacional\n");
            printf("Carta 1 (%s): %.2f\nCarta 2 (%s): %.2f\n", nome1, densidade1, nome2, densidade2);
            printf("Vencedor: %s\n", (densidade1 < densidade2) ? "Carta 1" : (densidade1 > densidade2 ? "Carta 2" : "Empate"));
            break;
        default:
            printf("Opção Inválida.\n");
    }

    return 0;
}