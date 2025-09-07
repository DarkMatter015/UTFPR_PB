#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"

struct lucasCamargo {
    char nome[50];
    char telefone[15];
    char email[50];
};

struct celula {
    LucasCamargo contato;
    Celula *prox;
};

struct agenda {
    Celula *primeira;
};

Agenda * criaAgendaVazia() {
    Agenda *ag = malloc(sizeof(Agenda));
    if (ag == NULL) {
        printf("Erro: falha ao alocar memoria para a agenda.\n");
        exit(1);
    }
    ag->primeira = NULL;
    return ag;
}

int verificaAgendaVazia(Agenda *ag) {
    return (ag->primeira == NULL);
}

void insereContato(Agenda *ag, char *nome, char *telefone, char *email) {
    LucasCamargo novo;
    strncpy(novo.nome, nome, sizeof(novo.nome) - 1);
    novo.nome[sizeof(novo.nome) - 1] = '\0'; // Garante terminação da string
    strncpy(novo.telefone, telefone, sizeof(novo.telefone) - 1);
    novo.telefone[sizeof(novo.telefone) - 1] = '\0';
    strncpy(novo.email, email, sizeof(novo.email) - 1);
    novo.email[sizeof(novo.email) - 1] = '\0';

    Celula *nova = malloc(sizeof(Celula));
    if (nova == NULL) {
        printf("Erro: falha ao alocar memoria para o contato.\n");
        exit(1);
    }
    nova->contato = novo;
    nova->prox = ag->primeira; // Insere no início
    ag->primeira = nova;
}

void removeContato(Agenda *ag, char *nome) {
    Celula *aux = ag->primeira;
    Celula *anterior = NULL;

    while (aux != NULL && strcmp(aux->contato.nome, nome) != 0) {
        anterior = aux;
        aux = aux->prox;
    }

    if (aux == NULL) {
        printf("Contato '%s' nao encontrado na agenda.\n", nome);
        return;
    }

    if (anterior == NULL) {
        ag->primeira = aux->prox; // Remove do início
    } else {
        anterior->prox = aux->prox; // Remove do meio ou fim
    }

    printf("Contato '%s' removido com sucesso.\n", nome);
    free(aux);
}

void imprimeAgenda(Agenda *ag) {
    if (verificaAgendaVazia(ag)) {
        printf("Agenda vazia.\n");
        return;
    }

    Celula *aux = ag->primeira;
    printf("\n=== Agenda Telefonica ===\n");
    while (aux != NULL) {
        printf("Nome: %s\n", aux->contato.nome);
        printf("Telefone: %s\n", aux->contato.telefone);
        printf("E-mail: %s\n", aux->contato.email);
        printf("------------------------\n");
        aux = aux->prox;
    }
}

void liberaAgenda(Agenda *ag) {
    Celula *aux = ag->primeira;
    Celula *liberar;
    while (aux != NULL) {
        liberar = aux;
        aux = aux->prox;
        free(liberar);
    }
    free(ag);
}
