/* TAD Lista de Números de Linha */

#include <stdio.h>
#include <stdlib.h>

#define OP_FALHA 0
#define OP_SUCESSO 1

/* Célula/Nó da lista de números de linha */
typedef struct tnlCel {
    int linha;
    struct tnlCel *proximo;
} TLNLinhaCel;

/* Cabeçalho da lista */
typedef struct {
    TLNLinhaCel *cabeca;
    TLNLinhaCel *ultimo;
    int tamanho;
} TLNLinha;

/* Protótipo dos módulos do TAD Lista de Números de Linha
    Sigla das funções: LNL - Lista de Números de Linha */
void LNLCriarVazia(TLNLinha *lista);
int LNLInserir(TLNLinha *lista,int nLinha);
int LNLRemover(TLNLinha *lista);
int LNLVerificar(TLNLinha *lista,int nLinha);
int LNLQuantidade(TLNLinha *lista);
void LNLImprimir(TLNLinha *lista);
void LNLEsvaziar(TLNLinha *lista);
