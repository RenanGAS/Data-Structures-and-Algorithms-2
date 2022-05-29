#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#include "hashtable_ea.h"


int main(int argc, char** argv){
    
    int n, i, chave;    

    int seed = 0;

    n = argc > 1 ? atoi(argv[1]) : 20;

    srand(seed);

    THEA* ht;

    ht = THEA_Criar(25);

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

    int clusterMax = THEA_ClusterMaximo(ht);
    float clusterMed = THEA_TamMedioClusters(ht);

    printf("\nO tamanho do maior cluster é de %d\n", clusterMax);
    printf("\nO tamanho médio dos clusters é %.2f\n", clusterMed);

    int numElem = ht->n;

    printf("\nA tabela hash tem %d elementos\n", numElem);

    // int minKey, maxKey;

    // minKey = ht->minK;
    // maxKey = ht->maxK;

    // // minKey = min(ht);
    // // maxKey = max(ht);

    // printf("\nValor da chave mínima: %d\n", minKey);
    // printf("\nValor da chave máxima: %d\n", maxKey);
}
