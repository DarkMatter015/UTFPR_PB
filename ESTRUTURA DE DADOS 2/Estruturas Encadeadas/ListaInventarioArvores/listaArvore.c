#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaArvore.h"

struct arvore {
    char regiao[50];
    char especie[50];
    int quantidade;
    int id_arvore;
};

struct celula {
    ARVORE item;
    Celula *prox;
};

struct lista {
    Celula *primeira;
};

Lista *criaListaVazia() {
    Lista *lst = malloc(sizeof(Lista));
    lst->primeira = NULL;
    return lst;
}

int verificaListaVazia(Lista *lst) {
    return (lst->primeira == NULL);
}

void insereFimLista(Lista *lst, char *regiao, char *especie, int quantidade, int id_arvore) {
    ARVORE novo;
    strcpy(novo.regiao, regiao);
    strcpy(novo.especie, especie);
    novo.quantidade = quantidade;
    novo.id_arvore = id_arvore;

    Celula *nova = malloc(sizeof(Celula));
    nova->item = novo;
    nova->prox = NULL;

    if (verificaListaVazia(lst)) {
        lst->primeira = nova;
    } else {
        Celula *ultima = lst->primeira;
        while (ultima->prox != NULL) {
            ultima = ultima->prox;
        }
        ultima->prox = nova;
    }
}

Celula *buscaPorEspecieRegiao(Lista *lst, char *regiao, char *especie) {
    Celula *aux = lst->primeira;
    while (aux != NULL) {
        if (strcmp(aux->item.regiao, regiao) == 0 && strcmp(aux->item.especie, especie) == 0) {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

void atualizaQuantidade(Lista *lst, char *regiao, char *especie, int quantidade) {
    Celula *existente = buscaPorEspecieRegiao(lst, regiao, especie);
    if (existente != NULL) {
        existente->item.quantidade += quantidade;
        printf("Identificado registro existente, atualizada a quantidade.\n");
    } else {
        printf("Erro: Registro não encontrado para atualização.\n");
    }
}

void removeFimLista(Lista *lst) {
    if (verificaListaVazia(lst)) {
        printf("Erro: Lista vazia!\n");
        return;
    }
    Celula *remover;
    Celula *anterior = NULL;
    Celula *aux = lst->primeira;

    while (aux->prox != NULL) {
        anterior = aux;
        aux = aux->prox;
    }
    remover = aux;

    printf("Registro removido: %s, Espécie: %s, Quantidade: %d, ID: %d\n",
           remover->item.regiao, remover->item.especie, remover->item.quantidade, remover->item.id_arvore);

    if (anterior == NULL) {
        lst->primeira = NULL;
    } else {
        anterior->prox = NULL;
    }
    free(remover);
}

void imprimeLista(Lista *lst) {
    if (verificaListaVazia(lst)) {
        printf("Lista vazia! Nenhum registro de árvores.\n");
        return;
    }
    printf("\n=== Espécies de árvores identificadas por região inventariada ===\n");
    Celula *aux = lst->primeira;
    while (aux != NULL) {
        printf("* %s\nChave: %d - Espécie %s - Quantidade: %d\n",
               aux->item.regiao, aux->item.id_arvore, aux->item.especie, aux->item.quantidade);
        aux = aux->prox;
    }
}

void analisaPorcentagens(Lista *lst) {
    if (verificaListaVazia(lst)) {
        printf("Nenhum registro de árvores para análise.\n");
        return;
    }

    struct {
        char nome[50];
        int total_arvores;
    } regioes[100];
    int num_regioes = 0;

    Celula *aux = lst->primeira;
    while (aux != NULL) {
        int encontrou = 0;
        for (int i = 0; i < num_regioes; i++) {
            if (strcmp(regioes[i].nome, aux->item.regiao) == 0) {
                regioes[i].total_arvores += aux->item.quantidade;
                encontrou = 1;
                break;
            }
        }
        if (!encontrou) {
            strcpy(regioes[num_regioes].nome, aux->item.regiao);
            regioes[num_regioes].total_arvores = aux->item.quantidade;
            num_regioes++;
        }
        aux = aux->prox;
    }

    int max_quantidade = 0;
    char max_especie[50] = "";
    int max_id = 0;
    aux = lst->primeira;
    while (aux != NULL) {
        if (aux->item.quantidade > max_quantidade) {
            max_quantidade = aux->item.quantidade;
            strcpy(max_especie, aux->item.especie);
            max_id = aux->item.id_arvore;
        }
        aux = aux->prox;
    }

    printf("\n=== Porcentagem de árvores por região ===\n");
    aux = lst->primeira;
    for (int i = 0; i < num_regioes; i++) {
        printf("%s\n", regioes[i].nome);
        Celula *temp = lst->primeira;
        while (temp != NULL) {
            if (strcmp(temp->item.regiao, regioes[i].nome) == 0) {
                float percentual = (regioes[i].total_arvores > 0) ?
                    ((float)temp->item.quantidade / regioes[i].total_arvores) * 100 : 0;
                printf("* %d árvores da espécie %s, equivalente a %.2f %% de árvores da região (Total: %d).\n",
                       temp->item.quantidade, temp->item.especie, percentual, regioes[i].total_arvores);
            }
            temp = temp->prox;
        }
    }

    printf("\n=== Espécie mais frequente ===\n");
    printf("Espécie: %s, ID: %d, Quantidade: %d\n", max_especie, max_id, max_quantidade);
}

void liberaLista(Lista *lst) {
    Celula *aux = lst->primeira;
    Celula *liberar;
    while (aux != NULL) {
        liberar = aux;
        aux = aux->prox;
        free(liberar);
    }
    free(lst);
}
