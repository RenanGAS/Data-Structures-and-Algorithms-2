#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

void copy_vector(int *v_x, int *v, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        if (i == tam - 1)
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
    int tam_e = q - p + 1;
    int tam_d = r - q;

    int *v_e = calloc(tam_e + 1, sizeof(int));
    int *v_d = calloc(tam_d + 1, sizeof(int));

    copy_vector(v_e, v, tam_e);
    copy_vector(v_d, v, tam_d);

    int i = 0;
    int j = 0;

    for (int k = p; k <= r; k++)
    {
        if (v_e[i] <= v_d[j])
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
        merge_sort(vector, m + 1, d);
        merge_vectors(vector, e, m, d);
    }
}

int main()
{
    int v[10] = {9, 5, 3, 1};

    printVector(v, 4);

    merge_sort(v, 0, 3);

    printVector(v, 4);

    return EXIT_SUCCESS;
}