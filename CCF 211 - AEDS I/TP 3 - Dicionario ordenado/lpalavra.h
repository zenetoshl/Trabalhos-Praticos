/* TAD Lista de Palavras */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "palavra.h"

#define TAMMAXLISTA 512

#define OP_NOVAPALAVRA 2
#define OP_NAOENCONTRADA (-1)

/* Cabeçalho da lista */
typedef struct {
    TPalavra palavras[TAMMAXLISTA];
    int ultimo;
} TLPalavra;

/* Protótipo dos módulos do TAD Lista de Númeors de Linha
    Sigla das funções: LPV - Lista de PalaVras */
void LPVCriarVazia(TLPalavra *lista);
int LPVInserir(TLPalavra *lista,char *cadeiaChar,int nLinha);
int LPVRemoverUltima(TLPalavra *lista);
int LPVRemoverPalavra(TLPalavra *lista,char *cadeiaChar);
int LPVVerificar(TLPalavra *lista,char *cadeiaChar);
int LPVQuantidade(TLPalavra *lista);
void LPVImprimir(TLPalavra *lista);
void LPVEsvaziar(TLPalavra *lista);

/* Update - TP3 */
void LPVCopiar(TLPalavra *para,TLPalavra *de);
 /* Algoritmos de Ordenação */
void BubbleSort(TLPalavra *lista, int *comp, int *mov);
void SelectSort(TLPalavra *lista, int *comp, int *mov);
void InsertSort(TLPalavra *lista, int *comp, int *mov);
void ShellSort(TLPalavra *lista, int *comp, int *mov);
void Quicksort(TLPalavra *lista, int *comp, int *mov);
    void QSOrdena(int Esq, int Dir, TLPalavra *lista, int *comp, int *mov);
    void QSParticao(int Esq, int Dir, int *i, int *j, TLPalavra *lista, int *comp, int *mov);
void Heapsort(TLPalavra *lista, int *comp, int *mov);
