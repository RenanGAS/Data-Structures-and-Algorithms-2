#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#include "ilist.h"
#include "hashtable_ed.h"

int main(int argc, char** argv){
    
    int n, m, i, chave;    

    int seed = 0;

    n = argc > 1 ? atoi(argv[1]) : 10;
    m = argc > 2 ? atoi(argv[2]) : n >> 1;

    srand(seed);

    THED* ht;
    ILIST *chaves = NULL;
    ht = THED_Criar(m, 10);

    // teste 1

    THED_Inserir(ht, 10, 5);
    THED_Inserir(ht, 11, 7);
    THED_Inserir(ht, 13, 0);
    THED_Imprimir(ht);

    int chave_buscar;
    chave_buscar = 11;
    INOH* no_elem;
    no_elem = THED_Buscar(ht, chave_buscar);
    printf("\nResultado da busca pela chave %d: %d->%d\n", chave_buscar, no_elem->chave, no_elem->valor);

    THED_Remover(ht, chave_buscar);
    printf("\nO elemento de chave %d foi removido\n", chave_buscar);
    THED_Imprimir(ht);

    // ILIST *chaves = THED_Chaves(ht);
    // ILIST_Imprimir(chaves, 0);
    // ILIST_Destruir(chaves);

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
