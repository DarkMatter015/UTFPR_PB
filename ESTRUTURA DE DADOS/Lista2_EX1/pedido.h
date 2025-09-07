#ifndef PEDIDO_H_INCLUDED
#define PEDIDO_H_INCLUDED

#define MAXTAM 15

typedef struct pedido Pedido;
typedef struct deque Deque;

Deque *cria_deque();
int dequeCheia(Deque *dq);
int dequeVazia(Deque *dq);
int insereFinalDeque(Deque *dq, int id, char descricao[], float custo);
int insereInicioDeque(Deque *dq, int id, char descricao[], float custo);
int removeInicioDeque(Deque *dq);
int removeFinalDeque(Deque *dq);
void imprimeDeque(Deque *dq);
void liberaDeque(Deque *dq);


#endif // PEDIDO_H_INCLUDED
