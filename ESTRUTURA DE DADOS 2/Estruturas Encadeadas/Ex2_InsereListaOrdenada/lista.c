#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct item {
    int chave;
};

struct celula {
    Item item;
    Celula *prox;
};

struct lista {
    Celula *primeira;
};

Lista * criaListaVazia() {
    Lista *lst = malloc(sizeof(Lista));
    if (lst == NULL) {
        printf("Erro: falha ao alocar memoria para a lista.\n");
        exit(1);
    }
    lst->primeira = NULL;
    return lst;
}

int verificaListaVazia(Lista *lst) {
    return (lst->primeira == NULL);
}

void insereFimLista(Lista *lst, int chave) {
    Item novo;
    novo.chave = chave;
    Celula *nova = malloc(sizeof(Celula));
    if (nova == NULL) {
        printf("Erro: falha ao alocar memoria para a celula.\n");
        exit(1);
    }
    nova->item = novo;
    nova->prox = NULL;
    if (verificaListaVazia(lst)) {
        lst->primeira = nova;
    } else {
        Celula *ultima = lst->primeira;
        while (ultima->prox != NULL) {
            ultima = ultima->prox;
        }
        ultima->prox = nova;
    }
}

void imprimeLista(Lista *lst) {
    Celula *aux = lst->primeira;
    while (aux != NULL) {
        printf("Chave: %d\n", aux->item.chave);
        aux = aux->prox;
    }
}

void liberaLista(Lista *lst) {
    Celula *aux = lst->primeira;
    Celula *liberar;
    while (aux != NULL) {
        liberar = aux;
        aux = aux->prox;
        free(liberar);
    }
    free(lst);
}

void insereOrdenado(Lista *lst1, Lista *lst2) {
    if (!verificaListaVazia(lst2) || verificaListaVazia(lst1)) {
        return; // Não faz nada se lst2 não estiver vazia ou lst1 estiver vazia
    }

    Celula *atual = lst1->primeira;
    while (atual != NULL) {
        Item novo;
        novo.chave = atual->item.chave;
        Celula *nova = malloc(sizeof(Celula));
        if (nova == NULL) {
            printf("Erro: falha ao alocar memoria para a celula.\n");
            exit(1);
        }
        nova->item = novo;
        nova->prox = NULL;

        // Inserir em lst2 de forma ordenada
        if (lst2->primeira == NULL || lst2->primeira->item.chave > novo.chave) {
            nova->prox = lst2->primeira;
            lst2->primeira = nova;
        } else {
            Celula *aux = lst2->primeira;
            Celula *anterior = NULL;
            while (aux != NULL && aux->item.chave <= novo.chave) {
                anterior = aux;
                aux = aux->prox;
            }
            nova->prox = aux;
            anterior->prox = nova;
        }
        atual = atual->prox;
    }
}
