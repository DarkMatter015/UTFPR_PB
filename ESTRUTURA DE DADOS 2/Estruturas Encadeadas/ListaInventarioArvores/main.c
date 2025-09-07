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
        printf("Informe a regi�o que est� sendo inventariada: ");
        scanf("%s[^\n]", regiao);
        fflush(stdin);

        do {
            printf("Informe a esp�cie de �rvore que ir� compor o invent�rio: ");
            scanf("%s[^\n]", especie);
            fflush(stdin);
            printf("Informe a quantidade de �rvores desta esp�cie que foram identificadas: ");
            scanf("%d", &quantidade);
            fflush(stdin);

            Celula *existente = buscaPorEspecieRegiao(lst, regiao, especie);
            if (existente != NULL) {
                atualizaQuantidade(lst, regiao, especie, quantidade);
            } else {
                insereFimLista(lst, regiao, especie, quantidade, id_arvore++);
            }

            printf("Deseja armazenar mais dados para essa regi�o? (S/N): ");
            scanf("%c", &continuar_regiao);
            fflush(stdin);
        } while (continuar_regiao == 'S' || continuar_regiao == 's');

        printf("Deseja armazenar dados de outra regi�o? (S/N): ");
        scanf("%c", &continuar_cadastro);
        fflush(stdin);
    } while (continuar_cadastro == 'S' || continuar_cadastro == 's');

    char opcao;
    do {
        printf("\n=== Menu de Op��es ===\n");
        printf("1. Desfazer �ltimo cadastro\n");
        printf("2. Exibir invent�rio\n");
        printf("3. Analisar porcentagens\n");
        printf("4. Sair\n");
        printf("Escolha uma op��o: ");
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
                printf("Op��o inv�lida! Tente novamente.\n");
        }
    } while (opcao != '4');

    return 0;
}
