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
        value = (rand() % 35) - 3;
        v[i] = value;
    }
}

int multPositives(int *v, int n)
{
    n -= 1;
    int tomult = 1;

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
        tomult = v[n];
    }

    return tomult * multPositives(v, n);
}

int main()
{
    int n = 10;
    int *v = calloc(n, sizeof(int));

    randomVector(v, n);

    printVector(v, n);

    int res = multPositives(v, n);

    printf("\nO produto dos elementos positivos do vetor é igual a: %d\n", res);

    return EXIT_SUCCESS;
}