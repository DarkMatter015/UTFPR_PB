#include <stdio.h>
#include <stdlib.h>
#include "sla.h"

struct item {
    char chave;
    //demais campos
};

struct fila {
    Item vetItens[MAXTAM];
    int primeiro;
    int ultimo;
    int tamanho;
};

Fila *criaFilaVazia() {
    Fila *f = (Fila *) malloc(sizeof(Fila));
    f->primeiro = 0;
    f->ultimo = 0;
    f->tamanho = 0;
    return f;
}

//retorna 1 se a fila está cheia ou não
int verificaFilaCheia(Fila *f) {
    return f->tamanho == MAXTAM;
}

void enfileira(Fila *f, char chave) {
    if (verificaFilaCheia(f))
    {
        printf("Erro: a fila esta cheia.\n");
        return;
    }
    Item novoItem;
    novoItem.chave = chave;
    f->vetItens[f->ultimo] = novoItem;
    f->ultimo = (f->ultimo + 1) % MAXTAM; //Controle da fila circular
    f->tamanho++;
}

void desenfileira(Fila *f) {
    if (verificaFilaVazia(f))
    {
        printf("Erro: a fila esta vazia.\n");
        return;
    }
    f->primeiro = (f->primeiro + 1) % MAXTAM;//Controle da fila circular
    f->tamanho--;
}

//retorna 1 se a fila está vazia e 0 se não está
int verificaFilaVazia(Fila *f) {
    return f->tamanho == 0;
}

void liberaFila(Fila *f) {
    free(f);
}

void imprimeFila(Fila *f) {
    int t;
    int i = f->primeiro;
    for (t = 0; t < f->tamanho; t++)
    {
        printf("Chave: %c\n", f->vetItens[i].chave);
        i = (i + 1) % MAXTAM; //Controle da fila circular
    }
}


// Pilha

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

void empilha(Pilha *p, char chave) {
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
