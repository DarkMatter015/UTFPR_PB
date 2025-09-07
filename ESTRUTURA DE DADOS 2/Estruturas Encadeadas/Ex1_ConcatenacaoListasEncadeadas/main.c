#include <stdio.h>
#include <stdlib.h>
#include "listaEnc.h"

int main() {
    Lista *lst1 = criaListaVazia();
    Lista *lst2 = criaListaVazia();

    // Preenchendo a primeira lista
    insereInicioLista(lst1, 1);
    insereFimLista(lst1, 2);
    insereFimLista(lst1, 3);

    // Preenchendo a segunda lista
    insereInicioLista(lst2, 4);
    insereFimLista(lst2, 5);

    printf("Lista 1 antes da concatenacao:\n");
    imprimeLista(lst1);

    printf("\nLista 2 antes da concatenacao:\n");
    imprimeLista(lst2);

    // Concatenando as listas
    concatenaListas(lst1, lst2);

    printf("\nLista 1 apos concatenacao:\n");
    imprimeLista(lst1);

    printf("\nLista 2 apos concatenacao (deve estar vazia):\n");
    imprimeLista(lst2);

    // Liberando memória
    liberaLista(lst1);
    liberaLista(lst2); // Não causa erro pois lst2->primeira é NULL

    return 0;
}
