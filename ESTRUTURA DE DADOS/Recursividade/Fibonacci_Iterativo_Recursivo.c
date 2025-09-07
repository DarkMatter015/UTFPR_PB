#include <stdio.h>
#include <stdlib.h>

//Função que imprime o n-ésimo termo da série de Fibonacci
//Abordagem iterativa
int fibonacci_Iterativo(int n)
{
    int primeiro = 0, segundo = 1, proximo = 0;
    if (n == 0) //os dois primeiros são fixos (0 e 1)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            proximo = primeiro + segundo;
            primeiro = segundo;
            segundo = proximo;
        }
    }
    return proximo;
}

//Função que imprime o n-ésimo termo da série de Fibonacci
//Abordagem recursiva
int fibonacci_Recursivo(int n)
{
    if (n == 0) //Condição de parada
    {
        return 0; //Caso base
    }
    else if (n == 1) //Condição de parada
    {
        return 1;//Caso base
    }
    else
    {
        //Chamada recursiva dupla
        return fibonacci_Recursivo(n - 1) + fibonacci_Recursivo(n - 2);
    }
}


int main()
{
    //Sequencia: 1,1,2,3,5,8,13,21,34,55,89...
    //Cada termo é formado pela soma dos dois anteriores
    int n;
    printf("Informe qual termo da sequencia de Fibonacci deseja visualizar: ");
    scanf("%d", &n);

    printf("\n%do termo da sequencia de Fibonacci usando\
 algoritmo iterativo: %d\n", n, fibonacci_Iterativo(n));

    printf("\n%do termo da sequencia de Fibonacci usando\
 algoritmo recursivo: %d\n", n, fibonacci_Recursivo(n));

    return 0;
}
