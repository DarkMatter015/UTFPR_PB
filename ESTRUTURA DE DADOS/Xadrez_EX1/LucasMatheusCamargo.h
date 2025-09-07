#ifndef LUCASMATHEUSCAMARGO_H_INCLUDED
#define LUCASMATHEUSCAMARGO_H_INCLUDED

typedef struct jogada Jogada;
typedef struct data Data;
typedef struct partida Partida;

Jogada *insereJogada(Jogada* vet, int jogador, char cor, char peca, char movimento[], int *nJogadas);
void imprimeJogadas(Jogada* vet, int nJogadas);
void liberarJogadas(Jogada* vet);

Data *dataNova(int d, int m, int a);
void imprimirData(Data *dt);
void liberarData(Data *dt);

Partida* inserePartida(Partida* vet, Data* data, char jogador1[], char jogador2[], char vencedor[], int tempo, Jogada* jogadas, int nJogadas, int* nPartidas);
void imprimirPartidas(Partida* vet, int nPartidas);
void liberarPartidas(Partida* vet, int nPartidas);

#endif // LUCASMATHEUSCAMARGO_H_INCLUDED
