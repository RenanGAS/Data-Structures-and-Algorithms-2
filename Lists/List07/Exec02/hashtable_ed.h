#pragma once

#include "ilist.h"

typedef struct THED {
    ILIST** t;
    size_t m, n, c, reserva;
    int min, max, diffMin, diffMax, flag;
} THED;

int THED_Hash(THED* HT, int chave);
THED* THED_Criar(int m, int alloc_step, size_t c);
void THED_Inserir(THED* HT, int chave, int valor);
void THED_Remover(THED* HT, int chave);
INOH* THED_Buscar(THED* HT, int chave);
void THED_Imprimir(THED* HT);
size_t THED_N(THED* HT);
ILIST* THED_Chaves(THED* HT);
void THED_Destruir(THED* HT);
int max(THED* HT);
int min(THED* HT);