#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

int main(){
    int jogadores = 0;
    int times = 1;
    int nacionalidades = 2;
    int partidas = 3;
    int localizacao = 4;

    int eh_digrafo = 1;
    printf("Criado grafo digrafo com 9 vertices, grau maximo 5, nao ponderado.\n");
    Grafo* gr = cria_Grafo(5, 5, 0);

    printf("Inclusao de arestas entre vertices 0, 1, 2, 3, 4 e 5:\n");
    printf("A={{%d,%d},", jogadores, times);
    insereAresta(gr, jogadores, times, eh_digrafo, 0);

    printf("A={{%d,%d},", jogadores, nacionalidades);
    insereAresta(gr, jogadores, nacionalidades, eh_digrafo, 0);

    printf("A={{%d,%d},", jogadores, jogadores);
    insereAresta(gr, jogadores, jogadores, eh_digrafo, 0);

    printf("A={{%d,%d},", times, nacionalidades);
    insereAresta(gr, times, nacionalidades, eh_digrafo, 0);

    printf("A={{%d,%d},", partidas, nacionalidades);
    insereAresta(gr, partidas, nacionalidades, eh_digrafo, 0);

    printf("A={{%d,%d}}\n", partidas, localizacao);
    insereAresta(gr, partidas, localizacao, eh_digrafo, 0);

    imprime_Grafo(gr);
//
//    printf("\nRemocao de aresta que une vertices 1 e 3: \n");
//    removeAresta(gr, 1, 3, 0);
//    imprime_Grafo(gr);

    int vis[5];
    int chave = 2; //chave para busca
    printf("\n\n.......\nSimulacao de busca em largura a partir do Vertice 0:\n");
    buscaLargura_Grafo(gr, 0, vis, chave);

    printf("\n\n.......\nSimulacao de busca em profundidade a partir do Vertice 0:\n");
    buscaProfundidade_Grafo(gr, 0, vis, chave);

    printf("\n\n.......\nSimulacao de busca pelo menor caminho a partir do Vertice 0:\n");
    int i,ant[5];
    float dist[5];
    menorCaminho_Grafo(gr, 0, ant, dist, chave);
    for(i=0; i<5; i++)
    {
        printf(".Ate o Vertice %d: Anterior %d -> distancia : %f\n",i,ant[i],dist[i]);
    }

    printf("\n\n.......\nSimulacao de busca pelo menor caminho a partir do Vertice 2:\n");
    menorCaminho_Grafo(gr, 2, ant, dist, chave);
    for(i=0; i<5; i++)
    {
        printf(".Ate o Vertice %d: Anterior %d -> distancia : %f\n",i,ant[i],dist[i]);
    }

    libera_Grafo(gr);
    return 0;
}
