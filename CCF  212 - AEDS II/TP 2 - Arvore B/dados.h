/*
	Bárbara de Oliveira Souza 3039
	Caio Augusto Moreira 3042
	Jose Grigorio Neto 3046

*/
#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

typedef struct
{
    int hArvore;
    int altura;
    int comparacoes;
    double nPalavras;
    int hTotal, cTotal;
    int hMaior,cMaior;
    int hMenor, cMenor;
    double mediaAltura;
    double mediaComparacoes;
}TDados;
void setarDados (TDados *pDados);
void controleAltura (TDados*pDados, int *altura);
void controleComparacao(TDados *pDados, int *comparacoes);
void atualizadorHC(TipoApontador Dicionario, TDados *pDados, int *altura, int *comparacoes);
void atualizarMedias (TDados *pDados);
void H(TipoApontador Dicionario, TDados *pDados);
int alturaArvore(TipoApontador Dicionario);
