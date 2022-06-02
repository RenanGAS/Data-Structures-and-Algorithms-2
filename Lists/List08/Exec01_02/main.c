#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#include "hashtable_ea.h"


int main(int argc, char** argv){
    
    int m, n, i, chave, *v;    

    int seed = 42;

    n = argc > 1 ? atoi(argv[1]) : 20;
    m = argc > 2 ? atoi(argv[2]) : 25;

    // srand(seed);

    THEA* ht;

    ht = THEA_Criar(m);

    // THEA_Inserir(ht, 10, 5);
    // THEA_Inserir(ht, 11, 7);
    // THEA_Inserir(ht, 3, 7);

    v = random_vector(n, 10 * n, seed);

    for(i = 0; i < n; i++){
        chave = v[i];
        THEA_Inserir(ht, chave, chave + (rand() % 10));
    }

    // THEA_Remover(ht, 0);
    // THEA_Remover(ht, 80);
    // THEA_Remover(ht, 3);
    // THEA_Remover(ht, 11);

    THEA_Imprimir(ht);

    printf("\nFator de Carga: %.2f\n", n / (float) m);

    float clusterMed = THEA_TamMedioClusters(ht);

    printf("\nCusto de uma busca Mal-Sucedida: %.2f\n", clusterMed);

    float succeededSearchCost = THEA_CustoBemSucedida(ht);

    printf("\nCusto de uma busca Bem-Sucedida: %.2f\n", succeededSearchCost);

    int clusterMax = THEA_ClusterMaximo(ht);

    printf("\nMaior Cluster: %d\n", clusterMax);

    // int numElem = ht->n;

    // printf("\nA tabela hash tem %d elementos\n", numElem);

    // int minKey, maxKey;

    // minKey = ht->minK;
    // maxKey = ht->maxK;

    // // minKey = min(ht);
    // // maxKey = max(ht);

    // printf("\nValor da chave mínima: %d\n", minKey);
    // printf("\nValor da chave máxima: %d\n", maxKey);
}
