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

    AB_Inserir(4, &a);
    AB_Inserir(20, &a);
    AB_Inserir(6, &a);
    AB_Inserir(2, &a);
    AB_Inserir(3, &a);
    // AB_Inserir(1, &a);
    // AB_Inserir(0, &a);
    // AB_Inserir(22, &a);
    // AB_Inserir(21, &a);
    // AB_Inserir(18, &a);
    // AB_Inserir(17, &a);
    // AB_Inserir(16, &a);

    // AB b = AB_Buscar(7, a);

    // printf("\nÀ esquerda de 7: %d\n", b->esq->dado);

    int tamAB = AB_Tamanho(a, 0, 0, 0);

    printf("\nTamanho da Árvore: %d\n", tamAB);

    int altAB = ABB_Altura(a, 0, 0, 0);

    printf("\nAltura da Árvore: %d\n\n", altAB);

    AB_CalcularProfundidades(a, 0);

    AB_Imprimir(&a, 0, 'r');

    int compIntAB = AB_ComprimentoInterno(a, 0);

    printf("\nComprimento Interno da Árvore: %d\n", compIntAB);

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
