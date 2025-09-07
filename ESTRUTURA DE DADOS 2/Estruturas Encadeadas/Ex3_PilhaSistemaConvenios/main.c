#include <stdio.h>
#include <stdlib.h>
#include "convenio.h"

int main() {
    Pilha *convenios = criaPilhaVazia();

    // Inserindo pelo menos quatro conv�nios
    printf("Cadastrando conv�nios:\n");
    empilhaConvenio(convenios, "Farm�cia Boa Sa�de", "Sa�de", 15.0);
    empilhaConvenio(convenios, "Academia FitLife", "Esporte", 20.0);
    empilhaConvenio(convenios, "Livraria Cultura", "Educa��o", 10.0);
    empilhaConvenio(convenios, "Restaurante Sabor", "Alimenta��o", 25.0);

    // Imprimindo a pilha ap�s inser��es
    printf("\nPilha ap�s cadastramento:\n");
    imprimePilha(convenios);

    // Removendo um conv�nio do topo
    printf("\nRemovendo conv�nio do topo:\n");
    desempilhaConvenio(convenios);

    // Imprimindo a pilha ap�s remo��o
    printf("\nPilha ap�s remo��o:\n");
    imprimePilha(convenios);

    // Liberando mem�ria
    liberaPilha(convenios);

    return 0;
}
