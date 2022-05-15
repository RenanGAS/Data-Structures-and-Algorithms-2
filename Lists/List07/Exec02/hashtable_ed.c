#include <stdlib.h>
#include <stdio.h>
#include "ilist.h"
#include "hashtable_ed.h"

int THED_Hash(THED *TH, int chave)
{
    return chave % TH->m;
}

THED *THED_Criar(int m, int alloc_step)
{
    int i;
    THED *nova_th;
    nova_th = malloc(sizeof(THED));

    nova_th->m = m;
    nova_th->n = 0;
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

    int boolValue = ILIST_Inserir(TH->t[pos], chave, valor);
}

void THED_Remover(THED *TH, int chave)
{
    int pos = THED_Hash(TH, chave);

    int boolValue = ILIST_Remover(TH->t[pos], chave);
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

    printf("===============\n");
}

size_t THED_N(THED *TH)
{
}

ILIST *THED_Chaves(THED *TH)
{
}

void THED_Destruir(THED *TH)
{
}
