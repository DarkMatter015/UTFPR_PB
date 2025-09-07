#ifndef ITEMLISTA_H_INCLUDED
#define ITEMLISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define MAXTAN 5

typedef struct item Item;

typedef struct lista Lista;

Lista *criaListaVazia();
int verificaListaCheia(Lista *list);
void adicionaItemFimLista(Lista *list, int chave);
void imprimeLista(Lista *list);
int buscaItemPorChave(Lista *list, int chave);
void removeItem(Lista *list, int chave);
int verificaListaVazia(Lista *list);
void liberaLista(Lista *list);



#endif // ITEMLISTA_H_INCLUDED
