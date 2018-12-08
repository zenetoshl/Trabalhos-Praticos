//
// Created by neto on 24/10/18.
//
#ifndef TP02_PALAVRA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#endif
#define INICIO 0
#define ESQ 1
#define DIR 2
#define ABAIXO 3


typedef struct{
    char **matriz;
    int  **matrizC;
    int Y;
    int X;
}CacaPalavra;

typedef struct{
    int chamadasRecursivas;
}AnaliseCaca;

int CacaPalavras(CacaPalavra* mats, int direcao, char* palavra, int* marca, int i, int j, AnaliseCaca* chama);
void PrintCacaPalavra (CacaPalavra mats);
int Procura (CacaPalavra *mats, char* palavra, AnaliseCaca *chama);
void Inicializa (CacaPalavra *mats);
int LerArq (CacaPalavra* mats, char* nome);
