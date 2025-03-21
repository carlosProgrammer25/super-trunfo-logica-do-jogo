#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os atributos da carta
struct Carta {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_demografica;
};

int main() {
    struct Carta carta1 = {"Brasil", 214000000, 8515767.0, 2.05, 50, 25.1};
    struct Carta carta2 = {"Argentina", 45600000, 2780000.0, 0.5, 30, 16.4};

    int opcao;

    printf("Bem-vindo ao Super Trunfo de Países!\n");
    printf("Escolha um atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de pontos turísticos\n");
    printf("5 - Densidade demográfica\n");
    printf("Digite sua escolha: ");
    scanf("%d", &opcao);

    printf("\nComparando os países:\n");
    printf("%s vs %s\n\n", carta1.nome, carta2.nome);

    switch (opcao) {
        case 1:
            printf("População: %d vs %d\n", carta1.populacao, carta2.populacao);
            if (carta1.populacao > carta2.populacao)
                printf("%s venceu!\n", carta1.nome);
            else if (carta1.populacao < carta2.populacao)
                printf("%s venceu!\n", carta2.nome);
            else
                printf("Empate!\n");
            break;
        case 2:
            printf("Área: %.2f vs %.2f\n", carta1.area, carta2.area);
            if (carta1.area > carta2.area)
                printf("%s venceu!\n", carta1.nome);
            else if (carta1.area < carta2.area)
                printf("%s venceu!\n", carta2.nome);
            else
                printf("Empate!\n");
            break;
        case 3:
            printf("PIB: %.2f vs %.2f\n", carta1.pib, carta2.pib);
            if (carta1.pib > carta2.pib)
                printf("%s venceu!\n", carta1.nome);
            else if (carta1.pib < carta2.pib)
                printf("%s venceu!\n", carta2.nome);
            else
                printf("Empate!\n");
            break;
        case 4:
            printf("Pontos turísticos: %d vs %d\n", carta1.pontos_turisticos, carta2.pontos_turisticos);
            if (carta1.pontos_turisticos > carta2.pontos_turisticos)
                printf("%s venceu!\n", carta1.nome);
            else if (carta1.pontos_turisticos < carta2.pontos_turisticos)
                printf("%s venceu!\n", carta2.nome);
            else
                printf("Empate!\n");
            break;
        case 5:
            printf("Densidade demográfica: %.2f vs %.2f\n", carta1.densidade_demografica, carta2.densidade_demografica);
            if (carta1.densidade_demografica < carta2.densidade_demografica)
                printf("%s venceu!\n", carta1.nome);
            else if (carta1.densidade_demografica > carta2.densidade_demografica)
                printf("%s venceu!\n", carta2.nome);
            else
                printf("Empate!\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
    }

    return 0;
}