#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

void copy_vector(int *v_x, int *v, int tam, int ref)
{
    for (int i = 0; i < tam; i++)
    {
        v_x[i] = v[i + ref];
    }

    v_x[tam] = INT_MAX;
}

void merge_vectors(int *v, int p, int q, int r)
{
    int tam_e = q - p + 1;
    int tam_d = r - q;

    int *v_e = calloc(tam_e + 1, sizeof(int));
    int *v_d = calloc(tam_d + 1, sizeof(int));

    copy_vector(v_e, v, tam_e, p);
    copy_vector(v_d, v, tam_d, q + 1);

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
    int v[15] = {9, 7, 5, 3, 0, 1, 2, 6, 12, 10, 11, 13, -1, 8, 20};

    printVector(v, 15);

    merge_sort(v, 0, 14);

    printVector(v, 15);

    printf("\n");

    return EXIT_SUCCESS;
}