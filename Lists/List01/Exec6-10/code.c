#include <stdio.h>
#include <stdlib.h>

int max(int x, int y)
{
    if (x >= y)
    {
        return x;
    }

    return y;
}

int maximum(int *v, int i, int f)
{
    int n_max = 0;

    if (i != f)
    {
        int m = (i + f) / 2;
        int left_side = maximum(v, i, m);
        int right_side = maximum(v, m + 1, f);
        n_max = max(left_side, right_side);
    }
    else
    {
        return v[i];
    }
    
    return n_max;
}

int main()
{
    printf("\nCálculo do maior número de uma sequência de números inteiros, através de uma Função Recursiva\n");

    int v[10] = {41, 63, 70, 52, 37, 16, 85, 18, 94, 21};

    int res = maximum(v, 0, 9);

    printf("\nMaior = %d\n\n", res);

    return EXIT_SUCCESS;
}