#ifndef ITEMDEQUE_H_INCLUDED
#define ITEMDEQUE_H_INCLUDED


typedef struct lucasEventoLive LucasEventoLive;
typedef struct celula Celula;
typedef struct deque Deque;

Deque* cria_Deque();
int verificaDequeVazia(Deque* dq);
void insereFinal_Deque(Deque* dq, int chave, char data_transmissao[], char titulo[], char apresentador[], int duracao, int plataforma_transmissao);
void insereInicio_Deque(Deque* dq, int chave, char data_transmissao[], char titulo[], char apresentador[], int duracao, int plataforma_transmissao);
void removeInicio_Deque(Deque* dq);
int removeFinal_Deque(Deque* dq);
void imprime_Deque(Deque* dq);
void contabilizaLives(Deque* dq);
LucasEventoLive* busca_Deque(Deque* dq, int chave);
void imprimeLive_Deque(LucasEventoLive* live);
void libera_Deque(Deque* dq);


#endif // ITEMDEQUE_H_INCLUDED
