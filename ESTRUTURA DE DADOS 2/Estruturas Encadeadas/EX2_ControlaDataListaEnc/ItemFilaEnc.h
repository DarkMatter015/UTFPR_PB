#ifndef ITEMFILAENC_H_INCLUDED
#define ITEMFILAENC_H_INCLUDED

#include "Data.h"

typedef struct item Item;
typedef struct celula Celula;
typedef struct fila Fila;

Fila* criaFilaVazia();
int verificaFilaVazia(Fila* f);
int insereFila(Fila* f, int id, char* nome, Data* dataEvento, char* hora, char* descricao);
void removeInicioFila(Fila* f);
void imprimeFila(Fila* f);
void liberaFila(Fila* f);
void imprimeItemFila(Item* item);

#endif // ITEMFILAENC_H_INCLUDED
