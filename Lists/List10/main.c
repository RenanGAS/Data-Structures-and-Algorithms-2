#include <stdio.h>
// #include "cstack.h"
// #include "shunting_yard.h"
#include "ab.h"

int main(int argc, char** argv){

    //char exp[] = "(2+1) - 2 * 3 * 6 / 2 + 5";
    //char exp[] = "((2+1) - 2 * 3)+5*4";
    // char exp[] = "(((2+1) +4)- 2 * 3)+5*4 - (2*4)";

    // char* rpn;

    // rpn = shunting_yard(exp);

    // printf("%s\n", rpn);

    AB a = AB_Criar(10, NULL, NULL);

    AB_Inserir(4, &a);
    AB_Inserir(20, &a);
    AB_Inserir(6, &a);
    AB_Inserir(2, &a);
    AB_Inserir(3, &a);

    // AB b = AB_Buscar(7, a);

    // printf("\nÀ esquerda de 7: %d\n", b->esq->dado);

    int tamAB = AB_Tamanho(a, 0, 0, 0);

    printf("\nTamanho da Árvore: %d\n\n", tamAB);

    AB_Imprimir(&a, 0, 'r');

    AB_Destruir(&a);
}
