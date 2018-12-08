/* TAD Dicionário */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "letra.h"
#include "texec.h"

#define NLETRAS 26

#define BUBBLESORT '1'
#define SELECTSORT '2'
#define INSERTSORT '3'
#define SHELLSORT  '4'
#define QUICKSORT  '5'
#define HEAPSORT   '6'

/* Definição do dicionario, usando o TAD Letra */
typedef struct {
    TLetra alfabeto[NLETRAS];
    int numeroDePalavras;
} TDicionario;

/* Protótipo dos módulos do TAD Dicionario */
/* Sigla das funções: DIC - DICionário */
void DICInicializar(TDicionario *dicionario);
int DICInserirPalavra(TDicionario *dicionario,char *cadeiaChar,int nLinha);
int DICRemoverPalavra(TDicionario *dicionario,char *cadeiaChar);
void DICExibirLetra(TDicionario *dicionario,char letra);
void DICExibir(TDicionario *dicionario);
int DICLerArquivo(TDicionario *dicionario,FILE *input);
void DICEsvaziar(TDicionario *dicionario);
int DICQuantidadePalavras(TDicionario *dicionario);

/* Update - TP3 */
void DICCriarCopia(TDicionario *copia,TDicionario *original);
void DICOrdenar(TDicionario *dicionario,char tipo,char letra,double *tempo,int *comp,int *mov);
