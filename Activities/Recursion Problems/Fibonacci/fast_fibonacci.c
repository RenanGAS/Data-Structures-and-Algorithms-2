#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint64_t f_fibo(int num, uint64_t* memo);

uint64_t w_fibo(int num)
{
    uint64_t* memo = calloc(num+1, sizeof(uint64_t));
    memo[0] = 1;
    memo[1] = 1;

    uint64_t res = f_fibo(num, memo);

    free(memo);

    return res;
}

uint64_t f_fibo(int num, uint64_t* memo)
{
    if (memo[num] != 0)
    {
        return memo[num];
    }
    
    uint64_t numL = f_fibo(num-1, memo);
    uint64_t numR = f_fibo(num-2, memo);
    memo[num] = numL + numR;

    return numL + numR;
}

int main(int args, char** argv)
{
    int num = atoi(argv[1]);

    uint64_t res = w_fibo(num);

    printf("\nfibo(%d) = %ld\n\n", num, res);

    return EXIT_SUCCESS;
}