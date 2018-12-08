//
// Created by flym on 19/09/18.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
//defines do RadixSort
#define GetBits(x,k,j) (x >> k) & ~((~0) << j)
#define BASE 256
#define M 8
#define NBITS 32

typedef struct{
    int chave;
}item;

void ShellSort(item *vetor, int tamanho);
void InsertSort(item *vetor, int tamanho);
void merge(item *vetor, int comeco, int meio, int fim);
void MergeSort(item *vetor, int comeco, int fim);
void ContagemInt(item *vetor, int tamanho, int Pass);
void RadixSort(item *vetor, int tamanho);