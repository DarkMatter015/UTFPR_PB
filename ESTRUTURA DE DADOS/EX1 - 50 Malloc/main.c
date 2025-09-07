// 1) Crie um vetor do tipo inteiro com 50 itens valorizados aleatoriamente usando a função
// malloc. Percorra o vetor imprimindo endereço e valor de cada item.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vNumeros[50];

    int *p = malloc(50 * sizeof(int));


    for(int i = 0; i < 50; i++){
        vNumeros[i] = rand() % 100 + 1;
    }

    for(int i = 0; i < 50; i++){
        p[i] = &vNumeros[i];
    }

    for(int i = 0; i < 50; i++){
        printf("\nValor: %d, Memoria: %ld, P: %ld", vNumeros[i], &vNumeros[i], p[i]);
    }

    return 0;
}
