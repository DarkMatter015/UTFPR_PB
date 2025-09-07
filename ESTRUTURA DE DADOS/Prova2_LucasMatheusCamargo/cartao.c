#include <stdio.h>
#include <stdlib.h>
#include "cartao.h"

struct lucasSicoob {
    int dia;
    int mes;
    int ano;
    float valor;
    char descricao[30];
    // 1 para debito - 2 para credito
    int tipoPagamento;
};

struct fila {
    LucasSicoob vetCartoes[MAXTAM];
    int primeiro;
    int ultimo;
    int tamanho;
};

Fila *criaFilaVazia() {
    Fila *f = (Fila *) malloc(sizeof(Fila));
    f->primeiro = 0;
    f->ultimo = 0;
    f->tamanho = 0;
    return f;
}

//retorna 1 se a fila está cheia ou não
int verificaFilaCheia(Fila *f) {
    return f->tamanho == MAXTAM;
}

void enfileira(Fila *f, int dia, int mes, int ano, float valor, char descricao[], int tipoPagamento) {
    if (verificaFilaCheia(f))
    {
        printf("Erro: a fila esta cheia.\n");
        return;
    }
    LucasSicoob novoCartao;
    novoCartao.dia = dia;
    novoCartao.mes = mes;
    novoCartao.ano = ano;
    novoCartao.valor = valor;
    strcpy(novoCartao.descricao, descricao);
    novoCartao.tipoPagamento = tipoPagamento;
    f->vetCartoes[f->ultimo] = novoCartao;
    f->ultimo = (f->ultimo + 1) % MAXTAM; //Controle da fila circular
    f->tamanho++;
}

void desenfileira(Fila *f) {
    if (verificaFilaVazia(f))
    {
        printf("Erro: a fila esta vazia.\n");
        return;
    }
    f->primeiro = (f->primeiro + 1) % MAXTAM;//Controle da fila circular
    f->tamanho--;
}

void exclusaoRegistros(Fila *f){
    if (verificaFilaVazia(f))
    {
        printf("Erro: a fila esta vazia.\n");
        return;
    }

    for(int i = f->tamanho; i >= 0; i--){
        f->primeiro = (f->primeiro + 1) % MAXTAM;//Controle da fila circular
        f->tamanho--;
        i--;
    }
}

//retorna 1 se a fila está vazia e 0 se não está
int verificaFilaVazia(Fila *f) {
    return f->tamanho == 0;
}

void liberaFila(Fila *f) {
    free(f);
}

void imprimeFila(Fila *f) {
    int t;
    int i = f->primeiro;
    for (t = 0; t < f->tamanho; t++)
    {
        printf("Data Registro: %d/%d/%d - Valor: R$ %2.f - Descricao: %s - Tipo Pagamento: %d\n", f->vetCartoes[i].dia, f->vetCartoes[i].mes, f->vetCartoes[i].ano, f->vetCartoes[i].valor, f->vetCartoes[i].descricao, f->vetCartoes[i].tipoPagamento);
        i = (i + 1) % MAXTAM; //Controle da fila circular
    }
}


float totalGastoCreditoRecursivo(Fila *f, int mes){
    if (verificaFilaVazia(f))
    {
        printf("Erro: a fila esta vazia.\n");
        return -1;
    }

    float total = 0;
    int t;
    int i = f->primeiro;
    for (t = 0; t < f->tamanho; t++){
        if(f->vetCartoes[i].mes = mes && f->vetCartoes[i].tipoPagamento == 2){
            total += f->vetCartoes[i].valor;
            i = (i + 1) % MAXTAM;
        }
    }

    return total;
}
