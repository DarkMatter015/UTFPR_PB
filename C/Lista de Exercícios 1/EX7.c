/*
Problema: Resolva as seguintes expressões matemáticas. X e Y são valores fornecidos pelo usuário. Calcule e
mostre o resultado de cada expressão. Reutilize variáveis, ou seja, terá apenas uma variável para armazenar
os resultados do tipo int e outra para armazenar o resultado do tipo float. Faz a primeira operação e já
imprime o resultado e assim para todas as demais operações. Atenção para os resultados que podem ser
valores float e para a prioridade dos operadores.
*/

#include <stdio.h>

int main(void){

    // declaração de variáveis do tipo float (número quebrado)
    int x, y, resInt;
    float resFloat;

    // entrada de dados
    printf("Informe o valor para X: ");
    scanf("%d", &x);

    printf("Informe o valor para Y: ");
    scanf("%d", &y);

    // processamento de dados
    resFloat = (x + y) / (float)y * (x * x);

    // saida de dados
    printf("\na) %f", resFloat);


    // processamento de dados
    resFloat = (x + y) / (float)(x - y);

    // saida de dados
    printf("\nb) %f", resFloat);

    // processamento de dados
    resFloat = (x * x + y * y * y) / (float)2;

    // saida de dados
    printf("\nc) %f", resFloat);

    // processamento de dados
    resFloat = x * x * x / (float)(x * x);

    // saida de dados
    printf("\nd) %f", resFloat);

    // processamento de dados
    resInt = x % y;

    // saida de dados
    printf("\ne1) %d", resInt);

    // processamento de dados
    resInt = x % 3;

    // saida de dados
    printf("\ne2) %d", resInt);

    // processamento de dados
    resInt = y % 5;

    // saida de dados
    printf("\ne3) %d", resInt);

    return 0;
}
