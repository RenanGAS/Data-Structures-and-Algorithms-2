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

void changePos(int *v, int i, int j)
{
    int aux = v[j];
    v[j] = v[i];
    v[i] = aux;
}

int partition(int *v, int p, int r)
{
    int pv = v[r];
    int i = p - 1;

    for (int j = p; j < r; j++)
    {
        if (v[j] <= pv)
        {
            i++;
            changePos(v, i, j);
        }
    }

    changePos(v, i + 1, r);

    return (i + 1);
}

void quickSort(int *v, int e, int d)
{
    if (e < d)
    {
        int r = partition(v, e, d);
        quickSort(v, e, r - 1);
        quickSort(v, r + 1, d);
    }
}

int main()
{
    int v[15] = {9, 7, 5, 3, 0, 1, 2, 20, 12, 10, 11, 13, -1, 8, 6};

    printVector(v, 15);

    quickSort(v, 0, 14);

    printVector(v, 15);

    printf("\n");

    return EXIT_SUCCESS;
}