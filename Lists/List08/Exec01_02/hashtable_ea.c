#include <stdlib.h>
#include <stdio.h>
#include "hashtable_ea.h"


// Funções Auxiliares

int firstKey(THEA *TH)
{
    for (int i = 0; i < TH->m; i++)
    {
        if (TH->TH[i].estado == E_OCUPADO)
        {
            return TH->TH[i].chave;
        }
    }

    return -1;
}

int min(THEA *TH)
{
    int i, minKey;

    minKey = firstKey(TH);

    if (minKey == -1)
    {
        return minKey;
    }

    for (i = 0; i < TH->m; i++)
    {
        if (TH->TH[i].estado == E_OCUPADO && TH->TH[i].chave < minKey)
        {
            minKey = TH->TH[i].chave;
        }
    }

    return minKey;
}

int max(THEA *TH)
{
    int i, maxKey;

    maxKey = firstKey(TH);

    if (maxKey == -1)
    {
        return maxKey;
    }

    for (i = 0; i < TH->m; i++)
    {
        if (TH->TH[i].estado == E_OCUPADO && TH->TH[i].chave > maxKey)
        {
            maxKey = TH->TH[i].chave;
        }
    }

    return maxKey;
}

int THEA_ClusterMaximo(THEA* TH)
{
    int i, numMax = 1, countNum = 0;

    for (i = 0; i < TH->m; i++)
    {
        if (TH->TH[i].estado == E_OCUPADO)
        {
            countNum++;
        }
        else
        {
            if (countNum > numMax)
            {
                numMax = countNum;
            }
            
            countNum = 0;
        }
    }

    return numMax;
}

float THEA_TamMedioClusters(THEA* TH)
{
    int i, sumSizes = 0, countNum = 0, countClusters = 0;

    for (i = 0; i < TH->m; i++)
    {
        if (TH->TH[i].estado == E_OCUPADO)
        {
            countNum++;
        }
        else
        {
            if (countNum > 0)
            {
                countClusters++;
            }
        
            sumSizes += countNum;
            
            countNum = 0;
        }
    }

    return sumSizes / (float) countClusters;
}


// Funções Principais

int THEA_Hash(THEA *TH, int chave, int k)
{
    return ((chave % TH->m) + k) % TH->m;
}

THEA *THEA_Criar(int m)
{
    THEA *new_ht = malloc(sizeof(THEA));

    new_ht->m = m;
    new_ht->n = 0;
    new_ht->minVK = malloc(10 * sizeof(int));
    new_ht->maxVK = malloc(10 * sizeof(int));
    new_ht->minK = 0;
    new_ht->maxK = 0;
    new_ht->countMin = 0;
    new_ht->countMax = 0;
    new_ht->flag = 0;
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

    if (!TH->flag)
    {
        TH->maxK = chave;
        TH->maxVK[TH->countMax] = chave;
        TH->countMax++;
        TH->minK = chave;
        TH->minVK[TH->countMin] = chave;
        TH->countMin++;
        TH->flag = 1;
    }
    else if (chave > TH->maxK)
    {
        TH->maxK = chave;

        if (TH->countMax < 10)
        {
            TH->maxVK[TH->countMax] = chave;
            TH->countMax++;
        }
        
    }
    else if (chave < TH->minK)
    {
        TH->minK = chave;

        if (TH->countMin < 10)
        {
            TH->minVK[TH->countMin] = chave;
            TH->countMin++;
        }
    } 

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

    if (chave == TH->maxK)
    {
        TH->maxK = TH->maxVK[TH->countMax - 2];
        TH->countMax--;
    }
    
    if (chave == TH->minK)
    {
        TH->minK = TH->minVK[TH->countMin - 2];
        TH->countMin--;
    }
    
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