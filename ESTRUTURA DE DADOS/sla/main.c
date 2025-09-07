#include <stdio.h>
#include <stdlib.h>
#include "sla.h"


int main()
{
    Pilha *p = criaPilhaVazia();
    Fila *f = criaFilaVazia();
    empilha(p, 'A');
    empilha(p, 'B');
    empilha(p, 'C');
    enfileira(f, p->topo);
    enfileira(f, p->topo);
    enfileira(f, 'D');
    empilha(p, desenfileira(f));
    empilha(p, desempilha(p));
    empilha(p, 'E');
    enfileira(f, 'E');
    desempilha(p);

    printf("Pilha: ");
    imprimePilha(p);
    printf("\nFila: ");
    imprimeFila(f);
    return 0;
}
