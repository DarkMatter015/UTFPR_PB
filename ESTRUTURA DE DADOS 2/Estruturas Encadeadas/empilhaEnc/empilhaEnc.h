#ifndef EMPILHAENC_H_INCLUDED
#define EMPILHAENC_H_INCLUDED

typedef struct item Item;

typedef struct celula Celula;

typedef struct pilha Pilha;

Pilha * criaPilhaVazia();

void empilha(Pilha *p, int chave);

void imprimePilha(Pilha *p);

int verificaPilhaVazia(Pilha *p);

void desempilha(Pilha *p);

void liberaPilha(Pilha *p);


#endif // EMPILHAENC_H_INCLUDED
