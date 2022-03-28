#pragma once

#include <stdio.h>

#define MAX_ITEMS 1000
#define MAX_TAM 21
#define BUF_LEN ((MAX_ITEMS * MAX_TAM) + 1)

typedef struct list List;

List *Create(char *items);
void Sort(List *l);
char *NoRepeat(List *l);
void Print(List *l);
void Delete(List *l);


