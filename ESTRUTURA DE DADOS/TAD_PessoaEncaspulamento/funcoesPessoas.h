#ifndef FUNCOESPESSOAS_H_INCLUDED
#define FUNCOESPESSOAS_H_INCLUDED

typedef struct pessoa Pessoa;

Pessoa *inserePessoa(Pessoa *vet, char nome[], int idade, int nPessoas);
void imprimePessoas(Pessoa *vet, int nPessoas);
void liberaPessoas(Pessoa *vet);

#endif // FUNCOESPESSOAS_H_INCLUDED
