#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"


char nomeFuncao(int *X) {
    int *varPonteiro; //Declara��o de um ponteiro de inteiro
    int exemplo;
    exemplo = 10;
    varPonteiro = &exemplo; //& d� acesso ao endere�o de mem�ria de uma vari�vel
    printf(*varPonteiro); //* � o operador de defer�ncia, d� acesso ao conte�do
    //de um ponteiro
}
