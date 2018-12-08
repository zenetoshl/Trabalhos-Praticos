/* TAD Palavra */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lnlinha.h"

#define MAXCHARPALAVRA 50

/* Definição de uma palavra, usando o TAD Lista de Números de Linha */
typedef struct {
    char cadeiaChar[MAXCHARPALAVRA];
    TLNLinha linhas;
} TPalavra;

/* Protótipo dos módulos do TAD Palavra
    Sigla das funções: PLV - PaLaVra */
void PLVCriarVazia(TPalavra *palavra);
void PLVPreencher(TPalavra *palavra,char *cadeiaChar);
void PLVRetornarCadeiaChar(TPalavra *palavra,char *cadeiaChar);
TLNLinha *PLVRetornarLNLinha(TPalavra *palavra);
void PLVImprimirChar(TPalavra *palavra);
void PLVImprimir(TPalavra *palavra);
