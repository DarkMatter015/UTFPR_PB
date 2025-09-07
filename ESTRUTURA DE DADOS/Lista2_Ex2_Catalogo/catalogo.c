#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "catalogo.h"

struct pilha {
    Filme vetItens[MAXTAM];
    int topo;
};

Pilha *criaPilhaVazia() {
    Pilha *p = (Pilha *) malloc(sizeof(Pilha));
    p->topo = -1;
    return p;
}

int verificaPilhaCheia(Pilha *p) {
    return p->topo == (MAXTAM - 1);
}

int verificaPilhaVazia(Pilha *p) {
    return p->topo == -1;
}

void empilha(Pilha *p, Filme filme) {
    if (verificaPilhaCheia(p)) {
        printf("Erro: pilha cheia.\n");
        return;
    }
    p->topo++;
    p->vetItens[p->topo] = filme;
}

int buscaPorCodigo(Pilha *p, int codigo) {
    for (int i = 0; i <= p->topo; i++) {
        if (p->vetItens[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

void removeItem(Pilha *p, int codigo) {
    int idx = buscaPorCodigo(p, codigo);
    if (idx == -1) {
        printf("Filme ou série não encontrado.\n");
        return;
    }

    for (int i = idx; i < p->topo; i++) {
        p->vetItens[i] = p->vetItens[i + 1];
    }
    p->topo--;
    printf("Elemento removido com sucesso.\n");
}

void imprimePilha(Pilha *p) {
    if (verificaPilhaVazia(p)) {
        printf("A pilha está vazia.\n");
        return;
    }

    for (int i = 0; i <= p->topo; i++) {
        printf("\nCódigo: %d\n", p->vetItens[i].codigo);
        printf("Título: %s\n", p->vetItens[i].titulo);
        printf("Gênero: %s\n", p->vetItens[i].genero);
        printf("Duração: %d minutos\n", p->vetItens[i].duracao);
    }
}

Pilha *filtraPorGenero(Pilha *p, char genero[]) {
    Pilha *novaPilha = criaPilhaVazia();
    for (int i = 0; i <= p->topo; i++) {
        if (strcmp(p->vetItens[i].genero, genero) == 0) {
            empilha(novaPilha, p->vetItens[i]);
        }
    }
    return novaPilha;
}

void liberaPilha(Pilha *p) {
    free(p);
}
