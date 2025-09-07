#ifndef ITEMDEQUE_H_INCLUDED
#define ITEMDEQUE_H_INCLUDED

#define MAXTAM 5

typedef struct item Item;
typedef struct deque Deque;

Deque *criaDeque();
int dequeCheia(Deque *dq);
int dequeVazia(Deque *dq);
int insereFinalDeque(Deque *dq, int chave);
int insereInicioDeque(Deque *dq, int chave);
int removeInicioDeque(Deque *dq);
int removeFinalDeque(Deque *dq);
void imprimeDeque(Deque *dq);
void liberaDeque(Deque *dq);


#endif // ITEMDEQUE_H_INCLUDED
