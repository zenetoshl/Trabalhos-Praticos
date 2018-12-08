/* TAD Lista de Números de Linha */

#include "lpalavra.h"

/* Criar Lista Vazia de Palavras
    Não zera a lista, apenas a inicializa. */
void LPVCriarVazia(TLPalavra *lista)
{
    lista->ultimo = 0;
}

/* Inserir Palavra na Lista
    Insere novo elemento na Lista de Palavras dada uma cadeia de caracteres e um número de linha onde ela aparece.
    Caso essa cadeia de caracteres já esteja presente na lista, apenas uma nova entrada de número é inserida,
    através do índice iExistente retornado pela função LPVVerificar, que é -1 caso a palavra não esteja presente na lista
    ou é o índice do elemento com a palavra correspondente. */
int LPVInserir(TLPalavra *lista,char *cadeiaChar,int nLinha)
{
    int iExistente;

    if (nLinha <= 0)
        return OP_FALHA;

    iExistente = LPVVerificar(lista,cadeiaChar);

    if (iExistente==OP_NAOENCONTRADA)
    {
        if (lista->ultimo==TAMMAXLISTA)
            return OP_FALHA;

        PLVCriarVazia(&(lista->palavras[lista->ultimo]));
        PLVPreencher(&(lista->palavras[lista->ultimo]),cadeiaChar);
        LNLInserir(PLVRetornarLNLinha(&(lista->palavras[lista->ultimo])),nLinha);

        lista->ultimo++;

        return OP_NOVAPALAVRA;
    }
    else
    {
        return LNLInserir(PLVRetornarLNLinha(&(lista->palavras[iExistente])),nLinha);
    }
}
/* Remover Última Palavra da Lista
    Remove a última Palavra da lista, desalocando todos as células da Lista de Números de Linha associada à Palavra. */
int LPVRemoverUltima(TLPalavra *lista)
{
    if (lista->ultimo==0)
        return OP_FALHA;

    LNLEsvaziar(PLVRetornarLNLinha(&(lista->palavras[--lista->ultimo])));

    return OP_SUCESSO;
}
/* Remover Palavra da Lista
    Remove uma dada palavra da lista, de acordo com uma cadeia de caracteres buscada pela função LPVVerificar,
    desalocando todos as células da Lista de Números de Linha associada à palavra. */
int LPVRemoverPalavra(TLPalavra *lista,char *cadeiaChar)
{
    int iExistente = LPVVerificar(lista,cadeiaChar);
    int i;

    if (lista->ultimo==0 || iExistente==OP_NAOENCONTRADA)
        return OP_FALHA;

    LNLEsvaziar(PLVRetornarLNLinha(&(lista->palavras[iExistente])));

    for (i=iExistente+1;i<lista->ultimo;i++)
        lista->palavras[i-1] = lista->palavras[i];

    lista->ultimo--;

    return OP_SUCESSO;
}
/* Verificar Lista de Palavras
    Verifica se uma dada cadeia de caracteres já está em algum índice da lista.
    Caso não esteja presente, retorna -1.
    Caso esteja presente, retorna o índice da Palavra que guarda a cadeia de caracteres. */
int LPVVerificar(TLPalavra *lista,char *cadeiaChar)
{
    int i;
    char cadeiaCharBusca[MAXCHARPALAVRA];

    for (i=0;i<lista->ultimo;i++)
    {
        PLVRetornarCadeiaChar(&(lista->palavras[i]),cadeiaCharBusca);
        if (strcmp(cadeiaCharBusca,cadeiaChar)==0)
            return i;
    }

    return OP_NAOENCONTRADA;
}

/* Quantidade de Palavras na Lista
    Retorna quantas palavras existem na lista. */
int LPVQuantidade(TLPalavra *lista)
{
    return lista->ultimo;
}

/* Imprimir Lista de Palavras
    Imprime todas as palavras dentro da lista.*/
void LPVImprimir(TLPalavra *lista)
{
    int i;

    if (lista->ultimo==0)
        printf("> Nenhuma palavra com esta letra.\n");
    else
        for (i=0;i<lista->ultimo;i++)
            PLVImprimir(&(lista->palavras[i]));
}
/* Esvaziar Lista de Palavras
    Avança de elemento em elemento, esvaziando a Lista de Números de Linha de cada Palavra antes de
    reiniciar a lista.*/
void LPVEsvaziar(TLPalavra *lista)
{
    int i;

    for (i=0;i<lista->ultimo;i++)
        LNLEsvaziar(PLVRetornarLNLinha(&(lista->palavras[i])));

    LPVCriarVazia(lista);
}

/* Update -  TP3 */
/* Copiar Lista de Palavas
    Copia todo o conteúdo de uma Lista de Palavras para outra. */
void LPVCopiar(TLPalavra *para,TLPalavra *de)
{
    int i;
    for (i=0;i<de->ultimo;i++)
        PLVCopiar(&(para->palavras[i]),&(de->palavras[i]));
    para->ultimo = de->ultimo;
}

/* Algoritmos de Ordenação */

/* Bubble Sort */
void BubbleSort(TLPalavra *lista, int *comp, int *mov)
{
    TPalavra aux;
    int i,j,trocas;

    for (i=0;i < lista->ultimo-1;i++)
    {
        trocas = 0;
        for (j=1;j < lista->ultimo-i;j++)
        {
            if (++(*comp) && PLVComparar(lista->palavras[j-1],lista->palavras[j]) > 0)
            {
                aux = lista->palavras[j-1];
                lista->palavras[j-1] = lista->palavras[j];
                lista->palavras[j] = aux;
                trocas = 1;
                (*mov)++;
            }
        }
        if (trocas==0)
            break;
    }
}

/* Select Sort */
void SelectSort(TLPalavra *lista, int *comp, int *mov)
{
    TPalavra aux;
    int i, j, min;
    int n = lista->ultimo;

    for (i=0;i<n-1;i++)
    {
        min = i;
        for (j=i+1;j<n;j++)
            if (++(*comp) && PLVComparar(lista->palavras[j],lista->palavras[min])<0)
                min = j;
        aux = lista->palavras[min];
        lista->palavras[min] = lista->palavras[i];
        lista->palavras[i] = aux;
        (*mov)++;
    }
}

/* Insert Sort */
void InsertSort(TLPalavra *lista, int *comp, int *mov)
{
    TPalavra aux;
    int i,j;
	int n = lista->ultimo;

    for (i=1;i<n;i++)
    {
        aux = lista->palavras[i];
        j = i-1;

        while (++(*comp) && j>=0 && PLVComparar(aux,(lista->palavras[j])) < 0)
        {
            lista->palavras[j+1] = lista->palavras[j];
            j--;
        }
        lista->palavras[j+1] = aux;
        (*mov)++;
    }
}

/* Shell Sort */
void ShellSort(TLPalavra *lista, int *comp, int *mov)
{
    TPalavra aux;
    int i,j,h = 1;
    int n = lista->ultimo;

    while (h < n)
        h = 3*h+1;

    while (h > 1)
    {
        h = h/3;
        for(i=h;i<n;i++)
        {
            aux = lista->palavras[i];
            j = i-h;
            while (++(*comp) && j>=0 && PLVComparar(aux, (lista->palavras[j])) < 0)
            {
                lista->palavras[j+h] = lista->palavras[j];
                j -= h;
            }
            lista->palavras[j+h] = aux;
            (*mov)++;
        }
    }
}

/* Quicksort */
void Quicksort(TLPalavra *lista, int *comp, int *mov)
{
    if (lista->ultimo)
        QSOrdena(0, lista->ultimo-1,lista,comp,mov);
}
void QSOrdena(int Esq, int Dir, TLPalavra *lista, int *comp, int *mov)
{
    int i,j;
    QSParticao(Esq, Dir, &i,&j, lista,comp,mov);
    if (Esq<j) QSOrdena(Esq,j,lista,comp,mov);
    if (i<Dir) QSOrdena(i,Dir,lista,comp,mov);
}

void QSParticao(int Esq, int Dir, int *i, int *j, TLPalavra *lista, int *comp, int *mov)
{
    TPalavra pivo,aux;
    *i = Esq; *j = Dir;
    pivo = lista->palavras[(*i+*j)/2];

    do
    {
        while (++(*comp) && PLVComparar(pivo,lista->palavras[*i])>0) (*i)++;
        while (++(*comp) && PLVComparar(pivo,lista->palavras[*j])<0) (*j)--;
        if(*i<=*j)
        {
            aux = lista->palavras[*j];
            lista->palavras[*j] = lista->palavras[*i];
            lista->palavras[*i] = aux;
            (*i)++;(*j)--;
            (*mov)++;
        }
    } while (*i<=*j);
}


/* Heapsort */
void Heapsort(TLPalavra *lista, int *comp, int *mov)
{
    TPalavra aux;
    int n = lista->ultimo;
    int i = n/2,pai,filho;

    while (1)
    {
        if (i > 0)
            aux = lista->palavras[--i];
        else
        {
            n--;
            if (n <= 0)
                break;
            aux = lista->palavras[n];
            lista->palavras[n] = lista->palavras[0];
        }
        pai = i;
        filho = i*2 + 1;
        while (filho < n)
        {
            if (filho + 1 < n && ++(*comp) && PLVComparar(lista->palavras[filho+1],lista->palavras[filho])>0)
                filho++;
            if (++(*comp) && PLVComparar(lista->palavras[filho],aux)>0)
            {
                lista->palavras[pai] = lista->palavras[filho];
                pai = filho;
                filho = pai*2 + 1;
            }
            else
                break;
        }
        lista->palavras[pai] = aux;
        (*mov)++;
    }
}
