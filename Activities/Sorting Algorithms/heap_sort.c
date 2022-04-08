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

void max_Heapify(int *v, int n, int i)
{
    int left = 2 * i + 1;
    int right = left + 1;

    if (left >= n)
    {
        return;
    }
    else
    {
        int aux = v[i];

        if (v[i] < v[left] && v[left] >= v[right])
        {

            v[i] = v[left];
            v[left] = aux;
            max_Heapify(v, n, left);
        }
        else if (v[i] < v[right] && v[right] >= v[left])
        {
            v[i] = v[right];
            v[right] = aux;
            max_Heapify(v, n, right);
        }
    }
}

void build_MaxHeap(int *v, int n)
{
    int init = n / 2 - 1;
    for (int i = init; i >= 0; i--)
    {
        max_Heapify(v, n, i);
    }
}

void heap_sort(int *v, int n)
{
    int f = n - 1;

    while (f != 1)
    {
        int aux = v[0];
        v[0] = v[f];
        v[f] = aux;

        f--;

        max_Heapify(v, f, 0);
    }

    return;
}

int main()
{
    int n = 15;
    int v[15] = {9, 7, 5, 3, 0, 1, 2, 20, 12, 10, 11, 13, -1, 8, 6};

    printVector(v, n);

    build_MaxHeap(v, n);

    printVector(v, n);

    heap_sort(v, n);

    printVector(v, n);

    printf("\n");

    return EXIT_SUCCESS;
}