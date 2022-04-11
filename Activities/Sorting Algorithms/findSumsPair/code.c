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

void findPair(int *v, int n, int x)
{
    int i = 0;
    int f = n - 1;
    int sum = 0;

    while (i != f)
    {
        sum = v[i] + v[f];

        if (sum == x)
        {
            printf("\n%d %d\n\n", v[i], v[f]);
            return;
        }
        else if (sum < x)
        {
            i++;
        }
        else if (sum > x)
        {
            f--;
        }
    }

    printf("\nNão existe um par que resulte em %d\n\n", x);
}

int main()
{
    printf("\nVerificação da existência de dois números em um vetor, que somados correspondem a um determinado valor fornecido.\n");

    int n = 10;
    int v[10] = {3, 6, 7, 23, 3, 1, 10, 3, 5, 0};
    int x = 5;

    printVector(v, n);

    quickSort(v, 0, 9);

    findPair(v, n, x);

    return EXIT_SUCCESS;
}