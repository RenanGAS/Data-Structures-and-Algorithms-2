#include <stdio.h>
#include <stdlib.h>

int sucessor(int x)
{
    return x + 1;
}

int sum(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    else if (b == 0)
    {
        return a;
    }

    if (a > b)
    {
        return sum(sucessor(a), b - 1);
    }
    else
    {
        return sum(a - 1, sucessor(b));
    }
}

int main()
{
    int a = 0, b = 0;

    printf("\nDigite um valor para 'a': ");
    scanf("%d", &a);

    printf("\nDigite um valor para 'b': ");
    scanf("%d", &b);

    int res = sum(a, b);

    printf("\n%d + %d = %d\n\n", a, b, res);

    return EXIT_SUCCESS;
}