#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "itemListaDuplEnc.h"

struct item {
    char nome[30];
    char endereco[50];
    int telefone;
};

struct celula {
    Item *item; // Agora Item é um ponteiro
    Celula *ant;
    Celula *prox;
};

struct listaDupl {
    Celula *primeira;
};

//Cria um item com os dados fornecidos
Item *criaItem(char nome[], char endereco[], int telefone) {
    Item *item = malloc(sizeof(Item));
    if (item == NULL) {
        printf("Erro ao alocar memória para Item.\n");
        return NULL;
    }
    strcpy(item->nome, nome);
    strcpy(item->endereco, endereco);
    item->telefone = telefone;
    return item;
}

//Libera um item da memória
void liberaItem(Item *item) {
    if (item != NULL) {
        free(item);
    }
}

//Cria uma lista vazia
ListaDupl *criaListaDuplVazia() {
    ListaDupl *ld = malloc(sizeof(ListaDupl));
    if (ld == NULL) {
        printf("Erro ao alocar memória para ListaDupl.\n");
        return NULL;
    }
    ld->primeira = NULL;
    return ld;
}

//Insere um contato ordenado por telefone
void insere(ListaDupl *ld, Item *item) {
    if (ld == NULL || item == NULL) {
        printf("Lista ou item inválido.\n");
        return;
    }

    Celula *nova = malloc(sizeof(Celula));
    if (nova == NULL) {
        printf("Erro ao alocar memória para Celula.\n");
        return;
    }
    nova->item = item;

    // Se a lista está vazia ou o telefone é menor que o primeiro
    if (verificaListaDuplVazia(ld) || item->telefone < ld->primeira->item->telefone) {
        nova->prox = ld->primeira;
        nova->ant = NULL;
        if (!verificaListaDuplVazia(ld)) {
            ld->primeira->ant = nova;
        }
        ld->primeira = nova;
        return;
    }

    // Percorre a lista para encontrar a posição de inserção
    Celula *atual = ld->primeira;
    while (atual != NULL && atual->item->telefone < item->telefone) {
        atual = atual->prox;
    }

    // Insere no final se atual for NULL
    if (atual == NULL) {
        Celula *ultima = ld->primeira;
        while (ultima->prox != NULL) {
            ultima = ultima->prox;
        }
        nova->prox = NULL;
        nova->ant = ultima;
        ultima->prox = nova;
        return;
    }

    // Insere antes de atual
    nova->prox = atual;
    nova->ant = atual->ant;
    atual->ant = nova;
    if (nova->ant != NULL) {
        nova->ant->prox = nova;
    } else {
        ld->primeira = nova;
    }
}

//Remove um contato por nome
void removePorNome(ListaDupl *ld, char nome[]) {
    if (ld == NULL || verificaListaDuplVazia(ld)) {
        printf("Lista vazia ou inválida.\n");
        return;
    }

    Celula *atual = ld->primeira;
    while (atual != NULL && strcmp(atual->item->nome, nome) != 0) {
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Contato com nome %s não encontrado.\n", nome);
        return;
    }

    if (atual->ant == NULL && atual->prox == NULL) { // Único contato
        ld->primeira = NULL;
    } else if (atual == ld->primeira) { // Primeiro contato
        ld->primeira = atual->prox;
        ld->primeira->ant = NULL;
    } else { // Contato no meio ou final
        Celula *proxima = atual->prox;
        Celula *anterior = atual->ant;
        anterior->prox = proxima;
        if (proxima != NULL) {
            proxima->ant = anterior;
        }
    }
    liberaItem(atual->item);
    free(atual);
}

//Imprime os dados de um contato por nome
void imprime_contato(ListaDupl *ld, char nome[]) {
    if (ld == NULL || verificaListaDuplVazia(ld)) {
        printf("Lista vazia ou inválida.\n");
        return;
    }

    Celula *atual = ld->primeira;
    while (atual != NULL && strcmp(atual->item->nome, nome) != 0) {
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Contato com nome %s não encontrado.\n", nome);
        return;
    }

    printf("Nome: %s\n", atual->item->nome);
    printf("Endereço: %s\n", atual->item->endereco);
    printf("Telefone: %d\n", atual->item->telefone);
}

//Imprime a lista da esquerda para a direita
void imprimeEsqDir(ListaDupl *ld) {
    if (ld == NULL || verificaListaDuplVazia(ld)) {
        printf("Lista vazia ou inválida.\n");
        return;
    }

    Celula *aux = ld->primeira;
    while (aux != NULL) {
        printf("Nome: %s, Endereço: %s, Telefone: %d\n",
               aux->item->nome, aux->item->endereco, aux->item->telefone);
        aux = aux->prox;
    }
}

//Verifica se a lista está vazia
int verificaListaDuplVazia(ListaDupl *ld) {
    return ld == NULL || ld->primeira == NULL;
}

//Libera a lista da memória
void liberaListaDupl(ListaDupl *ld) {
    if (ld == NULL) return;

    Celula *aux = ld->primeira;
    Celula *liberar;
    while (aux != NULL) {
        liberar = aux;
        aux = aux->prox;
        liberaItem(liberar->item);
        free(liberar);
    }
    free(ld);
}
