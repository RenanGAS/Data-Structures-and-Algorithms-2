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

int maximum(int n, int *v)
{
    int x;
    if (n == 1)
    {
        return v[0];
    }
    x = maximum(n - 1, v);
    if (x < v[n - 1])
    {
        return v[n - 1];
    }
    else
    {
        return x;
    }
}

void verifyMax(int *v, int n, int res)
{
    for (int i = 0; i < n; i++)
    {
        if (v[i] > res)
        {
            printf("\nResposta errada!\n");
            return;
        }
    }

    printf("\nResposta certa!\n");
}

int main()
{
    int res;
    int n = 10;
    int *v = calloc(n, sizeof(int));

    randomVector(v, n);

    printVector(v, n);

    res = maximum(n, v);

    printf("\nO maior elemento do vetor acima é: %d\n", res);

    verifyMax(v, n, res);

    return EXIT_SUCCESS;
}