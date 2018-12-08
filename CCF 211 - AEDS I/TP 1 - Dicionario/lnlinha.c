/* TAD Lista de N�meros de Linha */

#include "lnlinha.h"

/* Criar Lista Vazia de N�meros de Linha
    N�o zera a lista, apenas inicializa. */
void LNLCriarVazia(TLNLinha *lista)
{
    lista->cabeca = (TLNLinhaCel *)malloc(sizeof(TLNLinhaCel));
    lista->cabeca->proximo = NULL;
    lista->ultimo = lista->cabeca;
    lista->tamanho = 0;
}

/* Inserir N�mero de Linha
    Insere uma nova c�lula na lista no final caso ela j� n�o esteja presente.
    Caso o n�mero de linha j� esteja presente, a fun��o retorna 0, indicando que n�o inseriu uma nova c�lula.
    Caso o n�mero de linha n�o esteja presente, a fun��o retorna 1, indicando que uma nova c�lula foi inserida.*/
int LNLInserir(TLNLinha *lista,int nLinha)
{
    if (LNLVerificar(lista,nLinha)==OP_FALHA)
    {
        lista->ultimo->proximo = (TLNLinhaCel *)malloc(sizeof(TLNLinhaCel));

        if (lista->ultimo->proximo == NULL)
            return OP_FALHA;

        lista->ultimo->proximo->linha = nLinha;
        lista->ultimo->proximo->proximo = NULL;

        lista->ultimo = lista->ultimo->proximo;
        lista->tamanho++;
        return OP_SUCESSO;
    }

    return OP_FALHA;
}
/* Remover N�mero de Linha
    Retira a �ltima c�lula da lista e retorna 1 se a opera��o foi bem sucedida ou 0 caso contr�rio.*/
int LNLRemover(TLNLinha *lista)
{
    TLNLinhaCel *atual = lista->cabeca;

    if (lista->cabeca->proximo==NULL)
        return OP_FALHA;

    while (atual->proximo->proximo!=NULL)
        atual = atual->proximo;

    free(atual->proximo);
    atual->proximo = NULL;
    lista->tamanho--;
    lista->ultimo = atual;

    return OP_SUCESSO;
}

/* Verificar N�mero de Linha
    Verifica se um dado n�mero de linha j� est� presente na lista.*/
int LNLVerificar(TLNLinha *lista,int nLinha)
{
    TLNLinhaCel *atual = lista->cabeca->proximo;

    while (atual!=NULL)
    {
        if (atual->linha == nLinha)
            return OP_SUCESSO;

        atual = atual->proximo;
    }

    return OP_FALHA;
}

/* Retornar Quantidade de N�meros de Linha
    Retorna quantos n�meros est�o guardados dentro da lista.*/
int LNLQuantidade(TLNLinha *lista)
{
    return lista->tamanho;
}

/* Imprimir Lista de N�meros de Linha
    Imprime a lista completa, avisando se ela est� vazia.*/
void LNLImprimir(TLNLinha *lista)
{
    TLNLinhaCel *atual = lista->cabeca->proximo;

    if (atual==NULL)
        printf(">> N�o est� presente em nenhuma linha.\n");
    else
    {
        printf(">> Linhas:\n");
        while (atual!=NULL)
        {
            printf("     %d\n",atual->linha);
            atual = atual->proximo;
        }
    }
}
/* Esvaziar Lista de N�meros de Linha
    Avan�a de c�lula em c�lula liberando o espa�o alocado, esvaziando a lista.*/
void LNLEsvaziar(TLNLinha *lista)
{
    TLNLinhaCel *atual = lista->cabeca;
    TLNLinhaCel *anterior = NULL;
    while (atual!=NULL)
    {
        anterior = atual;
        atual = atual->proximo;
        free(anterior);
    }
}
