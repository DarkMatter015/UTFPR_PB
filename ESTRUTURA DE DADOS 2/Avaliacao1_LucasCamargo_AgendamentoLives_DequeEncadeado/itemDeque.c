#include <stdio.h>
#include <stdlib.h>
#include "itemDeque.h" //inclui os Protótipos

struct lucasEventoLive
{
    int chave;
    char data_transmissao[10];
    char titulo[20];
    char apresentador[20];
    int duracao;
    int plataforma_transmissao; // 1- Youtube, 2- Facebook, 3- Instagram
};

struct celula
{
    LucasEventoLive lucasEventoLive;
    Celula *prox;
};

struct deque
{
    Celula *ini;
    Celula *fim;
};

Deque* cria_Deque()
{
    Deque* dq = (Deque*) malloc(sizeof(Deque));
    if(dq != NULL)
    {
        dq->ini = NULL;
        dq->fim = NULL;
    }
    return dq;
}

int verificaDequeVazia(Deque* dq)
{
    return (dq->ini == NULL);
}

void insereFinal_Deque(Deque* dq, int chave, char data_transmissao[], char titulo[], char apresentador[], int duracao, int plataforma_transmissao)
{
    //cria novo lucasEventoLive que vai ser guardado na Deque
    LucasEventoLive novo;
    novo.chave = chave;
    strcpy(novo.data_transmissao, data_transmissao);
    strcpy(novo.titulo, titulo);
    strcpy(novo.apresentador, apresentador);
    novo.duracao = duracao;
    novo.plataforma_transmissao = plataforma_transmissao;
    //cria nova célula que vai guardar o lucasEventoLive
    Celula *nova = malloc(sizeof(Celula));
    nova->lucasEventoLive = novo;
    if (verificaDequeVazia(dq)) //se está vazia adiciona no início
    {
        //no->ant = NULL;
        nova->prox = dq->ini;
        dq->ini = nova;
    }
    else
    {
        //senão aciciona no final
        //no->ant = dq->final;
        //inserção no final, a nova célula aponta para NULL
        nova->prox = NULL;
        dq->fim->prox = nova;
    }
    dq->fim = nova;
}

void insereInicio_Deque(Deque* dq, int chave, char data_transmissao[], char titulo[], char apresentador[], int duracao, int plataforma_transmissao)
{
    //cria novo lucasEventoLive que vai ser guardado na Deque
    LucasEventoLive novo;
    novo.chave = chave;
    strcpy(novo.data_transmissao, data_transmissao);
    strcpy(novo.titulo, titulo);
    strcpy(novo.apresentador, apresentador);
    novo.duracao = duracao;
    novo.plataforma_transmissao = plataforma_transmissao;
    //cria nova célula que vai guardar o lucasEventoLive
    Celula *nova = malloc(sizeof(Celula));
    nova->lucasEventoLive = novo;
    nova->prox = dq->ini;
    if (verificaDequeVazia(dq)) //se está vazia fim será igual a ini
    {
        dq->fim = nova;
    }
    dq->ini = nova;
}


void removeInicio_Deque(Deque* dq)
{
    if (verificaDequeVazia(dq))
    {
        printf("Erro: Deque vazia!\n");
        return;
    }

    Celula *remover = dq->ini;
    dq->ini = remover->prox;
    free(remover);
    if (verificaDequeVazia(dq)) //se ficou vazia, fim aponta para NULL
        dq->fim = NULL;
}

int removeFinal_Deque(Deque* dq)
{
    if (verificaDequeVazia(dq))
    {
        printf("Erro: Deque vazia!\n");
        return;
    }
    Celula *remover = dq->fim;

    if (remover == dq->ini) //remover o primeiro e unico elemento?
    {
        dq->ini = NULL;
        dq->fim = NULL;
    }
    else
    {
        Celula *ultimo = dq->ini;
        while (ultimo->prox != dq->fim)
        {
            ultimo = ultimo->prox;
        }

        ultimo->prox = NULL;
        dq->fim = ultimo;
    }
    free(remover);
}


void imprime_Deque(Deque* dq)
{
    Celula *aux = dq->ini;
    while (aux != NULL)
    {
        printf("Chave: %d, Data Transmissao: %s, Titulo: %s, Apresentador: %s, Duracao(horas): %d, Plataforma Transmissao: %d\n",
               aux->lucasEventoLive.chave,
               aux->lucasEventoLive.data_transmissao,
               aux->lucasEventoLive.titulo,
               aux->lucasEventoLive.apresentador,
               aux->lucasEventoLive.duracao,
               aux->lucasEventoLive.plataforma_transmissao);
        aux = aux->prox;
    }
}

LucasEventoLive* busca_Deque(Deque* dq, int chave) {
    Celula *aux = dq->ini;
    while (aux != NULL) {
        if (aux->lucasEventoLive.chave == chave) {
            return &(aux->lucasEventoLive);
        }
        aux = aux->prox;
    }
    return NULL;
}

void imprimeLive_Deque(LucasEventoLive* live) {
    if (live == NULL) {
        printf("Elemento não encontrado!\n");
        return;
    }
    printf("Chave: %d, Data Transmissao: %s, Titulo: %s, Apresentador: %s, Duracao(horas): %d, Plataforma Transmissao: %d\n",
       live->chave,
       live->data_transmissao,
       live->titulo,
       live->apresentador,
       live->duracao,
       live->plataforma_transmissao);
}

void contabilizaLives(Deque* dq){
    Celula *aux = dq->ini;
    int youtube = 0, facebook = 0, instagram = 0;
    while (aux != NULL)
    {
        if(aux->lucasEventoLive.plataforma_transmissao == 1){
            youtube++;
        } else if(aux->lucasEventoLive.plataforma_transmissao == 2){
            facebook++;
        } else if(aux->lucasEventoLive.plataforma_transmissao == 3){
            instagram++;
        }
        aux = aux->prox;
    }

    printf("\nQuantidade de Lives por Plataforma:");
    printf("\nYoutube: %d", youtube);
    printf("\nFacebook: %d", facebook);
    printf("\nInstagram: %d", instagram);
}

void libera_Deque(Deque* dq)
{
    Celula *aux = dq->ini;
    Celula *liberar;
    while(aux != NULL)
    {
        liberar = aux;
        aux = aux->prox;
        free(liberar);
    }
    free(dq);
}
