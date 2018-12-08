/* TAD Dicionário */

#include "dicionario.h"

/* Inicializar o Dicionário
    Percorre todas as posições do campo alfabeto, inicializando-as
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

/* Inserir Palavra no Dicionário
    Insere uma nova palavra no dicionário, retornando OP_NOVAPALAVRA.
    Caso a palavra já exista no dicionário, apenas insere uma nova linha na palavra, retornando OP_SUCESSO.
    Caso a linha também já exista, não faz nenhuma operação, e retorna OP_FALHA. */
int DICInserirPalavra(TDicionario *dicionario,char *cadeiaChar,int nLinha)
{
    int i = cadeiaChar[0] - 'a';
    int resultado;

    resultado = LPVInserir(LABRetornarLPalavra(&(dicionario->alfabeto[i])),cadeiaChar,nLinha);

    if (resultado == OP_NOVAPALAVRA)
        dicionario->numeroDePalavras++;

    return resultado;
}

/* Remover Palavra do Dicionário
    Busca uma palavra no dicionário e a remove.
    Caso a palavra esteja no dicionário e ela for efetivamente removida, retorna OP_SUCESSO.
    Caso a palavra não esteja no dicionário, não faz nenhuma operação, e retorna OP_FALHA. */
int DICRemoverPalavra(TDicionario *dicionario,char *cadeiaChar)
{
    int i = cadeiaChar[0] - 'a';
    int resultado;

    resultado = LPVRemoverPalavra(LABRetornarLPalavra(&(dicionario->alfabeto[i])),cadeiaChar);

    if (resultado)
        dicionario->numeroDePalavras--;

    return resultado;
}

/* Exibir uma Letra do Dicionário
    Imprime apenas a Letra do dicionário indicada pelo parâmetro letra, mostrando quantas palavras estão salvas
    naquela letra, quais são, e em quais linhas aparecem. */
void DICExibirLetra(TDicionario *dicionario,char letra)
{
    printf("\n------------------------------\n\n");
    LABImprimir(&(dicionario->alfabeto[letra - 'A']));
    printf("------------------------------\n\n");
}

/* Exibir Dicionário
    Imprime todas as Letras do Dicionário, mostrando todas as Palavras salvas
    e todas as Listas de Números de Linha correspondentes. */
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

/* Ler Arquivo para o Dicionário
    Lê cada palavra de um arquivo de texto e adiciona-as no Dicionário, retornando OP_SUCESSO.
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

/* Esvaziar Dicionário
    Esvazia cada uma das Letras do Dicionário, liberando todo espaço de memória utilizado pelas Palavras salvas
    e pelas Listas de Números de Linha correspondentes.*/
void DICEsvaziar(TDicionario *dicionario)
{
    int i;
    for (i=0;i<NLETRAS;i++)
        LABEsvaziarEntradas(&(dicionario->alfabeto[i]));

    dicionario->numeroDePalavras = 0;
}

/* Quantidade de Palavras no Dicionário
    Retorna quantas palavras estão sendo armazenadas pelo Dicionário. */
int DICQuantidadePalavras(TDicionario *dicionario)
{
    return dicionario->numeroDePalavras;
}

/* Update - TP3 */

/* Criar Cópia do Dicionário
    Copia todo o conteúdo do Dicionário para mostrar as ordenações nele. */
void DICCriarCopia(TDicionario *copia,TDicionario *original)
{
    int i;
    DICEsvaziar(copia);
    copia->numeroDePalavras = original->numeroDePalavras;
    for (i=0;i<NLETRAS;i++)
        LABCopiar(&(copia->alfabeto[i]),&(original->alfabeto[i]));
}

/* Ordenar o Dicionário
    Ordena todo o Dicionário ou apenas uma das Letras, de acordo com o parâmetro letra (0 indica todo o Dicionário),
    utilizando o algoritmo de ordenação escolhido. Além disso, informa quanto tempo demorou para executar, quantas
    comparações foram feitas, e quantas movimentações foram feitas. */
void DICOrdenar(TDicionario *dicionario,char tipo,char letra,double *tempo,int *comp,int *mov)
{
    TTimer timer;
    int i;

    *tempo = 0;
    *comp = 0;
    *mov = 0;

    if (letra==0)
    {
        for (i=0;i<NLETRAS;i++)
        {
            TimerIniciar(&timer);
            switch (tipo)
            {
            case BUBBLESORT: BubbleSort(LABRetornarLPalavra(&(dicionario->alfabeto[i])),comp,mov); break;
            case SELECTSORT: SelectSort(LABRetornarLPalavra(&(dicionario->alfabeto[i])),comp,mov); break;
            case INSERTSORT: InsertSort(LABRetornarLPalavra(&(dicionario->alfabeto[i])),comp,mov); break;
            case SHELLSORT: ShellSort(LABRetornarLPalavra(&(dicionario->alfabeto[i])),comp,mov); break;
            case QUICKSORT: Quicksort(LABRetornarLPalavra(&(dicionario->alfabeto[i])),comp,mov); break;
            case HEAPSORT: Heapsort(LABRetornarLPalavra(&(dicionario->alfabeto[i])),comp,mov); break;
            }
            *tempo += TimerParar(&timer);
        }
    }
    else
    {
        TimerIniciar(&timer);
        switch (tipo)
        {
        case BUBBLESORT: BubbleSort(LABRetornarLPalavra(&(dicionario->alfabeto[letra - 'A'])),comp,mov); break;
        case SELECTSORT: SelectSort(LABRetornarLPalavra(&(dicionario->alfabeto[letra - 'A'])),comp,mov); break;
        case INSERTSORT: InsertSort(LABRetornarLPalavra(&(dicionario->alfabeto[letra - 'A'])),comp,mov); break;
        case SHELLSORT: ShellSort(LABRetornarLPalavra(&(dicionario->alfabeto[letra - 'A'])),comp,mov); break;
        case QUICKSORT: Quicksort(LABRetornarLPalavra(&(dicionario->alfabeto[letra - 'A'])),comp,mov); break;
        case HEAPSORT: Heapsort(LABRetornarLPalavra(&(dicionario->alfabeto[letra - 'A'])),comp,mov); break;
        }
        *tempo = TimerParar(&timer);
    }
}
