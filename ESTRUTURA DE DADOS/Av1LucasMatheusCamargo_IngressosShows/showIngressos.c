#include <stdio.h>
#include <stdlib.h>
#include "showIngressos.h"


struct showVivoRio {
    int id;
    char comprador[30];
    int dia;
    int mes;
    int ano;
    float valorIngresso;
    int quantidade;
    int setor;
    int meiaEntrada
};

ShowVivoRio *inserirIngresso(ShowVivoRio *vet, int id, char comprador[], int dia, int mes, int ano, float valorIngresso, int quantidade, int setor, int meiaEntrada, int nIngressos) {
    if(nIngressos == 0){
        vet = (ShowVivoRio *) malloc(sizeof(ShowVivoRio));
    }
    else{
        vet = (ShowVivoRio *) realloc(vet, (nIngressos + 1) * sizeof(ShowVivoRio));
    }

    vet[nIngressos].id = id;
    strcpy(vet[nIngressos].comprador, comprador);
    vet[nIngressos].dia = dia;
    vet[nIngressos].mes = mes;
    vet[nIngressos].ano = ano;
    vet[nIngressos].valorIngresso = valorIngresso;
    vet[nIngressos].quantidade = quantidade;
    vet[nIngressos].setor = setor;
    vet[nIngressos].meiaEntrada = meiaEntrada;


    return vet;
}

void imprimeIngressos(ShowVivoRio* vet, int nIngressos) {
    printf("Ingressos adquirirdos para o show:\n");
    for (int i = 0; i <= nIngressos; i++) {
        printf("ID %d - Comprador: %s - Data do Evento: %d/%d/%d - Valor do Ingresso: R$ %.2f - Quantidade de Ingressos: %d - Meia Entrada(0 - NÃO, 1 - SIM): %d \n\n",
               vet[i].id, vet[i].comprador, vet[i].dia, vet[i].mes, vet[i].ano, vet[i].valorIngresso, vet[i].quantidade, vet[i].setor, vet[i].meiaEntrada);
    }
}

void calculaValorTotal(ShowVivoRio* vet, int nIngressos){
    printf("\nVALOR TOTAL\n");
for(int i = 0; i <= nIngressos; i++){
    printf("ID Ingresso: %d\n", vet[i].id);
    if(vet[i].meiaEntrada == 1){
        printf("Valor total: R$ %.2f\n\n", (vet[i].valorIngresso / 2) * vet[i].quantidade);
    }
    else{

         printf("Valor total: R$ %.2f\n\n", vet[i].valorIngresso * vet[i].quantidade);
    }


}

}

void liberarIngressos(ShowVivoRio* vet) {
    free(vet);
}
