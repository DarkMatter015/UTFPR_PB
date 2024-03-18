/*
Problema: Calcular o valor do salário líquido de uma pessoa. Sobre o salário bruto incidem descontos de INSS e
imposto de renda.
*/

#include <stdio.h>

int main(void){

    // declaração de variáveis do tipo float (número quebrado)
    float salBruto, salLiquido, inss, ir;

    // entrada de dados
    printf("Informe o valor do salario bruto: R$ ");
    scanf("%f", &salBruto);

    printf("Informe o percentual de INSS: ");
    scanf("%f", &inss);

    printf("Informe o percentual de IR: ");
    scanf("%f", &ir);

    // processamento de dados
    inss /= 100;

    ir /= 100;

    salLiquido = salBruto - (salBruto * inss + salBruto * ir);

    // saida de dados
    printf("Salario liquido: R$ %.2f", salLiquido);


    return 0;
}
