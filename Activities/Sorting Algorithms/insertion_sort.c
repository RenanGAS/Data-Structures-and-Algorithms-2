#include <stdio.h>
#include <stdlib.h>

void verify(int *vector, int pos)
{
    int toInsert = vector[pos];

    while (pos > 0 && vector[pos - 1] > toInsert)
    {
        vector[pos] = vector[pos - 1];
        pos--;
    }

    vector[pos] = toInsert;
}

int *insertion_sort(int *vector, int end)
{
    for (int i = 1; i <= end; i++)
    {
        verify(vector, i);
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

    printVector(insertion_sort(v, 9), 10);

    return EXIT_SUCCESS;
}