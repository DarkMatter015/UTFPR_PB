#include <stdio.h>
#include <stdlib.h>

int fatorialIterativo(int n){
    int fat = n;

    for(int i = n-1; i > 0; i--){
        fat *= i;
    }

    return fat;
}

int fatorialRecursivo(int n){
    if(n == 1){ // condicao de parada

        return 1; // caso base
    }
    else{

        for(int i = n; i > 0; i--){

            return n * fatorialRecursivo(n-1); // chamada recursiva
        }
    }
}

int main()
{
    printf("Hello world!\n");

    int n = 5;

    printf("\nFat iterativo: %d", fatorialIterativo(n));
    printf("\nFat recursivo: %d", fatorialRecursivo(n));

    return 0;
}
