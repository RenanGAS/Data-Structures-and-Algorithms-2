#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void copy_vector(int *v_x, int *v, int i, int f)
{
    for (i = i; i < f; i++)
    {
        if (i == f - 1)
        {
            v_x[i] = INT_MAX;
        }
        else
        {
            v_x[i] = v[i];
        }
    }
}

void merge_vectors(int *v, int p, int q, int r)
{
    int *v_e = calloc(q + 2, sizeof(int));
    int *v_d = calloc((r - q) + 1, sizeof(int));

    copy_vector(v_e, v, p, q + 1);
    copy_vector(v_d, v, q, r + 1);

    int i = 0;
    int j = 0;

    for (int k = 0; k <= r; k++)
    {
        if (v_e[i] < v_d[j])
        {
            v[k] = v_e[i];
            i++;
        }
        else
        {
            v[k] = v_d[j];
            j++;
        }
    }

    free(v_e);
    free(v_d);
}

void merge_sort(int *vector, int e, int d)
{
    if (e < d)
    {
        int m = (e + d) / 2;
        merge_sort(vector, e, m);
        merge_vectors(vector, e, m, d);
        merge_sort(vector, m + 1, d);
        merge_vectors(vector, e, m, d);
    }
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

    merge_sort(v, 0, 9);

    printVector(v, 10);

    return EXIT_SUCCESS;
}