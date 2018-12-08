/* TAD Lista de Palavras */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "palavra.h"

#define OP_NOVAPALAVRA 2

/* C�lula/N� da lista de n�meros de linha */
typedef struct tlpCel {
    TPalavra palavra;
    struct tlpCel *proximo;
} TLPalavraCel;

/* Cabe�alho da lista */
typedef struct {
    TLPalavraCel *cabeca;
    TLPalavraCel *ultimo;
    int tamanho;
} TLPalavra;

/* Prot�tipo dos m�dulos do TAD Lista de N�meors de Linha
    Sigla das fun��es: LPV - Lista de PalaVras */
void LPVCriarVazia(TLPalavra *lista);
int LPVInserir(TLPalavra *lista,char *cadeiaChar,int nLinha);
int LPVRemoverUltima(TLPalavra *lista);
int LPVRemoverPalavra(TLPalavra *lista,char *cadeiaChar);
TLPalavraCel *LPVVerificar(TLPalavra *lista,char *cadeiaChar);
int LPVQuantidade(TLPalavra *lista);
void LPVImprimir(TLPalavra *lista);
void LPVEsvaziar(TLPalavra *lista);
