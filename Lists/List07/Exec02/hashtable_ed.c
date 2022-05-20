#include <stdlib.h>
#include <stdio.h>
#include "ilist.h"
#include "hashtable_ed.h"

#define B 0

#define C 0

// Funções Auxiliares

#if B

static int sendFirst(THED *TH)
{
    int i;
    for (i = 0; i < TH->m; i++)
    {
        if (TH->t[i]->tam > 0)
        {
            return TH->t[i]->nos[0].chave;
        }
    }
}

int max(THED *TH)
{
    int max = sendFirst(TH), i, j;

    for (i = 0; i < TH->m; i++)
    {
        for (j = 0; j < TH->t[i]->tam; j++)
        {
            INOH *no_elem = ILIST_Endereco(TH->t[i], j);

            if (no_elem->chave > max)
            {
                max = no_elem->chave;
            }
        }
    }

    return max;
}

int min(THED *TH)
{
    int min = sendFirst(TH), i, j;

    for (i = 0; i < TH->m; i++)
    {
        for (j = 0; j < TH->t[i]->tam; j++)
        {
            INOH *no_elem = ILIST_Endereco(TH->t[i], j);

            if (no_elem->chave < min)
            {
                min = no_elem->chave;
            }
        }
    }

    return min;
}

#endif

#if C

int min(THED *TH)
{
    return TH->min;
}

int max(THED *TH)
{
    return TH->max;
}

#endif

// Funções Principais

int THED_Hash(THED *TH, int chave)
{
    return chave % TH->m;
}

static void THED_Redimensionar(THED *HT, float c, size_t reserva)
{
    if (((float) HT->n / HT->m) <= c)
    {
        return;
    }

    int new_m = (HT->m * 2) + reserva;

    ILIST **new_t = malloc(new_m * sizeof(ILIST *));

    for (int i = 0; i < new_m; i++)
    {
        new_t[i] = malloc(sizeof(ILIST));
    }

    ILIST **old_t = HT->t;
    int old_m = HT->m;

    HT->t = new_t;
    HT->m = new_m;
    HT->n = 0;

    for (int i = 0; i < old_m; i++)
    {
        if (old_t[i]->tam > 0)
        {
            for (int j = 0; j < old_t[i]->tam; j++)
            {
                THED_Inserir(HT, old_t[i]->nos[j].chave, old_t[i]->nos[j].valor);
            }
        }
    }
}

THED *THED_Criar(int m, int alloc_step, float c)
{
    int i;
    THED *nova_th;
    nova_th = malloc(sizeof(THED));

    nova_th->m = m;
    nova_th->n = 0;
    nova_th->diffMin = 0;
    nova_th->diffMax = 0;
    nova_th->flag = 0;
    nova_th->c = c;
    nova_th->t = malloc(sizeof(ILIST *) * m);

    for (i = 0; i < m; i++)
    {
        nova_th->t[i] = ILIST_Criar(alloc_step);
    }

    return nova_th;
}

void THED_Inserir(THED *TH, int chave, int valor)
{
    int pos = THED_Hash(TH, chave);

    int list_size = ILIST_Tamanho(TH->t[pos]);

    int boolValue = ILIST_Inserir(TH->t[pos], chave, valor);

    if (list_size != ILIST_Tamanho(TH->t[pos]))
    {
        TH->n++;
    }

#if C

    if (!TH->flag)
    {
        TH->min = chave;
        TH->max = chave;
        TH->flag = 1;
    }

    if (TH->max < chave)
    {
        TH->diffMax = chave - TH->max;
        TH->max = chave;
    }
    else if (TH->min > chave)
    {
        TH->diffMin = TH->min - chave;
        TH->min = chave;
    }

#endif

    size_t reserva = 5;
    
    THED_Redimensionar(TH, TH->c, reserva);
}

void THED_Remover(THED *TH, int chave)
{
    int pos = THED_Hash(TH, chave);

    int list_size = ILIST_Tamanho(TH->t[pos]);

    int boolValue = ILIST_Remover(TH->t[pos], chave);

    if (list_size != ILIST_Tamanho(TH->t[pos]))
    {
        TH->n--;
    }

#if C

    if (TH->max == chave)
    {
        TH->max -= TH->diffMax;
    }
    else if (TH->min == chave)
    {
        TH->min += TH->diffMin;
    }

#endif
}

INOH *THED_Buscar(THED *TH, int chave)
{
    int pos = THED_Hash(TH, chave);

    int pos_list = ILIST_Buscar(TH->t[pos], chave);

    return ILIST_Endereco(TH->t[pos], pos_list);
}

void THED_Imprimir(THED *TH)
{
    int i;
    printf("\n===============");
    printf("\n  TABELA HASH\n");
    printf("===============\n");

    for (i = 0; i < TH->m; i++)
    {
        printf("\n%d:\n", i);
        ILIST_Imprimir(TH->t[i], 0);
        printf("\n");
    }

    printf("\nNúmero de Elementos: %lu\n\n", TH->n);
    printf("===============\n");
}

size_t THED_N(THED *TH)
{
    return TH->n;
}

ILIST *THED_Chaves(THED *TH)
{
    ILIST *s = ILIST_Criar(THED_N(TH) + 1);
    INOH *p;
    for (int i = 0; i < TH->m; i++)
    {
        ILIST_Rebobinar(TH->t[i]);
        p = ILIST_Prox(TH->t[i]);
        while (p != NULL)
        {
            ILIST_Inserir(s, p->chave, p->valor);
            p = ILIST_Prox(TH->t[i]);
        }
    }
    return s;
}

void THED_Destruir(THED *TH)
{
    for (int i = 0; i < TH->m; i++)
    {
        ILIST_Destruir(TH->t[i]);
    }

    free(TH->t);
    free(TH);
}
