#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ItemDequeEnc.h"

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    Deque* bucket_list = cria_Deque();
    Deque* realizadas = cria_Deque();
    int opcao, id, ano;
    char descricao[100], categoria[50], situacao[20];

    do {
        printf("\n=== Bucket List ===\n");
        printf("1. Inserir novo elemento\n");
        printf("2. Excluir elemento\n");
        printf("3. Buscar elemento\n");
        printf("4. Imprimir todos os elementos\n");
        printf("5. Copiar elementos realizados\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        clearBuffer();

        switch (opcao) {
            case 1:
                printf("ID: ");
                scanf("%d", &id);
                clearBuffer();
                printf("Descrição: ");
                fgets(descricao, 100, stdin);
                descricao[strcspn(descricao, "\n")] = 0;
                printf("Categoria: ");
                fgets(categoria, 50, stdin);
                categoria[strcspn(categoria, "\n")] = 0;
                printf("Ano: ");
                scanf("%d", &ano);
                clearBuffer();
                printf("Situação (Realizada/Em andamento/A realizar): ");
                fgets(situacao, 20, stdin);
                situacao[strcspn(situacao, "\n")] = 0;

                if (insereFinal_Deque(bucket_list, id, descricao, categoria, ano, situacao)) {
                    printf("Elemento inserido com sucesso!\n");
                } else {
                    printf("Erro: ID já existe!\n");
                }
                break;

            case 2:
                printf("ID do elemento a excluir: ");
                scanf("%d", &id);
                clearBuffer();
                if (removePorID_Deque(bucket_list, id)) {
                    printf("Elemento excluído com sucesso!\n");
                } else {
                    printf("Elemento não encontrado ou deque vazia!\n");
                }
                break;

            case 3:
                printf("ID do elemento a buscar: ");
                scanf("%d", &id);
                clearBuffer();
                Item* item = busca_Deque(bucket_list, id);
                imprimeItem_Deque(item); // Use the new function to print item
                break;

            case 4:
                printf("\nElementos na Bucket List:\n");
                imprime_Deque(bucket_list);
                break;

            case 5:
                libera_Deque(realizadas);
                realizadas = cria_Deque();
                copiaRealizadas_Deque(bucket_list, realizadas);
                printf("\nElementos realizados copiados:\n");
                imprime_Deque(realizadas);
                break;

            case 6:
                libera_Deque(bucket_list);
                libera_Deque(realizadas);
                printf("Programa encerrado.\n");
                break;

            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 6);

    return 0;
}
