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

    return new_list;
}

void Sort(List *l);

char *NoRepeat(List *l);

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

void Delete(List *l);