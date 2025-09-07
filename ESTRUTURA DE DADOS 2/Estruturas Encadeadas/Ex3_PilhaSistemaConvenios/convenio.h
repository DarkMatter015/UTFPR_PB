#ifndef CONVENIO_H_INCLUDED
#define CONVENIO_H_INCLUDED

typedef struct lucasCamargo LucasCamargo;
typedef struct celula Celula;
typedef struct pilha Pilha;

Pilha * criaPilhaVazia();
void empilhaConvenio(Pilha *p, char *nome, char *area, float desconto);
void desempilhaConvenio(Pilha *p);
void imprimePilha(Pilha *p);
int verificaPilhaVazia(Pilha *p);
void liberaPilha(Pilha *p);

#endif // CONVENIO_H_INCLUDED
