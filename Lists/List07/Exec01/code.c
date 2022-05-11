#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define A 1

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

int main()
{
    char string[4] = "ABC";

    int r = string_hash(string, 37);

    printf("\nPosição de \"%s\" na Hash Table = %d\n\n", string, r);

    return EXIT_SUCCESS;
}