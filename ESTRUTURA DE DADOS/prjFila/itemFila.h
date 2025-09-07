#ifndef ITEMFILA_H_INCLUDED
#define ITEMFILA_H_INCLUDED

#define MAXTAM 5

typedef struct item Item;
typedef struct fila Fila;

Fila *criaFilaVazia();
int verificaFilaCheia(Fila *f);
void enfileira(Fila *f, int chave);
void desenfileira(Fila *f);
int verificaFilaVazia(Fila *f);
void liberaFila(Fila *f);
void imprimeFila(Fila *f);

#endif // ITEMFILA_H_INCLUDED
