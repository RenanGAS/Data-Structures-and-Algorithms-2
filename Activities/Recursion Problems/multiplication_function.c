#include <stdio.h>

int mult(int a, int b)
{
    if (a == 0)
    {
        return 0;
    }
    else if (a == 1)
    {
        return b;
    }

    return b + mult(a - 1, b);
}

int main()
{
    printf("\nCálculo da multiplicação de dois números inteiros, positivos e maiores ou iguais a zero através de uma Função Recursiva\n");

    int a, b;
    printf("\nTendo em mente a multiplicação: a * b\n");
    printf("\nDigite um valor para \"a\": ");
    scanf("%d", &a);
    printf("\nDigite um valor para \"b\": ");
    scanf("%d", &b);

    int res = mult(a, b);

    printf("\n%d * %d = %d\n\n", a , b, res);
}