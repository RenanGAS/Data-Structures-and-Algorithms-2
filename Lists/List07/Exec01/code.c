#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define A 0

#define B 1

#define C 1

#if A

unsigned int string_hash(char *string, int M)
{
    int K = 31, pos = 0, convert_aux = 0, ac_aux = 0, len_aux = strlen(string), i;

    for (i = 0; string[i] != '\0'; i++)
    {
        convert_aux = string[i];
        len_aux--;
        ac_aux += convert_aux * pow(K, len_aux);
    }

    pos = ac_aux % M;

    return pos;
}

#endif

#if B

unsigned int horner_method(char *string, int K, int i, unsigned int p)
{
    int aux = 0;

    if (i == strlen(string))
    {
        return p;
    }

    aux = string[i];

    p = p * K + aux;

    i++;

    horner_method(string, K, i, p);
}

unsigned int string_hash(char *string, int M)
{
    int K = 31, pos = 0, res = 0;

    res = horner_method(string, K, 1, string[0]);

    pos = res % M;

    return pos;
}

#endif

#if C

void fa(int n)
{
    int i, countSoma = 0, countMult = 0, cpyN = n;

    for (i = 0; i < n; i++)
    {
        countSoma++;
        countMult += cpyN;
        cpyN--;
    }

    printf("\n\nAlgoritmo simples:\n");
    printf("\nNúmero de somas = %d, número de multiplicações = %d\n\n", countSoma, countMult);
}

void fb(int n)
{
    int i = 1, countSoma = 0, countMult = 0;

    while (i != n)
    {
        countSoma++;
        countMult++;
        i++;
    }
    
    printf("\nMétodo de Horner:\n");
    printf("\nNúmero de somas = %d, número de multiplicações = %d\n\n", countSoma, countMult);
}

#endif

int main()
{
    char string[4] = "ABC";

    int r = string_hash(string, 37);

    printf("\nPosição de \"%s\" na Hash Table = %d\n\n", string, r);
#if C
    printf("\n\nPara n = 5:\n");
    fa(5);
    fb(5);

    printf("\n\nPara n = 10:\n");
    fa(10);
    fb(10);

    printf("\n\nPara n = 20:\n");
    fa(20);
    fb(20);

    printf("\n\nPara n = 100:\n");
    fa(100);
    fb(100);
#endif

    return EXIT_SUCCESS;
}