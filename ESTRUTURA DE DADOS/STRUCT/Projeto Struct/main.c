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
    // declaração sem typedef
    //struct aluno A; // variavel A do tipo struct aluno

    // declaração com typedef

    Aluno aluno_1;
    printf("Informe o nome do aluno: ");
    scanf("%[^\n]s", aluno_1.nome);

    printf("Informe o RA: ");
    scanf("%d", &aluno_1.RA);

    printf("Informe o coeficiente: ");
    scanf("%f", &aluno_1.coeficiente);

    printf("\nNome: %s", aluno_1.nome);
    printf("\nRA: %d", aluno_1.RA);
    printf("\nCoeficiente: %f", aluno_1.coeficiente);

    Aluno aluno_2 = {"Maria", 456, 0.925};
    printf("\nDados da %s", aluno_2.nome);
    printf("\nNome: %s", aluno_2.nome);
    printf("\nRA: %d", aluno_2.RA);
    printf("\nCoeficiente: %f", aluno_2.coeficiente);

    aluno_2 = aluno_1;

    printf("\nNome: %s", aluno_2.nome);
    printf("\nRA: %d", aluno_2.RA);
    printf("\nCoeficiente: %f", aluno_2.coeficiente);

    return 0;
}
