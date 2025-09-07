#ifndef ITEMLISTADUPLENC_H_INCLUDED
#define ITEMLISTADUPLENC_H_INCLUDED

typedef struct item Item;
typedef struct listaDupl ListaDupl;
typedef struct celula Celula;

//Cria uma lista vazia
ListaDupl *criaListaDuplVazia();
//Cria um item com os dados fornecidos
Item *criaItem(char nome[], char endereco[], int telefone);
//Insere um contato ordenado por telefone
void insere(ListaDupl *ld, Item *item);
//Remove um contato por nome
void removePorNome(ListaDupl *ld, char nome[]);
//Imprime os dados de um contato por nome
void imprime_contato(ListaDupl *ld, char nome[]);
//Imprime a lista da esquerda para a direita
void imprimeEsqDir(ListaDupl *ld);
//Verifica se a lista está vazia
int verificaListaDuplVazia(ListaDupl *ld);
//Libera a lista da memória
void liberaListaDupl(ListaDupl *ld);
//Libera um item da memória
void liberaItem(Item *item);

#endif // ITEMLISTADUPLENC_H_INCLUDED
