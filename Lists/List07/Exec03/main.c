#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#include "ilist.h"
#include "hashtable_ed.h"

int main(int argc, char** argv){
    
    int n, m, i, chave;    

    int seed = 42;

    n = argc > 1 ? atoi(argv[1]) : 10;
    m = argc > 2 ? atoi(argv[2]) : n / 2;

    THED* ht = inserir_n_aleatorios(n, m, seed);

    THED_Imprimir(ht);

    int max_size = THED_MaisLonga(ht);
    int min_size = THED_MaisCurta(ht);
    float med_size = THED_TamMedio(ht);

    printf("\nComprimento da maior lista: %d\n\nComprimento da menor lista: %d\n\nComprimento médio das listas: %.2f\n\n", max_size, min_size, med_size);

    // srand(seed);

    // THED* ht;
    // ILIST *chaves = NULL;
    // ht = THED_Criar(m, 10);

    // teste 1

    /* THED_Inserir(ht, 3, 5);
    THED_Inserir(ht, 14, 10);
    THED_Inserir(ht, 29, 0);
    THED_Inserir(ht, 32, 2);

    THED_Imprimir(ht);

    chaves = THED_Chaves(ht);
    ILIST_Imprimir(chaves, 0);
    ILIST_Destruir(chaves); */

    // teste 2

    // for(i = 0; i < n; i++){
    //     chave = (rand() % (n*10));
    //     THED_Inserir(ht, chave, chave + (rand() % 10));
    // }

    // THED_Imprimir(ht);

    // chaves = THED_Chaves(ht);
    // ILIST_Imprimir(chaves, 0);
    // ILIST_Destruir(chaves);

    THED_Destruir(ht);

    return EXIT_SUCCESS;
}
