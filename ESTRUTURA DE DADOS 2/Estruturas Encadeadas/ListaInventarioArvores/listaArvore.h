#ifndef LISTAARVORE_H_INCLUDED
#define LISTAARVORE_H_INCLUDED

typedef struct arvore ARVORE;
typedef struct celula Celula;
typedef struct lista Lista;

Lista *criaListaVazia();
int verificaListaVazia(Lista *lst);
void insereFimLista(Lista *lst, char *regiao, char *especie, int quantidade, int id_arvore);
Celula *buscaPorEspecieRegiao(Lista *lst, char *regiao, char *especie);
void atualizaQuantidade(Lista *lst, char *regiao, char *especie, int quantidade);
void removeFimLista(Lista *lst);
void imprimeLista(Lista *lst);
void analisaPorcentagens(Lista *lst);
void liberaLista(Lista *lst);

#endif
