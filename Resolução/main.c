//Wesley Silva Araújo (2023010487)

#include <stdio.h>
#include <string.h>
#include "lst.h"

int main() {
    Lista *dados[100] = {NULL}; // Vetor de ponteiros para listas de palavras
    char entrada[101]; // Buffer para armazenar palavras lidas do arquivo
    FILE *arquivo = fopen("frases.txt", "r");
    if (!arquivo) {
        perror("Erro ao abrir arquivo");
        return 1;
    }

    int linha_atual = 0;
    while (fscanf(arquivo, " %100s", entrada) != EOF) {
        int encontrado = 0;
         // Verifica se a palavra já existe na lista de dados
        for (int i = 0; dados[i] != NULL; i++) {
            if (strcmp(entrada, obter_palavra(dados[i])) == 0) {
                inserir_nodo(dados[i], linha_atual);
                encontrado = 1;
                break;
            }
        }
        // Se a palavra não foi encontrada, cria uma nova lista para ela
        if (!encontrado) {
            int i;
            for (i = 0; dados[i] != NULL; i++);
            dados[i] = criar_lista(entrada);
            inserir_nodo(dados[i], linha_atual);
        }
        // Incrementa a linha ao encontrar uma nova quebra de linha
        if (fgetc(arquivo) == '\n') {
            linha_atual++;
        }
    }
    fclose(arquivo);
    // Imprime as listas e libera a memória
    for (int i = 0; dados[i] != NULL; i++) {
        imprimir_lista(dados[i]);
        liberar_lista(dados[i]);
    }

    return 0;
}
