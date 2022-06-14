#ifndef __AB_H__
#define __AB_H__

typedef struct AB
{
    struct AB *esq;
    struct AB *dir;
    int dado;
    int profundidade;
} * AB;

AB AB_Criar(int dado, AB e, AB d);
AB AB_Buscar(int dado, AB A);
void AB_Inserir(int dado, AB *A);
void AB_Imprimir(AB *A, int i, char p);
void AB_Destruir(AB *A);
int AB_Tamanho(AB A, int tamE, int tamD, int n);
int ABB_Altura(AB A, int n, int max, int flag);
void AB_CalcularProfundidades(AB A, int p);
int AB_ComprimentoInterno(AB A, int c);
int AB_AB(AB A, int r);

#endif