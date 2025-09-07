#include <stdio.h>
#include <stdlib.h>

//Fun��o que imprime um vetor ao contr�rio usando abordagem iterativa
void imprimeVetor_Iterativo(int vet[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        printf("%d\t", vet[i]);
    }
}

//Fun��o que imprime um vetor ao contr�rio usando abordagem recursiva
void imprimeVetor_Recursivo(int vet[], int n)
{
    if (n == 0) //Condi��o de parada
    {
        return; //Caso base
    }
    else
    {
        printf("%d\t", vet[n-1]);
        imprimeVetor_Recursivo(vet, n - 1); //Chamada recursiva
    }
}



int main()
{
    int n;
    printf("Informe o numero de elementos desejados para o vetor: ");
    scanf("%d", &n);
    int *vet = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        vet[i] = i; //atribui o valor de i para inserir algum dado no vetor
    }

    printf("\nImpressao de vetor ao contr�rio usando algoritmo iterativo:\n");
    imprimeVetor_Iterativo(vet, n);

    printf("\nImpressao de vetor ao contr�rio usando algoritmo recursivo:\n");
    imprimeVetor_Recursivo(vet, n);

    free(vet);

    return 0;
}
