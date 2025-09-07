#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ItemDequeEnc.h"

struct item {
    int id;
    char descricao[100];
    char categoria[50];
    int ano;
    char situacao[20];
};

struct celula {
    Item item;
    Celula *prox;
};

struct deque {
    Celula *ini;
    Celula *fim;
};

Deque* cria_Deque() {
    Deque* dq = (Deque*) malloc(sizeof(Deque));
    if (dq != NULL) {
        dq->ini = NULL;
        dq->fim = NULL;
    }
    return dq;
}

int verificaDequeVazia(Deque* dq) {
    return (dq->ini == NULL);
}

int insereFinal_Deque(Deque* dq, int id, char* descricao, char* categoria, int ano, char* situacao) {
    if (busca_Deque(dq, id) != NULL) {
        return 0; // ID já existe
    }
    Item novo;
    novo.id = id;
    strncpy(novo.descricao, descricao, 99);
    novo.descricao[99] = '\0';
    strncpy(novo.categoria, categoria, 49);
    novo.categoria[49] = '\0';
    novo.ano = ano;
    strncpy(novo.situacao, situacao, 19);
    novo.situacao[19] = '\0';

    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    nova->prox = NULL;

    if (verificaDequeVazia(dq)) {
        dq->ini = nova;
        dq->fim = nova;
    } else {
        dq->fim->prox = nova;
        dq->fim = nova;
    }
    return 1;
}

int insereInicio_Deque(Deque* dq, int id, char* descricao, char* categoria, int ano, char* situacao) {
    if (busca_Deque(dq, id) != NULL) {
        return 0; // ID já existe
    }
    Item novo;
    novo.id = id;
    strncpy(novo.descricao, descricao, 99);
    novo.descricao[99] = '\0';
    strncpy(novo.categoria, categoria, 49);
    novo.categoria[49] = '\0';
    novo.ano = ano;
    strncpy(novo.situacao, situacao, 19);
    novo.situacao[19] = '\0';

    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    nova->prox = dq->ini;

    if (verificaDequeVazia(dq)) {
        dq->fim = nova;
    }
    dq->ini = nova;
    return 1;
}

void removeInicio_Deque(Deque* dq) {
    if (verificaDequeVazia(dq)) {
        printf("Erro: Deque vazia!\n");
        return;
    }
    Celula *remover = dq->ini;
    dq->ini = remover->prox;
    free(remover);
    if (verificaDequeVazia(dq)) {
        dq->fim = NULL;
    }
}

void removeFinal_Deque(Deque* dq) {
    if (verificaDequeVazia(dq)) {
        printf("Erro: Deque vazia!\n");
        return;
    }
    Celula *remover = dq->fim;
    if (remover == dq->ini) {
        dq->ini = NULL;
        dq->fim = NULL;
    } else {
        Celula *ultimo = dq->ini;
        while (ultimo->prox != dq->fim) {
            ultimo = ultimo->prox;
        }
        ultimo->prox = NULL;
        dq->fim = ultimo;
    }
    free(remover);
}

void imprime_Deque(Deque* dq) {
    if (verificaDequeVazia(dq)) {
        printf("Deque vazia!\n");
        return;
    }
    Celula *aux = dq->ini;
    while (aux != NULL) {
        printf("ID: %d\n", aux->item.id);
        printf("Descrição: %s\n", aux->item.descricao);
        printf("Categoria: %s\n", aux->item.categoria);
        printf("Ano: %d\n", aux->item.ano);
        printf("Situação: %s\n", aux->item.situacao);
        printf("-------------------\n");
        aux = aux->prox;
    }
}

Item* busca_Deque(Deque* dq, int id) {
    Celula *aux = dq->ini;
    while (aux != NULL) {
        if (aux->item.id == id) {
            return &(aux->item);
        }
        aux = aux->prox;
    }
    return NULL;
}

void copiaRealizadas_Deque(Deque* origem, Deque* destino){
    Celula *aux = origem->ini;
    while (aux != NULL) {
        if (strcmp(aux->item.situacao, "Realizada") == 0) {
            insereFinal_Deque(destino, aux->item.id, aux->item.descricao,
                             aux->item.categoria, aux->item.ano, aux->item.situacao);
        }
        aux = aux->prox;
    }
}

int removePorID_Deque(Deque* dq, int id) {
    if (verificaDequeVazia(dq)) {
        return 0; // Deque vazia
    }
    if (dq->ini->item.id == id) {
        removeInicio_Deque(dq);
        return 1;
    }
    Celula *aux = dq->ini;
    while (aux->prox != NULL && aux->prox->item.id != id) {
        aux = aux->prox;
    }
    if (aux->prox == NULL) {
        return 0; // ID não encontrado
    }
    Celula *temp = aux->prox;
    aux->prox = temp->prox;
    if (temp == dq->fim) {
        dq->fim = aux;
    }
    free(temp);
    return 1;
}

void imprimeItem_Deque(Item* item) {
    if (item == NULL) {
        printf("Elemento não encontrado!\n");
        return;
    }
    printf("ID: %d\n", item->id);
    printf("Descrição: %s\n", item->descricao);
    printf("Categoria: %s\n", item->categoria);
    printf("Ano: %d\n", item->ano);
    printf("Situação: %s\n", item->situacao);
}

void libera_Deque(Deque* dq) {
    Celula *aux = dq->ini;
    Celula *liberar;
    while (aux != NULL) {
        liberar = aux;
        aux = aux->prox;
        free(liberar);
    }
    free(dq);
}
