#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "itemListaDuplEnc.h"

struct item {
    int chave;
};

struct celula {
    Item item;
    Celula *ant; //A c�lula tamb�m guarda quem � a sua anterior
    Celula *prox;
};

struct listaDupl {
    Celula *primeira;
};

//Cria uma lista vazia
ListaDupl *criaListaDuplVazia() {
    ListaDupl *ld = malloc(sizeof(ListaDupl));
    ld->primeira = NULL;
    return ld;
}

//adiciona um elment no in�cio da lista
void inserirInicio(ListaDupl *ld, int chave)
{
    //criar novo item que vai ser guardado na fila
    Item novo;
    novo.chave = chave;
    //cria nova c�lula que vai guardar o item
    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    nova->ant = NULL;
    nova->prox = ld->primeira;
    //se a lista n�o est� vazia, a anterior da que era a primeira ser� a nova
    if (!verificaListaDuplVazia(ld)) //se est� vazia adiciona no in�cio
    {
        ld->primeira->ant = nova;
    }
    ld->primeira = nova;
}

//adiciona um elemento no meio da listaDupl
void inserirMeio(ListaDupl *ld, int chaveB, int chaveI)
{
    Celula *anterior = buscaChave(ld, chaveB);
    if (anterior == NULL)
    {
        printf("Chave nao encontrada ou lista vazia.\n");
        return;
    }
    //criar novo item que vai ser guardado na fila
    Item novo;
    novo.chave = chaveI;
    Celula *proxima = anterior->prox;
    //cria nova c�lula que vai guardar o item
    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    nova->ant = anterior;
    nova->prox = proxima;
    anterior->prox = nova;
    if (proxima != NULL) //somente caso pr�xima n�o seja NULL, pois a NULL n�o tem anterior
    {
        proxima->ant = nova;
    }
}

//adiciona um elemento no final da lista
void inserirFinal(ListaDupl *ld, int chave)
{
    if (verificaListaDuplVazia(ld))
    {
        inserirInicio(ld, chave);
    }
    else
    {
        //criar noov item que vai ser guardado na fila
        Item novo;
        novo.chave = chave;
        //cria nova c�lula que vai guardar o item
        Celula *nova = malloc(sizeof(Celula));
        nova->item = novo;
        nova->prox = NULL;
        Celula *ultima = ld->primeira;
        while (ultima->prox != NULL)
        {
            ultima = ultima->prox;
        }
        nova->ant = ultima;
        ultima->prox = nova;
    }
}

//Busca por chave na lista
Celula *buscaChave(ListaDupl *ld, int chave)
{
    Celula *aux = ld->primeira;
    while (aux != NULL && aux->item.chave != chave)
    {
        aux = aux->prox;
    }
    return aux;
}

//imprime a Lista Duplamente Encadeada da equerda para direita
void imprimeEsqDir(ListaDupl *ld)
{
    Celula *aux = ld->primeira;
    while (aux != NULL)
    {
        printf("\nChave: %d ", aux->item.chave);
        aux = aux->prox;
    }
}

//imprime a Lista Duplamente Encadeada da direita para esquerda
void imprimeDirEsq(ListaDupl *ld)
{
    //ir at� a �ltima c�lula
    Celula *aux = ld->primeira;
    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }
    while (aux != NULL)
    {
         printf("\nChave: %d ", aux->item.chave);
         aux = aux->ant;
    }
}

//remove um item da lista duplamente encadeada
void removePorChave(ListaDupl *ld, int chave)
{
    Celula *remover = buscaChave(ld, chave);
    if (remover == NULL)
    {
        printf("Item nao encontrado ou lista vazia.\n");
        return;
    }
    if (remover->ant == NULL && remover->prox == NULL) //� a �nica, ou seja, a primeira
    {
        ld->primeira = NULL;
    }
    else if (remover == ld->primeira) //remover do in�cio
    {
        ld->primeira = remover->prox;
        ld->primeira->ant = NULL;
    }
    else //remover do meio
    {
        Celula *proxima = remover->prox;
        Celula *anterior = remover->ant;
        anterior->prox = proxima;
        if (proxima != NULL)
        {
            proxima->ant = anterior;
        }
    }
    free(remover);
}

//retorna 1 se a lista est� vazia ou 0 se n�o est� vazia
int verificaListaDuplVazia(ListaDupl *ld)
{
    return ld->primeira == NULL;
}

//libera da mem�ria
void liberaListaDupl(ListaDupl *ld)
{
    Celula *aux = ld->primeira;
    Celula *liberar;
    while (aux != NULL)
    {
        liberar = aux;
        aux = aux->prox;
        free(liberar);
    }
    free(ld);
}


void trocaCelulas(ListaDupl *ld, int chave1, int chave2) {
    // Verifica se a lista � nula ou vazia
    if (ld == NULL || verificaListaDuplVazia(ld)) {
        printf("Lista vazia ou inv�lida.\n");
        return;
    }

    // Verifica se as chaves s�o iguais
    if (chave1 == chave2) {
        printf("As chaves s�o iguais, nenhuma troca necess�ria.\n");
        return;
    }

    // Busca as c�lulas correspondentes �s chaves
    Celula *cel1 = buscaChave(ld, chave1);
    Celula *cel2 = buscaChave(ld, chave2);

    // Verifica se ambas as chaves foram encontradas
    if (cel1 == NULL || cel2 == NULL) {
        printf("Uma ou ambas as chaves n�o foram encontradas.\n");
        return;
    }

    // Verifica se as c�lulas s�o adjacentes
    int adjacentes = (cel1->prox == cel2 || cel2->prox == cel1);

    // Ajusta ponteiros das c�lulas adjacentes ou n�o
    // Atualiza o ponteiro 'ant' da c�lula seguinte � cel1
    if (cel1->prox != NULL && cel1->prox != cel2) {
        cel1->prox->ant = cel2;
    }
    // Atualiza o ponteiro 'ant' da c�lula seguinte � cel2
    if (cel2->prox != NULL && cel2->prox != cel1) {
        cel2->prox->ant = cel1;
    }

    // Atualiza o ponteiro 'prox' da c�lula anterior � cel1
    if (cel1->ant != NULL && cel1->ant != cel2) {
        cel1->ant->prox = cel2;
    }
    // Atualiza o ponteiro 'prox' da c�lula anterior � cel2
    if (cel2->ant != NULL && cel2->ant != cel1) {
        cel2->ant->prox = cel1;
    }

    // Troca os ponteiros 'prox' e 'ant' das c�lulas
    Celula *temp_ant = cel1->ant;
    Celula *temp_prox = cel1->prox;
    cel1->ant = cel2->ant;
    cel1->prox = cel2->prox;
    cel2->ant = temp_ant;
    cel2->prox = temp_prox;

    // Ajusta se as c�lulas s�o adjacentes
    if (adjacentes) {
        if (cel1->prox == cel2) {
            cel1->ant = cel2;
            cel2->prox = cel1;
        } else {
            cel2->ant = cel1;
            cel1->prox = cel2;
        }
    }

    // Atualiza o in�cio da lista, se necess�rio
    if (ld->primeira == cel1) {
        ld->primeira = cel2;
    } else if (ld->primeira == cel2) {
        ld->primeira = cel1;
    }
}

void inserirOrdenado(ListaDupl *ld, int chave) {
    // Verifica se a lista � nula
    if (ld == NULL) {
        printf("Lista inv�lida.\n");
        return;
    }

    // Se a lista est� vazia ou a chave � menor que a primeira, insere no in�cio
    if (verificaListaDuplVazia(ld) || chave < ld->primeira->item.chave) {
        inserirInicio(ld, chave);
        return;
    }

    // Cria o novo item
    Item novo;
    novo.chave = chave;
    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;

    // Percorre a lista para encontrar a posi��o de inser��o
    Celula *atual = ld->primeira;
    while (atual != NULL && atual->item.chave < chave) {
        atual = atual->prox;
    }

    // Insere no final se atual for NULL
    if (atual == NULL) {
        inserirFinal(ld, chave);
        free(nova); // Libera a c�lula alocada, pois inserirFinal j� aloca
        return;
    }

    // Insere antes de 'atual'
    nova->prox = atual;
    nova->ant = atual->ant;
    atual->ant = nova;
    if (nova->ant != NULL) {
        nova->ant->prox = nova;
    } else {
        ld->primeira = nova; // Caso a inser��o seja no in�cio (mas n�o vazia)
    }
}

void inverterLista(ListaDupl *ld) {
    // Verifica se a lista � nula ou vazia
    if (ld == NULL || verificaListaDuplVazia(ld)) {
        printf("Lista vazia ou inv�lida.\n");
        return;
    }

    Celula *atual = ld->primeira;
    Celula *temp = NULL;

    // Troca os ponteiros ant e prox de cada c�lula
    while (atual != NULL) {
        // Armazena o ponteiro ant temporariamente
        temp = atual->ant;
        // Troca ant por prox
        atual->ant = atual->prox;
        atual->prox = temp;
        // Avan�a para a pr�xima c�lula (que agora � apontada por ant)
        atual = atual->ant;
    }

    // Atualiza o ponteiro primeira para apontar para a �ltima c�lula original
    ld->primeira = temp->ant;
}
