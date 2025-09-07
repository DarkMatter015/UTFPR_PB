#include <stdio.h>
#include <stdlib.h>
#include "LucasMatheusCamargo.h"

int main()
{
    Partida* partidas;
    int nPartidas = 0;
    char continuar;
    char jogador1[50], jogador2[50], vencedor[50];
    int tempo, dia, mes, ano;

    do {
        printf("\nDigite os dados da nova partida:\n");

        printf("Jogador 1: ");
        scanf("%s", jogador1);

        printf("Jogador 2: ");
        scanf("%s", jogador2);

        printf("Informe a data da partida (dia mes ano): ");
        scanf("%d %d %d", &dia, &mes, &ano);

        // Criando a data para a partida
        Data *data = dataNova(dia, mes, ano);

        // Vetor para armazenar as jogadas da partida atual
        Jogada* vetJogadas = NULL;
        int nJogadas = 0;

        int jogador = 1;
        char cor = 'B';
        char peca, movimento[3];

        // Loop para registrar jogadas até o usuário parar
        do {
            printf("\nJogador %d - Cor: %c\n", jogador, cor);
            printf("Informe a peça movida (T, R, D, B, C ou vazio para peão): ");
            scanf(" %c", &peca);

            printf("Informe o movimento (ex: e2, 0-0, f8D): ");
            scanf("%s", movimento);

            // Insere a jogada no vetor de jogadas
            vetJogadas = insereJogada(vetJogadas, jogador, cor, peca, movimento, &nJogadas);

            // Alterna o jogador e a cor
            jogador = (jogador == 1) ? 2 : 1;
            cor = (cor == 'B') ? 'P' : 'B';

            printf("Deseja inserir outra jogada? (s/n): ");
            scanf(" %c", &continuar);

        } while (continuar == 's' || continuar == 'S');

        // Pergunta o vencedor e o tempo após o término das jogadas
        printf("\nQuem foi o vencedor da partida? (Jogador 1 ou Jogador 2): ");
        scanf("%s", vencedor);

        printf("Tempo de jogo (em minutos): ");
        scanf("%d", &tempo);

        // Insere a partida com todos os dados e jogadas registradas
        partidas = inserePartida(partidas, data, jogador1, jogador2, vencedor, tempo, vetJogadas, nJogadas, &nPartidas);

        // Libera o vetor de jogadas para a próxima partida
        vetJogadas = NULL;
        nJogadas = 0;

        printf("Deseja registrar outra partida? (s/n): ");
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 'S');

    // Imprime todas as partidas registradas
    imprimirPartidas(partidas, nPartidas);

    // Libera a memória alocada para as partidas e suas jogadas
    liberarPartidas(partidas, nPartidas);

    return 0;
}
