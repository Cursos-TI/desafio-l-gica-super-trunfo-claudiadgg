#include <stdio.h>
// Desafio Super Trunfo - Países
// Nível Novato - Comparação por População
// Desenvolvido por Claudia Goulart

// Estrutura para armazenar dados de uma cidade
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

// Função para calcular densidade populacional e PIB per capita
void calcularIndicadores(struct Carta *c) {
    c->densidadePopulacional = c->area > 0 ? (float)c->populacao / c->area : 0;
    c->pibPerCapita = c->populacao > 0 ? (c->pib * 1000000000) / c->populacao : 0;
}

// Função para exibir os dados da carta
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

// Cadastro da primeira carta
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

    // Cadastro da segunda carta
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

   // Exibição das cartas
    exibirCarta(carta1);
    exibirCarta(carta2);

    // Comparação por População
    printf("\n===== Comparação de Cartas (Atributo: População) =====\n");
    printf("%s: %d habitantes\n", carta1.nomeCidade, carta1.populacao);
    printf("%s: %d habitantes\n", carta2.nomeCidade, carta2.populacao);

    if (carta1.populacao > carta2.populacao) {
        printf("Resultado: %s venceu!\n", carta1.nomeCidade);
    } else if (carta2.populacao > carta1.populacao) {
        printf("Resultado: %s venceu!\n", carta2.nomeCidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
