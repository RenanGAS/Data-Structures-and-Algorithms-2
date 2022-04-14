#include <stdio.h>
#include <stdlib.h>

int fiboSequence(int n2, int n1, int n)
{
    if (n < 2)
    {
        return 1;
    }

    return fiboSequence(n1 - 2, n1 - 1, n1) + fiboSequence(n2 - 2, n2 - 1, n2);
}

int main()
{
    int n = 11;

    int res = fiboSequence(n - 2, n - 1, n);

    printf("\nfiboSequence(%d) = %d\n\n", n, res);

    return EXIT_SUCCESS;
}