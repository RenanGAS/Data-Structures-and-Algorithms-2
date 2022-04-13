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

int linearSearch(int *v, int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (v[i] == x)
        {
            return i;
        }
        else if (v[i] > x)
        {
            break;
        }
    }

    return -1;
}

int main()
{
    int n = 10;
    int x = 32;
    int v[10] = {23, 53, 1, 2, 0, 3, 32, 98, 58, 28};

    quickSort(v, 0, 9);

    printVector(v, n);

    int pos = linearSearch(v, n, x);

    if (pos != -1)
    {
        printf("\nO elemento %d está na posição %d.\n\n", x, pos);
    }
    else
    {
        printf("\nO elemento não pertence à lista.\n\n");
    }

    return EXIT_SUCCESS;
}