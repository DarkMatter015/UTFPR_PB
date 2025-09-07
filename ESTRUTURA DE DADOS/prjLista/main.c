#include <stdio.h>
#include <stdlib.h>
#include "itemLista.h"

int main()
{
    Lista *lst;
    int vazia, cheia, chave;

    printf("Criando lista vazia.\n");
    lst = criaListaVazia();

    vazia = verificaListaVazia(lst);
    printf("Lista vazia? %d\n", vazia);

    cheia = verificaListaCheia(lst);
    printf("Lista cheia? %d\n", cheia);

    printf("\nAdicionando o 1o item.\n");
    chave = 1;
    adicionaItemFimLista(lst, chave);

    vazia = verificaListaVazia(lst);
    printf("Lista vazia? %d\n", vazia);

    printf("\nAdicionando o 2o item.\n");
    chave = 2;
    adicionaItemFimLista(lst, chave);

    printf("\nAdicionando o 3o item.\n");
    chave = 3;
    adicionaItemFimLista(lst, chave);

    printf("\nAdicionando o 4o item.\n");
    chave = 4;
    adicionaItemFimLista(lst, chave);

    printf("\nAdicionando o 5o item.\n");
    chave = 5;
    adicionaItemFimLista(lst, chave);

    cheia = verificaListaCheia(lst);
    printf("Lista cheia? %d\n", cheia);

    printf("\nTentando adicionar o 6o item.\n");
    chave = 6;
    adicionaItemFimLista(lst, chave);

    printf("\nItens da lista: \n");
    imprimeLista(lst);

    printf("\nBuscando posicao do item a partir da chave:\n");
    printf("\nPosicao do item com chave = 3: %d\n",
           buscaItemPorChave(lst, 3));
    printf("\nPosicao do item com chave = 6: %d\n",
           buscaItemPorChave(lst, 6));

    printf("\nTentando remover item com chave = 6.\n");
    removeItem(lst, 6);
    imprimeLista(lst);

    printf("\nTentando remover item com chave = 3.\n");
    removeItem(lst, 3);
    imprimeLista(lst);
    liberaLista(lst);
    return 0;
}
