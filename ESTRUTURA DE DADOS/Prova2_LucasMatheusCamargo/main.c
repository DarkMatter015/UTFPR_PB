#include <stdio.h>
#include <stdlib.h>
#include "cartao.h"

int main()
{

    int opcao;
    Fila *f = criaFilaVazia();
    do{


        printf("\n----- Catalogo de Pagamentos Cartao -----\n");
        printf("1. Inserir novo pagamento\n");
        printf("2. Excluir Pagamento\n");
        printf("3. Imprimir todos os pagamentos cadastrados\n");
        printf("4. Destruir todos os registros\n");
        printf("5. Calcular total de pagamentos via credito\n");
        printf("6. Sair\n");
        printf("----------------------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);


        int dia, mes, ano, tipoPagamento;
        float valor;
        char descricao[30];

        switch(opcao){
            case 1:

                printf("Qual o dia do registro: ");
                scanf("%d", &dia);
                printf("Qual o mes do registro: ");
                scanf("%d", &mes);
                printf("Qual o ano do registro: ");
                scanf("%d", &ano);
                printf("Qual o valor: R$ ");
                scanf("%f", &valor);
                printf("Descricao: ");
                fflush(stdin);
                gets(descricao);
                printf("Qual o tipo de pagamento(1 - Debito, 2 - credito): ");
                scanf("%d", &tipoPagamento);

                enfileira(f, dia, mes, ano, valor, descricao, tipoPagamento);
                break;

            case 2:
                printf("\nEXCLUINDO ULTIMO PAGAMENTO REALIZADO\n");
                desenfileira(f);
                break;

            case 3:
                printf("\n=== PAGAMENTOS REALIZADOS ===\n");
                imprimeFila(f);
                break;

            case 4:
                printf("\n==== DESTRUINDO TODOS OS PAGAMENTOS ===\n");
                exclusaoRegistros(f);
                break;

            case 5:

                printf("\nDigite um mes para filtrar: ");
                scanf("%d", mes);

                printf("\n=== TOTAL DE PAGAMENTOS VIA CREDITO ===\n");
                printf("Total: R$ %f", totalGastoCreditoRecursivo(f, mes));
                break;

            default:
                break;
        }
    }while(opcao != 6);

    return 0;
}
