#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "itemListaDuplEnc.h"

int main() {
    ListaDupl *agenda;
    Item *contato;

    printf("Criando agenda telefônica vazia.\n");
    agenda = criaListaDuplVazia();
    if (agenda == NULL) {
        printf("Falha ao criar agenda.\n");
        return 1;
    }

    printf("Agenda vazia? %d\n", verificaListaDuplVazia(agenda));

    // Inserindo contatos
    printf("\nAdicionando contatos:\n");
    contato = criaItem("Alice", "Rua A, 123", 5551234);
    if (contato != NULL) insere(agenda, contato);

    contato = criaItem("Bob", "Rua B, 456", 5555678);
    if (contato != NULL) insere(agenda, contato);

    contato = criaItem("Carol", "Rua C, 789", 5553456);
    if (contato != NULL) insere(agenda, contato);

    contato = criaItem("David", "Rua D, 101", 5559012);
    if (contato != NULL) insere(agenda, contato);

    printf("\nAgenda telefônica (ordenada por telefone):\n");
    imprimeEsqDir(agenda);

    printf("\nBuscando contato 'Carol':\n");
    imprime_contato(agenda, "Carol");

    printf("\nBuscando contato 'Eve' (inexistente):\n");
    imprime_contato(agenda, "Eve");

    printf("\nRemovendo contato 'Bob':\n");
    removePorNome(agenda, "Bob");

    printf("\nAgenda após remoção:\n");
    imprimeEsqDir(agenda);

    printf("\nLiberando agenda.\n");
    liberaListaDupl(agenda);

    return 0;
}
