#include "shoplist.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char list[MAX_ITEMS] = "agua leite sucrilos suco carne carne sucrilos laranja uva melancia laranja";
    List *new_list = Create(list);
    Print(new_list);
    Sort(new_list);
    Print(new_list);
    char *new_list_ = NoRepeat(new_list);
    printf("\nLista de Compras: %s\n", new_list_);
    Delete(new_list);

    return EXIT_SUCCESS;
}