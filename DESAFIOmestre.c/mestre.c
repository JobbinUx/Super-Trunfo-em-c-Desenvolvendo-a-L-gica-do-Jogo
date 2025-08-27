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