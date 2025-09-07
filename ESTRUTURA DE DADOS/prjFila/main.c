#include <stdio.h>
#include <stdlib.h>
#include "itemFila.h"

int main()
{
    Fila *f = criaFilaVazia();
    printf("Enfileirando 5 itens: \n");
    enfileira(f, 1);
    enfileira(f, 2);
    enfileira(f, 3);
    enfileira(f, 4);
    enfileira(f, 5);
    imprimeFila(f);
    printf("\nTentando enfileirar mais um item:\n");
    enfileira(f, 6);
    printf("Desenfileirando um item: \n");
    desenfileira(f);
    imprimeFila(f);
    liberaFila(f);
    return 0;
}
