/* TAD Lista de N�meros de Linha */

#include <stdio.h>
#include <stdlib.h>

#define OP_FALHA 0
#define OP_SUCESSO 1

/* C�lula/N� da lista de n�meros de linha */
typedef struct tnlCel {
    int linha;
    struct tnlCel *proximo;
} TLNLinhaCel;

/* Cabe�alho da lista */
typedef struct {
    TLNLinhaCel *cabeca;
    TLNLinhaCel *ultimo;
    int tamanho;
} TLNLinha;

/* Prot�tipo dos m�dulos do TAD Lista de N�meros de Linha
    Sigla das fun��es: LNL - Lista de N�meros de Linha */
void LNLCriarVazia(TLNLinha *lista);
int LNLInserir(TLNLinha *lista,int nLinha);
int LNLRemover(TLNLinha *lista);
int LNLVerificar(TLNLinha *lista,int nLinha);
int LNLQuantidade(TLNLinha *lista);
void LNLImprimir(TLNLinha *lista);
void LNLEsvaziar(TLNLinha *lista);
