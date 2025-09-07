#include <stdio.h>
#include <stdlib.h>
#include "itemLista.h"

struct item {
    int chave;
    //demais campos
};

struct lista {
    Item vetItens[MAXTAM];
    int ultimo;
};

Lista *criaListaVazia() {
    Lista *lst = (Lista *) malloc(sizeof(Lista));
    lst->ultimo = -1;
    return lst;
}

//retorna 1 se a lista está cheia e 0 se não
int verificaListaCheia(Lista *lst) {
    return lst->ultimo == (MAXTAM - 1);
}

//adiciona um elemento no fim da lista
void adicionaItemFimLista(Lista *lst, int chave) {
    if (verificaListaCheia(lst))
    {
        printf("Erro: a lista esta cheia.\n");
        return;
    }
    Item novoItem;
    novoItem.chave = chave;
    //demais campos
    lst->ultimo++;
    lst->vetItens[lst->ultimo] = novoItem;
}

void imprimeLista(Lista *lst) {
    for (int i = 0; i <= lst->ultimo; i++)
    {
        printf("Chave: %d\n", lst->vetItens[i].chave);
    }
}

//retorna o índice do item com a chave buscada ou -1 se encontrou
int buscaItemPorChave(Lista *lst, int chave) {
    int i = 0;
    while ((i <= lst->ultimo) && (lst->vetItens[i].chave != chave))
    {
        i++;
    }
    if (i <= lst->ultimo)
    {
        return i;
    }
    else
    {
        return -1;
    }
}

//remove um item qualquer da lista
void removeItem(Lista *lst, int chave) {
    int posicao = buscaItemPorChave(lst, chave);
    if (posicao == -1)
    {
        printf("Erro: a lista esta vazia ou o item nao existe.\n");
        return;
    }
    for (int i = posicao; i < lst->ultimo; i++)
    {
        lst->vetItens[i] = lst->vetItens[i+1];
    }
    lst->ultimo--;
}

//retorna 1 se a lista esta vazia ou 0 se não
int verificaListaVazia(Lista * lst) {
    return lst->ultimo == -1;
}

void liberaLista(Lista *lst) {
    free(lst);
}
