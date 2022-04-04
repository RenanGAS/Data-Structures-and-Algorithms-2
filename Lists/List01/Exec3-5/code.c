#include <stdio.h>
#include <stdlib.h>

int sumDecimalPlaces(int n)
{
    if (n < 10)
    {
        return n;
    }

    return ((n % 10) + sumDecimalPlaces(n / 10));
    
}

int main()
{
    int num = 293867;

    int res = sumDecimalPlaces(num);

    printf("\nA soma das casas decimais de %d é: %d\n\n", num, res);

    return EXIT_SUCCESS;
}