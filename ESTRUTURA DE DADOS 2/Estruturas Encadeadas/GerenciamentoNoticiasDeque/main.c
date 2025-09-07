#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dequeNoticia.h"

void exibeMenu() {
    printf("\n=== Sistema de Gerenciamento de Notícias ===\n");
    printf("1. Adicionar notícia no início (prioritária)\n");
    printf("2. Adicionar notícia no final (ordem de chegada)\n");
    printf("3. Remover notícia do início\n");
    printf("4. Remover notícia do final\n");
    printf("5. Imprimir notícias\n");
    printf("6. Analisar classificações\n");
    printf("7. Sair\n");
    printf("Escolha uma opção: ");
}

int main() {
    Deque *dq = cria_Deque();
    int opcao, id_noticia = 1;
    char titulo[100], autor[50], classificacao[30];

    // Adicionando 4 notícias iniciais
    /*printf("Inicializando com 4 notícias de exemplo...\n");
    insereInicio_Deque(dq, "Novo Produto Lançado", "Ana Costa", "Lançamentos", id_noticia++);
    insereFinal_Deque(dq, "Evento Cultural Interno", "João Silva", "Cultura", id_noticia++);
    insereInicio_Deque(dq, "Atualização de Software", "Maria Oliveira", "Novidades", id_noticia++);
    insereFinal_Deque(dq, "Treinamento de Equipe", "Pedro Santos", "Cultura", id_noticia++);
    imprime_Deque(dq); */

    do {
        exibeMenu();
        scanf("%d", &opcao);
        fflush(stdin);

        switch (opcao) {
            case 1: // Adicionar no início
                printf("Digite o título da notícia: ");
                scanf("%s[^\n]", titulo);
                fflush(stdin);
                printf("Digite o nome do autor: ");
                scanf("%s[^\n]", autor);
                fflush(stdin);
                printf("Digite a classificação (ex.: Novidades, Cultura, Lançamentos): ");
                scanf("%s[^\n]", classificacao);
                fflush(stdin);
                insereInicio_Deque(dq, titulo, autor, classificacao, id_noticia++);
                printf("Notícia adicionada no início com sucesso!\n");
                break;

            case 2: // Adicionar no final
                printf("Digite o título da notícia: ");
                scanf("%s[^\n]", titulo);
                fflush(stdin);
                printf("Digite o nome do autor: ");
                scanf("%s[^\n]", autor);
                fflush(stdin);
                printf("Digite a classificação (ex.: Novidades, Cultura, Lançamentos): ");
                scanf("%s[^\n]", classificacao);
                fflush(stdin);
                insereFinal_Deque(dq, titulo, autor, classificacao, id_noticia++);
                printf("Notícia adicionada no final com sucesso!\n");
                break;

            case 3: // Remover do início
                removeInicio_Deque(dq);
                break;

            case 4: // Remover do final
                removeFinal_Deque(dq);
                break;

            case 5: // Imprimir deque
                imprime_Deque(dq);
                break;

            case 6: // Analisar classificações
                analisaClassificacoes(dq);
                break;

            case 7: // Sair
                printf("Encerrando o programa e liberando o deque...\n");
                libera_Deque(dq);
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 7);

    return 0;
}
