#include <stdio.h>
#include <stdlib.h>

int isEven(int n)
{
    if (n <= 1)
    {
        return n;
    }
    
    return isEven(n - 2);
}

int main()
{
    printf("\nVerificação da paridade de um número natural 'n' utilizando subtração, através de uma Função Recursiva\n");

    int n = 0;

    printf("\nDigite um número para \"n\": ");
    scanf("%d", &n);

    if (isEven(n))
    {
        printf("\n%d não é um número par.\n\n", n);
    }
    else
    {
        printf("\n%d é um número par.\n\n", n);
    }

    return EXIT_SUCCESS;
}