#include <stdio.h>
#include <stdlib.h>

float sumFractions(int n)
{
    if (n == 1)
    {
        printf(" %d = ", n);
        return 1;
    }
    else
    {
        printf(" 1/%d +", n);
    }
    
    return ((1 / (float)n) + sumFractions(n - 1));
}

int main()
{
    printf("\nCálculo da soma de \"1/n\" termos naturais através de uma Função Recursiva\n");

    int n = 0;
    printf("\nDigite um número: ");
    scanf("%d", &n);

    printf("\n%d = ", n);

    float res = sumFractions(n);

    printf("%f\n\n", res);

    return EXIT_SUCCESS;
}