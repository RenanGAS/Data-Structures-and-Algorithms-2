#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 0

typedef struct v
{
    int data;
    int key;
} V;

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

void printStruct(V **s, int n)
{
    printf("\nv =");
    for (int i = 0; i < n; i++)
    {
        printf(" %d |", s[i]->data);
    }

    printf("\n   ");

    for (int i = 0; i < n; i++)
    {
        printf("  %d |", s[i]->key);
    }

    printf("\n\n");
}

void printStructNull(V **s, int n)
{
    printf("\nv =");
    for (int i = 0; i < n; i++)
    {
        printf(" %d |", s[i]->data);
    }

    printf("\n   ");

    for (int i = 0; i < n; i++)
    {
        printf(" %d |", s[i]->key);
    }

    printf("\n\n");
}

int maxElement(V **v, int n)
{
    int m = v[0]->key;

    for (int i = 1; i < n; i++)
    {
        if (m < v[i]->key)
        {
            m = v[i]->key;
        }
    }

    return m;
}

void counting_sort(V **v, int n)
{
    int i, t, sum = 0;
    int max = maxElement(v, n) + 2;

    V **s = malloc(n * sizeof(V));
    int *c = calloc(max, sizeof(int));

    for (i = 0; i < max; i++)
    {
        c[v[i]->key]++;
    }

#if DEBUG
    printf("\n");
    printVector(c, max);
#endif

    for (int i = 0; i < max; i++)
    {
        t = c[i];
        c[i] = sum;
        sum += t;
    }

#if DEBUG
    printf("\n");
    printVector(c, max);
    printf("\n");
#endif

    for (i = 0; i < n; i++)
    {
        s[c[v[i]->key]] = v[i];
        c[v[i]->key]++;
    }

#if DEBUG
    printStruct(s, n);
    printf("\n");
#endif

    memcpy(v, s, n * sizeof(V));
}

int main()
{
    int n = 11;
    V **vector = malloc(n * sizeof(V));

    for (int i = 0; i < n; i++)
    {
        vector[i] = calloc(2, sizeof(int));
        vector[i]->key = rand() % 10;
        vector[i]->data = (rand() % 60) + 10;
    }

    printStruct(vector, n);

    counting_sort(vector, n);

    printStruct(vector, n);

    return EXIT_SUCCESS;
}