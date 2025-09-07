#include <stdio.h>
#include <stdlib.h>
#include "ArvoreLLRB.h"

struct no_arvore{
    char info[50];
    struct no_arvore *esq; //ponteiro para a subarvore da esquerda
    struct no_arvore *dir; //ponteiro para a subarvore da direita
    int cor; //constantes declaradas no arquivo .h, sendo RED = 1 e BLACK = 0
};


ArvLLRB* cria_ArvLLRB(){
    ArvLLRB* raiz = (ArvLLRB*) malloc(sizeof(ArvLLRB));
    if(raiz != NULL){
        *raiz = NULL;
    }
    return raiz;
}

//Fun��o recursiva que libera todos os n�s filhos a partir de um n� raiz
void libera_NO(struct no_arvore* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

//Libera a �rvore red-black ap�s liberar todos os n�s
void libera_ArvLLRB(ArvLLRB* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada n�
    free(raiz);//libera a raiz
}

//Retorna 1 se encontrou o valor procurado, ou 0 se n�o encontrou
int consulta_ArvLLRB(ArvLLRB *raiz, char valor[]){
    if(raiz == NULL)
        return 0;
    struct no_arvore* atual = *raiz;
    while(atual != NULL){
        if(strcmp(valor, atual->info) == 0){
            return 1;
        }
        if(strcmp(valor, atual->info) > 0)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}
// =================================
// ROTA��O
// =================================
struct no_arvore* rotacionaEsquerda(struct no_arvore* A){
    struct no_arvore* B = A->dir;
    A->dir = B->esq;
    B->esq = A;
    B->cor = A->cor;
    A->cor = RED;
    return B;
}

struct no_arvore* rotacionaDireita(struct no_arvore* A){
    struct no_arvore* B = A->esq;
    A->esq = B->dir;
    B->dir = A;
    B->cor = A->cor;
    A->cor = RED;
    return B;
}
// =================================
// PROPRIEDADES
// =================================
int cor(struct no_arvore* H){
    if(H == NULL)
        return BLACK;
    else
        return H->cor;
}

void trocaCor(struct no_arvore* H){
    H->cor = !H->cor;
    if(H->esq != NULL)
        H->esq->cor = !H->esq->cor;
    if(H->dir != NULL)
        H->dir->cor = !H->dir->cor;
}

// =================================
// INSERCAO
// =================================
struct no_arvore* insereNO(struct no_arvore* H, char valor[], int *resp){
    if(H == NULL){
        struct no_arvore *novo;
        novo = (struct no_arvore*)malloc(sizeof(struct no_arvore));
        if(novo == NULL){
            *resp = 0;
            return NULL;
        }

        strcpy(novo->info, valor);
        novo->cor = RED;
        novo->dir = NULL;
        novo->esq = NULL;
        *resp = 1;
        return novo;
    }
    //continua��o
    if(strcmp(valor, H->info) == 0)
        *resp = 0;// Valor duplicado
    else{
        if(strcmp(valor, H->info) < 0)
            H->esq = insereNO(H->esq,valor,resp);
        else
            H->dir = insereNO(H->dir,valor,resp);
    }

    //n� Vermelho � sempre filho � esquerda
    if(cor(H->dir) == RED && cor(H->esq) == BLACK)
        H = rotacionaEsquerda(H);

    //Filho e Neto s�o vermelhos
    //Filho vira pai de 2 n�s vermelhos
    if(cor(H->esq) == RED && cor(H->esq->esq) == RED)
        H = rotacionaDireita(H);

    //2 filhos Vermelhos: troca cor!
    if(cor(H->esq) == RED && cor(H->dir) == RED)
        trocaCor(H);

    return H;
}

int insere_ArvLLRB(ArvLLRB* raiz, char valor[]){
    int resp;
    //Fun��o respons�vel pela busca do local de inser��o do n�
    *raiz = insereNO(*raiz,valor,&resp);
    if((*raiz) != NULL)
        (*raiz)->cor = BLACK;

    return resp;
}
// =================================
// REMO��O
// =================================
struct no_arvore* balancear(struct no_arvore* H){
    //n� Vermelho � sempre filho � esquerda
    if(cor(H->dir) == RED)
        H = rotacionaEsquerda(H);

    //Filho da esquerda e neto da esquerda s�o vermelhos
    if(H->esq != NULL && cor(H->esq) == RED && cor(H->esq->esq) == RED)
        H = rotacionaDireita(H);

    //2 filhos Vermelhos: troca cor!
    if(cor(H->esq) == RED && cor(H->dir) == RED)
        trocaCor(H);

    return H;
}

struct no_arvore* move2EsqRED(struct no_arvore* H){
    trocaCor(H);
    if(cor(H->dir->esq) == RED){
        H->dir = rotacionaDireita(H->dir);
        H = rotacionaEsquerda(H);
        trocaCor(H);
    }
    return H;
}

struct no_arvore* move2DirRED(struct no_arvore* H){
    trocaCor(H);
    if(cor(H->esq->esq) == RED){
        H = rotacionaDireita(H);
        trocaCor(H);
    }
    return H;
}

struct no_arvore* removerMenor(struct no_arvore* H){
    if(H->esq == NULL){
        free(H);
        return NULL;
    }
    if(cor(H->esq) == BLACK && cor(H->esq->esq) == BLACK)
        H = move2EsqRED(H);

    H->esq = removerMenor(H->esq);
    return balancear(H);
}

struct no_arvore* procuraMenor(struct no_arvore* atual){
    struct no_arvore *no1 = atual;
    struct no_arvore *no2 = atual->esq;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}

struct no_arvore* remove_NO(struct no_arvore* H, char valor[]){
    if(strcmp(valor, H->info) < 0){
        if(cor(H->esq) == BLACK && cor(H->esq->esq) == BLACK)
            H = move2EsqRED(H);

        H->esq = remove_NO(H->esq, valor);
    }else{
        if(cor(H->esq) == RED)
            H = rotacionaDireita(H);

        if(strcmp(valor, H->info) == 0 && (H->dir == NULL)){
            free(H);
            return NULL;
        }

        if(cor(H->dir) == BLACK && cor(H->dir->esq) == BLACK)
            H = move2DirRED(H);

        if(strcmp(valor, H->info) == 0){
            struct no_arvore* x = procuraMenor(H->dir);
            strcpy(H->info, x->info);
            H->dir = removerMenor(H->dir);
        }else
            H->dir = remove_NO(H->dir, valor);
    }
    return balancear(H);
}

int remove_ArvLLRB(ArvLLRB *raiz, char valor[]){
    if(consulta_ArvLLRB(raiz,valor)){
        struct no_arvore* h = *raiz;
        //Fun��o respons�vel pela busca do n� a ser removido
        *raiz = remove_NO(h,valor);
        if(*raiz != NULL)
            (*raiz)->cor = BLACK;
        return 1;
    }else
        return 0;
}
// =================================
// PROPRIEDADES �RVORE
// =================================
int estaVazia_ArvLLRB(ArvLLRB *raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

//Retorna a quantidade de n�s a partir de uma raiz
int totalNO_ArvLLRB(ArvLLRB *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;

    int alt_esq = totalNO_ArvLLRB(&((*raiz)->esq));
    int alt_dir = totalNO_ArvLLRB(&((*raiz)->dir));
    return (alt_esq + alt_dir + 1);
}

//Mostra a altura da �rvore
int altura_ArvLLRB(ArvLLRB *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvLLRB(&((*raiz)->esq));
    int alt_dir = altura_ArvLLRB(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}
// =================================
// PERCURSO
// =================================
void  posOrdem_ArvLLRB(ArvLLRB *raiz, int H){
    if(raiz == NULL)
        return;

    if(*raiz != NULL){
        posOrdem_ArvLLRB(&((*raiz)->esq),H+1);
        posOrdem_ArvLLRB(&((*raiz)->dir),H+1);

        if((*raiz)->cor == RED)
            printf("Chave: %s - Vermelho - Nivel(%d) \n",(*raiz)->info,H);
        else
            printf("Chave: %s - Preto - Nivel(%d) \n",(*raiz)->info,H);

    }
}

void emOrdem_ArvLLRB(ArvLLRB *raiz, int H, char pai[]){
    if(raiz == NULL)
        return;

    if(*raiz != NULL){
        emOrdem_ArvLLRB(&((*raiz)->esq),H+1, (*raiz)->info);

        if((*raiz)->cor == RED) {

            printf("Chave: %s - Vermelho - Nivel(%d) - Pai: %d\n",(*raiz)->info,H, pai);
        } else {

            printf("Chave: %s - Preto - Nivel(%d) - Pai: %d\n",(*raiz)->info,H, pai);
        }
        emOrdem_ArvLLRB(&((*raiz)->dir),H+1, (*raiz)->info);
    }
}

void nomesEmOrdem(ArvLLRB *raiz, int H, int pai){
    if(raiz == NULL)
        return;

    if(*raiz != NULL){

        nomesEmOrdem(&((*raiz)->esq),H+1, (*raiz)->info);

        if (altura_ArvLLRB(raiz) == 1){
            printf(" %s(Folha)", (*raiz)->info);
        } else
        printf(" %s", (*raiz)->info);

        nomesEmOrdem(&((*raiz)->dir),H+1, (*raiz)->info);
    }
}

void preOrdem_ArvLLRB(ArvLLRB *raiz,int H){
    if(raiz == NULL)
        return;

    if(*raiz != NULL){
        if((*raiz)->cor == RED)
            printf("Chave: %s - Vermelho - Nivel(%d) \n",(*raiz)->info,H);
        else
            printf("Chave: %s - Preto - Nivel(%d) \n",(*raiz)->info,H);

        preOrdem_ArvLLRB(&((*raiz)->esq),H+1);
        preOrdem_ArvLLRB(&((*raiz)->dir),H+1);
    }
}


