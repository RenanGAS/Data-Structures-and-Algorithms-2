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

static int binarySearch(int *v, int e, int d, int x)
{
    int m = 0;

    if (e <= d)
    {
        m = (e + d) / 2;

        if (v[m] == x)
        {
            return m;
        }
        else if (v[m] > x)
        {
            return binarySearch(v, e, m - 1, x);
        }

        return binarySearch(v, m + 1, d, x);
    }

    return -1;
}

int binarySearch_wrapper(int *v, int n, int x)
{
    int res = binarySearch(v, 0, n - 1, x);

    return res;
}

int main()
{
    int n = 10;
    int x = 53;
    int v[10] = {12, 53, 98, 0, 2, 87, 34, 57, 38, 23};

    quickSort(v, 0, n - 1);

    printVector(v, n);

    int pos = binarySearch_wrapper(v, n, x);

    if (pos != -1)
    {
        printf("\nO elemento %d está na posição %d.\n\n", x, pos);
    }
    else
    {
        printf("\nO elemento %d não pertence ao vetor.\n\n", x);
    }

    return EXIT_SUCCESS;
}