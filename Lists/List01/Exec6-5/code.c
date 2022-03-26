#include <stdio.h>
#include <stdlib.h>

int intDiv(int m, int n)
{
    if (m < n)
    {
        return 0;
    }

    return 1 + intDiv(m - n, n);
}

int main()
{
    printf("\nCálculo da divisão inteira de \"m\" por \"n\" utilizando soma e subtração, através de uma Função Recursiva\n");

    int m = 0;
    int n = 0;

    printf("\nDigite um número para \"m\": ");
    scanf("%d", &m);
    printf("\nDigite um número para \"n\": ");
    scanf("%d", &n);

    int res = intDiv(m, n);

    printf("\n%d / %d = %d\n\n", m, n, res);

    return EXIT_SUCCESS;
}