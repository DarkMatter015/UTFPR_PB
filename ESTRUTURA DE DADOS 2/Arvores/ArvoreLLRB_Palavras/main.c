#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArvoreLLRB.h"

int main(){
    ArvLLRB * raiz = cria_ArvLLRB();
    char delimitador[] = " ";
    char *ptr;
    char valor[100];
    char l[1000];

    int i = 0, N = 6;
    char val[100] = "importantes uteis estruturas define muito arvore";

    printf("%s\n\n", val);

    // TENTEI
    /*
    printf("Exemplo: \n");
    strcpy(l, "1-3-5-2-7-9-21-6");
    //quebra a string de entrada
    ptr = strtok(val, delimitador);
    while(ptr != NULL) {
        strcpy(valor, strtok(val, delimitador));
        printf("%s", valor);
        printf("%s", ptr);
        ptr = strtok(ptr, delimitador); //breaks string str into a series of tokens using the delimiter delim.

    }
    */

    insere_ArvLLRB(raiz, "importantes");
    insere_ArvLLRB(raiz, "uteis");
    insere_ArvLLRB(raiz, "estruturas");
    insere_ArvLLRB(raiz, "define");
    insere_ArvLLRB(raiz, "muito");
    insere_ArvLLRB(raiz, "arvore");

    printf("\nTotal de nos da arvore: %d \n",totalNO_ArvLLRB(raiz));
    emOrdem_ArvLLRB(raiz,0, -1);

    printf("\n\nTentando:\n");
    nomesEmOrdem(raiz, 0, -1);

    printf("\n\nAltura da arvore: %d \n",altura_ArvLLRB(raiz));

    /*for(i=0; i< N; i++){
        if (insere_ArvLLRB(raiz,val[i]) == 0) {
            printf("Erro na insercao do valor: %d\n",val[i]);
        }
    }/

    /*printf("\nTotal de nos da arvore: %d \n",totalNO_ArvLLRB(raiz));
    printf("Altura da arvore: %d \n",altura_ArvLLRB(raiz));
    printf("\nImpressao da arvore usando percurso em ordem:\n");
    emOrdem_ArvLLRB(raiz,0, -1);

    printf("\n\nRemocao da chave 50: \n\n");
    remove_ArvLLRB(raiz,50);
//    remove_ArvLLRB(raiz,20);
//    remove_ArvLLRB(raiz,30);

    printf("\nImpressao da arvore usando percurso em ordem:\n");
    emOrdem_ArvLLRB(raiz,0, -1);

    printf("\n\nRemocao da chave 1: \n\n");
    remove_ArvLLRB(raiz,1);

    printf("\nImpressao da arvore usando percurso em ordem:\n");
    emOrdem_ArvLLRB(raiz,0, -1);*/

    libera_ArvLLRB(raiz);

    return 0;
}
