#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Data.h"

struct data {
    int dia;
    int mes;
    int ano;
};

Data* dataNova(int d, int m, int a) {
    Data* dt = (Data*) malloc(sizeof(Data));
    if (dt != NULL) {
        dt->dia = d;
        dt->mes = m;
        dt->ano = a;
    }
    return dt;
}

Data* dataHoje(void) {
    Data* dt = malloc(sizeof(Data));
    time_t tempo;
    struct tm* hj;
    tempo = time(NULL); // Obtem o tempo corrente
    hj = localtime(&tempo); // Obtem a data do sistema operacional
    dt->dia = hj->tm_mday;
    dt->mes = hj->tm_mon + 1;
    dt->ano = hj->tm_year + 1900;
    return dt;
}

void imprimirData(Data* dt) {
    if (dt != NULL) {
        printf("%02d/%02d/%04d", dt->dia, dt->mes, dt->ano);
    } else {
        printf("Data inválida");
    }
}

void liberarData(Data* dt) {
    if (dt != NULL) {
        free(dt);
    }
}
