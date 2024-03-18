/*
Problema: Tendo como entrada dois valores inteiros, elaborar um programa para calcular e mostrar:
a) A soma desses valores;
b) A subtração do primeiro pelo segundo;
c) A multiplicação entre eles;
d) A divisão inteira do primeiro pelo segundo;
e) A divisão float do primeiro pelo segundo;
f) O resto da divisão do primeiro pelo segundo.
*/

#include <stdio.h>

int main(void){

    // declaração de variáveis do tipo float (número quebrado)
    int valor1, valor2, resInt;
    float resFloat;

    // entrada de dados
    printf("Informe o primeiro valor: ");
    scanf("%d", &valor1);

    printf("Informe o segundo valor: ");
    scanf("%d", &valor2);

    // processamento de dados
    resInt = valor1 + valor2;

    // saida de dados
    printf("%d + %d = %d", valor1, valor2, resInt);

    // processamento de dados
    resInt = valor1 - valor2;

    // saida de dados
    printf("\n%d - %d = %d", valor1, valor2, resInt);

    // processamento de dados
    resInt = valor1 * valor2;

    // saida de dados
    printf("\n%d * %d = %d", valor1, valor2, resInt);

    // processamento de dados
    resInt = valor1 / valor2;

    // saida de dados
    printf("\n%d / %d = %d", valor1, valor2, resInt);

    // processamento de dados
    resFloat = (float)valor1 / valor2;

    // saida de dados
    printf("\n%d / %d = %.2f", valor1, valor2, resFloat);

    // processamento de dados
    resInt = valor1 % valor2;

    // saida de dados
    printf("\n%d %% %d = %d", valor1, valor2, resInt);

    return 0;
}
