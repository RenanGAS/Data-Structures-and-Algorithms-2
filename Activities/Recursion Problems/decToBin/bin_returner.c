#include <stdio.h>
#include <math.h>

int ds(int num)
{
    if (num == 0)
    {
        return 0;
    }

    return num % 2 + 10*ds(num / 2);
}

int main()
{
    printf("\nCálculo do Binário de um número Decimal através de uma Função Recursiva\n");

    int num;
    printf("\nDigite um número: ");
    scanf("%d", &num);

    int res = ds(num);

    printf("\n%d = %d\n\n", num, res);
}