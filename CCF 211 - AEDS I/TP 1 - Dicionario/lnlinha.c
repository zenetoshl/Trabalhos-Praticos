/* TAD Lista de Números de Linha */

#include "lnlinha.h"

/* Criar Lista Vazia de Números de Linha
    Não zera a lista, apenas inicializa. */
void LNLCriarVazia(TLNLinha *lista)
{
    lista->cabeca = (TLNLinhaCel *)malloc(sizeof(TLNLinhaCel));
    lista->cabeca->proximo = NULL;
    lista->ultimo = lista->cabeca;
    lista->tamanho = 0;
}

/* Inserir Número de Linha
    Insere uma nova célula na lista no final caso ela já não esteja presente.
    Caso o número de linha já esteja presente, a função retorna 0, indicando que não inseriu uma nova célula.
    Caso o número de linha não esteja presente, a função retorna 1, indicando que uma nova célula foi inserida.*/
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
/* Remover Número de Linha
    Retira a última célula da lista e retorna 1 se a operação foi bem sucedida ou 0 caso contrário.*/
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

/* Verificar Número de Linha
    Verifica se um dado número de linha já está presente na lista.*/
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

/* Retornar Quantidade de Números de Linha
    Retorna quantos números estão guardados dentro da lista.*/
int LNLQuantidade(TLNLinha *lista)
{
    return lista->tamanho;
}

/* Imprimir Lista de Números de Linha
    Imprime a lista completa, avisando se ela está vazia.*/
void LNLImprimir(TLNLinha *lista)
{
    TLNLinhaCel *atual = lista->cabeca->proximo;

    if (atual==NULL)
        printf(">> Não está presente em nenhuma linha.\n");
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
/* Esvaziar Lista de Números de Linha
    Avança de célula em célula liberando o espaço alocado, esvaziando a lista.*/
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
