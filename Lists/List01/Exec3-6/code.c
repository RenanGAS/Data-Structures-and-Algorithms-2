#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int floorOf(int num)
{
    if (num == 1)
    {
        return 0;
    }

    return 1 + floorOf(num / 2);
}

int main()
{
    int num = 98;
    float lg2n = log2(num); // log2(x) = y <=> 2^y = x

    int res = floorOf(num);

    printf("\nO piso de log2(%d) = %f é: %d\n\n", num, lg2n, res);

    return EXIT_SUCCESS;
}