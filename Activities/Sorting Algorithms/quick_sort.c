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

int partition(int *v, int p, int r)
{   
}

void quickSort(int *v, int e, int d)
{
}

int main()
{
    int v[15] = {9, 7, 5, 3, 0, 1, 2, 6, 12, 10, 11, 13, -1, 8, 20};

    printVector(v, 15);

    quickSort(v, 0, 14);

    printVector(v, 15);

    printf("\n");

    return EXIT_SUCCESS;
}