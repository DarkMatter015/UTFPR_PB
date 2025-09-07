#ifndef CATALOGO_H_INCLUDED
#define CATALOGO_H_INCLUDED

#define MAXTAM 100

typedef struct {
    int codigo;
    char titulo[50];
    char genero[30];
    int duracao; // Duração em minutos
} Filme;

typedef struct pilha Pilha;

Pilha *criaPilhaVazia();
int verificaPilhaCheia(Pilha *p);
int verificaPilhaVazia(Pilha *p);
void empilha(Pilha *p, Filme filme);
void imprimePilha(Pilha *p);
int buscaPorCodigo(Pilha *p, int codigo);
void removeItem(Pilha *p, int codigo);
Pilha *filtraPorGenero(Pilha *p, char genero[]);
void liberaPilha(Pilha *p);

#endif // CATALOGO_H_INCLUDED
