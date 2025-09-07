#ifndef DEQUENOTICIA_H_INCLUDED
#define DEQUENOTICIA_H_INCLUDED

typedef struct noticia NOTICIA;
typedef struct celula Celula;
typedef struct deque Deque;

Deque *cria_Deque();
int verificaDequeVazia(Deque *dq);
void insereInicio_Deque(Deque *dq, char *titulo, char *autor, char *classificacao, int id_noticia);
void insereFinal_Deque(Deque *dq, char *titulo, char *autor, char *classificacao, int id_noticia);
void removeInicio_Deque(Deque *dq);
void removeFinal_Deque(Deque *dq);
void imprime_Deque(Deque *dq);
void libera_Deque(Deque *dq);
void analisaClassificacoes(Deque *dq);

#endif // DEQUENOTICIA_H_INCLUDED
