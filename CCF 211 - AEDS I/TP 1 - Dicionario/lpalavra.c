/* TAD Lista de N�meros de Linha */

#include "lpalavra.h"

/* Criar Lista Vazia de Palavras
    N�o zera a lista, apenas a inicializa. */
void LPVCriarVazia(TLPalavra *lista)
{
    lista->cabeca = (TLPalavraCel *)malloc(sizeof(TLPalavraCel));
    PLVCriarVazia(&(lista->cabeca->palavra));
    lista->cabeca->proximo = NULL;
    lista->ultimo = lista->cabeca;
    lista->tamanho = 0;
}

/* Inserir Palavra na Lista
    Insere nova c�lula na Lista de Palavras dada uma cadeia de caracteres e um n�mero de linha onde ela aparece.
    Caso essa cadeia de caracteres j� esteja presente na lista, apenas uma nova entrada de n�mero � inserida,
    atrav�s do ponteiro pExistente retornado pela fun��o LPVVerificar, que � NULL caso a palavra n�o esteja presente na lista
    ou � o endere�o da c�lula com a palavra correspondente. */
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
/* Remover �ltima Palavra da Lista
    Remove a �ltima palavra da lista, desalocando todos as c�lulas da Lista de N�meros de Linha associada � palavra. */
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
    desalocando todos as c�lulas da Lista de N�meros de Linha associada � palavra. */
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
    Verifica se uma dada cadeia de caracteres j� est� em alguma c�lula da lista.
    Caso n�o esteja presente, retorna NULL.
    Caso esteja presente, retorna o endere�o da c�lula contendo a cadeia de caracteres na Palavra. */
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
    Avan�a de c�lula em c�lula, esvaziando a Lista de N�meros de Linha de cada Palavra antes de desaloc�-la,
    liberando todo o espa�o de cada c�lula, esvaziando assim a Lista de Palavras.*/
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
