#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ItemFilaEnc.h"
#include "Data.h"

struct item {
    int id;
    char nome[100];
    Data* dataEvento;
    char hora[10];
    char descricao[200];
    Data* dataInscricao;
};

struct celula {
    Item item;
    Celula* prox;
};

struct fila {
    Celula* primeira;
};

Fila* criaFilaVazia() {
    Fila* f = (Fila*) malloc(sizeof(Fila));
    if (f != NULL) {
        f->primeira = NULL;
    }
    return f;
}

int verificaFilaVazia(Fila* f) {
    return (f->primeira == NULL);
}

int insereFila(Fila* f, int id, char* nome, Data* dataEvento, char* hora, char* descricao) {
    Item novo;
    novo.id = id;
    strncpy(novo.nome, nome, 99);
    novo.nome[99] = '\0';
    novo.dataEvento = dataEvento;
    strncpy(novo.hora, hora, 9);
    novo.hora[9] = '\0';
    strncpy(novo.descricao, descricao, 199);
    novo.descricao[199] = '\0';
    novo.dataInscricao = dataHoje();
    if (novo.dataInscricao == NULL) {
        return 0; // Falha ao obter data de inscrição
    }

    Celula* nova = (Celula*) malloc(sizeof(Celula));
    if (nova == NULL) {
        liberarData(novo.dataInscricao);
        return 0;
    }
    nova->item = novo;
    nova->prox = NULL;

    if (verificaFilaVazia(f)) {
        f->primeira = nova;
    } else {
        Celula* ultima = f->primeira;
        while (ultima->prox != NULL) {
            ultima = ultima->prox;
        }
        ultima->prox = nova;
    }
    return 1;
}

void removeInicioFila(Fila* f) {
    if (verificaFilaVazia(f)) {
        printf("Erro: Fila vazia!\n");
        return;
    }
    Celula* remover = f->primeira;
    f->primeira = remover->prox;
    liberarData(remover->item.dataEvento);
    liberarData(remover->item.dataInscricao);
    free(remover);
}

void imprimeItemFila(Item* item) {
    if (item == NULL) {
        printf("Item inválido!\n");
        return;
    }
    printf("ID: %d\n", item->id);
    printf("Nome: %s\n", item->nome);
    printf("Data do Evento: ");
    imprimirData(item->dataEvento);
    printf("\n");
    printf("Hora: %s\n", item->hora);
    printf("Descrição: %s\n", item->descricao);
    printf("Data de Inscrição: ");
    imprimirData(item->dataInscricao);
    printf("\n");
}

void imprimeFila(Fila* f) {
    if (verificaFilaVazia(f)) {
        printf("Fila vazia!\n");
        return;
    }
    Celula* aux = f->primeira;
    while (aux != NULL) {
        imprimeItemFila(&(aux->item));
        printf("-------------------\n");
        aux = aux->prox;
    }
}

void liberaFila(Fila* f) {
    Celula* aux = f->primeira;
    Celula* liberar;
    while (aux != NULL) {
        liberar = aux;
        aux = aux->prox;
        liberarData(liberar->item.dataEvento);
        liberarData(liberar->item.dataInscricao);
        free(liberar);
    }
    free(f);
}
