#ifndef SLA_H_INCLUDED
#define SLA_H_INCLUDED

#define MAXTAM 5

typedef struct item Item;
typedef struct fila Fila;
typedef struct pilha Pilha;

// FILA


Fila *criaFilaVazia();
int verificaFilaCheia(Fila *f);
void enfileira(Fila *f, char chave);
void desenfileira(Fila *f);
int verificaFilaVazia(Fila *f);
void liberaFila(Fila *f);
void imprimeFila(Fila *f);


// pilha
Pilha *criaPilhaVazia();
int verificaPilhaCheia(Pilha *p);
void empilha(Pilha *p, char chave);
void desempilha(Pilha *p);
void imprimePilha(Pilha *p);
int verificaPilhaVazia(Pilha *p);
void liberaPilha(Pilha *p);

#endif // SLA_H_INCLUDED
