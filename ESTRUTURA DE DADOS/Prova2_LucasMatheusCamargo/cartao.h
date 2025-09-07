#ifndef CARTAO_H_INCLUDED
#define CARTAO_H_INCLUDED

#define MAXTAM 5

typedef struct lucasSicoob LucasSicoob;
typedef struct fila Fila;

Fila *criaFilaVazia();
int verificaFilaCheia(Fila *f);
void enfileira(Fila *f, int dia, int mes, int ano, float valor, char descricao[], int tipoPagamento);
void desenfileira(Fila *f);
int verificaFilaVazia(Fila *f);
void liberaFila(Fila *f);
void imprimeFila(Fila *f);


#endif // CARTAO_H_INCLUDED
