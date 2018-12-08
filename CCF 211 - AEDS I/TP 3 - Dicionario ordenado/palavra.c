/* TAD Palavra */

#include "palavra.h"

/* Criar Palavra Vazia
    Limpa a cadeia de caracteres e inicializa a Lista de N�meros de Linha contida no TAD Palavra.*/
void PLVCriarVazia(TPalavra *palavra)
{
    palavra->cadeiaChar[0] = '\0';
    LNLCriarVazia(&(palavra->linhas));
}

/* Preencher Cadeia de Caracteres da Palavra
    Copia a cadeia de caracteres passada na fun��o para o campo Palavra do TAD.*/
void PLVPreencher(TPalavra *palavra,char *cadeiaChar)
{
    strcpy(palavra->cadeiaChar,cadeiaChar);
}

/* Retornar Cadeia de Caracteres da Palavra
    Copia a cadeia de caracteres do campo Palavra do TAD para a cadeia de caracteres passada na fun��o,
    podendo ser utilizada pelo usu�rio separadamente.*/
void PLVRetornarCadeiaChar(TPalavra *palavra,char *cadeiaChar)
{
    strcpy(cadeiaChar,palavra->cadeiaChar);
}

/* Retornar Lista de N�meros de Linha da Palavra
    Retorna um ponteiro para o campo linhas (uma Lista de N�meros de Linha) da Palavra. */
TLNLinha *PLVRetornarLNLinha(TPalavra *palavra)
{
    return &(palavra->linhas);
}

/* Imprimir Cadeia de Caracteres da Palavra
    Imprime apenas a cadeia de caracteres guardada no campo Palavra do TAD.*/
void PLVImprimirChar(TPalavra *palavra)
{
    printf("> Palavra: %s\n",palavra->cadeiaChar);
}

/* Imprimir TAD Palavra
    Imprime a cadeia de caracteres junto com a Lista de N�meros de Linhas em que a Palavra aparece.*/
void PLVImprimir(TPalavra *palavra)
{
    printf("> Palavra: %s\n",palavra->cadeiaChar);
    LNLImprimir(&(palavra->linhas));
    printf("\n");
}

/* Update - TP3 */
/* Comparar Palavras
    Compara a rela��o lexicogr�fica entre duas Palavras. Retorna 0 se forem iguais, um inteiro negativo se a
    palavra A for lexicograficamente inferior que B, ou um inteiro positivo se A for lexicograficamente superior a B,
    assim como especificado pela fun��o strcmp da biblioteca de strings. */
int PLVComparar(TPalavra plvA, TPalavra plvB)
{
    return strcmp(plvA.cadeiaChar,plvB.cadeiaChar);
}

/* Copiar Palavras
    Copia todo o conte�do de uma Palavra para outra. */
void PLVCopiar(TPalavra *para,TPalavra *de)
{
    strcpy(para->cadeiaChar,de->cadeiaChar);
    LNLCopiar(&(para->linhas),&(de->linhas));
}

/* Trocar Palavras
    Troca o conte�do de duas Palavras. */
void PLVTrocar(TPalavra *pA, TPalavra *pB)
{
    TPalavra troca;
    PLVCriarVazia(&troca);
    PLVCopiar(&troca,pA);
    PLVCopiar(pA,pB);
    PLVCopiar(pB,&troca);
    LNLEsvaziar(&(troca.linhas));
}
