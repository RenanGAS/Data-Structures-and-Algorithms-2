#include <stdlib.h>
#include <stdio.h>
#include "ilist.h"
#include "hashtable_ed.h"


int THED_Hash(THED *TH, int chave)
{
    return chave % TH->m;
}

static void THED_Redimensionar(THED *HT, int m_novo)
{
    ILIST **new_t, **old_t; 
    int i, j, old_m;

    new_t = malloc(m_novo * sizeof(ILIST *));

    for (int i = 0; i < m_novo; i++)
    {
        new_t[i] = ILIST_Criar(10);
    }

    old_t = HT->t;
    old_m = HT->m;
    HT->t = new_t;
    HT->m = m_novo;
    HT->n = 0;

    for (i = 0; i < old_m; i++)
    {
        for (j = 0; j < old_t[i]->tam; j++)
        {
            THED_Inserir(HT, old_t[i]->nos[j].chave, old_t[i]->nos[j].valor);
        }
    }
}

THED *THED_Criar(int m, int alloc_step, int k)
{
    int i;
    THED *nova_th;
    nova_th = malloc(sizeof(THED));

    nova_th->m = m;
    nova_th->n = 0;
    nova_th->k = k;
    nova_th->t = malloc(sizeof(ILIST *) * m);

    for (i = 0; i < m; i++)
    {
        nova_th->t[i] = ILIST_Criar(alloc_step);
    }

    return nova_th;
}

void THED_Inserir(THED *TH, int chave, int valor)
{
    if ((TH->n / TH->m) > TH->k)
    {
        printf("\nRedimensionamento:\n\n%d / %d > %d .: M = %d -> M = %d\n", TH->n, TH->m, TH->k, TH->m, (TH->m * 2) + 1);
        THED_Redimensionar(TH, (TH->m * 2) + 1);
    }

    int pos = THED_Hash(TH, chave);

    int list_size = ILIST_Tamanho(TH->t[pos]);

    int boolValue = ILIST_Inserir(TH->t[pos], chave, valor);

    if (list_size != ILIST_Tamanho(TH->t[pos]))
    {
        TH->n++;
    }
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

    printf("\nNúmero de Elementos: %d\n\n", TH->n);
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
