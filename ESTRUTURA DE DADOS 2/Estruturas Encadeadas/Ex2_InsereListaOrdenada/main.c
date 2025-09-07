#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {
    Lista *lst1 = criaListaVazia();
    Lista *lst2 = criaListaVazia();

    // Preenchendo a primeira lista (não ordenada)
    insereFimLista(lst1, 5);
    insereFimLista(lst1, 2);
    insereFimLista(lst1, 7);
    insereFimLista(lst1, 1);
    insereFimLista(lst1, 4);

    printf("Lista 1 (original):\n");
    imprimeLista(lst1);

    // Inserindo os elementos de lst1 em lst2 de forma ordenada
    insereOrdenado(lst1, lst2);

    printf("\nLista 2 (ordenada):\n");
    imprimeLista(lst2);

    // Liberando memória
    liberaLista(lst1);
    liberaLista(lst2);

    return 0;
}
