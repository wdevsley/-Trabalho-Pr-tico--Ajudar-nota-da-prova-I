//Wesley Silva Araújo (2023010487)

#ifndef LST_H
#define LST_H

// Tipo exportado: Nodo ou Nó
typedef struct nodo Nodo;

// Tipo exportado: Lista encadeada
typedef struct lista Lista;

// Retorna a palavra armazenada na lista
const char *obter_palavra(const Lista *lista);

// Função cria
Lista *criar_lista(const char *palavra);

// Função insere
void inserir_nodo(Lista *lista, int linha);

// Função imprime
void imprimir_lista(const Lista *lista);

// Função libera
void liberar_lista(Lista *lista);

#endif
