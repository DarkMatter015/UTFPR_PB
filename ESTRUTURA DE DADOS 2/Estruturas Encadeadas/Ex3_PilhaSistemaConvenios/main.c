#include <stdio.h>
#include <stdlib.h>
#include "convenio.h"

int main() {
    Pilha *convenios = criaPilhaVazia();

    // Inserindo pelo menos quatro convênios
    printf("Cadastrando convênios:\n");
    empilhaConvenio(convenios, "Farmácia Boa Saúde", "Saúde", 15.0);
    empilhaConvenio(convenios, "Academia FitLife", "Esporte", 20.0);
    empilhaConvenio(convenios, "Livraria Cultura", "Educação", 10.0);
    empilhaConvenio(convenios, "Restaurante Sabor", "Alimentação", 25.0);

    // Imprimindo a pilha após inserções
    printf("\nPilha após cadastramento:\n");
    imprimePilha(convenios);

    // Removendo um convênio do topo
    printf("\nRemovendo convênio do topo:\n");
    desempilhaConvenio(convenios);

    // Imprimindo a pilha após remoção
    printf("\nPilha após remoção:\n");
    imprimePilha(convenios);

    // Liberando memória
    liberaPilha(convenios);

    return 0;
}
