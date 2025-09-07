#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaArvore.h"

int main() {
    Lista *lst = criaListaVazia();
    int id_arvore = 1;
    char regiao[50], especie[50], continuar_regiao, continuar_cadastro;
    int quantidade;

    do {
        printf("Informe a região que está sendo inventariada: ");
        scanf("%s[^\n]", regiao);
        fflush(stdin);

        do {
            printf("Informe a espécie de árvore que irá compor o inventário: ");
            scanf("%s[^\n]", especie);
            fflush(stdin);
            printf("Informe a quantidade de árvores desta espécie que foram identificadas: ");
            scanf("%d", &quantidade);
            fflush(stdin);

            Celula *existente = buscaPorEspecieRegiao(lst, regiao, especie);
            if (existente != NULL) {
                atualizaQuantidade(lst, regiao, especie, quantidade);
            } else {
                insereFimLista(lst, regiao, especie, quantidade, id_arvore++);
            }

            printf("Deseja armazenar mais dados para essa região? (S/N): ");
            scanf("%c", &continuar_regiao);
            fflush(stdin);
        } while (continuar_regiao == 'S' || continuar_regiao == 's');

        printf("Deseja armazenar dados de outra região? (S/N): ");
        scanf("%c", &continuar_cadastro);
        fflush(stdin);
    } while (continuar_cadastro == 'S' || continuar_cadastro == 's');

    char opcao;
    do {
        printf("\n=== Menu de Opções ===\n");
        printf("1. Desfazer último cadastro\n");
        printf("2. Exibir inventário\n");
        printf("3. Analisar porcentagens\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%c", &opcao);
        fflush(stdin);

        switch (opcao) {
            case '1':
                removeFimLista(lst);
                break;
            case '2':
                imprimeLista(lst);
                break;
            case '3':
                analisaPorcentagens(lst);
                break;
            case '4':
                printf("Encerrando o programa e liberando a lista...\n");
                liberaLista(lst);
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != '4');

    return 0;
}
