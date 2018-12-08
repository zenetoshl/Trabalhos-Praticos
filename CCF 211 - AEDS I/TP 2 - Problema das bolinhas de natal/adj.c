/* Adjacências
    Conjunto de funções resposáveis por verificar as adjacências, gerar os arranjos,
    além do "TAD" que vai representar as adjacências, através de uma matriz. */

#include "adj.h"

void ADJInicializar(TAdj *adj)
{
    adj->matriz = NULL;
    adj->n = 0;
    adj->k = 2;
}

void ADJResetar(TAdj *adj)
{
    int i;
    if (adj->matriz!=NULL)
    {
        for (i=0;i<adj->n;i++)
            free(adj->matriz[i]);
        free(adj->matriz);
    }
}

void ADJMudarNumeroDeCores(TAdj *adj,int k)
{
    adj->k = k;
}

int ADJPreencher(TAdj *adj,FILE *input)
{
    int i,j;

    if (fscanf(input,"%d",&(adj->n))==EOF)
        return 0;

    ADJResetar(adj);
    adj->matriz = (int **)malloc(adj->n*sizeof(int *));
    for (i=0;i<adj->n;i++)
    {
        adj->matriz[i] = (int *)malloc(adj->n*sizeof(int));
        for (j=0;j<adj->n;j++)
            adj->matriz[i][j] = -(i==j);
    }

    while (fscanf(input,"%d %d",&i,&j)!=EOF)
    {
        if (i>=0 && i<=adj->n && j>=0 && j<=adj->n)
        {
            adj->matriz[i-1][j-1] = 1;
            adj->matriz[j-1][i-1] = 1;
        }
    }

    return 1;
}

int ADJVerificar(TAdj adj,int *arranjo)
{
    int i,j;
    for (i=0;i<adj.n;i++)
        for (j=i+1;j<adj.n;j++)
            if (adj.matriz[i][j]==1 && arranjo[i]==arranjo[j])
                return 0;

    return 1;
}



int PRMArranjos(TAdj adj)
{
    int *arranjo;
    int i, validos = 0;

    arranjo = (int *)calloc(adj.n+1,sizeof(int));
    if (arranjo == NULL)
        return -1;

    while (arranjo[adj.n]==0)
    {
        for (i=0;i<adj.k;i++)
        {
            validos += ADJVerificar(adj,arranjo);
            arranjo[0]++;
        }

        for (i=0;i<adj.n;i++)
            if (arranjo[i]==adj.k)
            {
                arranjo[i] = 0;
                arranjo[i+1]++;
            }
    }

    return validos;
}
