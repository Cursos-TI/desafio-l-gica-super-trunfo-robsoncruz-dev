#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 3 - Desenvolvendo a Lógica do Jogo
// Nível: Novato
// Objetivo: Cadastrar duas cartas e comparar apenas um atributo para decidir o vencedor.

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
    
    // === Comparação de Cartas (Lógica do Jogo - Nivel Novato) ===
    // Requisito: Escolher apenas um atributo para comparar 
    // Atributo escolhido: Densidade Populacional
    // Requisito: Para Densidade Populacional, a carta com o MENOR valor vence 

    printf("\n\n--- BATALHA SUPER TRUNFO ---\n");
    printf("Atributo escolhido: Densidade Populacional (Menor vence!)\n");
    printf("--------------------------------------------------\n");

    // Exibir os valores das cartas para o atributo escolhido
    printf("Carta 1 (%s): %.2f hab/km2\n", cidade_A, densidade_A);
    printf("Carta 2 (%s): %.2f hab/km2\n", cidade_B, densidade_B);
    printf("--------------------------------------------------\n");


    // === Resultado ===
    // Logica para determinar o vencedor
    if (densidade_A < densidade_B) {
        // Carta 1 vence
        printf("Resultado: A CARTA 1 (%s) VENCEU!\n", cidade_A); // [cite: 69]
    } 
    else if (densidade_B < densidade_A) {
        // Carta 2 vence
        printf("Resultado: A CARTA 2 (%s) VENCEU!\n", cidade_B);
    } 
    else {
        // Empate
        printf("Resultado: EMPATE!\n");
    }

    return 0;
}