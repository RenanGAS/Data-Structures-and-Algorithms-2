#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#include "hashtable_ea.h"


int main(int argc, char** argv){
    
    int n, i, chave;    

    int seed = 0;

    n = argc > 1 ? atoi(argv[1]) : 10;

    srand(seed);

    THEA* ht;

    ht = THEA_Criar(20);

    THEA_Inserir(ht, 10, 5);
    THEA_Inserir(ht, 11, 7);
    THEA_Inserir(ht, 3, 7);

    for(i = 0; i < n; i++){
        chave = (rand() % n*10);
        THEA_Inserir(ht, chave, chave + (rand() % 10));
    }

    // THEA_Remover(ht, 0);
    // THEA_Remover(ht, 80);
    // THEA_Remover(ht, 3);
    // THEA_Remover(ht, 11);

    THEA_Imprimir(ht);

    // int minKey, maxKey;

    // minKey = ht->minK;
    // maxKey = ht->maxK;

    // // minKey = min(ht);
    // // maxKey = max(ht);

    // printf("\nValor da chave mínima: %d\n", minKey);
    // printf("\nValor da chave máxima: %d\n", maxKey);
}
