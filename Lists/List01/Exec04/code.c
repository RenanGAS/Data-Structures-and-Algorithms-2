#include <stdio.h>
#include <stdlib.h>

int combination(int n, int k, int **m)
{
    if (k > n || k == 1)
    {
        return m[n][k];
    }
    else
    {
        m[n][k] = combination(n - 1, k, m) + combination(n - 1, k - 1, m);
    }

    return m[n][k];
}

int comb_wrapper(int n, int k)
{
    int **m = (int **)calloc(n + 1, sizeof(int *));

    for (int i = 0; i <= n; i++)
    {
        m[i] = (int *)calloc(k + 1, sizeof(int));
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if (i != 0 && j == 1)
            {
                m[i][j] = i;
            }
        }
    }

    return combination(n, k, m);
}

int main(int argc, char **argv)
{
    int n = atoi(argv[1]), k = atoi(argv[2]);

    int res = comb_wrapper(n, k);

    printf("\nConsiderando que cada comitê deva ter %d pessoas, com um grupo de %d conseguimos formar %d comitê(s) diferente(s).\n\n", k, n, res);

    return EXIT_SUCCESS;
}