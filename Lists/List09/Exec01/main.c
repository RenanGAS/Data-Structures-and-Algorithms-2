#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#include "hashtable_ea.h"


int main(int argc, char** argv){
    
    int m, n, i, chave;    

    int seed = 0;

    n = argc > 1 ? atoi(argv[1]) : 10;
    m = argc > 2 ? atoi(argv[2]) : 20;

    srand(seed);

    THEA* ht;

    ht = THEA_Criar(m);

    THEA_Inserir(ht, 10, 5);
    THEA_Inserir(ht, 11, 7);
    THEA_Inserir(ht, 3, 7);

    for(i = 0; i < n; i++){
        chave = (rand() % n*10);
        THEA_Inserir(ht, chave, chave + (rand() % 10));
    }

    THEA_Imprimir(ht);
}
