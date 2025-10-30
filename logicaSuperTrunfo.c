#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 3 - Desenvolvendo a Lógica do Jogo
// Nível: Aventureiro
// Objetivo: Criar um menu interativo (switch-case) para o usuário escolher qual atributo comparar.

int main() {
    // === Bloco de Variaveis ===
    // (reaproveitando o código do primeiro desafio - Tema 2)
    // --- Variaveis para Carta A ---
    unsigned long int populacao_A;
    int p_turistico_A;
    char estado_A[5], cidade_A[30], cod_carta_A[5];
    float area_A, pib_A;

    // --- Variaveis para Carta B ---
    unsigned long int populacao_B;
    int p_turistico_B;
    char estado_B[5], cidade_B[30], cod_carta_B[5];
    float area_B, pib_B;

    // --- Variaveis para Calculados (Nivel Aventureiro do Tema 2) ---
    float densidade_A, pib_per_capita_A;
    float densidade_B, pib_per_capita_B;

    // --- Variavel para o Menu (Nivel Aventureiro) ---
    int opcao;


    // === Cadastro das Cartas ===
    // (Reutilizado o código do primeiro desafio)

    // --- CARTA 1 ---
    printf("--- Cadastro da Carta 1 ---\n");
    printf("Insira a LETRA do Primeiro Estado: ");
    scanf(" %s", estado_A);

    printf("Insira o NUMERO do Estado:  ");
    scanf(" %s", cod_carta_A);

    printf("Insira o NOME da Cidade:  ");
    scanf(" %[^\n]", cidade_A);

    printf("Insira a POPULACAO da Cidade: ");
    scanf("%lu", &populacao_A);

    printf("Qual a AREA em Km2: ");
    scanf("%f", &area_A);

    printf("Qual o PIB em MBRL (Milhoes de Reais): ");
    scanf(" %f", &pib_A);

    printf("Quantidade de PONTOS TURISTICOS: ");
    scanf("%d", &p_turistico_A);

    printf(" -------------------------------- \n");
    
    // --- CARTA 2 ---
    printf("\n--- Cadastro da Carta 2 ---\n");
    printf("Insira a LETRA do Segundo Estado: ");
    scanf(" %s", estado_B);

    printf("Insira o NUMERO do Estado:  ");
    scanf(" %s", cod_carta_B);

    printf("Insira o NOME da Cidade:  ");
    scanf(" %[^\n]", cidade_B);

    printf("Insira a POPULACAO da Cidade: ");
    scanf("%lu", &populacao_B);

    printf("Qual a AREA em Km2: ");
    scanf("%f", &area_B);

    printf("Qual o PIB em MBRL (Milhoes de Reais): ");
    scanf(" %f", &pib_B);

    printf("Quantidade de PONTOS TURISTICOS: ");
    scanf("%d", &p_turistico_B);


    // === Bloco de Calculos ===
    // (Calculando Densidade e PIB per capita, conforme requisitos)
    // com correção caso o usuário entre com população 0
    if (area_A > 0) {
        densidade_A = (float)populacao_A / area_A;
    } else {
        densidade_A = 0;
    }

    if (populacao_A > 0) {
        pib_per_capita_A = (pib_A * 1000000) / (float)populacao_A;
    } else {
        pib_per_capita_A = 0;
    }

    if (area_B > 0) {
        densidade_B = (float)populacao_B / area_B;
    } else {
        densidade_B = 0;
    }

    if (populacao_B > 0) {
        pib_per_capita_B = (pib_B * 1000000) / (float)populacao_B;
    } else {
        pib_per_capita_B = 0;
    }
    

    // === Menu Interativo (Lógica do Jogo - Nivel Aventureiro) ===
    printf("\n\n--- BATALHA SUPER TRUNFO ---\n");
    printf("Escolha o atributo para a batalha:\n");
    printf("1. Populacao\n");
    printf("2. Area\n");
    printf("3. PIB\n");
    printf("4. Pontos Turisticos\n");
    printf("5. Densidade Demografica (Menor vence!)\n");
    printf("Digite sua opcao (1-5): ");
    
    scanf("%d", &opcao);

    printf("--------------------------------------------------\n");

    // === Resultado (usando switch-case) ===
    switch (opcao) {
        
        case 1: // Comparação de População (Maior vence)
            printf("Atributo: Populacao (Maior vence!)\n");
            printf("Carta 1 (%s): %lu\n", cidade_A, populacao_A);
            printf("Carta 2 (%s): %lu\n", cidade_B, populacao_B);
            printf("--------------------------------------------------\n");
            
            if (populacao_A > populacao_B) {
                printf("Resultado: A CARTA 1 (%s) VENCEU!\n", cidade_A);
            } else if (populacao_B > populacao_A) {
                printf("Resultado: A CARTA 2 (%s) VENCEU!\n", cidade_B);
            } else {
                printf("Resultado: EMPATE!\n");
            }
            break;

        case 2: // Comparação de Área (Maior vence)
            printf("Atributo: Area (Maior vence!)\n");
            printf("Carta 1 (%s): %.2f km2\n", cidade_A, area_A);
            printf("Carta 2 (%s): %.2f km2\n", cidade_B, area_B);
            printf("--------------------------------------------------\n");

            if (area_A > area_B) {
                printf("Resultado: A CARTA 1 (%s) VENCEU!\n", cidade_A);
            } else if (area_B > area_A) {
                printf("Resultado: A CARTA 2 (%s) VENCEU!\n", cidade_B);
            } else {
                printf("Resultado: EMPATE!\n");
            }
            break;

        case 3: // Comparação de PIB (Maior vence)
            printf("Atributo: PIB (Maior vence!)\n");
            printf("Carta 1 (%s): %.2f Milhoes BRL\n", cidade_A, pib_A);
            printf("Carta 2 (%s): %.2f Milhoes BRL\n", cidade_B, pib_B);
            printf("--------------------------------------------------\n");

            if (pib_A > pib_B) {
                printf("Resultado: A CARTA 1 (%s) VENCEU!\n", cidade_A);
            } else if (pib_B > pib_A) {
                printf("Resultado: A CARTA 2 (%s) VENCEU!\n", cidade_B);
            } else {
                printf("Resultado: EMPATE!\n");
            }
            break;

        case 4: // Comparação de Pontos Turísticos (Maior vence)
            printf("Atributo: Pontos Turisticos (Maior vence!)\n");
            printf("Carta 1 (%s): %d\n", cidade_A, p_turistico_A);
            printf("Carta 2 (%s): %d\n", cidade_B, p_turistico_B);
            printf("--------------------------------------------------\n");

            if (p_turistico_A > p_turistico_B) {
                printf("Resultado: A CARTA 1 (%s) VENCEU!\n", cidade_A);
            } else if (p_turistico_B > p_turistico_A) {
                printf("Resultado: A CARTA 2 (%s) VENCEU!\n", cidade_B);
            } else {
                printf("Resultado: EMPATE!\n");
            }
            break;

        case 5: // Comparação de Densidade (Menor vence)
            printf("Atributo: Densidade Demografica (Menor vence!)\n");
            printf("Carta 1 (%s): %.2f hab/km2\n", cidade_A, densidade_A);
            printf("Carta 2 (%s): %.2f hab/km2\n", cidade_B, densidade_B);
            printf("--------------------------------------------------\n");

            // Regra invertida: Menor vence
            if (densidade_A < densidade_B) {
                printf("Resultado: A CARTA 1 (%s) VENCEU!\n", cidade_A);
            } else if (densidade_B < densidade_A) {
                printf("Resultado: A CARTA 2 (%s) VENCEU!\n", cidade_B);
            } else {
                printf("Resultado: EMPATE!\n");
            }
            break;

        default: // opção se o usuário digite uma opção inválida 
            printf("Opcao invalida! Por favor, execute o programa novamente e escolha um numero de 1 a 5.\n");
            break;

    }

    return 0;
}