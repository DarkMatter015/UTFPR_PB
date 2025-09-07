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
    //cria nova célula que vai guardar o item
    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    //inserção no início: a próxima célula é aquela que era a primeira
    nova->prox = lst->primeira;
    //a primeira agora é a nova célula
    lst->primeira = nova;
}

void insereFimLista(Lista *lst, int chave) {
    //criar novo item que vai ser guardado na lista
    Item novo;
    novo.chave = chave;
    //...demais campos que possam existir na struct item
    //cria nova célula que vai guardar o item
    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    //inserção no fim
    nova->prox = NULL; //a nova célula vai ser a última, então aponta para NULL
    if (verificaListaVazia(lst))
    {  //se a lista está vazia, primeira aponta para a nova célula
        lst->primeira = nova;
    }
    else
    {  //se não está vazia, quem vai apontar para a nova é a que era a última
        Celula *ultima;
        ultima = lst->primeira; //partindo da primeira célula, chega na última
        while (ultima->prox != NULL)
        {
            ultima = ultima->prox;
        }
        ultima->prox = nova; //após a última, inserir a nova célula
    }
}

//Retorna a célula do item com a chave buscada ou NULL se não encontrou
Celula * buscaPorChave(Lista *lst, int chave) {
    Celula *aux = lst->primeira;
    while (aux != NULL && aux->item.chave != chave)
    {
        aux = aux->prox;
    }
    return aux;
}

//insere uma célula com a chave repassada na lista lst,
//após a célula com chave x
void insereMeioLista(Lista *lst, int chave, int x) {
    Celula *aux = buscaPorChave(lst, x); //verifica se a chave x existe
    if (aux != NULL)
    {
        //criar novo item que vai ser guardado na lista
        Item novo;
        novo.chave = chave;
        //cria nova célula que vai guardar o item
        Celula *nova = malloc(sizeof(Celula));
        nova->item = novo;
        //inserção no meio, após a chave x representada por aux
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

//remove da lista a célula que contem a chave x
void removeItem(Lista *lst, int x) {
    Celula *aux = lst->primeira;
    Celula *anterior;
    while (aux != NULL && aux->item.chave != x) //procura chave x
    {
        anterior = aux; //guarda a célula anterior
        aux = aux->prox;
    }
    if (aux == NULL)
    {
        printf("Item nao encontrado. \n");
        return;
    }
    if (aux == lst->primeira) //remove do início
    {
        lst->primeira = aux->prox;
    }
    else //remove do meio ou fim
    {
        anterior->prox = aux->prox;
    }
    //após ajustar os ponteiros, libera da memória a célula que continha x
    free(aux);
}

void liberaLista(Lista *lst) {
    Celula *aux = lst->primeira;
    Celula *liberar;
    while (aux != NULL)
    {
        liberar = aux;
        aux = aux->prox;
        free(liberar); //libera uma a uma as células da lista
    }
    free(lst); //libera a lista
}

int verificaListaOrdenada(Lista *lst) {
    // Se a lista está vazia ou tem apenas um elemento, ela está ordenada
    if (lst->primeira == NULL || lst->primeira->prox == NULL) {
        return 1; // Lista vazia ou com um único elemento é considerada ordenada
    }

    Celula *aux = lst->primeira;
    while (aux->prox != NULL) {
        // Se a chave atual for maior que a próxima, a lista não está ordenada
        if (aux->item.chave > aux->prox->item.chave) {
            return 0; // Não ordenada
        }
        aux = aux->prox;
    }
    return 1; // Ordenada
}
