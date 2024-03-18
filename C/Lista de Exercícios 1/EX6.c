/*
Problema: Leia dois valores A e B e efetue a troca do conteúdo das duas variáveis lidas, de forma que a variável A
passe a ter o valor de B e a variável B o valor de A. Mostre o conteúdo das variáveis antes e depois da troca.
*/

#include <stdio.h>

int main(void){

    // declaração de variáveis do tipo float (número quebrado)
    int a, b, aux;

    // entrada de dados
    printf("Informe o valor de A: ");
    scanf("%d", &a);

    printf("Informe o valor de B: ");
    scanf("%d", &b);

    // saida de dados
    printf("\nAntes da troca: A=%d e B=%d", a, b);

    // processamento de dados
    aux = a;

    a = b;

    b = aux;

    // saida de dados
    printf("\nDepois da troca: A=%d e B=%d", a, b);


    return 0;
}
