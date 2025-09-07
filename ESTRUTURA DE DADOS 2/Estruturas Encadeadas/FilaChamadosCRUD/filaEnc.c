#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filaEnc.h"

struct lucas {
    char nome[50];
    int ticket_id;
    char problema[100];
};

struct celula {
    LUCAS dados;
    Celula *prox;
};

struct fila {
    Celula *primeira; // Aponta para o início da fila
    Celula *ultima;   // Aponta para o fim da fila
};

Fila *criaFilaVazia() {
    Fila *f = malloc(sizeof(Fila));
    f->primeira = NULL;
    f->ultima = NULL;
    return f;
}

int verificaFilaVazia(Fila *f) {
    return (f->primeira == NULL);
}

void enfileira(Fila *f, char *nome, int ticket_id, char *problema) {
    LUCAS novo;
    strcpy(novo.nome, nome);
    novo.ticket_id = ticket_id;
    strcpy(novo.problema, problema);

    Celula *nova = malloc(sizeof(Celula));
    nova->dados = novo;
    nova->prox = NULL;

    if (verificaFilaVazia(f)) {
        f->primeira = nova;
        f->ultima = nova;
    } else {
        f->ultima->prox = nova;
        f->ultima = nova;
    }
}

void desenfileira(Fila *f) {
    if (verificaFilaVazia(f)) {
        printf("Fila vazia! Nenhum chamado para remover.\n");
        return;
    }
    Celula *temp = f->primeira;
    f->primeira = f->primeira->prox;
    if (f->primeira == NULL) {
        f->ultima = NULL; // Fila vazia
    }
    printf("Chamado removido: %s (ID: %d, Problema: %s)\n",
           temp->dados.nome, temp->dados.ticket_id, temp->dados.problema);
    free(temp);
}

void imprimeFila(Fila *f) {
    if (verificaFilaVazia(f)) {
        printf("Fila vazia! Nenhum chamado registrado.\n");
        return;
    }
    printf("\n=== Chamados na Fila ===\n");
    Celula *aux = f->primeira;
    while (aux != NULL) {
        printf("Nome: %s, ID: %d, Problema: %s\n",
               aux->dados.nome, aux->dados.ticket_id, aux->dados.problema);
        aux = aux->prox;
    }
    printf("======================\n");
}

void liberaFila(Fila *f) {
    Celula *aux = f->primeira;
    Celula *liberar;
    while (aux != NULL) {
        liberar = aux;
        aux = aux->prox;
        free(liberar);
    }
    free(f);
}
