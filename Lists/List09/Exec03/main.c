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

    for(i = 0; i < n; i++){
        chave = (rand() % n*10);
        THEA_Inserir(ht, chave, chave + (rand() % 10));
    }

    THEA_Remover(ht, 110);
    THEA_Remover(ht, 150);
    THEA_Remover(ht, 70);
    THEA_Remover(ht, 190);
    THEA_Remover(ht, 230);
    THEA_Remover(ht, 20);
    THEA_Remover(ht, 180);
    THEA_Remover(ht, 220);
    THEA_Remover(ht, 90);
    THEA_Remover(ht, 210);
    THEA_Remover(ht, 170);

    THEA_Imprimir(ht);
}
