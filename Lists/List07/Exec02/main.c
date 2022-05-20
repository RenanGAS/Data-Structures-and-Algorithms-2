#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#include "ilist.h"
#include "hashtable_ed.h"

int main(int argc, char **argv)
{

    int n, m, i, chave;

    int seed = 0;

    n = argc > 1 ? atoi(argv[1]) : 10;
    m = argc > 2 ? atoi(argv[2]) : n >> 1;

    srand(seed);

    THED *ht;
    ILIST *chaves = NULL;
    ht = THED_Criar(m, 10, 2);

    // teste 1

    for (int i = 0; i < n; i++)
    {
        chave = rand() % 100;
        THED_Inserir(ht, chave, rand() % 10);
    }
    
    // THED_Inserir(ht, 0, 4);
    // THED_Inserir(ht, 1, 4);
    // THED_Inserir(ht, 2, 4);
    // THED_Inserir(ht, 3, 4);
    // THED_Inserir(ht, 4, 4);
    // THED_Inserir(ht, 5, 4);
    // THED_Inserir(ht, 6, 4);
    // THED_Inserir(ht, 7, 4);
    // THED_Inserir(ht, 8, 4);
    // THED_Inserir(ht, 9, 4);
    // THED_Inserir(ht, 10, 4);
    // THED_Inserir(ht, 11, 4);
    // THED_Inserir(ht, 12, 4);
    // THED_Inserir(ht, 13, 4);
    // THED_Inserir(ht, 14, 4);
    // THED_Inserir(ht, 15, 4);
    // THED_Inserir(ht, 16, 4);
    // THED_Inserir(ht, 17, 4);
    // THED_Inserir(ht, 18, 4);
    // THED_Inserir(ht, 19, 4);
    // THED_Inserir(ht, 20, 4);
    // THED_Inserir(ht, 21, 4);

    THED_Imprimir(ht);

    // int chave_buscar;
    // chave_buscar = 11;
    // INOH *no_elem;
    // no_elem = THED_Buscar(ht, chave_buscar);

    // if (no_elem != NULL)
    // {
    //     printf("\nResultado da busca pela chave %d: %d->%d\n", chave_buscar, no_elem->chave, no_elem->valor);
    // }

    // THED_Remover(ht, chave_buscar);
    // printf("\nO elemento de chave %d foi removido\n", chave_buscar);
    // THED_Imprimir(ht);

    // Testes Min e Max

    /* THED_Remover(ht, 14);
    printf("\nO elemento de chave %d foi removido\n", 14);

    THED_Remover(ht, 0);
    printf("\nO elemento de chave %d foi removido\n", 0);

    THED_Imprimir(ht);

    printf("\ndiffMax: %d\n\n", ht->diffMax);
    printf("\ndiffMin: %d\n\n", ht->diffMin);

    THED_Remover(ht, 13);
    printf("\nO elemento de chave %d foi removido\n", 13);

    THED_Remover(ht, 4);
    printf("\nO elemento de chave %d foi removido\n", 4);

    printf("\ndiffMax: %d\n\n", ht->diffMax);
    printf("\ndiffMin: %d\n\n", ht->diffMin);

    int max_chave, min_chave = 0;

    max_chave = max(ht);
    printf("\nA maior chave da tabela é %d\n", max_chave);

    min_chave = min(ht);
    printf("\nA menor chave da tabela é %d\n", min_chave); */

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
