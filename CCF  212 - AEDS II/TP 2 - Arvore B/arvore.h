/*
	Bárbara de Oliveira Souza 3039
	Caio Augusto Moreira 3042
	Jose Grigorio Neto 3046

*/

#include<stdlib.h>
#include<stdio.h>
#define M 1
#define MM  (M * 2)
#define FALSE 0
#define TRUE  1

typedef long TipoChave;

typedef struct TipoRegistro {
  TipoChave Chave;
} TipoRegistro;
typedef struct TipoPagina* TipoApontador;
typedef struct TipoPagina {
  short n;
  TipoRegistro r[MM];
  TipoApontador p[MM + 1];
} TipoPagina;

void Inicializa(TipoApontador *Dicionario);
void ImprimeI(TipoApontador Dicionario, int nivel);
void Imprime(TipoApontador Dicionario);

/*Funções Próprias ou Alteradas*/
void Pesquisa(TipoRegistro *x, TipoApontador Dicionario, int *HP, int *cPesquisa, double *Falha, double *Total);
//Inserção
void Insere(TipoRegistro Reg, TipoApontador *Dicionario, int *hInsere, int *cPesquisa, double *Falha, double *Total);
void Ins(TipoRegistro Reg, TipoApontador Dicionario, short *Cresceu, TipoRegistro *RegRetorno,  TipoApontador *ApRetorno, int *hInsere, int *cPesquisa, double *Falha);
void InsereNaPagina(TipoApontador Dicionario, TipoRegistro Reg, TipoApontador ApDir, int *cPesquisa);
//Remoção
void Retira(TipoChave Ch, TipoApontador *Dicionario, int *hRemover, int *cRemover, double *Falha, double*Total);
void Ret(TipoChave Ch, TipoApontador *Dicionario, short *Diminuiu, int *hRemover, int *cRemover, double *Falha);
void Reconstitui(TipoApontador ApPag, TipoApontador ApPai, int PosPai, short *Diminuiu, int *cRemover);
void Antecessor(TipoApontador Ap, int Ind, TipoApontador ApPai, short *Diminuiu, int *cRemover);
