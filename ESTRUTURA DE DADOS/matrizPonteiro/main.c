#include <stdio.h>
#include <stdlib.h>

// funcao aloca matriz
int **alocaMatriz(int nLinhas, int nColunas){

    int **m, l;
    // aloca memoria para um vetor com um ponteiro para cada linha

    m = malloc(nLinhas * sizeof(int*));
    // cada ponteiro aponta para uma linha

    for (l = 0; l < nLinhas; l++){
        m[l] = calloc(nColunas, sizeof(int)); // matriz de 0s
    }

    return m;
}

// funcao imprime matriz
void imprime(int **m, int nLinhas, int nColunas){

    for(int l = 0; l < nLinhas; l++){
        for(int c = 0; c < nColunas; c++){
            printf("%d\t", m[l][c]); // ou (*(*m+l)+c)
        }
        printf("\n");
    }
}

// funcao libera matriz da memoria
void liberaMatriz(int **m, int nLinhas){

    for(int l = 0; l < nLinhas; l++){
        free(m[l]); // libera os vetores inteiros/colunas apontadas em cada linha
    }
    free(m); // libera o vetor principal que contem as linhas
}

int main()
{
    int nLinhas = 4;
    int nColunas = 5;
    int **m = alocaMatriz(nLinhas, nColunas);
    imprime(m, nLinhas, nColunas);
    liberaMatriz(m, nLinhas);
    return 0;
}
