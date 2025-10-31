#include <stdio.h>
#include <string.h> // Biblioteca para usar o strcpy para aulixiar na exibiçao final

// Desafio Super Trunfo - Países
// Tema 3 - Desenvolvendo a Lógica do Jogo
// Nível: Mestre
// Objetivo: Criar menus dinâmicos para escolher 2 atributos, comparar e somar seus valores para dar o resultado.

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

    // --- Variaveis (Nivel Mestre) ---
    int opcao1, opcao2; // Para guardar as duas escolhas
    int erro = 0; // Flag para validar a entrada

    // Variaveis para guardar os valores escolhidos
    float valor_attr1_A = 0, valor_attr1_B = 0;
    float valor_attr2_A = 0, valor_attr2_B = 0;
    float soma_A, soma_B;

    // Variaveis para guardar os nomes dos atributos
    char attr_nome1[30], attr_nome2[30];


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
    

    // === Menus Interativos (Lógica do Jogo - Nivel Mestre) ===
    // --- Menu 1: Escolha do primeiro atributo ---
    printf("\n\n--- BATALHA SUPER TRUNFO ---\n");
    printf("Escolha o PRIMEIRO atributo para a batalha:\n");
    printf("1. Populacao\n");
    printf("2. Area\n");
    printf("3. PIB\n");
    printf("4. Pontos Turisticos\n");
    printf("5. Densidade Demografica (Menor vence!)\n");
    printf("Digite sua opcao (1-5): ");
    scanf("%d", &opcao1);

    // --- Menu 2: Escolha do Segundo atributo ---
    printf("\nEscolha o SEGUNDO atributo para a batalha:\n");
    
    // Lógica do "menu dinâmico":
    // Simplesmente não imprime a opção escolhida em opcao1
    if (opcao1 != 1) printf("1. Populacao\n");
    if (opcao1 != 2) printf("2. Area\n");
    if (opcao1 != 3) printf("3. PIB\n");
    if (opcao1 != 4) printf("4. Pontos Turisticos\n");
    if (opcao1 != 5) printf("5. Densidade Demografica (Menor vence!)\n");
    printf("Digite sua opcao: ");
    scanf("%d", &opcao2);

    // === Validação das Entradas ===
    if (opcao1 == opcao2) {
        printf("\nERRO: Voce nao pode escolher o mesmo atributo duas vezes!\n");
        erro = 1; // Ativa a flag de erro
    }
    if (opcao1 < 1 || opcao1 > 5 || opcao2 < 1 || opcao2 > 5) {
        printf("\nERRO: Opcao invalida! Escolha numeros de 1 a 5.\n");
        erro = 1; // Ativa a flag de erro
    }

    // Se a flag 'erro' foi ativada, para o programa
    if (erro == 1) {
        return 1; // Encerra o programa com um código de erro
    }
    // === Coleta de Dados (Atributo 1) ===
    // Guarda o valor e o nome do PRIMEIRO atributo escolhido
    switch (opcao1) {
        case 1:
            valor_attr1_A = (float)populacao_A;
            valor_attr1_B = (float)populacao_B;
            strcpy(attr_nome1, "Populacao");
            break;
        case 2:
            valor_attr1_A = area_A;
            valor_attr1_B = area_B;
            strcpy(attr_nome1, "Area");
            break;
        case 3:
            valor_attr1_A = pib_A;
            valor_attr1_B = pib_B;
            strcpy(attr_nome1, "PIB");
            break;
        case 4:
            valor_attr1_A = (float)p_turistico_A;
            valor_attr1_B = (float)p_turistico_B;
            strcpy(attr_nome1, "Pontos Turisticos");
            break;
        case 5:
            valor_attr1_A = densidade_A;
            valor_attr1_B = densidade_B;
            strcpy(attr_nome1, "Densidade Demografica");
            break;
    }
    // === Coleta de Dados (Atributo 2) ===
    // Guarda o valor e o nome do SEGUNDO atributo escolhido
    switch (opcao2) {
        case 1:
            valor_attr2_A = (float)populacao_A;
            valor_attr2_B = (float)populacao_B;
            strcpy(attr_nome2, "Populacao");
            break;
        case 2:
            valor_attr2_A = area_A;
            valor_attr2_B = area_B;
            strcpy(attr_nome2, "Area");
            break;
        case 3:
            valor_attr2_A = pib_A;
            valor_attr2_B = pib_B;
            strcpy(attr_nome2, "PIB");
            break;
        case 4:
            valor_attr2_A = (float)p_turistico_A;
            valor_attr2_B = (float)p_turistico_B;
            strcpy(attr_nome2, "Pontos Turisticos");
            break;
        case 5:
            valor_attr2_A = densidade_A;
            valor_attr2_B = densidade_B;
            strcpy(attr_nome2, "Densidade Demografica");
            break;
    }


    // === Exibição das Comparações Individuais ===
    // (Requisito: Exibir resultados individuais)
    printf("\n\n--- Comparacao Individual ---");

    // --- Comparação Atributo 1 ---
    printf("\nAtributo 1 (%s):\n", attr_nome1);
    printf("   Carta 1 (%s): %.2f\n", cidade_A, valor_attr1_A);
    printf("   Carta 2 (%s): %.2f\n", cidade_B, valor_attr1_B);
    
    // Logica da vitoria (respeitando a regra da densidade)
    if (opcao1 == 5) { // Regra: Menor Vence (Densidade)
        if (valor_attr1_A < valor_attr1_B) printf("   -> Vitoria: Carta 1 (%s)\n", cidade_A);
        else if (valor_attr1_B < valor_attr1_A) printf("   -> Vitoria: Carta 2 (%s)\n", cidade_B);
        else printf("   -> Resultado: Empate\n");
    } else { // Regra: Maior Vence
        if (valor_attr1_A > valor_attr1_B) printf("   -> Vitoria: Carta 1 (%s)\n", cidade_A);
        else if (valor_attr1_B > valor_attr1_A) printf("   -> Vitoria: Carta 2 (%s)\n", cidade_B);
        else printf("   -> Resultado: Empate\n");
    }

    // --- Comparação Atributo 2 ---
    printf("\nAtributo 2 (%s):\n", attr_nome2);
    printf("   Carta 1 (%s): %.2f\n", cidade_A, valor_attr2_A);
    printf("   Carta 2 (%s): %.2f\n", cidade_B, valor_attr2_B);

    // Logica da vitoria (respeitando a regra da densidade)
    if (opcao2 == 5) { // Regra: Menor Vence (Densidade)
        if (valor_attr2_A < valor_attr2_B) printf("   -> Vitoria: Carta 1 (%s)\n", cidade_A);
        else if (valor_attr2_B < valor_attr2_A) printf("   -> Vitoria: Carta 2 (%s)\n", cidade_B);
        else printf("   -> Resultado: Empate\n");
    } else { // Regra: Maior Vence
        if (valor_attr2_A > valor_attr2_B) printf("   -> Vitoria: Carta 1 (%s)\n", cidade_A);
        else if (valor_attr2_B > valor_attr2_A) printf("   -> Vitoria: Carta 2 (%s)\n", cidade_B);
        else printf("   -> Resultado: Empate\n");
    }


    // === Resultado Final (Soma dos Atributos) ===
    // (Requisito: somar os valores dos atributos e comparar a soma)
    
    soma_A = valor_attr1_A + valor_attr2_A;
    soma_B = valor_attr1_B + valor_attr2_B;
    
    printf("\n--------------------------------------------------");
    printf("--- RESULTADO FINAL (SOMA DOS ATRIBUTOS) ---");
    printf("\nSoma Carta 1 (%s): %.2f + %.2f = %.2f\n", cidade_A, valor_attr1_A, valor_attr2_A, soma_A);
    printf("Soma Carta 2 (%s): %.2f + %.2f = %.2f\n", cidade_B, valor_attr1_B, valor_attr2_B, soma_B);
    printf("--------------------------------------------------\n");

    // Lógica final: Maior soma vence
    if (soma_A > soma_B) {
        printf("VENCEDOR DA RODADA: CARTA 1 (%s)!\n", cidade_A);
    } 
    else if (soma_B > soma_A) {
        printf("VENCEDOR DA RODADA: CARTA 2 (%s)!\n", cidade_B);
    } 
    else {
        printf("RESULTADO DA RODADA: EMPATE!\n");
    }
    
    return 0;
}