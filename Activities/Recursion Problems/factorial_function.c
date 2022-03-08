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
    printf("\nCálculo de Fatoriais através de funções Recursivas\n");

    int n;
    printf("\nDigite um número: ");
    scanf("%d", &n);

    int res = fact(n);

    printf("\n%d! = %d\n\n", n, res);
}