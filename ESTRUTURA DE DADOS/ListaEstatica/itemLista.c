#include <stdio.h>
#include <stdlib.h>
#include "itemLista.h"

struct item{
    int chave;
};

struct lista{
    Item vetItens[MAXTAN];
    int ultimo;
};

Lista *criaListaVazia(){
    Lista *lst = (Lista *) malloc(sizeof(Lista));
    lst -> ultimo = -1;
    return lst;
}

// retorna 1 se lista esta cheia e 0 se nao
int verificaListaCheia(Lista *list){
    return list -> ultimo == (MAXTAN - 1);
}

// adiciona elemento no fim da lista
void adicionaItemFimLista(Lista *list, int chave){
    if (verificaListaCheia(list)){
        printf("ERRO: Lista esta cheia.\n");
        return;
    }
    Item novoItem;
    novoItem.chave = chave;
    list -> ultimo++;
    list -> vetItens[list -> ultimo] = novoItem;
}


void imprimeLista(Lista *list){
    for(int i = 0; i <= (list -> ultimo); i++){
        printf("Chave: %d\n", list -> vetItens[i].chave);
    }
}

// retorna o indice de item com a chave buscada ou -1 se nao encontra
int buscaItemPorChave(Lista *list, int chave){
    int i = 0;
    while((i <= list -> ultimo) && (list -> vetItens[i].chave != chave)){
        i++;
    }
    if(i <= list -> ultimo){
        return i;
    }
    else{
        return -1;
    }
}

// remove um item qualquer da lista
void removeItem(Lista *list, int chave){
    int posicao = buscaItemPorChave(list, chave);
    if(posicao == -1){
        printf("ERRO: a lista esta vazia ou o item nao existe.\n");
        return;
    }
    // reorganiza itens no vetor
    for (int i = posicao; i < list -> ultimo; i++){
        list -> vetItens[i] = list -> vetItens[i+1];
    }
    list -> ultimo--;
}

// verifica se lista esta vazia 1 ou 0 se nao
int verificaListaVazia(Lista *list){
    return list -> ultimo == -1;
}

void liberaLista(Lista *list){
    free(list);
}
