#include <stdio.h>
#include <stdlib.h>
#include "funcoesPessoas.h"

int main()
{
    Pessoa *vetPessoas;
    int n = 0;
    vetPessoas = inserePessoa(vetPessoas, "Ciclano de Rodriguez", 18, n);
    n++;
    vetPessoas = inserePessoa(vetPessoas, "Beltrano de nao sei oque", 87, n);

    imprimePessoas(vetPessoas, n);
    liberaPessoas(vetPessoas);
    return 0;
}
