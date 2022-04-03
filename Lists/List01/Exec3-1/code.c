#include <stdio.h>
#include <stdlib.h>

void printVector(int *vector, int size)
{
    printf("\nVetor = [");

    for (int i = 0; i < size; i++)
    {
        if (i != size - 1)
        {
            printf("%d, ", vector[i]);
        }
        else
        {
            printf("%d]\n", vector[i]);
        }
    }
}

void randomVector(int *v, int size)
{
    int value;

    for (int i = 0; i < size; i++)
    {
        value = (rand() % 1000) + 1;
        v[i] = value;
    }
}

int sumPositives(int *v, int n)
{
    n -= 1;
    int tosum = 0;

    if (n == 0)
    {
        if (v[n] > 0)
        {
            return v[n];
        }
        else
        {
            return 0;
        }
    }

    if (v[n] > 0)
    {
        tosum = v[n];
    }

    return tosum + sumPositives(v, n);
}

int main()
{
    int n = 10;
    int *v = calloc(n, sizeof(int));

    randomVector(v, n);

    printVector(v, n);

    int res = sumPositives(v, n);

    printf("\nA soma dos elementos do vetor é igual a: %d\n", res);

    return EXIT_SUCCESS;
}