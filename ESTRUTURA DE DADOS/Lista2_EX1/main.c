#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pedido.h"

int main() {
    Deque *meuDeque = cria_deque();
    int opcao, id;
    float custo;
    char descricao[50];

    do {
        printf("\nMenu:\n");
        printf("1. Inserir pedido\n");
        printf("2. Consultar pedidos por mesa\n");
        printf("3. Excluir pedidos por mesa\n");
        printf("4. Classificar e inserir pedido\n");
        printf("5. Filtrar pedidos por mesa\n");
        printf("6. Calcular total dos pedidos\n");
        printf("7. Imprimir todos os pedidos\n");
        printf("8. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o ID (mesa): ");
                scanf("%d", &id);
                printf("Digite a descricao do pedido: ");
                getchar(); // Limpa o buffer do teclado
                fgets(descricao, sizeof(descricao), stdin);
                descricao[strcspn(descricao, "\n")] = '\0'; // Remove o caractere '\n' do final
                printf("Digite o custo do pedido: ");
                scanf("%f", &custo);
                if (insereFinalDeque(meuDeque, id, descricao, custo)) {
                    printf("Pedido adicionado com sucesso!\n");
                } else {
                    printf("Erro ao adicionar pedido.\n");
                }
                break;
            case 2:
                printf("Digite o ID da mesa: ");
                scanf("%d", &id);
                consultaMesa(meuDeque, id);
                break;
            case 3:
                printf("Digite o ID da mesa: ");
                scanf("%d", &id);
                excluiMesa(meuDeque, id);
                break;
            case 4:
                printf("Digite o ID (mesa): ");
                scanf("%d", &id);
                printf("Digite a descricao do pedido: ");
                getchar(); // Limpa o buffer do teclado
                fgets(descricao, sizeof(descricao), stdin);
                descricao[strcspn(descricao, "\n")] = '\0'; // Remove o caractere '\n' do final
                printf("Digite o custo do pedido: ");
                scanf("%f", &custo);
                classificaPedido(meuDeque, id, descricao, custo);
                printf("Pedido classificado e adicionado!\n");
                break;
            case 5:
                printf("Digite o ID da mesa: ");
                scanf("%d", &id);
                Deque *novaDeque = filtraPedidosPorMesa(meuDeque, id);
                printf("Pedidos filtrados para a mesa %d:\n", id);
                imprimeDeque(novaDeque);
                liberaDeque(novaDeque);
                break;
            case 6:
                calculaTotalDeque(meuDeque);
                break;
            case 7:
                imprimeDeque(meuDeque);
                break;
            case 8:
                liberaDeque(meuDeque);
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 8);

    return 0;
}
