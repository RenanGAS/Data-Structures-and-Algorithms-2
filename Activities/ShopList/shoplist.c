#include "shoplist.h"
#include <string.h>

struct list
{
    char **items;
    int n;
};

List *Create(char *items)
{
    List *new_list = calloc(sizeof(List));
    new_list->items = calloc(MAX_ITEMS, sizeof(char));
    char *item = strtok(new_list->items, " ");
}

void Sort(List *l);

char *NoRepeat(List *l);

void Print(List *l);

void Delete(List *l);