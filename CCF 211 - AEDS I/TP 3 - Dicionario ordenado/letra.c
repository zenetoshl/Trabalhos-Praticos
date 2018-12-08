/* TAD Letra do Alfabeto */

#include "letra.h"
/* Criar Letra do Alfabeto Vazia
    Inicializa uma Letra do Alfabeto para ser utilizada, colocando o char '\0' no campo caractere e
    inicilizando a Lista de Palavras da Letra.*/
void LABCriarVazia(TLetra *letra)
{
    letra->caractere = '\0';
    LPVCriarVazia(&(letra->entradas));
}

/* Preencher Caractere da Letra do Alfabeto
    Preenche o campo caractere da Letra com o caractere passado como parâmetro. */
void LABPreencher(TLetra *letra,char caractere)
{
    letra->caractere = caractere;
}

/* Retornar Caractere da Letra do Alfabeto
    Retorna o caractere salvo no campo caractere da Letra. */
char LABRetornarCaractere(TLetra *letra)
{
    return letra->caractere;
}

/* Retornar Lista de Palavras da Letra do Alfabeto
    Retorna um ponteiro para o campo entradas (uma Lista de Palavras) da Letra. */
TLPalavra *LABRetornarLPalavra(TLetra *letra)
{
    return &(letra->entradas);
}

/* Imprimir Letra do Alfabeto
    Imprime o caractere e todas as Palavras contidas na lista da Letra. */
void LABImprimir(TLetra *letra)
{
    printf("\t----- %c -----\n",letra->caractere);
    printf("       < %d palavra%s >\n\n",LPVQuantidade(&(letra->entradas)),(LPVQuantidade(&(letra->entradas))>1)?"s":"");
    LPVImprimir(&(letra->entradas));
}

/* Esvaziar Entradas da Letra do Alfabeto
    Esvazia a Lista de Palavras contida do campo entradas da Letra.*/
void LABEsvaziarEntradas(TLetra *letra)
{
    LPVEsvaziar(&(letra->entradas));
}

/* Update - TP3 */
/* Copiar Letra
    Copia todo o conteúdo de uma Letra para outra. */
void LABCopiar(TLetra *para,TLetra *de)
{
    para->caractere = de->caractere;
    LPVCopiar(&(para->entradas),&(de->entradas));
}
