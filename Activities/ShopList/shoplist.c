#include "shoplist.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list
{
    char **items;
    int n;
};

List *Create(char *list)
{
    List *new_list = malloc(sizeof(List));
    new_list->items = malloc(MAX_ITEMS * sizeof(char));
    char *item = strtok(list, " ");

    int i = 0;

    while (item != NULL)
    {
        new_list->items[i] = malloc(MAX_TAM * sizeof(char));
        strcpy(new_list->items[i], item);
        i++;
        item = strtok(NULL, " ");
    }

    new_list->n = i;

    printf("\nLista criada.\n");

    return new_list;
}

static void merge(char **v, int p, int q, int r)
{
    char **e, **d;
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;
    char sentinela[] = "zzzzzz";
    e = malloc(sizeof(char *) * (n1 + 1));
    d = malloc(sizeof(char *) * (n2 + 1));
    for (i = 0; i < n1; i++)
        e[i] = v[p + i];
    for (j = 0; j < n2; j++)
        d[j] = v[q + 1 + j];
    e[n1] = sentinela;
    d[n2] = sentinela;
    i = 0;
    j = 0;
    for (k = p; k <= r; k++)
    {
        if (strcmp(e[i], d[j]) <= 0)
        {
            v[k] = e[i];
            i++;
        }
        else
        {
            v[k] = d[j];
            j++;
        }
    }
    free(e);
    free(d);
}

static void MergeSort(char **v, int e, int d)
{
    if (e < d)
    {
        int m = (e + d) / 2;
        MergeSort(v, e, m);
        MergeSort(v, m + 1, d);
        merge(v, e, m, d);
    }
}

void Sort(List *l)
{
    MergeSort(l->items, 0, l->n - 1);

    printf("\nLista ordenada.\n");
}

char *NoRepeat(List *l)
{
    Sort(l);
    char *max_list = malloc(BUF_LEN * sizeof(char));
    max_list[0] = '\0';
    strcat(max_list, l->items[0]);
    strcat(max_list, " ");

    char ref[21] = "";
    strcpy(ref, l->items[0]);

    for (int i = 1; i < l->n; i++)
    {
        if (strcmp(l->items[i], ref) != 0)
        {
            strcat(max_list, l->items[i]);
            strcat(max_list, " ");
            strcpy(ref, l->items[i]);
        }
    }

    printf("\nElementos repetidos deletados.\n");

    return max_list;
}

void Print(List *l)
{
    printf("\nLista de Compras:");

    for (int i = 0; i < l->n; i++)
    {
        if (i != l->n - 1)
        {
            printf(" %s,", l->items[i]);
        }
        else
        {
            printf(" %s\n", l->items[i]);
        }
    }
}

void Delete(List *l)
{
    for (int i = 0; i < l->n; i++)
    {
        free(l->items[i]);
    }

    free(l->items);
    free(l);

    printf("\nLista deletada.\n\n");
}