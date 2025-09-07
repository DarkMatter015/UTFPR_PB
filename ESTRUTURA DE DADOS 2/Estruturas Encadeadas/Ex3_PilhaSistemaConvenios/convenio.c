#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "convenio.h"

struct lucasCamargo {
    char nome[50];         // Nome da empresa
    char area[30];         // Área de atuação
    float desconto;        // Desconto para associados (em porcentagem)
};

struct celula {
    LucasCamargo convenio;
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

void empilhaConvenio(Pilha *p, char *nome, char *area, float desconto) {
    LucasCamargo novo;
    strncpy(novo.nome, nome, sizeof(novo.nome) - 1);
    novo.nome[sizeof(novo.nome) - 1] = '\0'; // Garante terminação da string
    strncpy(novo.area, area, sizeof(novo.area) - 1);
    novo.area[sizeof(novo.area) - 1] = '\0'; // Garante terminação da string
    novo.desconto = desconto;

    Celula *nova = malloc(sizeof(Celula));
    if (nova == NULL) {
        printf("Erro: falha ao alocar memoria para o convenio.\n");
        exit(1);
    }
    nova->convenio = novo;
    nova->prox = p->topo;
    p->topo = nova;
}

void desempilhaConvenio(Pilha *p) {
    if (verificaPilhaVazia(p)) {
        printf("ERRO: Pilha vazia!\n");
        return;
    }
    Celula *remover = p->topo;
    printf("Convênio '%s' removido do topo.\n", remover->convenio.nome);
    p->topo = remover->prox;
    free(remover);
}

void imprimePilha(Pilha *p) {
    if (verificaPilhaVazia(p)) {
        printf("Nenhum convênio cadastrado.\n");
        return;
    }
    Celula *aux;
    printf("\n=== Lista de Convênios ===\n");
    for (aux = p->topo; aux != NULL; aux = aux->prox) {
        printf("Empresa: %s\n", aux->convenio.nome);
        printf("Área: %s\n", aux->convenio.area);
        printf("Desconto: %.2f%%\n", aux->convenio.desconto);
        printf("------------------------\n");
    }
}

int verificaPilhaVazia(Pilha *p) {
    return p->topo == NULL;
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
