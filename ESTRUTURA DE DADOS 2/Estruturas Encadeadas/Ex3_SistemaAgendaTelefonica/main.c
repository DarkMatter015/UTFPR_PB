#include <stdio.h>
#include <stdlib.h>
#include "agenda.h"

int main() {
    Agenda *agenda = criaAgendaVazia();

    // Inserindo pelo menos quatro contatos
    insereContato(agenda, "Ana Silva", "11987654321", "ana.silva@email.com");
    insereContato(agenda, "Bruno Costa", "21976543210", "bruno.costa@email.com");
    insereContato(agenda, "Clara Mendes", "31965432109", "clara.mendes@email.com");
    insereContato(agenda, "Diego Souza", "41954321098", "diego.souza@email.com");

    // Imprimindo a agenda após inserções
    printf("Agenda apos insercao dos contatos:\n");
    imprimeAgenda(agenda);

    // Removendo um contato
    removeContato(agenda, "Bruno Costa");

    // Imprimindo a agenda após remoção
    printf("\nAgenda apos remocao de 'Bruno Costa':\n");
    imprimeAgenda(agenda);

    // Liberando memória
    liberaAgenda(agenda);

    return 0;
}
