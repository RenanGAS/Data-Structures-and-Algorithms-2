#ifndef __AB_H__
#define __AB_H__

typedef struct AB
{
    struct AB *esq;
    struct AB *dir;
    int dado;
    int profundidade;
    int n;
    int h;
    int ci;
} * AB;

AB AB_Criar(int dado, AB e, AB d);
AB AB_Buscar(int dado, AB A);
void AB_Inserir(int dado, AB *A, int countH, AB *Acpy);
void AB_Imprimir(AB *A, int i, char p);
void AB_Destruir(AB *A);
int AB_TamanhoLazy(AB A, int tamE, int tamD, int n);
int AB_TamanhoEager(AB A);
int AB_AlturaLazy(AB A, int n, int max, int flag);
int AB_AlturaEager(AB A);
void AB_CalcularProfundidades(AB A, int p);
int AB_ComprimentoInternoLazy(AB A, int c);
int AB_ComprimentoInternoEager(AB A);
int AB_AB(AB A, int r);

#endif