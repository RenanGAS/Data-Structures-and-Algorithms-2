#include "shoplist.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char list[MAX_ITEMS] = "agua leite sucrilos suco";
    List *new_list = Create(list);
    Print(new_list);

    return EXIT_SUCCESS;
}