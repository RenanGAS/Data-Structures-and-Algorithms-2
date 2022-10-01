#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 10024;
    int l = 0, r = n - 1, m = 0;
    int res = -1, exec = 0;

    while (r >= l)
    {
        exec++;

        m = l + ((r - l) / 2);

        if ((m * m) == n)
        {
            res = m;
            break;
        }

        if ((m * m) < n)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }

    if (res != -1)
    {
        printf("\nThe integer root of %d is: %d.\n", n, m);
    }
    else
    {
        printf("\nThere is no integer root for %d.\n", n);
    }

    printf("\nNumber of executions: %d.\n\n", exec);

    return EXIT_SUCCESS;
}