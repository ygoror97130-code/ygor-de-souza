
#include <stdio.h>
#include <stdlib.h>

struct Produto {
    char nome[100];
    float preco;
    int quantidade;
    struct Produto *proximo;
};

int main() {
    struct Produto *inicio = NULL;
    struct Produto *fim = NULL;
    int opcao;

    do {
        struct Produto *novo;

        novo = (struct Produto*) malloc(sizeof(struct Produto));

        if (novo == NULL) {
            printf("Erro ao alocar memoria!\n");
            return 1;
        }

        printf("Digite o nome do produto: ");
        scanf(" %99[^\n]", novo->nome);

        printf("Digite o preco: ");
        scanf("%f", &novo->preco);

        printf("Digite a quantidade: ");
        scanf("%d", &novo->quantidade);

        novo->proximo = NULL;

        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            fim->proximo = novo;
            fim = novo;
        }

        printf("\nDeseja cadastrar outro produto?\n");
        printf("1 - Sim / 0 - Nao: ");
        scanf("%d", &opcao);

    } while (opcao == 1);

    printf("\n=== PRODUTOS CADASTRADOS ===\n");

    struct Produto *atual = inicio;

    while (atual != NULL) {
        printf("\nNome: %s\n", atual->nome);
        printf("Preco: R$ %.2f\n", atual->preco);
        printf("Quantidade: %d\n", atual->quantidade);

        atual = atual->proximo;
    }

    // Liberar a memoria
    struct Produto *temp;

    while (inicio != NULL) {
        temp = inicio;
        inicio = inicio->proximo;
        free(temp);
    }

    return 0;
}
