#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

int main(){
    int eh_digrafo = 0;

    int antonina = 0;
    int paranagua = 1;
    int morretes = 2;
    int pontalDoParana = 3;
    int guaratuba = 4;

    printf("Criado grafo digrafo com 5 vertices, grau maximo 5, nao ponderado.\n");
    Grafo* gr = cria_Grafo(5, 4, 1);

    printf("Inclusao de arestas entre vertices 1, 2, 3, 4 e 5:\n");
    printf("A={{%d,%d},", antonina, paranagua);
    insereAresta(gr, antonina, paranagua, eh_digrafo, 20);

    printf("{%d,%d},", antonina, morretes);
    insereAresta(gr, antonina, morretes, eh_digrafo, 15);

    printf("{%d,%d},", paranagua, morretes);
    insereAresta(gr, paranagua, morretes, eh_digrafo, 25);

    printf("{%d,%d},", paranagua, pontalDoParana);
    insereAresta(gr, paranagua, pontalDoParana, eh_digrafo, 35);

    printf("{%d,%d},", morretes, pontalDoParana);
    insereAresta(gr, morretes, pontalDoParana, eh_digrafo, 40);

    printf("{%d,%d},", morretes, guaratuba);
    insereAresta(gr, morretes, guaratuba, eh_digrafo, 60);

    printf("{%d,%d}}\n", pontalDoParana, guaratuba);
    insereAresta(gr, pontalDoParana, guaratuba, eh_digrafo, 50);

    imprime_Grafo(gr);
//
//    printf("\nRemocao de aresta que une vertices 1 e 3: \n");
//    removeAresta(gr, 1, 3, 0);
//    imprime_Grafo(gr);

    int vis[5];
    int chave = 4; //chave para busca
    printf("\n\n.......\nSimulacao de busca em largura de vertice 4 (Guaratuba) a partir do Vertice 0 (Antonina):\n");
    buscaLargura_Grafo(gr, 0, vis, chave);

    libera_Grafo(gr);
    return 0;
}
