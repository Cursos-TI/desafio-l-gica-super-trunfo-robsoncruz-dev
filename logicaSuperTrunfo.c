#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 3 - Desenvolvendo a Lógica do Jogo
// Nível: Novato
// Objetivo: Cadastrar duas cartas e comparar UM atributo (hard-coded)
//           para decidir a vencedora.

int main() {
    // === Bloco de Variaveis ===
    // (Baseado no código do Tema 2)
    
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
    // (Necessários para a comparação)
    float densidade_A, pib_per_capita_A;
    float densidade_B, pib_per_capita_B;


    // === Cadastro das Cartas ===
    // Implemente a lógica para solicitar ao usuário que insira os dados das cidades
    // (Reutilizando o código do primeiro desafio, conforme requisitos) [cite: 4, 63]

    // --- CARTA 1 ---
    printf("--- Cadastro da Carta 1 ---\n");
    printf("Insira a LETRA do Primeiro Estado: ");
    scanf(" %s", estado_A); // [cite: 17]

    printf("Insira o NUMERO do Estado:  ");
    scanf(" %s", cod_carta_A); // [cite: 17]

    printf("Insira o NOME da Cidade:  ");
    scanf(" %[^\n]", cidade_A); // [cite: 18]

    printf("Insira a POPULACAO da Cidade: ");
    scanf("%lu", &populacao_A); // [cite: 19]

    printf("Qual a AREA em Km2: ");
    scanf("%f", &area_A); // [cite: 20]

    printf("Qual o PIB em MBRL (Milhoes de Reais): ");
    scanf(" %f", &pib_A); // [cite: 20]

    printf("Quantidade de PONTOS TURISTICOS: ");
    scanf("%d", &p_turistico_A); // [cite: 21]

    printf(" -------------------------------- \n");
    
    // --- CARTA 2 ---
    printf("\n--- Cadastro da Carta 2 ---\n");
    printf("Insira a LETRA do Segundo Estado: ");
    scanf(" %s", estado_B); // [cite: 23]

    printf("Insira o NUMERO do Estado:  ");
    scanf(" %s", cod_carta_B); // [cite: 23]

    printf("Insira o NOME da Cidade:  ");
    scanf(" %[^\n]", cidade_B); // [cite: 24]

    printf("Insira a POPULACAO da Cidade: ");
    scanf("%lu", &populacao_B); // [cite: 25]

    printf("Qual a AREA em Km2: ");
    scanf("%f", &area_B); // [cite: 26]

    printf("Qual o PIB em MBRL (Milhoes de Reais): ");
    scanf(" %f", &pib_B); // [cite: 26]

    printf("Quantidade de PONTOS TURISTICOS: ");
    scanf("%d", &p_turistico_B); // [cite: 27]


    // === Bloco de Calculos ===
    // (Calculando Densidade e PIB per capita, conforme requisitos) [cite: 64]
    
    // Evitar divisao por zero (caso area ou populacao seja 0)
    // (Um estudante poderia esquecer isso, mas é uma boa pratica simples)
    if (area_A > 0) {
        densidade_A = (float)populacao_A / area_A;
    } else {
        densidade_A = 0;
    }
    
    if (populacao_A > 0) {
        pib_per_capita_A = (pib_A * 1000000) / (float)populacao_A; // [cite: 28]
    } else {
        pib_per_capita_A = 0;
    }

    if (area_B > 0) {
        densidade_B = (float)populacao_B / area_B;
    } else {
        densidade_B = 0;
    }

    if (populacao_B > 0) {
        pib_per_capita_B = (pib_B * 1000000) / (float)populacao_B; // [cite: 28]
    } else {
        pib_per_capita_B = 0;
    }
    

    // === Comparação de Cartas (Lógica do Jogo - Nivel Novato) ===
    // [cite: 6]
    // Requisito: Escolher APENAS UM atributo para comparar 
    // Atributo escolhido: Densidade Populacional
    // Requisito: Para Densidade Populacional, a carta com o MENOR valor vence 

    printf("\n\n--- BATALHA SUPER TRUNFO ---\n");
    printf("Atributo escolhido: Densidade Populacional (Menor vence!)\n");
    printf("--------------------------------------------------\n");

    // Exibindo os valores das cartas para o atributo escolhido [cite: 68]
    printf("Carta 1 (%s): %.2f hab/km2\n", cidade_A, densidade_A);
    printf("Carta 2 (%s): %.2f hab/km2\n", cidade_B, densidade_B);
    printf("--------------------------------------------------\n");


    // === Exibição dos Resultados ===
    // [cite: 8]
    // Logica de decisao if/else para determinar o vencedor
    if (densidade_A < densidade_B) {
        // Carta 1 vence [cite: 7, 9]
        printf("Resultado: A CARTA 1 (%s) VENCEU!\n", cidade_A); // [cite: 69]
    } 
    else if (densidade_B < densidade_A) {
        // Carta 2 vence [cite: 8, 9]
        printf("Resultado: A CARTA 2 (%s) VENCEU!\n", cidade_B);
    } 
    else {
        // Empate
        printf("Resultado: EMPATE!\n");
    }

    return 0;
}