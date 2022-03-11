#include <stdio.h>
#include <stdlib.h>

void ds(int num)
{
    if (num == 1)
    {
       printf("%d", num);
    }
    else
    {
        ds(num / 2);
        printf("%d", num % 2);
    }
}

int main()
{
    printf("\nCálculo do Binário de um número Decimal através de uma Função Recursiva\n");

    int n;
    printf("\nDigite um número: ");
    scanf("%d", &n);

    printf("\n");

    ds(n);

    printf("\n\n");

    return EXIT_SUCCESS;
}