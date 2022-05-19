#include <stdio.h>
#include <stdlib.h>
#include "threa.h"

THEA *THEA_Criar(int m)
{
    THEA *nova;
    int i;
    nova = malloc(sizeof(THEA));
    nova->m = m;
    nova->n = 0;
    nova->t = malloc(sizeof(ELEM) * m);

    for (i = 0; i < m; i++)
    {
        nova->t[i].estado = E_LIVRE;
    }

    return nova;
}

static void THEA_Redimensionar(THEA* th, int novo_m){
    ELEM* nova, *antiga;
    int m_antigo;
    nova = malloc(sizeof(ELEM)* novo_m);
    for(int i = 0; i < novo_m; i++)
        nova[i].estado = E_LIVRE;
    antiga = th->t;
    m_antigo = th->m;
    th->t = nova;
    th->n = 0;
    th->m = novo_m;
    for (int i = 0; i <m_antigo; i++){
        if(antiga[i].estado == E_OCUPADO){
            THEA_Inserir(th, antiga[i].chave, antiga[i].valor);
        }
    }
    free(antiga);
}

int THEA_Inserir(THEA *th, int chave, int valor)
{
    int h, k, h_inicial;
    h = THEA_Buscar(th, chave);
    if(h >= 0){
        th->n--;
    }
    else{
        k = 0;

        if(th->n > (th->m / 2)){
            printf("tabela redimensionada de m= %d para %d.\n", th->m, th->m*2);
            printf("(n = %d)\n", th->n);
            THEA_Redimensionar(th, th->m*2);
        }

        h = THEA_Hash(th, chave, k);
        h_inicial = h;
        while(th->t[h].estado == E_OCUPADO){
            k++;
            h = THEA_Hash(th, chave, k);
            if(h == h_inicial)
                return -1;
        }
    }
    th->n++;
    th->t[h].chave = chave;
    th->t[h].valor = valor;
    th->t[h].estado = E_OCUPADO;

    return h;
}

int THEA_Hash(THEA *th, int chave, int k)
{
    return ((chave % th->m) + k) % th->m;
}

int THEA_Imprimir(THEA *th)
{
    for (int i = 0; i < th->m; i++)
    {
        printf("%2d: %d -> %d (%d)\n", i, th->t[i].chave, th->t[i].valor, th->t[i].estado);
    }

    printf("\n");
}

int THEA_Buscar(THEA *th, int chave){
    int h, h_inicial, k;
    k = 0;
    h = THEA_Hash(th, chave, k);
    h_inicial = h;

    while(th->t[h].estado != E_LIVRE){
        if((th->t[h].estado == E_OCUPADO) && (th->t[h].chave == chave))
            return h;
        k++;
        h = THEA_Hash(th, chave, k);
        if(h_inicial == h)
            return -1;
    }
    return -1;
}

void THEA_Remover(THEA* th, int chave){
    int p = THEA_Buscar(th, chave);
    if(p >= 0){
        th->t[p].estado = E_APAGADO;
        th->n--;
    }
}