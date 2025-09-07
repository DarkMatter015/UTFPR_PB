#include <stdio.h>
#include <stdlib.h>
#include "itemFila.h"

struct item {
    int chave;
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

void enfileira(Fila *f, int chave) {
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
        printf("Chave: %d\n", f->vetItens[i].chave);
        i = (i + 1) % MAXTAM; //Controle da fila circular
    }
}

