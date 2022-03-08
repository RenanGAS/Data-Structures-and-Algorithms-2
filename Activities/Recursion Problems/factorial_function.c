#include <stdio.h>

int fact(int num)
{
    if (num == 1)
    {
        return 1;
    }

    return num * fact(num-1);
}

int main()
{
    printf("\nCálculo do Fatorial de um número inteiro positivo através de uma Função Recursiva\n");

    int n;
    printf("\nDigite um número: ");
    scanf("%d", &n);

    int res = fact(n);

    printf("\n%d! = %d\n\n", n, res);
}