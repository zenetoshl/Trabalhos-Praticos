/* TAD Dicion�rio */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "letra.h"

#define NLETRAS 26

/* Defini��o do dicionario, usando o TAD Letra */
typedef struct {
    TLetra alfabeto[NLETRAS];
    int numeroDePalavras;
} TDicionario;

/* Prot�tipo dos m�dulos do TAD Dicionario */
/* Sigla das fun��es: DIC - DICion�rio */
void DICInicializar(TDicionario *dicionario);
int DICInserirPalavra(TDicionario *dicionario,char *cadeiaChar,int nLinha);
int DICRemoverPalavra(TDicionario *dicionario,char *cadeiaChar);
void DICExibirLetra(TDicionario *dicionario,char letra);
void DICExibir(TDicionario *dicionario);
int DICLerArquivo(TDicionario *dicionario,FILE *input);
void DICEsvaziar(TDicionario *dicionario);
int DICQuantidadePalavras(TDicionario *dicionario);
