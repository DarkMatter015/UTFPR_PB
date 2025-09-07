#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ItemFilaEnc.h"
#include "Data.h"

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    Fila* eventos = criaFilaVazia();
    int opcao, id, dia, mes, ano;
    char nome[100], hora[10], descricao[200];

    printf("Criando fila vazia.\n");
    int vazia = verificaFilaVazia(eventos);
    printf("Fila vazia? %d.\n", vazia);

    do {
        printf("\n=== Controle de Inscri��es em Eventos ===\n");
        printf("1. Inserir nova inscri��o\n");
        printf("2. Excluir inscri��o\n");
        printf("3. Imprimir todas as inscri��es\n");
        printf("4. Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);
        clearBuffer();

        switch (opcao) {
            case 1:
                printf("ID do participante: ");
                scanf("%d", &id);
                clearBuffer();
                printf("Nome do participante: ");
                fgets(nome, 100, stdin);
                nome[strcspn(nome, "\n")] = 0;
                printf("Data do evento (dd mm aaaa): ");
                scanf("%d %d %d", &dia, &mes, &ano);
                clearBuffer();
                Data* dataEvento = dataNova(dia, mes, ano);
                if (dataEvento == NULL) {
                    printf("Erro: Falha ao criar data do evento!\n");
                    break;
                }
                printf("Hora do evento (HH:MM): ");
                fgets(hora, 10, stdin);
                hora[strcspn(hora, "\n")] = 0;
                printf("Descri��o do evento: ");
                fgets(descricao, 200, stdin);
                descricao[strcspn(descricao, "\n")] = 0;

                printf("\nAdicionando inscri��o na fila.\n");
                if (insereFila(eventos, id, nome, dataEvento, hora, descricao)) {
                    printf("Inscri��o registrada com sucesso!\n");
                } else {
                    liberarData(dataEvento);
                    printf("Erro: Falha ao registrar inscri��o!\n");
                }
                vazia = verificaFilaVazia(eventos);
                printf("Fila vazia? %d.\n", vazia);
                break;

            case 2:
                printf("\nRemovendo inscri��o do in�cio da fila.\n");
                removeInicioFila(eventos);
                break;

            case 3:
                printf("\nInscri��es Registradas:\n");
                imprimeFila(eventos);
                break;

            case 4:
                printf("\nLiberando fila.\n");
                liberaFila(eventos);
                printf("Programa encerrado.\n");
                break;

            default:
                printf("Op��o inv�lida!\n");
        }
    } while (opcao != 4);

    return 0;
}
