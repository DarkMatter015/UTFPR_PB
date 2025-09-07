#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct item Item;
typedef struct celula Celula;
typedef struct lista Lista;

Lista * criaListaVazia();
int verificaListaVazia(Lista *lst);
void insereFimLista(Lista *lst, int chave);
void imprimeLista(Lista *lst);
void liberaLista(Lista *lst);
void insereOrdenado(Lista *lst1, Lista *lst2);

#endif // LISTA_H_INCLUDED
