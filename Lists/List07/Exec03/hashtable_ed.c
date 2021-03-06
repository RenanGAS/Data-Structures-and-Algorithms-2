#include <stdlib.h>
#include <stdio.h>
#include "ilist.h"
#include "hashtable_ed.h"

int THED_Hash(THED *HT, int chave)
{
    return chave % HT->m;
}

THED *THED_Criar(int m, int alloc_step)
{
    THED *nova;
    nova = malloc(sizeof(THED));
    nova->m = m;
    nova->n = 0;
    nova->t = malloc(sizeof(ILIST *) * m);
    for (int i = 0; i < m; i++)
        nova->t[i] = ILIST_Criar(alloc_step);
    return nova;
}

void THED_Inserir(THED *HT, int chave, int valor)
{
    int h = THED_Hash(HT, chave);
    int tam_lista = ILIST_Tamanho(HT->t[h]);
    ILIST_Inserir(HT->t[h], chave, valor);
    if (tam_lista != ILIST_Tamanho(HT->t[h]))
        HT->n++;
}

void THED_Remover(THED *HT, int chave)
{
    int h = THED_Hash(HT, chave);
    int tam_lista = ILIST_Tamanho(HT->t[h]);
    ILIST_Remover(HT->t[h], chave);
    if (tam_lista != ILIST_Tamanho(HT->t[h]))
        HT->n--;
}

INOH *THED_Buscar(THED *HT, int chave)
{
    int h = THED_Hash(HT, chave);
    int p = ILIST_Buscar(HT->t[h], chave);
    return ILIST_Endereco(HT->t[h], p);
}

void THED_Imprimir(THED *HT)
{
    printf("\nTABELA HASH M = %ld\n\n", HT->m);
    for (int i = 0; i < HT->m; i++)
    {
        printf("\n%d:\n", i);
        ILIST_Imprimir(HT->t[i], 0);
    }
    printf("\n==========\n\n");
}

size_t THED_N(THED *HT)
{
    return HT->n;
}

ILIST *THED_Chaves(THED *HT)
{
    ILIST *s = ILIST_Criar(THED_N(HT) + 1);
    INOH *p;
    for (int i = 0; i < HT->m; i++)
    {
        ILIST_Rebobinar(HT->t[i]);
        p = ILIST_Prox(HT->t[i]);
        while (p != NULL)
        {
            ILIST_Inserir(s, p->chave, p->valor);
            p = ILIST_Prox(HT->t[i]);
        }
    }
    return s;
}

void THED_Destruir(THED *HT)
{
    for (int i = 0; i < HT->m; i++)
        ILIST_Destruir(HT->t[i]);
    free(HT->t);
    free(HT);
}

THED *inserir_n_aleatorios(int n, int m, int seed)
{
    int i, chave;

    THED *new_ht = malloc(sizeof(THED));

    new_ht->m = m;
    new_ht->n = 0;
    new_ht->t = malloc(m * sizeof(ILIST *));

    for (i = 0; i < m; i++)
    {
        new_ht->t[i] = ILIST_Criar(10);
    }

    srand(seed);

    for (i = 0; i < n; i++)
    {
        chave = rand() % (10 * n);
        THED_Inserir(new_ht, chave, (rand() % 10) + 1);
    }

    return new_ht;
}

int THED_MaisLonga(THED *TH)
{
    int i;

    int max_size = TH->t[0]->tam;

    for (i = 1; i < TH->m; i++)
    {
        if (TH->t[i]->tam > max_size)
        {
            max_size = TH->t[i]->tam;
        }
    }

    return max_size;
}

int THED_MaisCurta(THED *TH)
{
    int i;

    int min_size = TH->t[0]->tam;

    for (i = 1; i < TH->m; i++)
    {
        if (TH->t[i]->tam < min_size)
        {
            min_size = TH->t[i]->tam;
        }
    }

    return min_size;
}

float THED_TamMedio(THED *TH)
{
    int i;

    float sum_sizes = 0;

    for (i = 0; i < TH->m; i++)
    {
        sum_sizes += TH->t[i]->tam;
    }

    return (sum_sizes / TH->m);
}
