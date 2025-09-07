#include <stdio.h>
#include <stdlib.h>
#include "pedido.h"

struct pedido {
    int id;
    char descricao[50];
    float custo;
};

struct deque {
    Pedido vetPedidos[MAXTAM];
    int inicio;
    int final;
    int qtd;
};

Deque *cria_deque(){
    Deque *dq;

    dq = (Deque*) malloc(sizeof(Deque));

    if(dq != NULL){
        dq -> inicio = 0;
        dq -> final = 0;
        dq -> qtd = 0;
    }

    return dq;
}

int dequeCheia(Deque *dq){
    return dq -> qtd == MAXTAM;
}

int dequeVazia(Deque *dq){
    return dq -> qtd == 0;
}


int insereFinalDeque(Deque *dq, int id, char descricao[], float custo){

    if(dequeCheia(dq) != 0){
        printf("\nErro: nao foi possivel inserir, deque cheio ou com erro!\n");
        return 0;
    }

    Pedido novoPedido;
    novoPedido.id = id;
    strcpy(novoPedido.descricao, descricao);
    novoPedido.custo = custo;

    dq -> vetPedidos[dq->final] = novoPedido;
    dq -> final = (dq->final+1) % MAXTAM;
    dq -> qtd++;

    return 1;
}

int insereInicioDeque(Deque *dq, int id, char descricao[], float custo){

    if(dequeCheia(dq) != 0){
        printf("\nErro: nao foi possivel inserir, deque cheio ou com erro!\n");
        return 0;
    }

    dq -> inicio--;

    if(dq -> inicio < 0){
        dq -> inicio = MAXTAM-1;
    }

    Pedido novoPedido;
    novoPedido.id = id;
    strcpy(novoPedido.descricao, descricao);
    novoPedido.custo = custo;

    dq -> vetPedidos[dq->inicio] = novoPedido;
    dq -> qtd++;

    return 1;
}

int removeInicioDeque(Deque *dq){
    if(dequeVazia(dq) != 0){
        printf("\nErro: nao foi possivel remover, deque vazio ou com erro!\n");
        return 0;
    }

    dq -> inicio = (dq->inicio+1) % MAXTAM;
    dq->qtd--;

    return 1;
}

int removeFinalDeque(Deque *dq){
    if(dequeVazia(dq) != 0){
        printf("\nErro: nao foi possivel remover, deque vazio ou com erro!\n");
        return 0;
    }

    dq -> final--;
    if(dq->final < 0){
        dq -> final = MAXTAM-1;
    }

    dq->qtd--;

    return 1;
}

void imprimeDeque(Deque *dq){
    int n, i = dq -> inicio;

    for(n=0; n < dq->qtd; n++){
        printf("ID: %d - Descricao: %s - Custo: R$ %.2f\n", dq->vetPedidos[i].id, dq->vetPedidos[i].descricao, dq->vetPedidos[i].custo);
        i = (i+1) % MAXTAM;
    }
}

void liberaDeque(Deque *dq){
    free(dq);
}


// B)

int consultaMesa(Deque *dq, int mesa) {
    if (dequeVazia(dq)) {
        printf("Deque vazio! Nenhum pedido encontrado.\n");
        return 0;
    }

    int encontrado = 0;
    int i = dq->inicio;

    for (int n = 0; n < dq->qtd; n++) {
        if (dq->vetPedidos[i].id == mesa) { // Supondo que 'id' seja o número da mesa
            printf("Mesa %d - Pedido: %s - Custo: R$%.2f\n", dq->vetPedidos[i].id, dq->vetPedidos[i].descricao, dq->vetPedidos[i].custo);
            encontrado = 1;
        }
        i = (i + 1) % MAXTAM;
    }

    if (!encontrado) {
        printf("Nenhum pedido encontrado para a mesa %d.\n", mesa);
    }

    return encontrado;
}

int excluiMesa(Deque *dq, int mesa) {
    if (dequeVazia(dq)) {
        printf("Deque vazio! Nenhum pedido para excluir.\n");
        return 0;
    }

    int i = dq->inicio;
    int nRemovidos = 0;

    for (int n = 0; n < dq->qtd; n++) {
        if (dq->vetPedidos[i].id == mesa) {
            removeInicioDeque(dq); // Remove sempre do início, já que ele será reordenado
            nRemovidos++;
        } else {
            i = (i + 1) % MAXTAM;
        }
    }

    if (nRemovidos > 0) {
        printf("Foram excluídos %d pedidos da mesa %d.\n", nRemovidos, mesa);
    } else {
        printf("Nenhum pedido encontrado para a mesa %d.\n", mesa);
    }

    return nRemovidos;
}


// C)

void classificaPedido(Deque *dq, int id, char descricao[], float custo) {
    if (strstr(descricao, "bebida") || strstr(descricao, "salgado")) {
        insereInicioDeque(dq, id, descricao, custo);
    } else {
        insereFinalDeque(dq, id, descricao, custo);
    }
}

Deque *filtraPedidosPorMesa(Deque *dq, int mesa) {
    Deque *novaDeque = cria_deque();

    if (novaDeque == NULL) {
        printf("Erro ao criar nova deque!\n");
        return NULL;
    }

    int i = dq->inicio;
    for (int n = 0; n < dq->qtd; n++) {
        if (dq->vetPedidos[i].id == mesa) {
            insereFinalDeque(novaDeque, dq->vetPedidos[i].id, dq->vetPedidos[i].descricao, dq->vetPedidos[i].custo);
        }
        i = (i + 1) % MAXTAM;
    }

    return novaDeque;
}

float calculaTotalDeque(Deque *dq) {
    float total = 0.0;
    int i = dq->inicio;

    for (int n = 0; n < dq->qtd; n++) {
        total += dq->vetPedidos[i].custo;
        i = (i + 1) % MAXTAM;
    }

    printf("Total dos pedidos: R$%.2f\n", total);
    return total;
}
