#include <stdio.h>
#include <stdlib.h>
#include "itemListaDuplEnc.h"

int main()
{
    ListaDupl *ld;
    int vazia, cheia, chave;

    printf("Criando lista duplamente encadeada vazia.\n");
    ld = criaListaDuplVazia();

    vazia = verificaListaDuplVazia(ld);
    printf("Lista vazia? %d\n", vazia);

    printf("\nAdicionando itens em ordem: 6, 5, 1, 3, 2, 4.\n");
    chave = 6;
    inserirOrdenado(ld, chave);
    chave = 5;
    inserirOrdenado(ld, chave);
    chave = 1;
    inserirOrdenado(ld, chave);
    chave = 3;
    inserirOrdenado(ld, chave);
    chave = 2;
    inserirOrdenado(ld, chave);
    chave = 4;
    inserirOrdenado(ld, chave);

    printf("\nItens da lista (Esq para Dir):");
    imprimeEsqDir(ld);

    printf("\nInvertendo a lista.\n");
    inverterLista(ld);

    printf("\nItens da lista após inversão (Esq para Dir):");
    imprimeEsqDir(ld);

    printf("\nTrocando células com chaves 1 e 5.\n");
    trocaCelulas(ld, 1, 5);

    printf("\nItens da lista após troca (Esq para Dir):");
    imprimeEsqDir(ld);

    printf("\nRemovendo item com chave = 6.");
    removePorChave(ld, 6);

    printf("\nItens da lista (Esq para Dir):");
    imprimeEsqDir(ld);

    printf("\nRemovendo item com chave = 3.");
    removePorChave(ld, 3);

    printf("\nItens da lista (Dir para Esq):");
    imprimeDirEsq(ld);

    liberaListaDupl(ld);

    return 0;
}
