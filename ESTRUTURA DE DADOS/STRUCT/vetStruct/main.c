#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;
//apelido

struct aluno {

    char nome[30];
    int RA;
    float coeficiente;

};

int main()
{
    int i, n = 3;
    Aluno vetAlunos[n];

    for(i = 0; i < n; i++){
        setbuf(stdin, NULL);
        printf("Nome do aluno %d", i+1);
        scanf("%[^\n]s", vetAlunos[i].nome);

        printf("RA: ");
        scanf("%d", &vetAlunos[i].RA);

        printf("Coeficiente: ");
        scanf("%f", &vetAlunos[i].coeficiente);
    }

    for(i = 0; i < n; i++){
        printf("\n\nNome: %s", vetAlunos[i].nome);
        printf("\nRA: %d", vetAlunos[i].RA);
        printf("\nCoeficiente: %.2f", vetAlunos[i].coeficiente);
    }
    return 0;
}
