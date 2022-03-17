#include <stdio.h>
#include <stdlib.h>

int toSum(int n, int base)
{
    if (n == 0 || n == 1 || base == n)
    {
        printf("%d = ", base);
        
        return n;
    }

    if (base != n)
    {
        printf("%d + ", base);
    }
    
    return base + toSum(n, base + 1);
}

int main()
{
    printf("\nCálculo da soma de \"n\" termos naturais através de uma Função Recursiva\n");

    int n = 0;
    printf("\nDigite um número: ");
    scanf("%d", &n);

    printf("\n%d = ", n);

    int res = toSum(n, 1);

    printf("%d\n\n", res);

    return EXIT_SUCCESS;
}