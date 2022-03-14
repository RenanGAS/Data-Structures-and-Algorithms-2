#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool Explorar(int A[10][10],int i,int j)
{
    if (i > 9 || i < 0 || j > 9 || j < 0)
    {
        return false;
    }

    if (A[i][j] == 1 || A[i][j] == 2)
    {
        return false;
    }

    A[i][j] = 2;

    if (A[i][j] == A[9][9])
    {
        return true;
    }

    if (Explorar(A, i - 1, j))
    {
        printf(" (%d, %d) ", i-1, j);
        return true;
    }

    if (Explorar(A, i + 1, j))
    {
        printf(" (%d, %d) ", i+1, j);
        return true;
    }

    if (Explorar(A, i, j - 1))
    {
        printf(" (%d, %d) ", i, j - 1);
        return true;
    }

    if (Explorar(A, i, j + 1))
    {
        printf(" (%d, %d) ", i, j + 1);
        return true;
    }
    
    return false;
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
    
    printf("\n");
    
    bool res = Explorar(A, 0, 0);

    if (!res)
    {
        printf("\nNão existe um caminho para a saída!\n\n");
    }
    else
    {
        printf(" (0, 0)\n\n");
    }
    
    return EXIT_SUCCESS;
}