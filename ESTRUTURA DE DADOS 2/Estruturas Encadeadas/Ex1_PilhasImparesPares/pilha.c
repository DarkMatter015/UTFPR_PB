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

void desempilha(Pilha *p) {
    if (verificaPilhaVazia(p)) {
        printf("ERRO: Pilha vazia!\n");
        return;
    }
    Celula *remover = p->topo;
    p->topo = remover->prox;
    free(remover);
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

void separaParesImpares(Pilha *p1, Pilha *p2, Pilha *p3) {
    // Verifica se p2 e p3 estão vazias e se p1 tem elementos
    if (!verificaPilhaVazia(p2) || !verificaPilhaVazia(p3) || verificaPilhaVazia(p1)) {
        printf("Erro: p2 e p3 devem estar vazias e p1 nao deve estar vazia.\n");
        return;
    }

    // Percorre p1 e separa os números
    Celula *aux = p1->topo;
    while (aux != NULL) {
        int chave = aux->item.chave;
        if (chave % 2 == 0) {
            empilha(p2, chave); // Par vai para p2
        } else {
            empilha(p3, chave); // Ímpar vai para p3
        }
        aux = aux->prox;
    }
}
