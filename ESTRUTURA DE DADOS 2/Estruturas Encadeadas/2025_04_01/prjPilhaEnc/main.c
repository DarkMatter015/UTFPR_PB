#include <stdio.h>
#include <stdlib.h>
#include "itemPilhaEnc.h"

int main()
{
    Pilha *p;
    int vazia, chave;
    printf("Criando pilha encadeada vazia.\n");
    p = criaPilhaVazia();

    vazia = verificaPilhaVazia(p);
    printf("Pilha vazia? %d", vazia);

    printf("\nAdicionando 1o item");
    chave = 1;
    empilha(p, chave);

    vazia = verificaPilhaVazia(p);
    printf("\nPilha vazia? %d", vazia);

    printf("\nAdicionando 2o item");
    chave = 2;
    empilha(p, chave);

    printf("\nAdicionando 3o item");
    chave = 3;
    empilha(p, chave);

    printf("\nAdicionando 4o item");
    chave = 4;
    empilha(p, chave);

    printf("\nAdicionando 5o item");
    chave = 5;
    empilha(p, chave);

    printf("\nAdicionando 6o item");
    chave = 6;
    empilha(p, chave);

    printf("\nItens da pilha:\n");
    imprimePilha(p);

    printf("\nRemovendo item do topo da pilha");
    desempilha(p);

    printf("\nItens da pilha:\n");
    imprimePilha(p);

    printf("\nRemovendo item do topo da pilha");
    desempilha(p);

    printf("\nItens da pilha:\n");
    imprimePilha(p);

    liberaPilha(p);

    return 0;
}
