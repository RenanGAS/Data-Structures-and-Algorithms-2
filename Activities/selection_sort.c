#include <stdio.h>
#include <stdlib.h>

int maior(int *vector, int end)
{
    int pmaior = 0;

    for (int i = 1; i <= end; i++)
    {
        if (vector[pmaior] < vector[i])
        {
            pmaior = i;

        }
    }

    return pmaior;
}

int *selection_sort(int *vector, int end)
{
    for (int i = end; i > 0; i--)
    {
        int m = maior(vector, i);

        int aux = vector[i];
        vector[i] = vector[m];
        vector[m] = aux;
    }

    return vector;
}

void printVector(int *vector, int tam)
{
    printf("\nvector = [");

    for (int i = 0; i < tam; i++)
    {
        if (i != tam - 1)
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