#include <stdio.h>
#include <stdlib.h>

static int binarySearch(int *v, int e, int d, int x)
{
    int m = 0;

    if (e <= d)
    {
        m = (e + d) / 2;

        if (v[m] == x)
        {
            return m;
        }
        else if (v[m] > x)
        {
            return binarySearch(v, e, m - 1, x);
        }

        return binarySearch(v, m + 1, d, x);
    }

    return -1;
}

int binarySearch_wrapper(int *v, int n, int x)
{
    int res = binarySearch(v, 0, n - 1, x);

    return res;
}

int linearSearch(int *v, int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (v[i] == x)
        {
            return i;
        }
        else if (v[i] > x)
        {
            break;
        }
    }

    return -1;
}