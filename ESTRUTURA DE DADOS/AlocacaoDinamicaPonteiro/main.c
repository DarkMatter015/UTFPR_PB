#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p;
    int num;

    printf("Informe o numero de elemento que pretende armazenar: ");
    scanf("%d", &num);

    p = (int *) malloc(num * sizeof(int));
    if(p == NULL){
        printf("\nERRO: nao foi possivel alocar memoria");
        system("pause");
        exit(1);
    }

    int i;
    for(i = 0; i < num; i++){
        printf("\nDIgite o valor da posicao %d: ", i);
        scanf("%d", &p[i]);
    }

    for(i = 0; i < num; i++){
        printf("\nPosicao %d: %d", i, p[i]);
    }

    printf("\n");

    printf("\nvetor apos diminuir para 3");
    num = 3;
    p = realloc(p, num * sizeof(int));
    for(i = 0; i < num; i++){
        printf("\nPosicao %d: %d", i, p[i]);
    }

    printf("\nvetor apos aumentar para 10");
    num = 10;
    p = realloc(p, num * sizeof(int));
    for(i = 0; i < num; i++){
        printf("\nPosicao %d: %d", i, p[i]);
    }

    return 0;
}
