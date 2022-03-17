#include <stdio.h>
#include <stdlib.h>

float expo(float x, unsigned int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n == 1)
    {
        return x;
    }

    return x * expo(x, n - 1);
}

int main()
{
    printf("\nCálculo do exponencial natural de um número real através de uma Função Recursiva\n");
    
    float x = 0;
    printf("\nDigite um número: ");
    scanf("%f", &x);

    unsigned int n = 0;
    printf("\nDigite seu expoente: ");
    scanf("%u", &n);

    float res = expo(x, n);

    printf("\n%.2f^%u = %.2f\n\n", x, n, res);

    return EXIT_SUCCESS;
}