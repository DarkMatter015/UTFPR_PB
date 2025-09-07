#include <stdio.h>
#include <stdlib.h>
#include "funcoesPessoas.h"

struct pessoa{
    char nome[30];
    int idade;
};

Pessoa *inserePessoa(Pessoa *vet, char nome[], int idade, int nPessoas){
    if(nPessoas == 0){
        vet = (Pessoa *) malloc(sizeof(Pessoa));
    }
    else{
        vet = (Pessoa *) realloc(vet, (nPessoas + 1) * sizeof(Pessoa));
    }
    strcpy(vet[nPessoas].nome, nome);
    vet[nPessoas].idade = idade;

    return vet;
}

void imprimePessoas(Pessoa *vet, int nPessoas){
    for(int i = 0; i <= nPessoas; i++){
        printf("\nNome: %s - Idade: %d", vet[i].nome, vet[i].idade);
    }
}

void liberaPessoas(Pessoa *vet){
    free(vet);
}
