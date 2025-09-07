#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "catalogo.h"

void menu() {
    printf("\n----- Catalogo de Filmes e Series -----\n");
    printf("1. Inserir novo elemento no catalogo\n");
    printf("2. Excluir elemento\n");
    printf("3. Buscar elemento\n");
    printf("4. Imprimir todos os elementos cadastrados\n");
    printf("5. Filtrar por genero\n");
    printf("6. Recomendacao para amigo\n");
    printf("7. Sair\n");
    printf("----------------------------------------\n");
    printf("Escolha uma opcao: ");
}

int main() {
    Pilha *catalogo = criaPilhaVazia();
    int opcao;
    Filme filme;
    char genero[30];
    char email[50];

    do {
        menu();
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer de entrada

        switch (opcao) {
            case 1:
                printf("\n--- Inserir Novo Elemento ---\n");
                printf("Digite o codigo: ");
                scanf("%d", &filme.codigo);
                getchar(); // Limpar o buffer de entrada
                if (buscaPorCodigo(catalogo, filme.codigo) != -1) {
                    printf("Erro: Codigo ja existe no catalogo.\n");
                    break;
                }
                printf("Digite o titulo: ");
                fgets(filme.titulo, sizeof(filme.titulo), stdin);
                filme.titulo[strcspn(filme.titulo, "\n")] = 0; // Remover a nova linha
                printf("Digite o genero: ");
                fgets(filme.genero, sizeof(filme.genero), stdin);
                filme.genero[strcspn(filme.genero, "\n")] = 0; // Remover a nova linha
                printf("Digite a duracao (em minutos): ");
                scanf("%d", &filme.duracao);
                empilha(catalogo, filme);
                break;

            case 2:
                printf("\n--- Excluir Elemento ---\n");
                printf("Digite o codigo do elemento a ser excluido: ");
                scanf("%d", &filme.codigo);
                removeItem(catalogo, filme.codigo);
                break;

            case 3:
                printf("\n--- Buscar Elemento ---\n");
                printf("Digite o codigo do elemento a buscar: ");
                scanf("%d", &filme.codigo);
                int posicao = buscaPorCodigo(catalogo, filme.codigo);
                if (posicao != -1) {
                    printf("Elemento encontrado:\n");
                    printf("Codigo: %d\n", catalogo->vetItens[posicao].codigo);
                    printf("Titulo: %s\n", catalogo->vetItens[posicao].titulo);
                    printf("Genero: %s\n", catalogo->vetItens[posicao].genero);
                    printf("Duracao: %d minutos\n", catalogo->vetItens[posicao].duracao);
                } else {
                    printf("Elemento nao encontrado no catalogo.\n");
                }
                break;

            case 4:
                printf("\n--- Catalogo Completo ---\n");
                imprimePilha(catalogo);
                break;

            case 5:
                printf("\n--- Filtrar por Genero ---\n");
                printf("Digite o genero para filtrar: ");
                fgets(genero, sizeof(genero), stdin);
                genero[strcspn(genero, "\n")] = 0; // Remover a nova linha
                Pilha *catalogoFiltrado = filtraPorGenero(catalogo, genero);
                printf("\nCatalogo Filtrado:\n");
                imprimePilha(catalogoFiltrado);
                liberaPilha(catalogoFiltrado);
                break;

            case 6:
                printf("\n--- Recomendacao para Amigo ---\n");
                printf("Digite o genero para recomendar: ");
                fgets(genero, sizeof(genero), stdin);
                genero[strcspn(genero, "\n")] = 0; // Remover a nova linha
                printf("Digite o email da pessoa para enviar a recomendacao: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0; // Remover a nova linha
                Pilha *catalogoRecomendado = filtraPorGenero(catalogo, genero);
                printf("\nCatalogo recomendado para %s:\n", email);
                imprimePilha(catalogoRecomendado);
                liberaPilha(catalogoRecomendado);
                break;

            case 7:
                printf("\nSaindo do programa...\n");
                break;

            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }
    } while (opcao != 7);

    liberaPilha(catalogo);
    return 0;
}
