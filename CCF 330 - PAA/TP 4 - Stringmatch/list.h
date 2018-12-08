// LList -> Linked List, lista encadeada, para inteiros

#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int i, j;
} Indices;

typedef struct llcel {
    Indices item;
    struct llcel *proximo;
} LListCel;

typedef struct {
    LListCel *cabeca;
    LListCel *ultimo;
    int tamanho;
} LList;

LList   LListCriar();
int     LListInserir(LList *lista, int i, int j);
Indices LListRetirar(LList *lista);
int     LListTamanho(LList lista);
void    LListEsvaziar(LList *lista);
void    LListImprimir(LList *lista);

#endif
