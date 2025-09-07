#include <stdio.h>
#include <stdlib.h>
#include "itemListaEnc.h"

int main()
{
    Lista *lst;
    int vazia, chave;

    printf("Criando lista vazia.\n");
    lst = criaListaVazia();

    vazia = verificaListaVazia(lst);
    printf("Lista vazia? %d.\n", vazia);

    printf("\nAdicionando o 1o item no inicio. \n");
    chave = 1;
    insereInicioLista(lst, chave);

    vazia = verificaListaVazia(lst);
    printf("Lista vazia? %d.\n", vazia);

    printf("\nAdicionando 2o item no fim.\n");
    chave = 2;
    insereFimLista(lst, chave);

    printf("\nAdicionando 3o item no meio depois do 1o.\n");
    chave = 3;
    insereMeioLista(lst, chave, 1);

    printf("\nAdicionando o 4o item no inicio. \n");
    chave = 4;
    insereInicioLista(lst, chave);

    printf("\nAdicionando 5o item no fim.\n");
    chave = 5;
    insereFimLista(lst, chave);

    printf("\nAdicionando o 6o item no meio depois do 4o. \n");
    chave = 6;
    insereMeioLista(lst, chave, 4);

    printf("\nItens da lista:\n");
    imprimeLista(lst);

    // Verificar se a lista está ordenada
    printf("\nLista ordenada? %d\n", verificaListaOrdenada(lst));

    printf("\nTentando remover item com chave = 6. \n");
    removeItem(lst, 6);

    printf("\nTentando remover item com chave = 11. \n");
    removeItem(lst, 11);

    printf("\nItens da lista após remoções:\n");
    imprimeLista(lst);

    // Verificar novamente se a lista está ordenada
    printf("\nLista ordenada após remoções? %d\n", verificaListaOrdenada(lst));

    liberaLista(lst);

    return 0;
}
