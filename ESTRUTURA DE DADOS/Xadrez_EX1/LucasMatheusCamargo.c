#include <stdio.h>
#include <stdlib.h>
#include "LucasMatheusCamargo.h"

struct jogada {
    int jogador;          // Identificação do jogador (1 ou 2)
    char cor;             // Cor da peça (B para Branco, P para Preto)
    char peca;            // Tipo da peça (T, R, D, B, C ou vazio para peão)
    char movimento[3];    // Movimento realizado (ex: "e2", "0-0", "f8D")
};

struct data {
    int dia;
    int mes;
    int ano;
};

typedef struct partida {
    Data* data;          // Data da partida
    char jogador1[50];    // Nome do Jogador 1
    char jogador2[50];    // Nome do Jogador 2
    char vencedor[50];    // Nome do vencedor
    int tempo;            // Tempo da partida em minutos
    Jogada* jogadas;      // Vetor de jogadas realizadas
    int nJogadas;         // Número de jogadas realizadas
};

// Função para inserir uma nova jogada no vetor
Jogada *insereJogada(Jogada *vet, int jogador, char cor, char peca, char movimento[], int *nJogadas) {
    if (*nJogadas == 0) {
        vet = (Jogada*)malloc(sizeof(Jogada));
    } else {
        vet = (Jogada*)realloc(vet, (*nJogadas + 1) * sizeof(Jogada));
    }

    vet[*nJogadas].jogador = jogador;
    vet[*nJogadas].cor = cor;
    vet[*nJogadas].peca = peca;
    strcpy(vet[*nJogadas].movimento, movimento);

    (*nJogadas)++;

    return vet;
}


// Função para imprimir todas as jogadas
void imprimeJogadas(Jogada* vet, int nJogadas) {
    printf("Jogadas realizadas na partida:\n");
    for (int i = 0; i < nJogadas; i++) {
        printf("Jogador %d (Cor: %c) - Peca: %c - Movimento: %s\n",
               vet[i].jogador, vet[i].cor, vet[i].peca, vet[i].movimento);
    }
}

// Função para liberar a memória alocada para o vetor de jogadas
void liberarJogadas(Jogada* vet) {
    free(vet);
}

// Nova DATA
Data *dataNova(int d, int m, int a) {
    Data *novaData = (Data*)malloc(sizeof(Data));
    if (novaData != NULL) {
        novaData->dia = d;
        novaData->mes = m;
        novaData->ano = a;
    }
    return novaData;
}

// Função para imprimir uma data
void imprimirData(Data *dt) {
    if (dt != NULL) {
        printf("Data: %02d/%02d/%d\n", dt->dia, dt->mes, dt->ano);
    } else {
        printf("Data inválida.\n");
    }
}

// Função para liberar a memória de uma data
void liberarData(Data *dt) {
    free(dt);
}


Partida* inserePartida(Partida* vet, Data* data, char jogador1[], char jogador2[], char vencedor[], int tempo, Jogada* jogadas, int nJogadas, int* nPartidas) {
    // Realoca o vetor de partidas para acomodar uma nova partida
    Partida* novoVet = (Partida*)realloc(vet, (*nPartidas + 1) * sizeof(Partida));

    if (novoVet == NULL) {
        printf("Erro ao alocar memória para nova partida.\n");
        return vet; // Retorna o vetor antigo se a realocação falhar
    }

    // Atualiza o vetor de partidas com o novo endereço
    vet = novoVet;

    // Configura os dados da nova partida
    vet[*nPartidas].data = data;
    strcpy(vet[*nPartidas].jogador1, jogador1);
    strcpy(vet[*nPartidas].jogador2, jogador2);
    strcpy(vet[*nPartidas].vencedor, vencedor);
    vet[*nPartidas].tempo = tempo;
    vet[*nPartidas].jogadas = jogadas;
    vet[*nPartidas].nJogadas = nJogadas;

    // Incrementa o contador de partidas
    (*nPartidas)++;

    return vet;
}

void imprimirPartidas(Partida* vet, int nPartidas) {
    if (nPartidas == 0) {
        printf("Nenhuma partida registrada.\n");
        return;
    }

    printf("Partidas realizadas:\n");
    for (int i = 0; i < nPartidas; i++) {
        printf("\nData da partida: ");
        imprimirData(vet[i].data);
        printf("Jogador 1: %s | Jogador 2: %s | Vencedor: %s | Tempo: %d minutos\n",
               vet[i].jogador1, vet[i].jogador2, vet[i].vencedor, vet[i].tempo);
        imprimeJogadas(vet[i].jogadas, vet[i].nJogadas);
    }
}

void liberarPartidas(Partida* vet, int nPartidas) {
    for (int i = 0; i < nPartidas; i++) {
        liberarData(vet[i].data);
        liberarJogadas(vet[i].jogadas);
    }
    free(vet);
}
