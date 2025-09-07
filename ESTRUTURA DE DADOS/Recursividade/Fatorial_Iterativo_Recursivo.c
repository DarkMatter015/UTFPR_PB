#include <stdio.h>
#include <stdlib.h>

//Função de cálculo fatorial usando abordagem iterativa
int fatorialIterativo(int n) {
    int fat = n;
    for (int i = n - 1; i > 0; i--)
    {
        fat *= i;
    }
    return fat;
}

//Função de cálculo de fatorial usando abordagem recursiva
int fatorialRecursivo(int n) {
    if (n == 1) //Condição de parada
    {
        return 1; //Caso base
    }
    else
    {
        return n * fatorialRecursivo(n - 1); //chamada recursiva
    }
}

int main()
{
    int n;
    printf("Informe um numero para calcular o fatorial: ");
    scanf("%d", &n);
    printf("\nFatorial de %d usando algoritmo iterativo: %d", n, fatorialIterativo(n));
    printf("\nFatorial de %d usando algoritmo recursivo: %d", n, fatorialRecursivo(n));
    return 0;
}
