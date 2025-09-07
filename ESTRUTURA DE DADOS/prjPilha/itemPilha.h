#ifndef ITEMPILHA_H_INCLUDED
#define ITEMPILHA_H_INCLUDED

#define MAXTAM 5

typedef struct item Item;
typedef struct pilha Pilha;

Pilha *criaPilhaVazia();
int verificaPilhaCheia(Pilha *p);
void empilha(Pilha *p, int chave);
void desempilha(Pilha *p);
void imprimePilha(Pilha *p);
int verificaPilhaVazia(Pilha *p);
void liberaPilha(Pilha *p);

#endif // ITEMPILHA_H_INCLUDED
