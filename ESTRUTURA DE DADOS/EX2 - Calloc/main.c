// 2) Repetir o exercício anterior usando a função calloc em vez de malloc, e inserindo o seu
// RA como conteúdo dos itens.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vNumeros[50];

    int *p = calloc(50, sizeof(int));


    for(int i = 0; i < 50; i++){
        vNumeros[i] = 2661934;
    }

    for(int i = 0; i < 50; i++){
        p[i] = &vNumeros[i];
    }

    for(int i = 0; i < 50; i++){
        printf("\nValor: %d, Memoria: %ld, P: %ld", vNumeros[i], &vNumeros[i], p[i]);
    }

    return 0;
}
