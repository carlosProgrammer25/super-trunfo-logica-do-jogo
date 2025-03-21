#include <stdio.h>

typedef struct {
    char nome[30];
    int pib;                // Produto Interno Bruto
    int populacao;          // População
    int area;               // Área
    int densidade_demografica; // Densidade Demográfica
} Pais;

int obterValorAtributo(int atributo, Pais pais) {
    switch (atributo) {
        case 1: return pais.pib;
        case 2: return pais.populacao;
        case 3: return pais.area;
        case 4: return pais.densidade_demografica;
        default: return 0;
    }
}

void exibirMenuAtributos() {
    printf("Escolha o primeiro atributo para comparação:\n");
    printf("1. PIB (Produto Interno Bruto)\n");
    printf("2. População\n");
    printf("3. Área\n");
    printf("4. Densidade Demográfica\n");
    printf("Escolha uma opção: ");
}

void exibirMenuAtributosSecundarios(int atributoEscolhido) {
    printf("Escolha o segundo atributo para comparação (não pode ser o mesmo que o primeiro):\n");
    if (atributoEscolhido != 1) printf("1. PIB (Produto Interno Bruto)\n");
    if (atributoEscolhido != 2) printf("2. População\n");
    if (atributoEscolhido != 3) printf("3. Área\n");
    if (atributoEscolhido != 4) printf("4. Densidade Demográfica\n");
    printf("Escolha uma opção: ");
}

int compararAtributos(int atributo, Pais pais1, Pais pais2) {
    switch (atributo) {
        case 1: // PIB
            return (pais1.pib > pais2.pib) ? 1 : (pais1.pib < pais2.pib) ? -1 : 0;
        case 2: // População
            return (pais1.populacao > pais2.populacao) ? 1 : (pais1.populacao < pais2.populacao) ? -1 : 0;
        case 3: // Área
            return (pais1.area > pais2.area) ? 1 : (pais1.area < pais2.area) ? -1 : 0;
        case 4: // Densidade Demográfica
            return (pais1.densidade_demografica < pais2.densidade_demografica) ? 1 : 
                   (pais1.densidade_demografica > pais2.densidade_demografica) ? -1 : 0;
        default:
            return 0;
    }
}

int main() {
    Pais pais1 = {"Brasil", 2100000, 211000000, 250};  // PIB, População, Área, Densidade Demográfica
    Pais pais2 = {"Argentina", 600000, 45000000, 16};

    int atributo1, atributo2;
    int resultado1, resultado2;
    int soma1, soma2;

    // Menu de escolha de atributos
    exibirMenuAtributos();
    scanf("%d", &atributo1);
    exibirMenuAtributosSecundarios(atributo1);
    scanf("%d", &atributo2);

    // Comparar os dois atributos escolhidos
    resultado1 = compararAtributos(atributo1, pais1, pais2);
    resultado2 = compararAtributos(atributo2, pais1, pais2);

    // Exibir os resultados da comparação de cada atributo
    printf("\nComparando os países %s e %s\n", pais1.nome, pais2.nome);
    printf("Atributo 1: ");
    if (resultado1 == 1) printf("%s vence\n", pais1.nome);
    else if (resultado1 == -1) printf("%s vence\n", pais2.nome);
    else printf("Empate\n");

    printf("Atributo 2: ");
    if (resultado2 == 1) printf("%s vence\n", pais1.nome);
    else if (resultado2 == -1) printf("%s vence\n", pais2.nome);
    else printf("Empate\n");

    // Soma dos atributos
    soma1 = obterValorAtributo(atributo1, pais1) + obterValorAtributo(atributo2, pais1);
    soma2 = obterValorAtributo(atributo1, pais2) + obterValorAtributo(atributo2, pais2);

    // Exibir o vencedor
    if (soma1 > soma2)
        printf("A carta vencedora é: %s\n", pais1.nome);
    else if (soma1 < soma2)
        printf("A carta vencedora é: %s\n", pais2.nome);
    else
        printf("Empate na soma dos atributos!\n");

    return 0;
}
