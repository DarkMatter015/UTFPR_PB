#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArvoreLLRB.h"

struct item {
    char nome[50]; // Nome da equipe
    int pontuacao; // Pontuação acumulada
};

struct no_arvore {
    Item *item; // Ponteiro para o item (nome e pontuação)
    struct no_arvore *esq;
    struct no_arvore *dir;
    int cor; // RED (1) ou BLACK (0)
};

struct arvLLRB {
    No_Arvore *raiz;
};

// Cria um item
Item *criaItem(char nome[], int pontuacao) {
    Item *item = malloc(sizeof(Item));
    if (item == NULL) {
        printf("Erro ao alocar memoria para Item.\n");
        return NULL;
    }
    strcpy(item->nome, nome);
    item->pontuacao = pontuacao;
    return item;
}

// Libera um item
void liberaItem(Item *item) {
    if (item != NULL) {
        free(item);
    }
}

// Cria uma árvore vazia
ArvLLRB *cria_ArvLLRB() {
    ArvLLRB *arv = malloc(sizeof(ArvLLRB));
    if (arv == NULL) {
        printf("Erro ao alocar memoria para ArvLLRB.\n");
        return NULL;
    }
    arv->raiz = NULL;
    return arv;
}

// Libera os nós recursivamente
void libera_NO(No_Arvore *no) {
    if (no == NULL) return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    liberaItem(no->item);
    free(no);
}

// Libera a árvore
void libera_ArvLLRB(ArvLLRB *raiz) {
    if (raiz == NULL) return;
    libera_NO(raiz->raiz);
    free(raiz);
}

// Consulta um nome na árvore
int consulta_ArvLLRB(ArvLLRB *raiz, char nome[]) {
    if (raiz == NULL || raiz->raiz == NULL) return 0;
    No_Arvore *atual = raiz->raiz;
    while (atual != NULL) {
        int cmp = strcmp(nome, atual->item->nome);
        if (cmp == 0) return 1;
        atual = cmp < 0 ? atual->esq : atual->dir;
    }
    return 0;
}

// Retorna a cor do nó
int cor(No_Arvore *H) {
    return H == NULL ? BLACK : H->cor;
}

// Troca a cor do nó e seus filhos
void trocaCor(No_Arvore *H) {
    printf("Troca de cor no no '%s': de %s para %s", H->item->nome,
           H->cor == RED ? "Vermelho" : "Preto",
           H->cor == RED ? "Preto" : "Vermelho");
    if (H->esq || H->dir) {
        printf(" (Filhos: %s, %s)",
               H->esq ? H->esq->item->nome : "Nenhum",
               H->dir ? H->dir->item->nome : "Nenhum");
    }
    printf("\n");
    H->cor = !H->cor;
    if (H->esq != NULL) H->esq->cor = !H->esq->cor;
    if (H->dir != NULL) H->dir->cor = !H->dir->cor;
}

// Rotação à esquerda
No_Arvore *rotacionaEsquerda(No_Arvore *A) {
    printf("Rotacao a esquerda no no '%s'\n", A->item->nome);
    No_Arvore *B = A->dir;
    A->dir = B->esq;
    B->esq = A;
    B->cor = A->cor;
    A->cor = RED;
    return B;
}

// Rotação à direita
No_Arvore *rotacionaDireita(No_Arvore *A) {
    printf("Rotacao a direita no na '%s'\n", A->item->nome);
    No_Arvore *B = A->esq;
    A->esq = B->dir;
    B->dir = A;
    B->cor = A->cor;
    A->cor = RED;
    return B;
}

// Inserção recursiva
No_Arvore *insereNO(No_Arvore *H, Item *item, int *resp) {
    if (H == NULL) {
        No_Arvore *novo = malloc(sizeof(No_Arvore));
        if (novo == NULL) {
            *resp = 0;
            return NULL;
        }
        novo->item = item;
        novo->cor = RED;
        novo->esq = novo->dir = NULL;
        *resp = 1;
        return novo;
    }

    int cmp = strcmp(item->nome, H->item->nome);
    if (cmp == 0) {
        *resp = 0; // Nome duplicado
        liberaItem(item);
    } else if (cmp < 0) {
        H->esq = insereNO(H->esq, item, resp);
    } else {
        H->dir = insereNO(H->dir, item, resp);
    }

    // Ajustes LLRB
    if (cor(H->dir) == RED) // Prioriza corrigir nó vermelho à direita
        H = rotacionaEsquerda(H);
    if (H->esq && cor(H->esq) == RED && H->esq->esq && cor(H->esq->esq) == RED)
        H = rotacionaDireita(H);
    if (H->esq && H->dir && cor(H->esq) == RED && cor(H->dir) == RED)
        trocaCor(H);

    return H;
}

// Insere uma equipe
int insere_ArvLLRB(ArvLLRB *raiz, Item *item) {
    if (raiz == NULL) return 0;
    int resp;
    raiz->raiz = insereNO(raiz->raiz, item, &resp);
    if (raiz->raiz != NULL)
        raiz->raiz->cor = BLACK;
    // Verificação de depuração
    int erros = 0;
    verificaPropriedadesLLRB(raiz->raiz, &erros);
    if (erros > 0) printf("Foram encontrados %d erros nas propriedades LLRB.\n", erros);
    return resp;
}

// Verifica propriedades LLRB (para depuração)
void verificaPropriedadesLLRB(No_Arvore *no, int *erros) {
    if (no == NULL) return;

    // Verifica raiz preta (só para a raiz)
    static int is_root = 1;
    if (is_root && no->cor == RED) {
        printf("Erro: Raiz '%s' esta vermelha.\n", no->item->nome);
        (*erros)++;
    }
    is_root = 0;

    // Verifica nó vermelho à direita
    if (no->dir && no->dir->cor == RED) {
        printf("Erro: No vermelho a direita em '%s' (filho: '%s').\n",
               no->item->nome, no->dir->item->nome);
        (*erros)++;
    }

    verificaPropriedadesLLRB(no->esq, erros);
    verificaPropriedadesLLRB(no->dir, erros);
    is_root = 1; // Restaura para próxima chamada
}

// Balanceamento para remoção
No_Arvore *balancear(No_Arvore *H) {
    if (cor(H->dir) == RED)
        H = rotacionaEsquerda(H);
    if (H->esq != NULL && cor(H->esq) == RED && cor(H->esq->esq) == RED)
        H = rotacionaDireita(H);
    if (cor(H->esq) == RED && cor(H->dir) == RED)
        trocaCor(H);
    return H;
}

// Move vermelho para a esquerda
No_Arvore *move2EsqRED(No_Arvore *H) {
    trocaCor(H);
    if (H->dir && H->dir->esq && cor(H->dir->esq) == RED) {
        H->dir = rotacionaDireita(H->dir);
        H = rotacionaEsquerda(H);
        trocaCor(H);
    }
    return H;
}

// Move vermelho para a direita
No_Arvore *move2DirRED(No_Arvore *H) {
    trocaCor(H);
    if (H->esq && H->esq->esq && cor(H->esq->esq) == RED) {
        H = rotacionaDireita(H);
        trocaCor(H);
    }
    return H;
}

// Remove o menor nó
No_Arvore *removerMenor(No_Arvore *H) {
    if (H->esq == NULL) {
        liberaItem(H->item);
        free(H);
        return NULL;
    }
    if (cor(H->esq) == BLACK && cor(H->esq->esq) == BLACK) {
        H = move2EsqRED(H);
    }

    H->esq = removerMenor(H->esq);
    return balancear(H);
}

// Procura o menor nó
No_Arvore *procuraMenor(No_Arvore *atual) {
    while (atual->esq != NULL) {
        atual = atual->esq;
    }
    return atual;
}

// Remove um nó recursivamente
No_Arvore *remove_NO(No_Arvore *H, char nome[]) {
    int cmp = strcmp(nome, H->item->nome);
    if (cmp < 0) {
        if (H->esq && cor(H->esq) == BLACK && cor(H->esq->esq) == BLACK)
            H = move2EsqRED(H);
        H->esq = remove_NO(H->esq, nome);
    } else {
        if (cor(H->esq) == RED)
            H = rotacionaDireita(H);
        if (cmp == 0 && H->dir == NULL) {
            liberaItem(H->item);
            free(H);
            return NULL;
        }
        if (H->dir && cor(H->dir) == BLACK && cor(H->dir->esq) == BLACK)
            H = move2DirRED(H);
        if (cmp == 0) {
            No_Arvore *x = procuraMenor(H->dir);
            H->item = x->item;
            x->item = NULL; // Evita liberação dupla
            H->dir = removerMenor(H->dir);
        } else {
            H->dir = remove_NO(H->dir, nome);
        }
    }
    return balancear(H);
}

// Remove uma equipe
int remove_ArvLLRB(ArvLLRB *raiz, char nome[]) {
    if (!consulta_ArvLLRB(raiz, nome)) return 0;
    raiz->raiz = remove_NO(raiz->raiz, nome);
    if (raiz->raiz != NULL)
        raiz->raiz->cor = BLACK;
    return 1;
}

// Atualiza a pontuação
int atualizaPontuacao(ArvLLRB *raiz, char nome[], char resultado) {
    if (raiz == NULL || raiz->raiz == NULL) return 0;
    No_Arvore *atual = raiz->raiz;
    while (atual != NULL) {
        int cmp = strcmp(nome, atual->item->nome);
        if (cmp == 0) {
            switch (resultado) {
                case 'V': atual->item->pontuacao += 3; break; // Vitória
                case 'E': atual->item->pontuacao += 1; break; // Empate
                case 'D': break; // Derrota (0 pontos)
                default: return 0; // Resultado inválido
            }
            return 1;
        }
        atual = cmp < 0 ? atual->esq : atual->dir;
    }
    return 0;
}

// Verifica se a árvore está vazia
int estaVazia_ArvLLRB(ArvLLRB *raiz) {
    return raiz == NULL || raiz->raiz == NULL;
}

// Conta o total de nós
int totalNO_ArvLLRB(ArvLLRB *raiz) {
    if (raiz == NULL || raiz->raiz == NULL) return 0;
    return totalNO_ArvLLRB(&(raiz->raiz->esq)) + totalNO_ArvLLRB(&(raiz->raiz->dir)) + 1;
}

// Calcula a altura
int altura_ArvLLRB(ArvLLRB *raiz) {
    if (raiz == NULL || raiz->raiz == NULL) return 0;
    int alt_esq = altura_ArvLLRB(&(raiz->raiz->esq));
    int alt_dir = altura_ArvLLRB(&(raiz->raiz->dir));
    return alt_esq > alt_dir ? alt_esq + 1 : alt_dir + 1;
}

// Percurso em-ordem
void emOrdem_ArvLLRB(ArvLLRB *raiz, int H, char pai[]) {
    if (raiz == NULL || raiz->raiz == NULL) return;

    emOrdem_ArvLLRB(&(raiz->raiz->esq), H + 1, raiz->raiz->item->nome);
    printf("Equipe: %s, Pontuacao: %d, Cor: %s, Nivel: %d, Pai: %s\n",
           raiz->raiz->item->nome,
           raiz->raiz->item->pontuacao,
           raiz->raiz->cor == RED ? "Vermelho" : "Preto",
           H,
           pai[0] == '\0' ? "Nenhum" : pai);
    emOrdem_ArvLLRB(&(raiz->raiz->dir), H + 1, raiz->raiz->item->nome);
}
