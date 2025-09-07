#ifndef ITEMDEQUEENC_H_INCLUDED
#define ITEMDEQUEENC_H_INCLUDED

typedef struct item Item;
typedef struct celula Celula;
typedef struct deque Deque;

Deque* cria_Deque();
void libera_Deque(Deque* dq);
int verificaDequeVazia(Deque* dq);
int insereFinal_Deque(Deque* dq, int id, char* descricao, char* categoria, int ano, char* situacao);
int insereInicio_Deque(Deque* dq, int id, char* descricao, char* categoria, int ano, char* situacao);
void removeInicio_Deque(Deque* dq);
void removeFinal_Deque(Deque* dq);
void imprime_Deque(Deque* dq);
Item* busca_Deque(Deque* dq, int id);
void copiaRealizadas_Deque(Deque* origem, Deque* destino);
int removePorID_Deque(Deque* dq, int id);
void imprimeItem_Deque(Item* item);

#endif // ITEMDEQUEENC_H_INCLUDED
