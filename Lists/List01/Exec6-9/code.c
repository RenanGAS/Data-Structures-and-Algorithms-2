#include <stdio.h>
#include <stdlib.h>

int sumVector(int n, int *v)
{
    if (n == 0)
    {
        return v[n];
    }

    return (v[n] + sumVector(n - 1, v));
}

int main()
{
    printf("\nCálculo da soma dos 'n' primeiros itens de um vetor 'v' de números inteiros, através de uma Função Recursiva\n");

    int v[10] = {2, 3, 6, 1, 0, 4, 5, 12, 10, 9};
    int n = 0;

    printf("\nDigite um número para \"n\": ");
    scanf("%d", &n);

    int res = sumVector(n - 1, v);

    printf("\nSoma = %d\n\n", res);

    return EXIT_SUCCESS;
}