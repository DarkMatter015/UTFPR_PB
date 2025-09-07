#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filaEnc.h"

void exibeMenu() {
    printf("\n=== Sistema de Gerenciamento de Chamados ===\n");
    printf("1. Adicionar novo chamado\n");
    printf("2. Remover chamado (atender)\n");
    printf("3. Imprimir fila de chamados\n");
    printf("4. Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    Fila *f = criaFilaVazia();
    int opcao, ticket_id = 1;
    char nome[50], problema[100];

    // Adicionando 4 registros iniciais
    /*printf("Inicializando com 4 chamados de exemplo...\n");
    enfileira(f, "Joao Silva", ticket_id++, "Problema com impressora");
    enfileira(f, "Maria Oliveira", ticket_id++, "Erro no software");
    enfileira(f, "Pedro Santos", ticket_id++, "Falha de rede");
    enfileira(f, "Ana Costa", ticket_id++, "Tela azul no Windows");
    imprimeFila(f); */

    do {
        exibeMenu();
        scanf("%d", &opcao);
        fflush(stdin);

        switch (opcao) {
            case 1: // Adicionar novo chamado
                printf("Digite o nome do usuario: ");
                scanf("%s[^\n]", nome);
                fflush(stdin);
                printf("Digite o problema: ");
                scanf("%s[^\n]", problema);
                fflush(stdin);
                enfileira(f, nome, ticket_id++, problema);
                printf("Chamado adicionado com sucesso!\n");
                break;

            case 2: // Remover chamado
                desenfileira(f);
                break;

            case 3: // Imprimir fila
                imprimeFila(f);
                break;

            case 4: // Sair
                printf("Encerrando o programa e liberando a fila...\n");
                liberaFila(f);
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
