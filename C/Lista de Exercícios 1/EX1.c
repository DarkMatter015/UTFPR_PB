/*
Problema: Escreva um programa que leia o valor de uma prestação e da taxa de juros cobrada pelo atraso da
prestação e forneça o valor atualizado.
*/

#include <stdio.h>

int main(void){

    // declaração de variáveis do tipo float (número quebrado)
    float comprimento, largura, altura, volume;

    // entrada de dados
    printf("Informe o comprimento: ");
    scanf("%f", &comprimento);

    printf("Informe a largura: ");
    scanf("%f", &largura);

    printf("Informe a altura: ");
    scanf("%f", &altura);

    // processamento de dados
    volume = comprimento * largura * altura;

    // saida de dados
    printf("Volume: %.2f cm3", volume);

    return 0;
}
