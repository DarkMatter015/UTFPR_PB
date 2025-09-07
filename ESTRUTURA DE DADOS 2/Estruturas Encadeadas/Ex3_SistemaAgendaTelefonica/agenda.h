#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED

typedef struct lucasCamargo LucasCamargo;
typedef struct celula Celula;
typedef struct agenda Agenda;

Agenda * criaAgendaVazia();
int verificaAgendaVazia(Agenda *ag);
void insereContato(Agenda *ag, char *nome, char *telefone, char *email);
void removeContato(Agenda *ag, char *nome);
void imprimeAgenda(Agenda *ag);
void liberaAgenda(Agenda *ag);

#endif // AGENDA_H_INCLUDED
