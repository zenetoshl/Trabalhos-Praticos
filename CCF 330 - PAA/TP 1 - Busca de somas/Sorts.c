//
// Created by flym on 19/09/18.
//

#include "Sorts.h"

void ShellSort(item *vetor, int tamanho) {
    int i , j , numAux;
    int h = 1;
    while(h < tamanho) {
        h = 3*h+1;
    }
    while ( h > 1) {
        h /= 3;
        for(i = h; i < tamanho; i++) {
            numAux = vetor[i].chave;
            j = i;
            while (j >= h && numAux < vetor[j - h].chave) {
                vetor[j].chave = vetor[j - h].chave;
                j = j - h;
            }
            vetor [j].chave = numAux;
        }
    }
}

void InsertSort(item *vetor, int tamanho) {
    int i, j, numAux;

    for (i = 1; i < tamanho; i++) {
        numAux = vetor[i].chave;


        for (j = i - 1; (j >= 0) && (numAux < vetor[j].chave); j--) {
            vetor[j + 1].chave = vetor[j].chave;
        }

        vetor[j+1].chave = numAux;
    }
}

void merge(item *vetor, int comeco, int meio, int fim) {
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    item *vetAux;
    vetAux = (item*)malloc(tam * sizeof(item));

    while(com1 <= meio && com2 <= fim){
        if(vetor[com1].chave < vetor[com2].chave) {
            vetAux[comAux].chave = vetor[com1].chave;
            com1++;
        } else {
            vetAux[comAux].chave = vetor[com2].chave;
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){  //Caso ainda haja elementos na primeira metade
        vetAux[comAux].chave = vetor[com1].chave;
        comAux++;
        com1++;
    }

    while(com2 <= fim) {   //Caso ainda haja elementos na segunda metade
        vetAux[comAux].chave = vetor[com2].chave;
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){    //Move os elementos de volta para o vetor original
        vetor[comAux].chave = vetAux[comAux-comeco].chave;
    }

    free(vetAux);
}

void MergeSort(item *vetor, int comeco, int fim){
    if (comeco < fim) {
        int meio = (fim+comeco)/2;


        MergeSort(vetor, comeco, meio);
        MergeSort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);
    }
    return;
}


void ContagemInt(item *vetor, int tamanho, int Pass)
{ int i, j;
    int C[BASE];
    item B[tamanho];
    for (i = 0; i <= BASE - 1; i++) C[i] = 0;
    for (i = 1; i <= tamanho; i++)
    { j = GetBits(vetor[i].chave, Pass*M, M);
        C[j] = C[j] + 1;
    }
    if (C[0] == tamanho) return;
    for (i = 1; i <= BASE - 1; i++) C[i] = C[i] + C[i-1];
    for (i = tamanho; i > 0; i--)
    { j = GetBits(vetor[i].chave, Pass*M, M);
        B[C[j]] = vetor[i];
        C[j] = C[j] - 1;
    }
    for (i = 1; i <= tamanho; i++) vetor[i] = B[i];
}

void RadixSort(item *vetor, int tamanho)
{ int i;
    for (i = 0; i < NBITS / M; i++) ContagemInt(vetor, tamanho, i);
}

