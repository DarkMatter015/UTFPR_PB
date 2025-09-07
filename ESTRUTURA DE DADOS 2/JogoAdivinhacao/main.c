#include<locale.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "jogo.h"

// ESTRUTURA DE NUMERO
typedef struct numero Numero;

struct numero
{
    char questao[60];
    int palpiteSim;
    int palpiteNao;
    Numero *ptrNao, *ptrSim;
};
// FUNCOES DA STRUCT DE NUMERO
void ApagarArvore(Numero *ptrRaiz)
{
    if (ptrRaiz == NULL)
    {
        return;
    }
    ApagarArvore(ptrRaiz->ptrNao);
    ApagarArvore(ptrRaiz->ptrSim);
    free(ptrRaiz);
}
// FUNCOEES DO PROGRAMA
int PedirPalpite(int *sPalpite)
{
    char c;
    printf("Você está pensando em %d (s/n)? \n", sPalpite);
    scanf(" %c", &c);
    if (tolower(c) == 's')
    {
        return 1;
    }
    return 0;
}

void AdicionarNodo(Numero *ptr, char cSimNao, int nRodada, NoArvBin *raiz)
{
    int sNumero;
    char c;
    Numero *pNumeroNovo = malloc(sizeof(Numero));
    pNumeroNovo->ptrNao = NULL;
    pNumeroNovo->ptrSim = NULL;
    if (cSimNao == 's')
    {
        pNumeroNovo->palpiteSim = ptr->palpiteSim;
        pNumeroNovo->palpiteNao = ptr->palpiteSim;
        ptr->ptrSim = pNumeroNovo;
    }
    else
    {
        pNumeroNovo->palpiteSim = ptr->palpiteNao;
        pNumeroNovo->palpiteNao = ptr->palpiteNao;
        ptr->ptrNao = pNumeroNovo;
    }
    printf("\nMaquina errou!\n");
    printf("Qual é o número correto? \n ");
    scanf(" %d", &sNumero);
    printf("Por favor entre com uma questão(igual, maior, menor) para identificar seu numero correto.\n");
    scanf(" %[^\n]s", pNumeroNovo->questao);
    printf("A resposta é 's' ou 'n'?\n");
    scanf(" %c", &c);
    if (tolower(c) == 's')
    {
        pNumeroNovo->palpiteSim = sNumero;
    }
    else
    {
        pNumeroNovo->palpiteNao = sNumero;
    }
    insere_ArvBin(raiz, nRodada, 0);
    return;
}
int main()
{
// CONFIGURACAO INICIAL
    setlocale(LC_ALL, "Portuguese");
    Numero *ptrRaiz = NULL, *ptrCur=NULL;
    NoArvBin* raiz = cria_ArvBin();
    char c;
    int jogando = 1, fezPalpite = 0;

    imprimeMenu();

// PRIMEIRA PERGUNTA
    ptrRaiz = malloc(sizeof(Numero));
    ptrRaiz->ptrNao = NULL;
    ptrRaiz->ptrSim = NULL;
    strcpy(ptrRaiz->questao, "É mais velho que o neymar?");
    ptrRaiz->palpiteSim = 50;
    ptrRaiz->palpiteNao = 18;
    printf("Adivinhe o numero!\n");
    ptrCur = ptrRaiz;


    int nRodada = 0;
    while (jogando)
    {
        if (nRodada == 0) printf("\n\nRODADA TESTE: \n");

        fezPalpite = 0;

        while (fezPalpite == 0)
        {
            printf("%s (s/n)\n", ptrCur->questao);
            scanf(" %c", &c);
            if (tolower(c) == 's')
            {


                if (ptrCur->ptrSim == NULL)
                {
                    if (PedirPalpite(ptrCur->palpiteSim) == 0)
                    {

                        AdicionarNodo(ptrCur, 's', nRodada, raiz);
                    }
                    else {
                        printf("\nMaquina acertou!\n");
                        insere_ArvBin(raiz, nRodada, 1);
                    }
                    fezPalpite=1;
                }
                else
                {
                    ptrCur = ptrCur->ptrSim;
                }
            }
            else
            {
                if (ptrCur->ptrNao == NULL)
                {
                    if (PedirPalpite(ptrCur->palpiteNao) == 0)
                    {
                        AdicionarNodo(ptrCur, 'n', nRodada, raiz);
                    }
                    else {
                        printf("\nMaquina acertou!\n");
                        insere_ArvBin(raiz, nRodada, 1);
                    }
                    fezPalpite=1;
                }
                else
                {
                    ptrCur = ptrCur->ptrNao;
                }
            }
        }

        if (nRodada != 0) {
            printf("Jogar novamente? (s/n) \n");
            scanf(" %c", &c);
            if (tolower(c) == 'n')
            {
                jogando=0;
            }
        }
        else printf("\nCOMECOU!!\n");

        nRodada ++;
        ptrCur = ptrRaiz;
    }
    printf("\n-=========== PLACAR ===========\n");
    imprimeResultado(raiz);
    libera_ArvBin(raiz);
    ApagarArvore(ptrRaiz);
    return 0;
}
