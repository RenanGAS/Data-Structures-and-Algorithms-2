#include <stdlib.h>
#include <stdio.h>
#include "hashtable_ea.h"


int THEA_Hash(THEA *TH, int chave, int k)
{
    return ((chave % TH->m) + k) % TH->m;
}

THEA *THEA_Criar(int m)
{
    THEA *new_ht = malloc(sizeof(THEA));

    new_ht->m = m;
    new_ht->n = 0;
    new_ht->TH = malloc(m * sizeof(ELEM));

    for (int i = 0; i < m; i++)
    {
        new_ht->TH[i].estado = E_LIVRE;
    }

    return new_ht;
}

int THEA_Inserir(THEA *TH, int chave, int valor)
{
    int k = 0, hash_init, hash;

    hash = THEA_Buscar(TH, chave);

    if (hash < 0)
    {
        hash = THEA_Hash(TH, chave, k);

        hash_init = hash;

        while (TH->TH[hash].estado == E_OCUPADO)
        {
            k++;
            hash = THEA_Hash(TH, chave, k);

            if (hash == hash_init)
            {
                printf("\nTabela cheia!\n\n");

                return -1;
            }
        }

        TH->n++;
    }

    TH->TH[hash].chave = chave;
    TH->TH[hash].valor = valor;
    TH->TH[hash].estado = E_OCUPADO;

    return hash;
}

int THEA_Buscar(THEA *TH, int chave)
{
    int hash, hash_init, k = 0;

    hash = THEA_Hash(TH, chave, k);

    hash_init = hash;

    while (TH->TH[hash].estado != E_LIVRE)
    {
        if ((TH->TH[hash].estado == E_OCUPADO) && (TH->TH[hash].chave == chave))
        {
            return hash;
        }

        k++;
        hash = THEA_Hash(TH, chave, k);

        if (hash == hash_init)
        {
            return -1;
        }
    }

    return -1;
}

void THEA_Remover(THEA *TH, int chave)
{
    int pos;

    pos = THEA_Buscar(TH, chave);

    if (pos != -1)
    {
        TH->TH[pos].estado = E_APAGADO;
    }

    TH->n--;
}

void THEA_Imprimir(THEA *TH)
{
    printf("\n");

    for (int i = 0; i < TH->m; i++)
    {
        if (TH->TH[i].estado == E_OCUPADO)
        {
            printf("\n%d: %d | %d | %d\n", i, TH->TH[i].chave, TH->TH[i].valor, TH->TH[i].estado);
        }
        else
        {
            printf("\n%d:  |  | %d\n", i, TH->TH[i].estado);
        }
        
    }

    printf("\n");
}