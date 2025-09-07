#include <stdio.h>
#include <stdlib.h>
#include "itemPilha.h"

struct item {
    int chave;
    //demais campos
};

struct pilha {
    Item vetItens[MAXTAM];
    int topo;
};

Pilha *criaPilhaVazia() {
    Pilha *p = (Pilha *) malloc(sizeof(Pilha));
    p->topo = -1;
    return p;
}

//retorna 1 se a pilha está cheia ou 0 se não está
int verificaPilhaCheia(Pilha *p) {
    return p->topo == (MAXTAM - 1);
}

void empilha(Pilha *p, int chave) {
    if (verificaPilhaCheia(p))
    {
        printf("Erro: a pilha esta cheia.\n");
        return;
    }
    Item novoItem;
    novoItem.chave = chave;
    p->topo++;
    p->vetItens[p->topo] = novoItem;
}

void desempilha(Pilha *p) {
    if (verificaPilhaVazia(p))
    {
        printf("Erro: a pilha esta vazia.\n");
        return;
    }
    p->topo--;
}

void imprimePilha(Pilha *p) {
    for (int i = 0; i <= p->topo; i++)
    {
        printf("Chave: %d\n", p->vetItens[i].chave);
    }
}
//retorna 1 se a pilha está vazia ou 0 se não está
int verificaPilhaVazia(Pilha *p) {
    return p->topo == -1;
}

void liberaPilha(Pilha *p) {
    free(p);
}

