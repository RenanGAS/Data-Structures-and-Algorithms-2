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

int ABB_Altura(AB A, int n, int max, int flag)
{
    if (A == NULL)
    {
        flag = 0;

        if (n > max)
        {
            max = n;
        }

        return max;
    }

    if (flag)
    {
        n++;
    }

    max = ABB_Altura(A->esq, n, max, 1);

    max = ABB_Altura(A->dir, n, max, 1);

    n -= 1;
}

void AB_CalcularProfundidades(AB A, int p)
{
    if (A == NULL)
    {
        return;
    }

    A->profundidade = p;

    p++;

    AB_CalcularProfundidades(A->esq, p);

    AB_CalcularProfundidades(A->dir, p);

    p -= 2;
}

AB AB_Criar(int dado, AB e, AB d)
{
    AB n;

    n = malloc(sizeof(struct AB));
    n->dado = dado;
    n->esq = e;
    n->dir = d;
    n->profundidade = 0;

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

    printf("(%c) (%d) %d\n", p, (*A)->profundidade, (*A)->dado);

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
