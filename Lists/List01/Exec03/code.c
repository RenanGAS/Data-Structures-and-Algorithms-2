#include <stdio.h>
#include <stdlib.h>

#define EXE 0

int recursiveMDC(int x, int y)
{
    if (x >= y && x % y == 0)
    {
        return y;
    }
    else if (x < y)
    {
        return recursiveMDC(y, x);
    }

    return recursiveMDC(y, x % y);
}

int iterativeMDC(int x, int y)
{
    int i, aux;

    for (i = y; x % i != 0; x = y, i = aux)
    {
        aux = x;

        if (x >= i)
        {
            aux = x % i;
        }
    }

    return i;
}

int main(int argc, char **argv)
{
    int x = atoi(argv[1]), y = atoi(argv[2]);

#if EXE == 0
    int res = recursiveMDC(x, y);
#endif

#if EXE == 1
    int res = iterativeMDC(x, y);
#endif

    printf("\nO MDC de %d e %d é %d.\n\n", x, y, res);

    return EXIT_SUCCESS;
}