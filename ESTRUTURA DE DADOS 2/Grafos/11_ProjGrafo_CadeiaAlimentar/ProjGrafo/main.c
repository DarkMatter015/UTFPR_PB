#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

int main(){
    int sementes = 0;
    int pombo = 1;
    int gaviao = 2;
    int nectar = 3;
    int beijaFlor = 4;
    int abelha = 5;
    int joaoDeBarro = 6;
    int bemTeVi = 7;
    int andorinha = 8;

    int eh_digrafo = 1;
    printf("Criado grafo digrafo com 9 vertices, grau maximo 5, nao ponderado.\n");
    Grafo* gr = cria_Grafo(9, 5, 0);

    printf("Inclusao de arestas entre vertices 0, 1, 2, 3, 4, 5, 6, 7, 8 e 9:\n");
    printf("A={{%d,%d},", sementes, pombo);
    insereAresta(gr, sementes, pombo, eh_digrafo, 0);

    printf("{%d,%d},", pombo, gaviao);
    insereAresta(gr, pombo, gaviao, eh_digrafo, 0);

    printf("{%d,%d},", nectar, beijaFlor);
    insereAresta(gr, nectar, beijaFlor, eh_digrafo, 0);

    printf("{%d,%d},", beijaFlor, gaviao);
    insereAresta(gr, beijaFlor, gaviao, eh_digrafo, 0);

    printf("{%d,%d},", nectar, abelha);
    insereAresta(gr, nectar, abelha, eh_digrafo, 0);

    printf("{%d,%d},", abelha, beijaFlor);
    insereAresta(gr, abelha, beijaFlor, eh_digrafo, 0);

    printf("{%d,%d},", abelha, joaoDeBarro);
    insereAresta(gr, abelha, joaoDeBarro, eh_digrafo, 0);

    printf("{%d,%d},", abelha, andorinha);
    insereAresta(gr, abelha, andorinha, eh_digrafo, 0);

    printf("{%d,%d}}\n", bemTeVi, andorinha);
    insereAresta(gr, bemTeVi, andorinha, eh_digrafo, 0);

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
