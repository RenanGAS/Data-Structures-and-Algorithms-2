#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int maxElement(int *v, int n)
{
    int max = v[0];

    for (int i = 1; i < n; i++)
    {
        if (v[i] > max)
        {
            max = v[i];
        }
    }

    return max;
}

void counting(int *v, int n, int div, int base, int *temp)
{
    int i, t, c[10], sum = 0;
    memset(c, 0, base * sizeof(int));

#define DIGIT(X) ((X / div) % base)

    for (i = 0; i < n; i++)
    {
        c[DIGIT(v[i])]++;
    }

    for (i = 0; i < base; i++)
    {
        t = c[i];
        c[i] = sum;
        sum += t;
    }

    for (int i = 0; i < n; i++)
    {
        temp[c[DIGIT(v[i])]] = v[i];
        c[DIGIT(v[i])]++;
    }

    memcpy(v, temp, n * sizeof(int));
}

void radixSort(int *v, int n)
{
    int div = 1, base = 10, *temp;
    int max = maxElement(v, n);
    temp = malloc(n * sizeof(int));

    while (max != 0)
    {
        counting(v, n, div, base, temp);
        div *= base;
        max /= base;
    }

    free(temp);
}

int main()
{
    int n = 10;
    int *v = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        v[i] = (rand() % 600);
    }

    printVector(v, n);

    radixSort(v, n);

    printVector(v, n);

    return EXIT_SUCCESS;
}