/* TAD Letra do Alfabeto */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lpalavra.h"

/* Defini��o de uma letra do alfabeto, usando o TAD Lista de Palavras */
typedef struct {
    char caractere;
    TLPalavra entradas;
} TLetra;

/* Prot�tipo dos m�dulos do TAD Letra do Alfabeto
    Sigla das fun��es: LAB - Letra do AlfaBeto */
void LABCriarVazia(TLetra *letra);
void LABPreencher(TLetra *letra,char caractere);
char LABRetornarCaractere(TLetra *letra);
TLPalavra *LABRetornarLPalavra(TLetra *letra);
void LABImprimir(TLetra *letra);
void LABEsvaziarEntradas(TLetra *letra);

/* Update - TP3 */
void LABCopiar(TLetra *para,TLetra *de);
