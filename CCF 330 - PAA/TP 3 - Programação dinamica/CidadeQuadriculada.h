#ifndef UNTITLED_CIDADEQUADRICULADA_H
#define UNTITLED_CIDADEQUADRICULADA_H
#include <stdio.h>
#include <stdlib.h>
#endif //UNTITLED_CIDADEQUADRICULADA_H

#define Y 1
#define X 0


#define N 2
#define L 1


#define FIM 1
#define INICIO 0


typedef struct{
    int **cidade;
    int startEnd[2][2];
    int tam[2];
}Cidade;


void Inicializa (Cidade *m);
int LerArqC (Cidade *m, char* nome);
int** CalcularManeiras(Cidade *m);
void ImprimeCaminho(int** matriz, Cidade m);
int CidadeQuad(Cidade *m);
