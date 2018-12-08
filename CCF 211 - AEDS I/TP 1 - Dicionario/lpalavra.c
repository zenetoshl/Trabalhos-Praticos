/* TAD Lista de Números de Linha */

#include "lpalavra.h"

/* Criar Lista Vazia de Palavras
    Não zera a lista, apenas a inicializa. */
void LPVCriarVazia(TLPalavra *lista)
{
    lista->cabeca = (TLPalavraCel *)malloc(sizeof(TLPalavraCel));
    PLVCriarVazia(&(lista->cabeca->palavra));
    lista->cabeca->proximo = NULL;
    lista->ultimo = lista->cabeca;
    lista->tamanho = 0;
}

/* Inserir Palavra na Lista
    Insere nova célula na Lista de Palavras dada uma cadeia de caracteres e um número de linha onde ela aparece.
    Caso essa cadeia de caracteres já esteja presente na lista, apenas uma nova entrada de número é inserida,
    através do ponteiro pExistente retornado pela função LPVVerificar, que é NULL caso a palavra não esteja presente na lista
    ou é o endereço da célula com a palavra correspondente. */
int LPVInserir(TLPalavra *lista,char *cadeiaChar,int nLinha)
{
    TLPalavraCel *pExistente = LPVVerificar(lista,cadeiaChar);

    if (nLinha <= 0)
        return OP_FALHA;

    if (pExistente==NULL)
    {
        lista->ultimo->proximo = (TLPalavraCel *)malloc(sizeof(TLPalavraCel));

        if (lista->ultimo->proximo==NULL)
            return OP_FALHA;

        PLVCriarVazia(&(lista->ultimo->proximo->palavra));
        PLVPreencher(&(lista->ultimo->proximo->palavra),cadeiaChar);
        LNLInserir(PLVRetornarLNLinha(&(lista->ultimo->proximo->palavra)),nLinha);

        lista->ultimo->proximo->proximo = NULL;

        lista->ultimo = lista->ultimo->proximo;
        lista->tamanho++;
        return OP_NOVAPALAVRA;
    }
    else
    {
        return LNLInserir(PLVRetornarLNLinha(&(pExistente->palavra)),nLinha);
    }
}
/* Remover Última Palavra da Lista
    Remove a última palavra da lista, desalocando todos as células da Lista de Números de Linha associada à palavra. */
int LPVRemoverUltima(TLPalavra *lista)
{
    TLPalavraCel *atual = lista->cabeca;

    if (lista->cabeca->proximo==NULL)
        return OP_FALHA;

    while (atual->proximo->proximo!=NULL)
        atual = atual->proximo;

    LNLEsvaziar(PLVRetornarLNLinha(&(atual->proximo->palavra)));
    free(atual->proximo);
    atual->proximo = NULL;
    lista->tamanho--;
    lista->ultimo = atual;

    return OP_SUCESSO;
}
/* Remover Palavra da Lista
    Remove uma dada palavra da lista, de acordo com uma cadeia de caracteres,
    desalocando todos as células da Lista de Números de Linha associada à palavra. */
int LPVRemoverPalavra(TLPalavra *lista,char *cadeiaChar)
{
    TLPalavraCel *atual = lista->cabeca;
    TLPalavraCel *removida = NULL;
    char cadeiaCharBusca[MAXCHARPALAVRA];

    if (lista->cabeca->proximo==NULL)
        return OP_FALHA;

    while (atual->proximo!=NULL)
    {
        PLVRetornarCadeiaChar(&(atual->proximo->palavra),cadeiaCharBusca);
        if (strcmp(cadeiaCharBusca,cadeiaChar)==0)
        {
            removida = atual->proximo;
            atual->proximo = atual->proximo->proximo;
            lista->tamanho--;

            LNLEsvaziar(PLVRetornarLNLinha(&(removida->palavra)));
            free(removida);

            if (atual->proximo==NULL)
                lista->ultimo = atual;

            return OP_SUCESSO;
        }

        atual = atual->proximo;
    }

    return OP_FALHA;
}
/* Verificar Lista de Palavras
    Verifica se uma dada cadeia de caracteres já está em alguma célula da lista.
    Caso não esteja presente, retorna NULL.
    Caso esteja presente, retorna o endereço da célula contendo a cadeia de caracteres na Palavra. */
TLPalavraCel *LPVVerificar(TLPalavra *lista,char *cadeiaChar)
{
    TLPalavraCel *atual = lista->cabeca->proximo;
    char cadeiaCharBusca[MAXCHARPALAVRA];

    while (atual!=NULL)
    {
        PLVRetornarCadeiaChar(&(atual->palavra),cadeiaCharBusca);
        if (strcmp(cadeiaCharBusca,cadeiaChar)==0)
            return atual;

        atual = atual->proximo;
    }

    return NULL;
}

/* Quantidade de Palavras na Lista
    Retorna quantas palavras existem na lista. */
int LPVQuantidade(TLPalavra *lista)
{
    return lista->tamanho;
}

/* Imprimir Lista de Palavras
    Imprime todas as palavras dentro da lista.*/
void LPVImprimir(TLPalavra *lista)
{
    TLPalavraCel *atual = lista->cabeca->proximo;

    if (atual==NULL)
        printf("> Nenhuma palavra com esta letra.\n");
    else
    {
        while (atual!=NULL)
        {
            PLVImprimir(&(atual->palavra));
            atual = atual->proximo;
        }

    }
}
/* Esvaziar Lista de Palavras
    Avança de célula em célula, esvaziando a Lista de Números de Linha de cada Palavra antes de desalocá-la,
    liberando todo o espaço de cada célula, esvaziando assim a Lista de Palavras.*/
void LPVEsvaziar(TLPalavra *lista)
{
    TLPalavraCel *atual = lista->cabeca;
    TLPalavraCel *anterior = NULL;

    while (atual!=NULL)
    {
        anterior = atual;
        atual = atual->proximo;
        LNLEsvaziar(PLVRetornarLNLinha(&(anterior->palavra)));
        free(anterior);
    }

    LPVCriarVazia(lista);
}
