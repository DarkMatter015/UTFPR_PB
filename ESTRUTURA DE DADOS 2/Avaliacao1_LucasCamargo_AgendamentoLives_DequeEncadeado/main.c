#include <stdio.h>
#include <stdlib.h>
#include "itemDeque.h"

int main()
{
    int opcao, chave, duracao, plataforma_transmissao;
    char data_transmissao[10], titulo[20], apresentador[20];

    Deque* dq;

    do{
        printf("\n=== Agendamento de Lives ===\n");
            printf("0. Criar novo deque (NECESSARIO NO INICIO DO PROGRAMA!)\n");
            printf("1. Inserir nova live no inicio\n");
            printf("2. Inserir nova live no final\n");
            printf("3. Excluir elemento do inicio\n");
            printf("4. Excluir elemento do final\n");
            printf("5. Buscar elemento\n");
            printf("6. Imprimir todos os elementos\n");
            printf("7. Calcular quantidades de lives por plataforma\n");
            printf("8. Destruir dados das lives(Liberar Deque)\n");
            printf("9. Sair\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &opcao);
            fflush(stdin);

        switch(opcao){
        case 0:
            dq = cria_Deque();
            break;
        case 1:
            printf("CHAVE: ");
            scanf("%d", &chave);
            fflush(stdin);
            printf("Data da Transmissao: ");
            scanf("%s", data_transmissao);
            fflush(stdin);
            printf("Titulo: ");
            scanf("%s", titulo);
            fflush(stdin);
            printf("Apresentador: ");
            scanf("%s", apresentador);
            fflush(stdin);
            printf("Duracao(horas): ");
            scanf("%d", &duracao);
            printf("Plataforma de Transmissao (1- Youtube, 2- Facebook, 3- Instagram): ");
            scanf("%d", &plataforma_transmissao);

            insereInicio_Deque(dq, chave, data_transmissao, titulo, apresentador, duracao, plataforma_transmissao);
            printf("Elemento inserido com sucesso!\n");
            break;
        case 2:
            printf("CHAVE: ");
            scanf("%d", &chave);
            fflush(stdin);
            printf("Data da Transmissao: ");
            scanf("%s", data_transmissao);
            fflush(stdin);
            printf("Titulo: ");
            scanf("%s", titulo);
            fflush(stdin);
            printf("Apresentador: ");
            scanf("%s", apresentador);
            fflush(stdin);
            printf("Duracao(horas): ");
            scanf("%d", &duracao);
            printf("Plataforma de Transmissao (1- Youtube, 2- Facebook, 3- Instagram): ");
            scanf("%d", &plataforma_transmissao);

            insereFinal_Deque(dq, chave, data_transmissao, titulo, apresentador, duracao, plataforma_transmissao);
            printf("Elemento inserido com sucesso!\n");
            break;
        case 3:
            printf("Excluindo live do inicio...");
            removeInicio_Deque(dq);
            printf("\nRemovido com sucesso!");
            break;
        case 4:
            printf("Excluindo live do final...");
            removeFinal_Deque(dq);
            printf("\nRemovido com sucesso!");
            break;
        case 5:
            printf("CHAVE da live a buscar: ");
            scanf("%d", &chave);
            LucasEventoLive* live = busca_Deque(dq, chave);
            imprimeLive_Deque(live);
            break;
        case 6:
            printf("\nLives:\n");
                imprime_Deque(dq);
            break;
        case 7:
            contabilizaLives(dq);
            break;
        case 8:
            libera_Deque(dq);
            break;
        default:
            printf("Opção inválida!\n");
        }

    }while(opcao != 9);
    return 0;
}
