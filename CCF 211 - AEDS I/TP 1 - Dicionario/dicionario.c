/* TAD Dicion�rio */

#include "dicionario.h"

/* Inicializar o Dicion�rio
    Percorre todas as posi��es do campo alfabeto, inicializando-as
    e preenchendo com o caractere o caractere correspondente. */
void DICInicializar(TDicionario *dicionario)
{
    int i;
    for (i=0;i<NLETRAS;i++)
    {
        LABCriarVazia(&(dicionario->alfabeto[i]));
        LABPreencher(&(dicionario->alfabeto[i]),'A' + i);
    }
    dicionario->numeroDePalavras = 0;
}

/* Inserir Palavra no Dicion�rio
    Insere uma nova palavra no dicion�rio, retornando OP_NOVAPALAVRA.
    Caso a palavra j� exista no dicion�rio, apenas insere uma nova linha na palavra, retornando OP_SUCESSO.
    Caso a linha tamb�m j� exista, n�o faz nenhuma opera��o, e retorna OP_FALHA. */
int DICInserirPalavra(TDicionario *dicionario,char *cadeiaChar,int nLinha)
{
    int i = cadeiaChar[0] - 'a';
    int resultado;

    resultado = LPVInserir(LABRetornarLPalavra(&(dicionario->alfabeto[i])),cadeiaChar,nLinha);

    if (resultado == OP_NOVAPALAVRA)
        dicionario->numeroDePalavras++;

    return resultado;
}

/* Remover Palavra do Dicion�rio
    Busca uma palavra no dicion�rio e a remove.
    Caso a palavra esteja no dicion�rio e ela for efetivamente removida, retorna OP_SUCESSO.
    Caso a palavra n�o esteja no dicion�rio, n�o faz nenhuma opera��o, e retorna OP_FALHA. */
int DICRemoverPalavra(TDicionario *dicionario,char *cadeiaChar)
{
    int i = cadeiaChar[0] - 'a';
    int resultado;

    resultado = LPVRemoverPalavra(LABRetornarLPalavra(&(dicionario->alfabeto[i])),cadeiaChar);

    if (resultado)
        dicionario->numeroDePalavras--;

    return resultado;
}

/* Exibir uma Letra do Dicion�rio
    Imprime apenas a Letra do dicion�rio indicada pelo par�metro letra, mostrando quantas palavras est�o salvas
    naquela letra, quais s�o, e em quais linhas aparecem. */
void DICExibirLetra(TDicionario *dicionario,char letra)
{
    printf("\n------------------------------\n\n");
    LABImprimir(&(dicionario->alfabeto[letra - 'A']));
    printf("------------------------------\n\n");
}

/* Exibir Dicion�rio
    Imprime todas as Letras do Dicion�rio, mostrando todas as Palavras salvas
    e todas as Listas de N�meros de Linha correspondentes. */
void DICExibir(TDicionario *dicionario)
{
    int i;

    printf("          < %d palavra%s no total >\n\n",dicionario->numeroDePalavras,(dicionario->numeroDePalavras>1)?"s":"");
    printf("------------------------------\n\n");
    for (i=0;i<NLETRAS;i++) {
        LABImprimir(&(dicionario->alfabeto[i]));
        printf("------------------------------\n\n");
    }
}

/* Ler Arquivo para o Dicion�rio
    L� cada palavra de um arquivo de texto e adiciona-as no Dicion�rio, retornando OP_SUCESSO.
    Caso haja falha ao ler o arquivo, retorna OP_FALHA.*/
int DICLerArquivo(TDicionario *dicionario,FILE *input)
{
    char cadeiaChar[MAXCHARPALAVRA];
    int nLinha = 1;
    char flag;

    if (input == NULL)
        return OP_FALHA;

    while (fscanf(input,"%s",cadeiaChar)!=EOF)
    {
        DICInserirPalavra(dicionario,cadeiaChar,nLinha);

        flag = fgetc(input);

        if (flag == '\n')
            nLinha++;
    }

    return OP_SUCESSO;
}

/* Esvaziar Dicion�rio
    Esvazia cada uma das Letras do Dicion�rio, liberando todo espa�o de mem�ria utilizado pelas Palavras salvas
    e pelas Listas de N�meros de Linha correspondentes.*/
void DICEsvaziar(TDicionario *dicionario)
{
    int i;
    for (i=0;i<NLETRAS;i++)
        LABEsvaziarEntradas(&(dicionario->alfabeto[i]));

    dicionario->numeroDePalavras = 0;
}

/* Quantidade de Palavras no Dicion�rio
    Retorna quantas palavras est�o sendo armazenadas pelo Dicion�rio. */
int DICQuantidadePalavras(TDicionario *dicionario)
{
    return dicionario->numeroDePalavras;
}
