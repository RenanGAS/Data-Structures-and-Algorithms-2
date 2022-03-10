#include <stdio.h>
#include <math.h>

int ds(int n)
{
    if (n == 0)
    {
        return 0;
    }

    return n % 2 + 10*ds(n / 2);
}

int main()
{
    int n = 17;
    int r = ds(n);
    printf("\n%d = %d\n\n", n, r);

}