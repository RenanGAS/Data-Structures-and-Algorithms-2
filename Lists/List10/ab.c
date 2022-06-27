#include "ab.h"
#include <stdlib.h>
#include <stdio.h>

int AB_TamanhoLazy(AB A, int tamE, int tamD, int n)
{
    if (A == NULL)
    {
        return n;
    }

    n++;

    tamE = AB_TamanhoLazy(A->esq, tamE, tamD, n);

    n = 0;

    tamD = AB_TamanhoLazy(A->dir, tamE, tamD, n);

    return tamE + tamD;
}

int AB_AlturaLazy(AB A, int n, int max, int flag)
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

    max = AB_AlturaLazy(A->esq, n, max, 1);

    max = AB_AlturaLazy(A->dir, n, max, 1);

    n -= 1;
}

int AB_AlturaEager(AB A)
{
    return A->h;
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

int AB_ComprimentoInternoLazy(AB A, int c)
{
    if (A == NULL)
    {
        return c;
    }

    c += A->profundidade;

    c = AB_ComprimentoInternoLazy(A->esq, c);

    c = AB_ComprimentoInternoLazy(A->dir, c);
}

int AB_ComprimentoInternoEager(AB A)
{
    return A->ci;
}

int AB_AB(AB A, int r)
{
    if (A == NULL)
    {
        return r;
    }

    if (A->esq != NULL && A->esq->dado > A->dado)
    {
        r = 0;
    }
    else if (A->dir != NULL && A->dir->dado <= A->dado)
    {
        r = 0;
    }

    r = AB_AB(A->esq, r);

    r = AB_AB(A->dir, r);
}

int AB_TamanhoEager(AB A)
{
    return A->n;
}

AB AB_Criar(int dado, AB e, AB d)
{
    AB no;

    no = malloc(sizeof(struct AB));
    no->dado = dado;
    no->esq = e;
    no->dir = d;
    no->profundidade = 0;
    no->n = 1;
    no->h = 0;
    no->ci = 0;

    return no;
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

void AB_Inserir(int dado, AB *A, int countH, AB *Acpy)
{
    if ((*A) == NULL)
    {
        if ((*Acpy)->h < countH)
        {
            (*Acpy)->h = countH;
        }

        (*Acpy)->ci += countH;

        *A = AB_Criar(dado, NULL, NULL);
        return;
    }
    else
    {
        (*A)->n++;
        countH++;

        if (dado < (*A)->dado)
        {
            AB_Inserir(dado, &(*A)->esq, countH, Acpy);
        }
        else
        {
            AB_Inserir(dado, &(*A)->dir, countH, Acpy);
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

    printf("(%c) (%d) (%d) %d\n", p, (*A)->profundidade, (*A)->n, (*A)->dado);

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
