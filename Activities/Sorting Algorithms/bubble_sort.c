#include <stdio.h>
#include <stdlib.h>

void bubbling(int *vector, int end)
{
    int aux1 = 0;
    for (int i = 1; i <= end; i++)
    {
        if (vector[aux1] > vector[i])
        {
            int aux2 = vector[i];
            vector[i] = vector[aux1];
            vector[aux1] = aux2;
        }

        aux1++;
    }
}

int *bubble_sort(int *vector, int end)
{
    for (int i = end; i > 0; i--)
    {
        bubbling(vector, i);
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

    printVector(bubble_sort(v, 9), 10);

    return EXIT_SUCCESS;
}