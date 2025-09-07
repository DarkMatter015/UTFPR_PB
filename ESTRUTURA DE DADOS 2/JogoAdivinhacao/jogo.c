#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"

struct no_arvore {
    int info;
    NoArvBin *esq;
    NoArvBin *dir;
};

NoArvBin* cria_ArvBin(){
    NoArvBin* raiz = (NoArvBin*) malloc(sizeof(NoArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO(struct no_arvore* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvBin(NoArvBin* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);
    free(raiz);
}

int insere_ArvBin(NoArvBin* raiz, int valor, int maquinaAcertou){

    if(raiz == NULL) {
        return 0;
    }
    struct no_arvore* novo;
    novo = (struct no_arvore*) malloc(sizeof(struct no_arvore));
    if(novo == NULL) {
        return 0;
    }
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct no_arvore* atual = *raiz;
        struct no_arvore* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == atual->info){
                free(novo);
                return 0;
            }

            if(maquinaAcertou == 1) {
                atual = atual->dir;
            } else {
                atual = atual->esq;
            }
        }
        if(maquinaAcertou == 1) {
            ant->dir = novo;
        } else {
            ant->esq = novo;
        }
    }
    return 1;
}


void imprimeResultado(NoArvBin *raiz) {
    if (raiz == NULL || *raiz == NULL) {
        printf("\nSem informações de placar.\n");
        return;
    }

    printf("\n=== HISTÓRICO DE RODADAS ===\n");

    printf("\n- Rodadas vencidas pelo jogador:\n");
    imprimeRodadasJogador(&((*raiz)->esq));

    printf("\nRodadas vencidas pela máquina:\n");
    imprimeRodadasMaquina(&((*raiz)->dir));
}

void imprimeRodadasJogador(NoArvBin *raiz) {
    if (raiz == NULL)
        return;
    if (*raiz != NULL) {
        imprimeRodadasJogador(&((*raiz)->esq));
        printf("Rodada vencida pelo jogador: %d\n", (*raiz)->info);
        imprimeRodadasJogador(&((*raiz)->dir));
    }
}

void imprimeRodadasMaquina(NoArvBin *raiz) {
    if (raiz == NULL)
        return;
    if (*raiz != NULL) {
        imprimeRodadasMaquina(&((*raiz)->esq));
        printf("Rodada vencida pela máquina: %d\n", (*raiz)->info);
        imprimeRodadasMaquina(&((*raiz)->dir));
    }
}

void imprimeMenu() {

    printf("=== AKINATOR NUMBERS ===\n");

    printf("\n=== REGRAS DO JOGO ===\n");
    printf("- Pense em um número inicial e não o mude até acabar a rodada de adivinhacao.\n");
    printf("- A cada rodada, a máquina faz uma pergunta e dependendo da resposta ela tenta adivinhar.\n");
    printf("- Você deve informar se a máquina acertou ou errou.(Seja sinsero rsrs)\n");

    printf("\n=== COMO JOGAR ===\n");
    printf("1. Você pensará em um número fixo durante a rodada (sem digitar).\n");
    printf("2. A máquina fará perguntas que envolvem numeros para basear as tentativas.\n");
    printf("3. Após cada tentativa, informe se a máquina acertou (s) ou errou (n).\n\n");

    printf("Pressione algum botao para jogar...\n");
    getchar();
    fflush(stdin);
}
