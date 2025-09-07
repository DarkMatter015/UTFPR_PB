#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct item {
    int chave;
};

struct celula {
    Item item;
    Celula *prox;
};

struct pilha {
    Celula *topo;
};

Pilha * criaPilhaVazia() {
    Pilha *p = malloc(sizeof(Pilha));
    if (p == NULL) {
        printf("Erro: falha ao alocar memoria para a pilha.\n");
        exit(1);
    }
    p->topo = NULL;
    return p;
}

void empilha(Pilha *p, int chave) {
    Item novo;
    novo.chave = chave;
    Celula *nova = malloc(sizeof(Celula));
    if (nova == NULL) {
        printf("Erro: falha ao alocar memoria para a celula.\n");
        exit(1);
    }
    nova->item = novo;
    nova->prox = p->topo;
    p->topo = nova;
}

void imprimePilha(Pilha *p) {
    Celula *aux;
    for (aux = p->topo; aux != NULL; aux = aux->prox) {
        printf("Chave: %d\n", aux->item.chave);
    }
}

int verificaPilhaVazia(Pilha *p) {
    return p->topo == NULL;
}

int desempilha(Pilha *p) {
    if (verificaPilhaVazia(p)) {
        printf("ERRO: Pilha vazia!\n");
        return -1; // Valor inválido para indicar erro
    }
    Celula *remover = p->topo;
    int chave = remover->item.chave;
    p->topo = remover->prox;
    free(remover);
    return chave;
}

void liberaPilha(Pilha *p) {
    Celula *aux = p->topo;
    Celula *liberar;
    while (aux != NULL) {
        liberar = aux;
        aux = aux->prox;
        free(liberar);
    }
    free(p);
}

void removeDuplicados(Pilha *p) {
    if (verificaPilhaVazia(p)) {
        return; // Nada a fazer se a pilha estiver vazia
    }

    // Criar pilha auxiliar
    Pilha *aux = criaPilhaVazia();
    int ultimoVisto = -1; // Valor inicial que não conflita com chaves válidas

    // Passo 1: Desempilhar tudo de p para aux, mantendo apenas o primeiro de cada duplicado
    while (!verificaPilhaVazia(p)) {
        int chave = desempilha(p);
        if (chave != ultimoVisto) { // Só empilha se não for duplicado do anterior
            empilha(aux, chave);
            ultimoVisto = chave;
        }
    }

    // Passo 2: Transferir de volta para p
    while (!verificaPilhaVazia(aux)) {
        empilha(p, desempilha(aux));
    }

    // Liberar a pilha auxiliar
    liberaPilha(aux);
}
