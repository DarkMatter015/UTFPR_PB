#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArvoreLLRB.h"

int main() {
    ArvLLRB *raiz = cria_ArvLLRB();
    if (raiz == NULL) {
        printf("Erro ao criar a arvore.\n");
        return 1;
    }

    // Fase 1: Cadastro de equipes
    printf("=== Cadastro de Equipes ===\n");
    while (1) {
        char nome[50];
        printf("Digite o nome da equipe (ou 'sair' para encerrar): ");
        scanf("%[^\n]", nome);
        fflush(stdin);
        if (strcmp(nome, "sair") == 0) break;

        Item *item = criaItem(nome, 0);
        if (item == NULL) continue;
        if (insere_ArvLLRB(raiz, item)) {
            printf("Equipe '%s' inserida com sucesso.\n", nome);
        } else {
            printf("Erro: Equipe '%s' ja existe ou falha na insercao.\n", nome);
            liberaItem(item);
        }
    }

    // Impressão da árvore
    printf("\n=== Arvore de Equipes (em-ordem) ===\n");
    if (estaVazia_ArvLLRB(raiz)) {
        printf("Arvore vazia.\n");
    } else {
        emOrdem_ArvLLRB(raiz, 0, "");
        printf("\nTotal de equipes: %d\n", totalNO_ArvLLRB(raiz));
        printf("Altura da arvore: %d\n", altura_ArvLLRB(raiz));
    }

    // Fase 2: Cadastro de resultados
    printf("\n=== Cadastro de Resultados ===\n");
    while (1) {
        printf("\n1. Inserir resultado de competicao\n2. Sair\nEscolha: ");
        int opcao;
        scanf("%d", &opcao);
        fflush(stdin);

        if (opcao == 2) break;
        if (opcao != 1) {
            printf("Opcao invalida.\n");
            continue;
        }

        char equipe1[50], equipe2[50], resultado[10];
        printf("Digite o nome da primeira equipe: ");
        scanf("%[^\n]", equipe1);
        fflush(stdin);
        printf("Digite o nome da segunda equipe: ");
        scanf("%[^\n]", equipe2);
        fflush(stdin);
        printf("Resultado (V para vitoria de %s, E para empate, D para derrota de %s): ", equipe1, equipe1);
        scanf("%s", resultado);
        fflush(stdin);

        if (!consulta_ArvLLRB(raiz, equipe1) || !consulta_ArvLLRB(raiz, equipe2)) {
            printf("Erro: Uma ou ambas as equipes nao existem.\n");
            continue;
        }

        if (resultado[0] == 'V' || resultado[0] == 'v') {
            atualizaPontuacao(raiz, equipe1, 'V');
            atualizaPontuacao(raiz, equipe2, 'D');
            printf("Pontuacao atualizada: %s venceu, %s perdeu.\n", equipe1, equipe2);
        } else if (resultado[0] == 'E' || resultado[0] == 'e') {
            atualizaPontuacao(raiz, equipe1, 'E');
            atualizaPontuacao(raiz, equipe2, 'E');
            printf("Pontuacao atualizada: Empate entre %s e %s.\n", equipe1, equipe2);
        } else if (resultado[0] == 'D' || resultado[0] == 'd') {
            atualizaPontuacao(raiz, equipe1, 'D');
            atualizaPontuacao(raiz, equipe2, 'V');
            printf("Pontuacao atualizada: %s perdeu, %s venceu.\n", equipe1, equipe2);
        } else {
            printf("Resultado invalido.\n");
        }
    }

    // Impressão final
    printf("\n=== Arvore Atualizada (em-ordem) ===\n");
    if (estaVazia_ArvLLRB(raiz)) {
        printf("Arvore vazia.\n");
    } else {
        emOrdem_ArvLLRB(raiz, 0, "");
        printf("\nTotal de equipes: %d\n", totalNO_ArvLLRB(raiz));
        printf("Altura da arvore: %d\n", altura_ArvLLRB(raiz));
    }

    libera_ArvLLRB(raiz);
    return 0;
}
