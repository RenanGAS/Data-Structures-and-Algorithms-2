#include "ab.h"
#include <stdlib.h>
#include <stdio.h>

int AB_Tamanho(AB A, int tamE, int tamD, int n)
{
    if (A == NULL)
    {
        return n;
    }

    n++;

    tamE = AB_Tamanho(A->esq, tamE, tamD, n);

    n = 0;

    tamD = AB_Tamanho(A->dir, tamE, tamD, n);

    return tamE + tamD;
}

AB AB_Criar(int dado, AB e, AB d)
{
    AB n;

    n = malloc(sizeof(struct AB));
    n->dado = dado;
    n->esq = e;
    n->dir = d;

    return n;
}

AB AB_Buscar(int dado, AB A)
{
    if (A == NULL)
    {
        return NULL;
    }

    if (A->dado == dado)
    {
        return A;
    }

    if (dado < A->dado)
    {
        return AB_Buscar(dado, A->esq);
    }

    return AB_Buscar(dado, A->dir);
}

void AB_Inserir(int dado, AB *A)
{
    if ((*A) == NULL)
    {
        *A = AB_Criar(dado, NULL, NULL);
        return;
    }
    else
    {
        if (dado < (*A)->dado)
        {
            AB_Inserir(dado, &(*A)->esq);
        }
        else
        {
            AB_Inserir(dado, &(*A)->dir);
        }
    }
}

void AB_Imprimir(AB *A, int i, char p)
{
    if ((*A) == NULL)
    {
        return;
    }

    for (int j = 0; j < i; j++)
    {
        printf("\t");
    }

    printf("(%c) %d\n", p, (*A)->dado);

    i++;

    AB_Imprimir(&(*A)->esq, i, 'e');

    AB_Imprimir(&(*A)->dir, i, 'd');

    i -= 2;
}

void AB_Destruir(AB *A)
{
    if (*A == NULL)
    {
        return;
    }

    AB_Destruir(&(*A)->esq);
    AB_Destruir(&(*A)->dir);
    free(*A);
}
