#include <stdio.h>
#include <stdlib.h>

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

    int res = iterativeMDC(x, y);

    printf("\nO MDC de %d e %d é %d.\n\n", x, y, res);

    return EXIT_SUCCESS;
}