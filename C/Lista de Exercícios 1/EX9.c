/*
Problema: Um viajante de carro fará o trajeto entre duas cidades e ao término da viagem deseja saber:
a) Quantas vezes foi necessário abastecer o carro (use a função ceil() da biblioteca math.h para arredondar o
valor para cima).
b) Quantos litros foram consumidos para percorrer a distância indicada.
c) Quantos litros restaram no tanque após a chegada ao destino.
Faça um programa que leia a distância entre as duas cidades, a capacidade do tanque e o consumo médio
do veículo, calcule e mostre as informações solicitadas.
*/

#include <stdio.h>

#include <math.h>

int main(void){

    // declaração de variáveis do tipo float (número quebrado)
    float distancia, tanque, consumoMedio, litrosNecessario, n_abastecimento;

    // entrada de dados
    printf("Informe a distancia (em Km) percorrida entre as cidades: ");
    scanf("%f", &distancia);

    printf("Informe a capacidade maxima do tanque de combustivel do veiculo: ");
    scanf("%f", &tanque);

    printf("Informe o consumo medio (em Km por litro) do veiculo: ");
    scanf("%f", &consumoMedio);

    // processamento de dados
    litrosNecessario = distancia / consumoMedio;

    // saida de dados
    printf("\nForam necesarios %.1f litros de combustivel para percorrer o trajeto.\n", litrosNecessario);

    // processamento de dados
    n_abastecimento = litrosNecessario / tanque;

    // saida de dados
    printf("\nForam necesario abastecer o veiculo %.0f vezes.\n", ceil(n_abastecimento));

    // processamento de dados
    tanque = tanque * ceil(n_abastecimento) - litrosNecessario;

    // saida de dados
    printf("\nRestou no tanque de combustivel %.1f litros.\n", tanque);

    return 0;
}
