#include <stdio.h>
#include <stdlib.h>

typedef struct aluno Aluno;

struct aluno{
    char nome[30];
    int RA;
    float notas[3];
    float media;
};

Aluno cadastraAluno(char nome[], int RA, float notas[]){
    Aluno novoAluno;
    strcpy(novoAluno.nome, nome);
    novoAluno.RA = RA;
    novoAluno.notas[0] = notas[0];
    novoAluno.notas[1] = notas[1];
    novoAluno.notas[2] = notas[2];

    return novoAluno;
}

void imprimeALuno(Aluno a){
    printf("\nAluno: %s - %d", a.nome, a.RA);
    printf("\nMedia: %.2f", a.media);
}

Aluno calculaMedia(Aluno a){
    float soma = 0;
    for(int i = 0; i < 3; i++){
        soma += a.notas[i];
    }

    a.media = soma / 3;

    return a;
}

int main()
{
    Aluno aluno1;
    char nome[30];
    int RA;
    float notas[3];
    printf("\nInforme o nome do aluno: ");
    scanf("%[^\n]s", nome);
    printf("Informe o RA do aluno: ");
    scanf("%d", &RA);
    printf("Informe 3 notas separadas por espacos: ");
    scanf("%f %f %f", &notas[0], &notas[1], &notas[2]);

    aluno1 = cadastraAluno(nome, RA, notas);
    aluno1 = calculaMedia(aluno1);
    imprimeALuno(aluno1);
    return 0;
}
