/// Barbara de Oliveira Souza - 3039
/// Caio Augusto Moreira Campos - 3042
/// Jose Grigorio Neto - 3046
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef enum
{
    Interno,Externo
}TipoNo;

typedef struct TPNo* TipoArvore;
typedef struct TPNo
{
    TipoNo orientacao;
    union
    {
        struct
        {
            int posicao;
            char letra;
            TipoArvore Esq, Dir;
        }NInterno;
        char Chave[50];
    }NO;
}TPNo;


void Inicializar (TipoArvore *pArvore);
TipoArvore CriaNoInterno (int posicao,char difere, TipoArvore *Esq, TipoArvore *Dir);
TipoArvore CriaNoExterno (char *k);
TipoArvore InsereEntre (char *k, TipoArvore *t, int i, char difere);
int EExterno (TipoArvore p);
TipoArvore Insere(char *k, TipoArvore *t);
int pesquisa(char *k, TipoArvore t, int *qtComp,int *altura);
int ComparaPlv(char *palavraArvore, char *palavraRecebida);
int maior(int a, int b);
void qtNos(TipoArvore raiz,int *qtNosInternos,int *qtNosExternos);
int alturaPat (TipoArvore raiz);
