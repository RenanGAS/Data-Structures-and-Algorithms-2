#include <stdio.h>
#include <stdlib.h>

int mult(int m, int n)
{
    if (m == 1)
    {
        return n;
    }

    return n + mult(m - 1, n);
}

int main()
{
    printf("\nCálculo do produto de \"m\" por \"n\" utilizando soma e subtração, através de uma Função Recursiva\n");

    int m = 0;
    int n = 0;

    printf("\nDigite um número para \"m\": ");
    scanf("%d", &m);
    printf("\nDigite um número para \"n\": ");
    scanf("%d", &n);

    int res = mult(m, n);

    printf("\n%d * %d = %d\n\n", m, n, res);

    return EXIT_SUCCESS;
}