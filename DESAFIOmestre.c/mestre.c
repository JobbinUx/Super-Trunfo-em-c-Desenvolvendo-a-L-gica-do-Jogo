#include <stdio.h>
#include <string.h>

#define NUM_CARTAS 2

// Estrutura para armazenar os dados da carta
typedef struct {
    char nome[30];
    int populacao;              // em milhões
    int area;                   // em mil km²
    int pib;                    // em bilhões
    int expectativaVida;        // em anos
    int densidadeDemografica;   // pessoas por km²
    int ataque;                 // 0 a 100
    int recuo;                  // 0 a 100 (quanto menor, melhor)
} Carta;

// Função para mostrar os atributos disponíveis
void mostrarAtributos(int excluido) {
    printf("\nEscolha um atributo:\n");
    if (excluido != 1) printf("1 - População\n");
    if (excluido != 2) printf("2 - Área\n");
    if (excluido != 3) printf("3 - PIB\n");
    if (excluido != 4) printf("4 - Expectativa de Vida\n");
    if (excluido != 5) printf("5 - Densidade Demográfica\n");
    if (excluido != 6) printf("6 - Ataque\n");
    if (excluido != 7) printf("7 - Recuo\n");
    printf("Escolha: ");
}

// Função para obter o valor do atributo
int obterValor(Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.expectativaVida;
        case 5: return c.densidadeDemografica;
        case 6: return c.ataque;
        case 7: return c.recuo;
        default: return 0;
    }
}
// Nome do atributo
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Expectativa de Vida";
        case 5: return "Densidade Demográfica";
        case 6: return "Ataque";
        case 7: return "Recuo";
        default: return "Desconhecido";
    }
    int menorVence(int atributo) {
    return (atributo == 5 || atributo == 7); // Densidade ou Recuo
}

int main() {
    // Cartas pré-cadastradas
    Carta cartas[NUM_CARTAS] = {
        {"Brasil", 213, 8516, 2200, 75, 25, 80, 20},
        {"Alemanha", 83, 357, 4200, 81, 232, 70, 10}
    };

    int atributo1 = 0, atributo2 = 0;

    // Escolha do primeiro atributo
    do {
        mostrarAtributos(0);
        scanf("%d", &atributo1);
        if (atributo1 < 1 || atributo1 > 7) {
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (atributo1 < 1 || atributo1 > 7);
  // Escolha do segundo atributo
    do {
        mostrarAtributos(atributo1);
        scanf("%d", &atributo2);
        if (atributo2 < 1 || atributo2 > 7 || atributo2 == atributo1) {
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (atributo2 < 1 || atributo2 > 7 || atributo2 == atributo1);

    // Obter os valores
    int valor1_c1 = obterValor(cartas[0], atributo1);
    int valor1_c2 = obterValor(cartas[1], atributo1);
    int valor2_c1 = obterValor(cartas[0], atributo2);
    int valor2_c2 = obterValor(cartas[1], atributo2);

    // Mostrar os dados
    printf("\n--- Comparando Cartas ---\n");
    printf("Carta 1: %s\n", cartas[0].nome);
    printf("Carta 2: %s\n", cartas[1].nome);

    printf("\nAtributo 1: %s\n", nomeAtributo(atributo1));
    printf("  %s: %d\n", cartas[0].nome, valor1_c1);
    printf("  %s: %d\n", cartas[1].nome, valor1_c2);

    printf("\nAtributo 2: %s\n", nomeAtributo(atributo2));
    printf("  %s: %d\n", cartas[0].nome, valor2_c1);
    printf("  %s: %d\n", cartas[1].nome, valor2_c2);