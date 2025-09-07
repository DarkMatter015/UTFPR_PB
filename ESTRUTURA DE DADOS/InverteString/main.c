#include <stdio.h>
#include <stdlib.h>

char inverteString(char *s){

    int tamanho;
    tamanho = strlen(s);
    char *sInvertida = malloc(tamanho * sizeof(char));

    int j = 0;
    for(int i = tamanho - 1; i >= 0; i--){
        sInvertida[j] = s[i];
        j++;
    }

    sInvertida[j] = "\0";

    return sInvertida;
}

int main()
{

    char *s = "ponteiros";
    char *i = inverteString(s);
    printf("%s", i);

    return 0;
}
