#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalin(char *str, int i, int f)
{
    if (i == f || i + 1 == f)
    {
        return str[i] == str[f];
    }

    return str[i] == str[f] & isPalin(str, i + 1, f - 1);
}

int main()
{
    printf("\nVerificação da palindromidade de uma string através de uma Função Recursiva\n");

    char str[100];

    printf("\nDigite uma palavra: ");
    scanf("%s", str);

    int f = 0;
    printf("\nDigite a posição de sua última letra: ");
    scanf("%d", &f);

    if (isPalin(str, 0, f))
    {
        printf("\n\"%s\" é palíndromo!\n\n", str);
    }
    else
    {
        printf("\n\"%s\" não é palíndromo!\n\n", str);
    }
    
    return EXIT_SUCCESS;
}