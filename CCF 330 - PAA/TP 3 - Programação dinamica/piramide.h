#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int **matriz;
    int **matrizPeso;
    int quantidade;

}piramide;


void InicializaPiramide (piramide *mats, int tamanho);
int LerArq (piramide* mats, char* nome);
int **Liberar_matriz_real (int m, int n, int **v);
void TrazPraFrente (piramide *piramideJogo);
void  printarResultado (piramide *piramideJogo);
int maior (int a, int b);
void ResolveRecursivo(piramide *piramidejogo);
void ResolveMemoization (piramide *piramidejogo);
int Memoization(piramide *piramidejogo, int i, int j);
