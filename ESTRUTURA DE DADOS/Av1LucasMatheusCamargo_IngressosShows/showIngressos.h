#ifndef SHOWINGRESSOS_H_INCLUDED
#define SHOWINGRESSOS_H_INCLUDED

typedef struct showVivoRio ShowVivoRio;

ShowVivoRio *inserirIngresso(ShowVivoRio *vet, int id, char comprador[], int dia, int mes, int ano, float valorIngresso, int quantidade, int setor, int meiaEntrada, int nIngressos);
void imprimeIngressos(ShowVivoRio* vet, int nIngressos);
void liberarIngressos(ShowVivoRio* vet);

#endif // SHOWINGRESSOS_H_INCLUDED
