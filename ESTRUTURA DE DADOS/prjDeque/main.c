#include <stdio.h>
#include <stdlib.h>
#include "itemDeque.h"

int main()
{
    Deque *dq;

    int vazia, cheia, chave;

    printf("Criando deque vazia.\n");
    dq = criaDeque();

    vazia = dequeVazia(dq);
    printf("Deque vazia? %d\n", vazia);

    cheia = dequeCheia(dq);
    printf("Deque cheia? %d\n", cheia);

    printf("\nAdicionando o 1o item (2) no inicio.\n");
    chave = 2;
    insereInicioDeque(dq, chave);
    vazia = dequeVazia(dq);
    printf("Deque vazia? %d\n", vazia);

    printf("\nAdicionando o 2o item (11) no fim.\n");
    chave = 11;
    insereFinalDeque(dq, chave);

    printf("\nAdicionando o 3o item (8) no inicio.\n");
    chave = 8;
    insereInicioDeque(dq, chave);

    printf("\nAdicionando o 4o item (33) no fim.\n");
    chave = 33;
    insereFinalDeque(dq, chave);

    printf("\nAdicionando o 5o item (5) no inicio.\n");
    chave = 5;
    insereInicioDeque(dq, chave);

    printf("\nAdicionando o 6o item (6) no fim.\n");
    chave = 6;
    insereFinalDeque(dq, chave);

    printf("\nItens da deque: \n");
    imprimeDeque(dq);

    printf("\nRemovendo item do final.\n");
    removeFinalDeque(dq);
    imprimeDeque(dq);

    printf("\nRemovendo item do inicio.\n");
    removeInicioDeque(dq);
    imprimeDeque(dq);

    liberaDeque(dq);
    return 0;
}
