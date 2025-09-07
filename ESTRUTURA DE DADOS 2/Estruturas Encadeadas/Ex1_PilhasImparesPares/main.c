#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {
    // Criando as tr�s pilhas
    Pilha *p1 = criaPilhaVazia();
    Pilha *p2 = criaPilhaVazia();
    Pilha *p3 = criaPilhaVazia();

    // Preenchendo a primeira pilha com n�meros
    printf("Preenchendo a pilha 1:\n");
    empilha(p1, 1);
    empilha(p1, 2);
    empilha(p1, 3);
    empilha(p1, 4);
    empilha(p1, 5);
    empilha(p1, 6);

    printf("Pilha 1 (original):\n");
    imprimePilha(p1);

    // Separando pares e �mpares
    separaParesImpares(p1, p2, p3);

    printf("\nPilha 2 (pares):\n");
    imprimePilha(p2);

    printf("\nPilha 3 (�mpares):\n");
    imprimePilha(p3);

    // Liberando mem�ria
    liberaPilha(p1);
    liberaPilha(p2);
    liberaPilha(p3);

    return 0;
}
