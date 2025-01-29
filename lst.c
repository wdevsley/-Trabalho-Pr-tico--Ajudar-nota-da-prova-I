//Wesley Silva Araújo (2023010487)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lst.h"

struct nodo {
    int linha;          // Número da linha onde a palavra ocorre
    int ocorrencias;    // Número de vezes que a palavra ocorre nessa linha
    struct nodo *proximo;  // Ponteiro para o próximo nodo na lista
};

struct lista {
    int tamanho;
    char palavra[100];
    Nodo *inicio;
};
// Cria uma nova lista associada a uma palavra
Lista *criar_lista(const char *palavra) {
    Lista *nova = (Lista *)malloc(sizeof(Lista));
    nova->tamanho = 0;
    strncpy(nova->palavra, palavra, sizeof(nova->palavra) - 1);
    nova->palavra[sizeof(nova->palavra) - 1] = '\0';
    nova->inicio = NULL;
    return nova;
}
// Insere um novo nodo na lista ou incrementa as ocorrências se a linha já existir
void inserir_nodo(Lista *lista, int linha) {
    Nodo *atual = lista->inicio;
    while (atual != NULL) {
        if (atual->linha == linha) {
            atual->ocorrencias++;
            return;
        }
        atual = atual->proximo;
    }
// Criando um novo nodo caso a linha ainda não esteja registrada
    Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
    novo->linha = linha;
    novo->ocorrencias = 1;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->tamanho++;
}
// Exibe a lista de ocorrências da palavra
void imprimir_lista(const Lista *lista) {
    printf("%10s:", lista->palavra);
    Nodo *atual = lista->inicio;
    while (atual != NULL) {
        printf(" (%d|%d)", atual->linha, atual->ocorrencias);
        atual = atual->proximo;
    }
    printf("\n");
}
// Libera toda a memória alocada para a lista
void liberar_lista(Lista *lista) {
    Nodo *atual = lista->inicio;
    while (atual != NULL) {
        Nodo *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(lista);
    // Retorna a palavra armazenada na lista
}const char *obter_palavra(const Lista *lista) {
    return lista->palavra;
}

