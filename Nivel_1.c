#include <stdio.h>

// Estrutura para armazenar os dados da carta
typedef struct {
    char estado[3];
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Carta;

int main() {
    // Criando duas cartas
    Carta carta1, carta2;
    
    // Entrada de dados para a carta 1
    printf("Digite o estado da Carta 1: ");
    scanf("%s", carta1.estado);
    printf("Digite o código da Carta 1: ");
    scanf("%s", carta1.codigo);
    printf("Digite o nome da cidade da Carta 1: ");
    scanf("%s", carta1.nome);
    printf("Digite a população da Carta 1: ");
    scanf("%d", &carta1.populacao);
    printf("Digite a área da Carta 1: ");
    scanf("%f", &carta1.area);
    printf("Digite o PIB da Carta 1: ");
    scanf("%f", &carta1.pib);
    printf("Digite o número de pontos turísticos da Carta 1: ");
    scanf("%d", &carta1.pontos_turisticos);
    
    // Entrada de dados para a carta 2
    printf("\nDigite o estado da Carta 2: ");
    scanf("%s", carta2.estado);
    printf("Digite o código da Carta 2: ");
    scanf("%s", carta2.codigo);
    printf("Digite o nome da cidade da Carta 2: ");
    scanf("%s", carta2.nome);
    printf("Digite a população da Carta 2: ");
    scanf("%d", &carta2.populacao);
    printf("Digite a área da Carta 2: ");
    scanf("%f", &carta2.area);
    printf("Digite o PIB da Carta 2: ");
    scanf("%f", &carta2.pib);
    printf("Digite o número de pontos turísticos da Carta 2: ");
    scanf("%d", &carta2.pontos_turisticos);
    
    // Cálculo da Densidade Populacional e PIB per capita
    float densidade1 = carta1.populacao / carta1.area;
    float densidade2 = carta2.populacao / carta2.area;
    float pib_per_capita1 = carta1.pib / carta1.populacao;
    float pib_per_capita2 = carta2.pib / carta2.populacao;
    
    // Escolha do atributo para comparação
    int atributo_escolhido = 3; // 1 - População, 2 - Área, 3 - PIB, 4 - Densidade Populacional, 5 - PIB per capita
    
    printf("\nComparação de cartas\n");
    
    float valor1, valor2;
    char atributo_nome[30];
    int regra_menor_vence = 0;
    
    switch (atributo_escolhido) {
        case 1:
            valor1 = carta1.populacao;
            valor2 = carta2.populacao;
            sprintf(atributo_nome, "População");
            break;
        case 2:
            valor1 = carta1.area;
            valor2 = carta2.area;
            sprintf(atributo_nome, "Área");
            break;
        case 3:
            valor1 = carta1.pib;
            valor2 = carta2.pib;
            sprintf(atributo_nome, "PIB");
            break;
        case 4:
            valor1 = densidade1;
            valor2 = densidade2;
            sprintf(atributo_nome, "Densidade Populacional");
            regra_menor_vence = 1;
            break;
        case 5:
            valor1 = pib_per_capita1;
            valor2 = pib_per_capita2;
            sprintf(atributo_nome, "PIB per capita");
            break;
        default:
            printf("Atributo inválido!");
            return 1;
    }
    
    printf("Atributo escolhido: %s\n", atributo_nome);
    printf("Carta 1 - %s (%s): %.2f\n", carta1.nome, carta1.estado, valor1);
    printf("Carta 2 - %s (%s): %.2f\n\n", carta2.nome, carta2.estado, valor2);
    
    if ((regra_menor_vence && valor1 < valor2) || (!regra_menor_vence && valor1 > valor2)) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
    } else if ((regra_menor_vence && valor1 > valor2) || (!regra_menor_vence && valor1 < valor2)) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
    } else {
        printf("Resultado: Empate!\n");
    }
    
    return 0;
}
