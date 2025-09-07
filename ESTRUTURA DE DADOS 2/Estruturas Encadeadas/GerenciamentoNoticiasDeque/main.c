#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dequeNoticia.h"

void exibeMenu() {
    printf("\n=== Sistema de Gerenciamento de Not�cias ===\n");
    printf("1. Adicionar not�cia no in�cio (priorit�ria)\n");
    printf("2. Adicionar not�cia no final (ordem de chegada)\n");
    printf("3. Remover not�cia do in�cio\n");
    printf("4. Remover not�cia do final\n");
    printf("5. Imprimir not�cias\n");
    printf("6. Analisar classifica��es\n");
    printf("7. Sair\n");
    printf("Escolha uma op��o: ");
}

int main() {
    Deque *dq = cria_Deque();
    int opcao, id_noticia = 1;
    char titulo[100], autor[50], classificacao[30];

    // Adicionando 4 not�cias iniciais
    /*printf("Inicializando com 4 not�cias de exemplo...\n");
    insereInicio_Deque(dq, "Novo Produto Lan�ado", "Ana Costa", "Lan�amentos", id_noticia++);
    insereFinal_Deque(dq, "Evento Cultural Interno", "Jo�o Silva", "Cultura", id_noticia++);
    insereInicio_Deque(dq, "Atualiza��o de Software", "Maria Oliveira", "Novidades", id_noticia++);
    insereFinal_Deque(dq, "Treinamento de Equipe", "Pedro Santos", "Cultura", id_noticia++);
    imprime_Deque(dq); */

    do {
        exibeMenu();
        scanf("%d", &opcao);
        fflush(stdin);

        switch (opcao) {
            case 1: // Adicionar no in�cio
                printf("Digite o t�tulo da not�cia: ");
                scanf("%s[^\n]", titulo);
                fflush(stdin);
                printf("Digite o nome do autor: ");
                scanf("%s[^\n]", autor);
                fflush(stdin);
                printf("Digite a classifica��o (ex.: Novidades, Cultura, Lan�amentos): ");
                scanf("%s[^\n]", classificacao);
                fflush(stdin);
                insereInicio_Deque(dq, titulo, autor, classificacao, id_noticia++);
                printf("Not�cia adicionada no in�cio com sucesso!\n");
                break;

            case 2: // Adicionar no final
                printf("Digite o t�tulo da not�cia: ");
                scanf("%s[^\n]", titulo);
                fflush(stdin);
                printf("Digite o nome do autor: ");
                scanf("%s[^\n]", autor);
                fflush(stdin);
                printf("Digite a classifica��o (ex.: Novidades, Cultura, Lan�amentos): ");
                scanf("%s[^\n]", classificacao);
                fflush(stdin);
                insereFinal_Deque(dq, titulo, autor, classificacao, id_noticia++);
                printf("Not�cia adicionada no final com sucesso!\n");
                break;

            case 3: // Remover do in�cio
                removeInicio_Deque(dq);
                break;

            case 4: // Remover do final
                removeFinal_Deque(dq);
                break;

            case 5: // Imprimir deque
                imprime_Deque(dq);
                break;

            case 6: // Analisar classifica��es
                analisaClassificacoes(dq);
                break;

            case 7: // Sair
                printf("Encerrando o programa e liberando o deque...\n");
                libera_Deque(dq);
                break;

            default:
                printf("Op��o inv�lida! Tente novamente.\n");
        }
    } while (opcao != 7);

    return 0;
}
