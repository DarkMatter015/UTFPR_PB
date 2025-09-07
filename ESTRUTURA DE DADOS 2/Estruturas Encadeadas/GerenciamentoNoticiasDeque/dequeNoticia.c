#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dequeNoticia.h"

struct noticia {
    char titulo[100];
    char autor[50];
    char classificacao[30]; // (ex.: Novidades, Lan�amentos, Cultura)
    int id_noticia;
};

struct celula {
    NOTICIA item;
    Celula *prox;
};

struct deque {
    Celula *ini;
    Celula *fim;
};

Deque *cria_Deque() {
    Deque *dq = malloc(sizeof(Deque));
    if (dq != NULL) {
        dq->ini = NULL;
        dq->fim = NULL;
    }
    return dq;
}

int verificaDequeVazia(Deque *dq) {
    return (dq->ini == NULL);
}

void insereInicio_Deque(Deque *dq, char *titulo, char *autor, char *classificacao, int id_noticia) {
    NOTICIA novo;
    strcpy(novo.titulo, titulo);
    strcpy(novo.autor, autor);
    strcpy(novo.classificacao, classificacao);
    novo.id_noticia = id_noticia;

    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    nova->prox = dq->ini;
    if (verificaDequeVazia(dq)) {
        dq->fim = nova;
    }
    dq->ini = nova;
}

void insereFinal_Deque(Deque *dq, char *titulo, char *autor, char *classificacao, int id_noticia) {
    NOTICIA novo;
    strcpy(novo.titulo, titulo);
    strcpy(novo.autor, autor);
    strcpy(novo.classificacao, classificacao);
    novo.id_noticia = id_noticia;

    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    nova->prox = NULL;
    if (verificaDequeVazia(dq)) {
        dq->ini = nova;
        dq->fim = nova;
    } else {
        dq->fim->prox = nova;
        dq->fim = nova;
    }
}

void removeInicio_Deque(Deque *dq) {
    if (verificaDequeVazia(dq)) {
        printf("Erro: Deque vazio!\n");
        return;
    }
    Celula *remover = dq->ini;
    printf("Not�cia removida: %s (ID: %d, Autor: %s, Classifica��o: %s)\n",
           remover->item.titulo, remover->item.id_noticia, remover->item.autor, remover->item.classificacao);
    dq->ini = remover->prox;
    free(remover);
    if (verificaDequeVazia(dq)) {
        dq->fim = NULL;
    }
}

void removeFinal_Deque(Deque *dq) {
    if (verificaDequeVazia(dq)) {
        printf("Erro: Deque vazio!\n");
        return;
    }
    Celula *remover = dq->fim;
    printf("Not�cia removida: %s (ID: %d, Autor: %s, Classifica��o: %s)\n",
           remover->item.titulo, remover->item.id_noticia, remover->item.autor, remover->item.classificacao);
    if (remover == dq->ini) {
        dq->ini = NULL;
        dq->fim = NULL;
    } else {
        Celula *ultimo = dq->ini;
        while (ultimo->prox != dq->fim) {
            ultimo = ultimo->prox;
        }
        ultimo->prox = NULL;
        dq->fim = ultimo;
    }
    free(remover);
}

void imprime_Deque(Deque *dq) {
    if (verificaDequeVazia(dq)) {
        printf("Deque vazio! Nenhuma not�cia registrada.\n");
        return;
    }
    printf("\n=== Not�cias no Jornal ===\n");
    Celula *aux = dq->ini;
    while (aux != NULL) {
        printf("T�tulo: %s, ID: %d, Autor: %s, Classifica��o: %s\n",
               aux->item.titulo, aux->item.id_noticia, aux->item.autor, aux->item.classificacao);
        aux = aux->prox;
    }
    printf("=========================\n");
}

void libera_Deque(Deque *dq) {
    Celula *aux = dq->ini;
    Celula *liberar;
    while (aux != NULL) {
        liberar = aux;
        aux = aux->prox;
        free(liberar);
    }
    free(dq);
}

void analisaClassificacoes(Deque *dq) {
    if (verificaDequeVazia(dq)) {
        printf("Nenhuma not�cia cadastrada para an�lise.\n");
        return;
    }

    // Estrutura para contar not�cias por classifica��o
    struct {
        char nome[30];
        int quantidade;
    } categorias[100]; // Suporta at� 100 classifica��es diferentes
    int num_categorias = 0;
    int total_noticias = 0;

    // Contar not�cias por classifica��o
    Celula *aux = dq->ini;
    while (aux != NULL) {
        int encontrou = 0;
        for (int i = 0; i < num_categorias; i++) {
            if (strcmp(categorias[i].nome, aux->item.classificacao) == 0) {
                categorias[i].quantidade++;
                encontrou = 1;
                break;
            }
        }
        if (!encontrou) {
            strcpy(categorias[num_categorias].nome, aux->item.classificacao);
            categorias[num_categorias].quantidade = 1;
            num_categorias++;
        }
        total_noticias++;
        aux = aux->prox;
    }

    // Encontrar a classifica��o com maior n�mero de not�cias
    int max_quantidade = 0;
    char *max_classificacao = categorias[0].nome;
    for (int i = 0; i < num_categorias; i++) {
        if (categorias[i].quantidade > max_quantidade) {
            max_quantidade = categorias[i].quantidade;
            max_classificacao = categorias[i].nome;
        }
    }

    // Calcular percentual
    float percentual = (total_noticias > 0) ? ((float)max_quantidade / total_noticias) * 100 : 0;

    // Imprimir resultados
    printf("\n=== An�lise de Classifica��es ===\n");
    printf("Total de not�cias: %d\n", total_noticias);
    for (int i = 0; i < num_categorias; i++) {
        printf("Classifica��o: %s, Quantidade: %d\n", categorias[i].nome, categorias[i].quantidade);
    }
    printf("Classifica��o mais frequente: %s (%d not�cias, %.2f%%)\n", max_classificacao, max_quantidade, percentual);
    printf("=============================\n");
}
