#include <stdio.h>
#include <stdlib.h>

unsigned int fact(unsigned int n)
{
    unsigned int res = 1;

    for (int i = 2; i <= n; i++)
    {
        res *= i;
    }

    return res;
}

int main()
{
    printf("\nCálculo do fatorial de um número inteiro maior ou igual a zero, através de uma Função Iterativa\n");

    unsigned int n = 0;

    printf("\nDigite um número inteiro maior ou igual a zero: ");
    scanf("%u", &n);

    unsigned int res = fact(n);

    printf("\n%u! = %u\n\n", n, res);

    return EXIT_SUCCESS;
}