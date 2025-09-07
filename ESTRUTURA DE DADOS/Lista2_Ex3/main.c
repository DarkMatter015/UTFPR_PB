#include <stdio.h>
#include <stdlib.h>
#define LEN 60
int SIZE = 4;
char arr[LEN][LEN];

void inicializa() {
    int j;
    int j_ = SIZE - 1;
    int p = 3;
    for (j = 0; j < j_; j++) {
        p *= 2;
    }
    SIZE = p;
    int i;
    for (i = 0; i < LEN; i++) {
        int j;
        for (j = 0; j < LEN; j++) {
            arr[i][j] = ' ';
        }
    }
}

void imprimeColunas(int i) {
    for (int j = 0; j < LEN; j++) {
        printf("%c", arr[i][j]);
    }
    printf("\n");
}

void fractalRec(int i_1, int j_1, int i_2, int j_2, int i_3, int j_3) {
    if (i_2 - i_1 == 3) {
        arr[i_1][j_1] = '4'; // Usei '7' como exemplo
        arr[i_1 + 1][j_1 - 1] = '4';
        arr[i_1 + 1][j_1 + 1] = '4';
        arr[i_2 - 1][j_2 + 1] = '4';
        arr[i_2 - 1][j_2 + 3] = '4';
        arr[i_3 - 1][j_3 - 1] = '4';
    } else {
        fractalRec(i_1, j_1, i_1 + (i_2 - i_1) / 2, j_2 + (j_1 - j_2) / 2, i_1 + (i_3 - i_1) / 2, j_3 - (j_3 - j_1) / 2);
        fractalRec(i_2 - (i_2 - i_1) / 2, j_2 + (j_3 - j_1) / 2, i_2, j_2, i_3, j_2 + (j_3 - j_2) / 2);
        fractalRec(i_1 + (i_3 - i_1) / 2, j_1 + (j_3 - j_1) / 2, i_3, j_2 + (j_3 - j_2) / 2, i_3, j_3);
    }
}

// Função iterativa que substitui a versão recursiva imprimeLinhaRec
void imprimeLinhaLucas() {
    for (int i = 0; i < SIZE; i++) {
        imprimeColunas(i);
    }
}

int main(int argc, char *argv[]) {
    inicializa();
    fractalRec(0, SIZE, SIZE, 0, SIZE, SIZE * 2);
    imprimeLinhaLucas(); // Chama a versão iterativa da função
    return 0;
}
