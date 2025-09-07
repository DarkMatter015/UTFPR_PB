#include <stdio.h>
#include <stdlib.h>
#include "itemDeque.h"

struct item
{
    int chave;
    //demais campos
};

struct deque
{
    Item itens[MAXTAM];
    int inicio;
    int fim;
    int qtd;
};

Deque *criaDeque()
{
    Deque *dq;
    dq = (Deque*) malloc(sizeof(Deque));
    dq->inicio = 0;
    dq->fim = 0;
    dq->qtd = 0;
    return dq;
}

int dequeCheia(Deque *dq)
{
    return (dq->qtd == MAXTAM);
}

int dequeVazia(Deque *dq)
{
    return (dq->qtd == 0);
}

int insereFinalDeque(Deque *dq, int chave)
{
    if (dequeCheia(dq) != 0)
    {
        printf("\nErro: Nao foi possivel inserir, deque cheia ou erro.\n");
        return 0;
    }
    Item novoItem;
    novoItem.chave = chave;
    dq->itens[dq->fim] = novoItem;
    dq->fim = (dq->fim + 1) % MAXTAM;
    dq->qtd++;
    return 1;
}

int insereInicioDeque(Deque *dq, int chave)
{
    if (dequeCheia(dq) != 0)
    {
        printf("\nErro: Nao foi possivel inserir, deque cheia ou erro.\n");
        return 0;
    }
    dq->inicio--;
    if (dq->inicio < 0)
    {
        dq->inicio = MAXTAM - 1;
    }
    Item novoItem;
    novoItem.chave = chave;
    dq->itens[dq->inicio] = novoItem;
    dq->qtd++;
    return 1;
}

int removeInicioDeque(Deque *dq)
{
    if (dequeVazia(dq) != 0)
    {
        printf("\nErro: Nao foi possivel remover, deque vazia ou erro.\n");
        return 0;
    }
    dq->inicio = (dq->inicio + 1) % MAXTAM;
    dq->qtd--;
    return 1;
}

int removeFinalDeque(Deque *dq)
{
    if (dequeVazia(dq) != 0)
    {
        printf("\nErro: Nao foi possivel remover, deque vazia ou erro.\n");
        return 0;
    }
    dq->fim--;
    if (dq->fim < 0)
    {
        dq->fim = MAXTAM - 1;
    }
    dq->qtd--;
    return 1;
}

void imprimeDeque(Deque *dq)
{
    int i = dq->inicio;
    for (int n = 0; n <dq->qtd; n++)
    {
        printf("%d\n", dq->itens[i].chave);
        i = (i + 1) % MAXTAM;
    }
}

void liberaDeque(Deque *dq)
{
    free(dq);
}


