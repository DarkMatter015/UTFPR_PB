#include <stdio.h>
#include <stdlib.h>
#include "itemListaEnc.h"

struct item {
    int chave;
    //demais campos
};

struct celula {
    Item item;
    Celula *prox;
};

struct lista {
    Celula *primeira;
};

Lista * criaListaVazia() {
    Lista *lst = malloc(sizeof(Lista));
    lst->primeira = NULL;
    return lst;
}

int verificaListaVazia(Lista *lst) {
    return (lst->primeira == NULL);
}

void insereInicioLista(Lista *lst, int chave) {
    //criar novo item que vai ser guardado na lista
    Item novo;
    novo.chave = chave;
    //...demais campos que possam existir na struct item
    //cria nova c�lula que vai guardar o item
    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    //inser��o no in�cio: a pr�xima c�lula � aquela que era a primeira
    nova->prox = lst->primeira;
    //a primeira agora � a nova c�lula
    lst->primeira = nova;
}

void insereFimLista(Lista *lst, int chave) {
    //criar novo item que vai ser guardado na lista
    Item novo;
    novo.chave = chave;
    //...demais campos que possam existir na struct item
    //cria nova c�lula que vai guardar o item
    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    //inser��o no fim
    nova->prox = NULL; //a nova c�lula vai ser a �ltima, ent�o aponta para NULL
    if (verificaListaVazia(lst))
    {  //se a lista est� vazia, primeira aponta para a nova c�lula
        lst->primeira = nova;
    }
    else
    {  //se n�o est� vazia, quem vai apontar para a nova � a que era a �ltima
        Celula *ultima;
        ultima = lst->primeira; //partindo da primeira c�lula, chega na �ltima
        while (ultima->prox != NULL)
        {
            ultima = ultima->prox;
        }
        ultima->prox = nova; //ap�s a �ltima, inserir a nova c�lula
    }
}

//Retorna a c�lula do item com a chave buscada ou NULL se n�o encontrou
Celula * buscaPorChave(Lista *lst, int chave) {
    Celula *aux = lst->primeira;
    while (aux != NULL && aux->item.chave != chave)
    {
        aux = aux->prox;
    }
    return aux;
}

//insere uma c�lula com a chave repassada na lista lst,
//ap�s a c�lula com chave x
void insereMeioLista(Lista *lst, int chave, int x) {
    Celula *aux = buscaPorChave(lst, x); //verifica se a chave x existe
    if (aux != NULL)
    {
        //criar novo item que vai ser guardado na lista
        Item novo;
        novo.chave = chave;
        //cria nova c�lula que vai guardar o item
        Celula *nova = malloc(sizeof(Celula));
        nova->item = novo;
        //inser��o no meio, ap�s a chave x representada por aux
        nova->prox = aux->prox;
        aux->prox = nova;
    }
    else
    {
        printf("O item informado nao existe.\n");
    }
}

void imprimeLista(Lista *lst) {
    Celula *aux;
    for (aux = lst->primeira; aux != NULL; aux = aux->prox)
    {
        printf("Chave: %d\n", aux->item.chave);
        //demais campos
    }
}

//remove da lista a c�lula que contem a chave x
void removeItem(Lista *lst, int x) {
    Celula *aux = lst->primeira;
    Celula *anterior;
    while (aux != NULL && aux->item.chave != x) //procura chave x
    {
        anterior = aux; //guarda a c�lula anterior
        aux = aux->prox;
    }
    if (aux == NULL)
    {
        printf("Item nao encontrado. \n");
        return;
    }
    if (aux == lst->primeira) //remove do in�cio
    {
        lst->primeira = aux->prox;
    }
    else //remove do meio ou fim
    {
        anterior->prox = aux->prox;
    }
    //ap�s ajustar os ponteiros, libera da mem�ria a c�lula que continha x
    free(aux);
}

void liberaLista(Lista *lst) {
    Celula *aux = lst->primeira;
    Celula *liberar;
    while (aux != NULL)
    {
        liberar = aux;
        aux = aux->prox;
        free(liberar); //libera uma a uma as c�lulas da lista
    }
    free(lst); //libera a lista
}

int verificaListaOrdenada(Lista *lst) {
    // Se a lista est� vazia ou tem apenas um elemento, ela est� ordenada
    if (lst->primeira == NULL || lst->primeira->prox == NULL) {
        return 1; // Lista vazia ou com um �nico elemento � considerada ordenada
    }

    Celula *aux = lst->primeira;
    while (aux->prox != NULL) {
        // Se a chave atual for maior que a pr�xima, a lista n�o est� ordenada
        if (aux->item.chave > aux->prox->item.chave) {
            return 0; // N�o ordenada
        }
        aux = aux->prox;
    }
    return 1; // Ordenada
}
