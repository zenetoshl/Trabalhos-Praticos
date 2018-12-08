/* TAD Palavra */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lnlinha.h"

#define MAXCHARPALAVRA 50

/* Defini��o de uma palavra, usando o TAD Lista de N�meros de Linha */
typedef struct {
    char cadeiaChar[MAXCHARPALAVRA];
    TLNLinha linhas;
} TPalavra;

/* Prot�tipo dos m�dulos do TAD Palavra
    Sigla das fun��es: PLV - PaLaVra */
void PLVCriarVazia(TPalavra *palavra);
void PLVPreencher(TPalavra *palavra,char *cadeiaChar);
void PLVRetornarCadeiaChar(TPalavra *palavra,char *cadeiaChar);
TLNLinha *PLVRetornarLNLinha(TPalavra *palavra);
void PLVImprimirChar(TPalavra *palavra);
void PLVImprimir(TPalavra *palavra);
