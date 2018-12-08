/*
	Bárbara de Oliveira Souza 3039
	Caio Augusto Moreira 3042
	Jose Grigorio Neto 3046

*/

#include "dados.h"

void setarDados (TDados *pDados)
{
    pDados->hArvore = -1;
    pDados->altura = 0;
    pDados->comparacoes =0;
    pDados->nPalavras = 0;
    pDados->hTotal= 0;
    pDados->cTotal = 0;
    pDados->hMaior= 0;
    pDados->cMaior= 0;
    pDados->hMenor= 0;
    pDados->cMenor= 0;
    pDados->mediaAltura= 0;
}
///SEMPRE que manipular a altura ou comparação no main, deve-se chamar esta função para atualizar a estatística;
void atualizadorHC(TipoApontador Dicionario, TDados *pDados, int *altura, int *comparacoes)
{
    controleAltura(pDados,altura);
    controleComparacao(pDados, comparacoes);
    atualizarMedias(pDados);
    H(Dicionario, pDados);
}
void atualizarMedias (TDados *pDados)
{
    if(pDados->nPalavras != 0)
    {
        pDados->mediaAltura = (pDados->hTotal)/pDados->nPalavras;
        pDados->mediaComparacoes = (pDados->cTotal)/pDados->nPalavras;
    }
}
void controleAltura (TDados*pDados, int *altura)
{
    if((*altura) > pDados->hMaior)
        pDados->hMaior = (*altura);
    else if((*altura)< pDados->hMenor)
        pDados->hMenor = (*altura);
    pDados->hTotal += (*altura);
    (*altura) = 0;
}
void controleComparacao(TDados *pDados, int *comparacoes)
{
    if((*comparacoes) > pDados->cMaior)
        pDados->cMaior = (*comparacoes);
    else if((*comparacoes)< pDados->cMenor)
        pDados->cMenor = (*comparacoes);
    pDados->cTotal += (*comparacoes);
    (*comparacoes) = 0;
}

void H(TipoApontador Dicionario, TDados *pDados)
{
    pDados->hArvore = alturaArvore(Dicionario);
}
int alturaArvore(TipoApontador Dicionario)
{
    if(Dicionario == NULL)
        return -1;
    return 1 + (alturaArvore(Dicionario->p[0]));
}
