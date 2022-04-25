#include <stdio.h>
#include <stdlib.h>

void printVector(int *vector, int size)
{
    printf("\nvector = [");

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

int minElem(int *v, int ini, int n)
{
    int min = ini;

    for (int i = ini + 1; i < n; i++)
    {
        if (v[i] < v[min])
        {
            min = i;
        }
    }

    return min;
}

void swap(int *v, int target, int src)
{
    int aux;
    aux = v[target];
    v[target] = v[src];
    v[src] = aux;
}

void selectionLessSort(int *v, int n)
{
    int min;

    for (int i = 0; i < n; i++)
    {
        min = minElem(v, i, n);
        swap(v, i, min);
    }
}

int main()
{
    int n = 10;
    int v[10] = {12, 33, 42, 9, 1, 98, 34, 63, 32, 8};

    printVector(v, n);

    selectionLessSort(v, n);

    printVector(v, n);

    printf("\n");

    return EXIT_SUCCESS;
}