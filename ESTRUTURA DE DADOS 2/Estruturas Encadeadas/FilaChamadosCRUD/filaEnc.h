#ifndef FILAENC_H_INCLUDED
#define FILAENC_H_INCLUDED

typedef struct lucas LUCAS;
typedef struct celula Celula;
typedef struct fila Fila;

Fila *criaFilaVazia();
int verificaFilaVazia(Fila *f);
void enfileira(Fila *f, char *nome, int ticket_id, char *problema);
void desenfileira(Fila *f);
void imprimeFila(Fila *f);
void liberaFila(Fila *f);

#endif // FILAENC_H_INCLUDED
