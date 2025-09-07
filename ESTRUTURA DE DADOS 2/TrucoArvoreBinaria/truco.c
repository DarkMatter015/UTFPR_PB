#include <stdio.h>
#include <stdlib.h>
#include "truco.h"

struct carta {
    char valor;
    int naipe; /* 0- Ouros, 1- Espadas, 2- Copas, 3- paus*/
};

struct jogador {
    int id;
    char nome[50];
};
