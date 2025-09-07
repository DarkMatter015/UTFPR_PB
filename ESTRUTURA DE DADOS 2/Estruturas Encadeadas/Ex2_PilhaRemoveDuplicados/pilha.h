#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct item Item;
typedef struct celula Celula;
typedef struct pilha Pilha;

Pilha * criaPilhaVazia();
void empilha(Pilha *p, int chave);
void imprimePilha(Pilha *p);
int verificaPilhaVazia(Pilha *p);
int desempilha(Pilha *p); // Retorna a chave desempilhada
void liberaPilha(Pilha *p);
void removeDuplicados(Pilha *p);

#endif // PILHA_H_INCLUDED
