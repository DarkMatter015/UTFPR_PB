#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"


char nomeFuncao(int *X) {
    int *varPonteiro; //Declaração de um ponteiro de inteiro
    int exemplo;
    exemplo = 10;
    varPonteiro = &exemplo; //& dá acesso ao endereço de memória de uma variável
    printf(*varPonteiro); //* é o operador de deferência, dá acesso ao conteúdo
    //de um ponteiro
}
