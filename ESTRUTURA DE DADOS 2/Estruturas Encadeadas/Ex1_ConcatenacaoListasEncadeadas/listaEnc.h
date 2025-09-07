#ifndef LISTAENC_H_INCLUDED
#define LISTAENC_H_INCLUDED

typedef struct item Item;
typedef struct celula Celula;
typedef struct lista Lista;

Lista * criaListaVazia();
int verificaListaVazia(Lista *lst);
void insereInicioLista(Lista *lst, int chave);
void insereFimLista(Lista *lst, int chave);
Celula * buscaPorChave(Lista *lst, int chave);
void insereMeioLista(Lista *lst, int chave, int x);
void imprimeLista(Lista *lst);
void removeItem(Lista *lst, int x);
void liberaLista(Lista *lst);
void concatenaListas(Lista *lst1, Lista *lst2);


#endif // LISTAENC_H_INCLUDED
