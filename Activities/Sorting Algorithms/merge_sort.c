#include <stdio.h>
#include <stdlib.h>

void merge_vectors(int *v, int p, int q, int r)
{
}

void merge_sort(int *vector, int e, int d)
{
    if(e < d){
        int m = (e + d) / 2;
        merge_sort(v, e, m);
        merge_sort(v, m + 1, d);
        merge_vectors(v, e, m, d);
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

    printVector(merge_sort(v, 9), 10);

    return EXIT_SUCCESS;
}