#include <stdio.h>
// #include "cstack.h"
// #include "shunting_yard.h"
#include "ab.h"

int main(int argc, char **argv)
{

    // char exp[] = "(2+1) - 2 * 3 * 6 / 2 + 5";
    // char exp[] = "((2+1) - 2 * 3)+5*4";
    //  char exp[] = "(((2+1) +4)- 2 * 3)+5*4 - (2*4)";

    // char* rpn;

    // rpn = shunting_yard(exp);

    // printf("%s\n", rpn);

    AB a = AB_Criar(10, NULL, NULL);

    AB_Inserir(4, &a, 0, &a);
    AB_Inserir(20, &a, 0, &a);
    AB_Inserir(6, &a, 0, &a);
    AB_Inserir(2, &a, 0, &a);
    AB_Inserir(3, &a, 0, &a);
    // AB_Inserir(1, &a);
    // AB_Inserir(0, &a);
    // AB_Inserir(22, &a);
    // AB_Inserir(21, &a);
    // AB_Inserir(18, &a);
    // AB_Inserir(17, &a);
    // AB_Inserir(16, &a);

    // AB b = AB_Buscar(7, a);

    // printf("\nÀ esquerda de 7: %d\n", b->esq->dado);

    int tamLazyAB = AB_TamanhoLazy(a, 0, 0, 0);

    printf("\nTamanho (Lazy) da Árvore : %d\n", tamLazyAB);

     int tamEagerAB = AB_TamanhoEager(a);

    printf("\nTamanho (Eager) da Árvore: %d\n", tamEagerAB);

    int altLazyAB = AB_AlturaLazy(a, 0, 0, 0);

    printf("\nAltura (Lazy) da Árvore: %d\n", altLazyAB);

    int altEagerAB = AB_AlturaEager(a);

    printf("\nAltura (Eager) da Árvore: %d\n\n", altEagerAB);

    AB_CalcularProfundidades(a, 0);

    AB_Imprimir(&a, 0, 'r');

    int compIntABLazy = AB_ComprimentoInternoLazy(a, 0);

    printf("\nComprimento Interno (Lazy) da Árvore: %d\n", compIntABLazy);

    int compIntABEager = AB_ComprimentoInternoEager(a);

    printf("\nComprimento Interno (Eager) da Árvore: %d\n", compIntABEager);

    int verifyAB = AB_AB(a, 1);

    if (verifyAB)
    {
        printf("\nA Árvore é de Busca Binária\n");
    }
    else
    {
        printf("\nA Árvore não é de Busca Binária\n");
    }

    AB_Destruir(&a);
}
