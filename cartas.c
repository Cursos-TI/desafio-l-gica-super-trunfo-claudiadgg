#include <stdio.h>

// Desafio Super Trunfo - Países
// Desenvolvido por Claudia Goulart

struct Carta {
    char estado[50];
    char codigo[20];
    char nomeCidade[100];
    int populacao;
    float pib; // em bilhões
    float area; // em km²
    int pontosTuristicos;

    float densidadePopulacional;
    float pibPerCapita;
};

void calcularIndicadores(struct Carta *c) {
    c->densidadePopulacional = c->area > 0 ? (float)c->populacao / c->area : 0;
    c->pibPerCapita = c->populacao > 0 ? (c->pib * 1000000000) / c->populacao : 0;
}

void exibirCarta(struct Carta c) {
    printf("\n===== Carta: %s (%s) =====\n", c.nomeCidade, c.estado);
    printf("Código: %s\n", c.codigo);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: R$ %.2f bilhões\n", c.pib);
    printf("Pontos turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade populacional: %.2f hab/km²\n", c.densidadePopulacional);
    printf("PIB per capita: R$ %.2f\n", c.pibPerCapita);
}

int main() {
    struct Carta carta1, carta2;

    printf("Cadastro da primeira carta:\n");
    printf("Estado: ");
    scanf(" %[^\n]", carta1.estado);
    printf("Código da carta: ");
    scanf(" %[^\n]", carta1.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta1.nomeCidade);
    printf("População: ");
    scanf("%d", &carta1.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &carta1.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);
    calcularIndicadores(&carta1);

    printf("\nCadastro da segunda carta:\n");
    printf("Estado: ");
    scanf(" %[^\n]", carta2.estado);
    printf("Código da carta: ");
    scanf(" %[^\n]", carta2.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta2.nomeCidade);
    printf("População: ");
    scanf("%d", &carta2.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &carta2.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);
    calcularIndicadores(&carta2);

    exibirCarta(carta1);
    exibirCarta(carta2);

    int escolha;
    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Densidade Populacional\n");
    printf("5 - PIB per capita\n");
    printf("6 - Pontos turísticos\n");
    printf("Digite o número do atributo: ");
    scanf("%d", &escolha);

    printf("\n===== Comparação =====\n");

    switch(escolha) {
        case 1:
            printf("População:\n");
            if (carta1.populacao > carta2.populacao)
                printf("%s venceu!\n", carta1.nomeCidade);
            else if (carta2.populacao > carta1.populacao)
                printf("%s venceu!\n", carta2.nomeCidade);
            else
                printf("Empate!\n");
            break;
        case 2:
            printf("Área:\n");
            if (carta1.area > carta2.area)
                printf("%s venceu!\n", carta1.nomeCidade);
            else if (carta2.area > carta1.area)
                printf("%s venceu!\n", carta2.nomeCidade);
            else
                printf("Empate!\n");
            break;
        case 3:
            printf("PIB:\n");
            if (carta1.pib > carta2.pib)
                printf("%s venceu!\n", carta1.nomeCidade);
            else if (carta2.pib > carta1.pib)
                printf("%s venceu!\n", carta2.nomeCidade);
            else
                printf("Empate!\n");
            break;
        case 4:
            printf("Densidade populacional:\n");
            if (carta1.densidadePopulacional > carta2.densidadePopulacional)
                printf("%s venceu!\n", carta1.nomeCidade);
            else if (carta2.densidadePopulacional > carta1.densidadePopulacional)
                printf("%s venceu!\n", carta2.nomeCidade);
            else
                printf("Empate!\n");
            break;
        case 5:
            printf("PIB per capita:\n");
            if (carta1.pibPerCapita > carta2.pibPerCapita)
                printf("%s venceu!\n", carta1.nomeCidade);
            else if (carta2.pibPerCapita > carta1.pibPerCapita)
                printf("%s venceu!\n", carta2.nomeCidade);
            else
                printf("Empate!\n");
            break;
        case 6:
            printf("Pontos turísticos:\n");
            if (carta1.pontosTuristicos > carta2.pontosTuristicos)
                printf("%s venceu!\n", carta1.nomeCidade);
            else if (carta2.pontosTuristicos > carta1.pontosTuristicos)
                printf("%s venceu!\n", carta2.nomeCidade);
            else
                printf("Empate!\n");
            break;
        default:
            printf("Opção inválida!\n");
    }

    return 0;
}

