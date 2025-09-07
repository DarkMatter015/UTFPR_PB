#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {
    Pilha *p = criaPilhaVazia();

    // Preenchendo a pilha com o exemplo fornecido
    printf("Preenchendo a pilha inicial:\n");
    empilha(p, 9);
    empilha(p, 9);
    empilha(p, 8);
    empilha(p, 4);
    empilha(p, 3);
    empilha(p, 2);
    empilha(p, 2);
    empilha(p, 1);
    empilha(p, 0);

    printf("Pilha inicial:\n");
    imprimePilha(p);

    // Removendo duplicados
    printf("\nRemovendo duplicados...\n");
    removeDuplicados(p);

    printf("Pilha sem duplicados:\n");
    imprimePilha(p);

    // Liberando memória
    liberaPilha(p);

    return 0;
}
