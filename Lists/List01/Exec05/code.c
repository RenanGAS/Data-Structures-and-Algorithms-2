#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool Explorar(A, i, j)
{
}

int main()
{
    int A[10][10] = {
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 1, 1, 1, 1, 0, 1, 1, 1, 1},
        {0, 1, 1, 0, 0, 0, 1, 1, 0, 0},
        {0, 1, 1, 0, 1, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {1, 0, 1, 1, 1, 0, 1, 1, 1, 0},
        {1, 0, 1, 1, 1, 0, 1, 0, 0, 0},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
    };

    bool res = Explorar(A, 0, 0);

    if (!res)
    {
        printf("\nNão existe um caminho para a saída!\n\n");
    }

    return EXIT_SUCCESS;
}