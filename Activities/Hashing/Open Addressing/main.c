#include <stdio.h>
#include <stdlib.h>
#include "threa.h"

int main()
{
    int m = 10;
    THEA *new_th = THEA_Criar(m);

    THEA_Inserir(new_th, 10, 10);
    THEA_Inserir(new_th, 21, 21);
    THEA_Inserir(new_th, 44, 44);
    THEA_Inserir(new_th, 32, 32);
    THEA_Inserir(new_th, 12, 12);
    THEA_Inserir(new_th, 37, 37);
    THEA_Inserir(new_th, 43, 43);

    THEA_Inserir(new_th, 11, 12);
    THEA_Inserir(new_th, 87, 37);
    THEA_Inserir(new_th, 9, 43);

    THEA_Imprimir(new_th);

    return EXIT_SUCCESS;
}