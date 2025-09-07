#include <stdio.h>
#include <stdlib.h>
#include "itemLista.h"

int main()
{
    Lista *lista;
    int vazia, cheia, chave;

    printf("Criando lista vazia\n");
    lista = criaListaVazia();

    vazia = verificaListaVazia(lista);
    printf("Lista vazia? %d\n", vazia);

    cheia = verificaListaCheia(lista);
    printf("Lista cheia? %d\n", cheia);

    printf("\nAdicionando o 1o item.\n");
    chave = 1;
    adicionaItemFimLista(lista, chave);

    printf("\nAdicionando o 2o item.\n");
    chave = 2;
    adicionaItemFimLista(lista, chave);

    printf("\nAdicionando o 3o item.\n");
    chave = 3;
    adicionaItemFimLista(lista, chave);

    printf("\nAdicionando o 4o item.\n");
    chave = 4;
    adicionaItemFimLista(lista, chave);

    printf("\nAdicionando o 5o item.\n");
    chave = 5;
    adicionaItemFimLista(lista, chave);

    printf("\nTentando adicionar o 6o item.\n");
    chave = 6;
    adicionaItemFimLista(lista, chave);

    printf("\nItens da lista: \n");
    imprimeLista(lista);

    printf("\nBuscando posicao do item a partir da chave: \n");
    printf("Posicao do item com chave = 3: %d\n", buscaItemPorChave(lista, 3));

    printf("\nTentando remover item com chave = 6: \n");
    removeItem(lista, 6);
    imprimeLista(lista);

    printf("\nTentando remover item com chave = 3: \n");
    removeItem(lista, 3);
    imprimeLista(lista);
    liberaLista(lista);

    return 0;
}
