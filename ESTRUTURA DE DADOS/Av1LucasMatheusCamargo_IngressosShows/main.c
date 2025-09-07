#include <stdio.h>
#include <stdlib.h>
#include "showIngressos.h"


int main()
{

    ShowVivoRio *vetShow;
    int n = 0;

    vetShow = inserirIngresso(vetShow, 1, "Lucas", 12, 04, 2012, 120, 2, 1, 1, n);
    n++;
    vetShow = inserirIngresso(vetShow, 2, "Matheus", 15, 04, 2018, 230, 1, 0, 1, n);
    n++;
    vetShow = inserirIngresso(vetShow, 3, "Camargo", 10, 07, 2011, 50, 3, 1, 1, n);
    n++;
    vetShow = inserirIngresso(vetShow, 4, "Kleitin", 01, 05, 2024, 100, 5, 2, 10, n);

    imprimeIngressos(vetShow, n);

    calculaValorTotal(vetShow, n);

    liberarIngressos(vetShow);

    return 0;
}
