#ifndef ARVORELLRB_H_INCLUDED
#define ARVORELLRB_H_INCLUDED

#define RED 1
#define BLACK 0

typedef struct item Item;
typedef struct no_arvore No_Arvore;
typedef struct arvLLRB ArvLLRB;

// Cria um item com nome e pontua��o
Item *criaItem(char nome[], int pontuacao);
// Libera um item
void liberaItem(Item *item);
// Cria uma �rvore LLRB vazia
ArvLLRB *cria_ArvLLRB();
// Libera a �rvore LLRB
void libera_ArvLLRB(ArvLLRB *raiz);
// Insere uma equipe na �rvore
int insere_ArvLLRB(ArvLLRB *raiz, Item *item);
// Remove uma equipe por nome
int remove_ArvLLRB(ArvLLRB *raiz, char nome[]);
// Consulta uma equipe por nome
int consulta_ArvLLRB(ArvLLRB *raiz, char nome[]);
// Atualiza a pontua��o de uma equipe
int atualizaPontuacao(ArvLLRB *raiz, char nome[], char resultado);
// Verifica se a �rvore est� vazia
int estaVazia_ArvLLRB(ArvLLRB *raiz);
// Conta o total de n�s
int totalNO_ArvLLRB(ArvLLRB *raiz);
// Calcula a altura da �rvore
int altura_ArvLLRB(ArvLLRB *raiz);
// Percurso em-ordem
void emOrdem_ArvLLRB(ArvLLRB *raiz, int H, char pai[]);

#endif // ARVORELLRB_H_INCLUDED
