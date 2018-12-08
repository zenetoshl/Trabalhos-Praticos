/* TAD Palavra */

#include "palavra.h"

/* Criar Palavra Vazia
    Limpa a cadeia de caracteres e inicializa a Lista de Números de Linha contida no TAD Palavra.*/
void PLVCriarVazia(TPalavra *palavra)
{
    palavra->cadeiaChar[0] = '\0';
    LNLCriarVazia(&(palavra->linhas));
}

/* Preencher Cadeia de Caracteres da Palavra
    Copia a cadeia de caracteres passada na função para o campo Palavra do TAD.*/
void PLVPreencher(TPalavra *palavra,char *cadeiaChar)
{
    strcpy(palavra->cadeiaChar,cadeiaChar);
}

/* Retornar Cadeia de Caracteres da Palavra
    Copia a cadeia de caracteres do campo Palavra do TAD para a cadeia de caracteres passada na função,
    podendo ser utilizada pelo usuário separadamente.*/
void PLVRetornarCadeiaChar(TPalavra *palavra,char *cadeiaChar)
{
    strcpy(cadeiaChar,palavra->cadeiaChar);
}

/* Retornar Lista de Números de Linha da Palavra
    Retorna um ponteiro para o campo linhas (uma Lista de Números de Linha) da Palavra. */
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
    Imprime a cadeia de caracteres junto com a Lista de Números de Linhas em que a Palavra aparece.*/
void PLVImprimir(TPalavra *palavra)
{
    printf("> Palavra: %s\n",palavra->cadeiaChar);
    LNLImprimir(&(palavra->linhas));
    printf("\n");
}
