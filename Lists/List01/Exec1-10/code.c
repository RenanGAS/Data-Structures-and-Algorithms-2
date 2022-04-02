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

void maxmin(int n, int *v, int *res) // Faz 2(n - 1) comparações entre elementos do vetor
{
    if (n == 1)
    {
        res[0] = res[1] = v[0];
    }
    else
    {
        maxmin(n - 1, v, res);
        if (res[0] > v[n - 1])
        {
            res[0] = v[n - 1];
        }
        else if (res[1] < v[n - 1])
        {
            res[1] = v[n - 1];
        }
    }

    return;
}

int main()
{
    int n = 10;
    int *v = calloc(n, sizeof(int));
    int *res = calloc(2, sizeof(int));

    randomVector(v, n);

    printVector(v, n);

    maxmin(n, v, res);

    printf("\nO menor elemento do vetor acima é: %d\n", res[0]);
    printf("\nE o maior elemento do vetor acima é: %d\n", res[1]);
    return EXIT_SUCCESS;
}