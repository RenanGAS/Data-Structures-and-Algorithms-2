#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint64_t fibo(int num)
{
    if (num <= 1)
    {
        return 1;
    }

    return fibo(num-1)+fibo(num-2);
}

int main(int args, char** argv)
{
    int num = atoi(argv[1]);

    uint64_t res = fibo(num);

    printf("\nfibo(%d) = %ld\n\n", num, res);

    return EXIT_SUCCESS;
}