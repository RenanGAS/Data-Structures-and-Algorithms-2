#include <stdio.h>
#include <stdlib.h>

int bigger(int *vector, int end)
{
    int pbigger = 0;

    for (int i = 1; i <= end; i++)
    {
        if (vector[pbigger] < vector[i])
        {
            pbigger = i;
        }
    }

    return pbigger;
}

int *selection_sort(int *vector, int end)
{
    for (int i = end; i > 0; i--)
    {
        int b = bigger(vector, i);

        int aux = vector[i];
        vector[i] = vector[b];
        vector[b] = aux;
    }

    return vector;
}

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

int main()
{
    int v[10] = {9, 5, 2, 3, 7, 1, 0, 4, 6, 8};

    printVector(v, 10);

    printVector(selection_sort(v, 9), 10);

    return EXIT_SUCCESS;
}