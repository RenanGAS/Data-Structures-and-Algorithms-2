#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int max = maxElement(v, n) + 2;

    int *c = calloc(max, sizeof(int));

    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < max; j++)
        {
            if (v[j]->key == i)
            {
                c[i]++;
            }
        }
    }

    // printf("\n");
    // printVector(c, max);

    V **s = malloc(n * sizeof(V));

    int countS = 0;

    for (int i = 0; i < max; i++)
    {
        if (c[i] > 0)
        {
            for (int j = 0; j < c[i]; j++)
            {
                s[countS] = calloc(2, sizeof(int));
                s[countS]->key = i;
                countS++;
            }
        }
    }

    // printf("\n");
    // printStructNull(s, n);

    for (int i = max - 1; i >= 0; i--)
    {
        int pull = c[i];

        for (int j = 0; j < i; j++)
        {
            c[i] += c[j];
        }

        c[i] -= pull;
    }

    // printf("\n");
    // printVector(c, max);
    // printf("\n");

    for (int i = 0; i < n; i++)
    {
        s[c[v[i]->key]]->data = v[i]->data;
        c[v[i]->key]++;
    }

    // printStruct(s, n);
    // printf("\n");

    memcpy(&v, &s, n);

    printStruct(v, n);
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

    // printStruct(vector, n);

    return EXIT_SUCCESS;
}