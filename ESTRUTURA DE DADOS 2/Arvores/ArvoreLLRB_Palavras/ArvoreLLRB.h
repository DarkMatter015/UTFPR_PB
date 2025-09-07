#define RED 1
#define BLACK 0

typedef struct no_arvore* ArvLLRB;

ArvLLRB* cria_ArvLLRB();
void libera_ArvLLRB(ArvLLRB* raiz);
int insere_ArvLLRB(ArvLLRB* raiz,char valor[]);
int remove_ArvLLRB(ArvLLRB *raiz, char valor[]);
int estaVazia_ArvLLRB(ArvLLRB *raiz);
int totalNO_ArvLLRB(ArvLLRB *raiz);
int altura_ArvLLRB(ArvLLRB *raiz);
int consulta_ArvLLRB(ArvLLRB *raiz, char valor[]);
void preOrdem_ArvLLRB(ArvLLRB *raiz, int H);
void emOrdem_ArvLLRB(ArvLLRB *raiz, int H, char pai[]);
void posOrdem_ArvLLRB(ArvLLRB *raiz, int H);
void nomesEmOrdem(ArvLLRB *raiz, int H, int pai);
