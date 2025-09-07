#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED

typedef struct no_arvore* NoArvBin;

NoArvBin* cria_ArvBin();
void libera_NO(struct no_arvore* no);
void libera_ArvBin(NoArvBin* raiz);
int insere_ArvBin(NoArvBin* raiz, int valor, int maquinaAcertou);
void imprimeResultado(NoArvBin *raiz);
void imprimeMenu();

#endif // JOGO_H_INCLUDED
