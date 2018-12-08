/// Barbara de Oliveira Souza - 3039
/// Caio Augusto Moreira Campos - 3042
/// Jose Grigorio Neto - 3046

#include "trie.h"

void inicializaTST (Celula **raiz)
{
    *raiz = NULL;
}
///Inicia Cada elemento da estrutura Celula.
Celula* novaCelula (char palavra)
{
    Celula *aux = (Celula *) malloc( sizeof(Celula));
    aux->palavra = palavra;
    aux->palavraCompleta =0;
    aux->esq = NULL;
    aux->dir = NULL;
    aux->ig = NULL;
    return aux;
}
///Insere uma nova palavra, dada a palavra esta funçao recursiva caminha
///pela arvore ate inserir todas as letras da palavra.
void inserir (Celula** raiz, char *palavra)
{
    if(*raiz== NULL)
    {
        *raiz = novaCelula(*palavra);

    }
    if((*palavra)<(*raiz)->palavra)
        inserir(&((*raiz)->esq),palavra);
    else if((*palavra)>(*raiz)->palavra)
        inserir(&((*raiz)->dir),palavra);
    else
    {
        if(*(palavra+1))
            inserir(&((*raiz)->ig),palavra+1);
        else
            (*raiz)->palavraCompleta = 1;
    }
}
///

///A função altura pecorre todos os nos da arvore e retorna aquele que possui maior profundidade.
int altura (Celula *raiz)
{
    int hd,he,hi;
    if(raiz==NULL)
        return -1;
    hd = altura(raiz->dir);
    he = altura(raiz->esq);
    hi = altura(raiz->ig);

    if(hd>he && hd>hi)
        return altura(raiz->dir) +1;
    if(he>hd && he>hi)
        return altura(raiz->esq) + 1;
    if(hi>hd && hi>he)
        return altura(raiz->ig) + 1;
    else
        return altura(raiz->ig) +1;
}
///Funçao que contabiliza os nos, pecorendo a arvore em todos os sentidos
/// ate encontrar um no nulo.
void contaNos (Celula *raiz, int *contador)
{
    if(raiz!=NULL)
    {
        (*contador)++;
        contaNos(raiz->dir,contador);
        contaNos(raiz->esq,contador);
        contaNos(raiz->ig,contador);
    }
}
///Funçao externa que retorna a quantidade de nos na arvore.
int externoContaNos (Celula *raiz)
{
    int contadorNo = 0;
    contaNos(raiz,&contadorNo);
    return contadorNo;
}
///Esta funçao pecorre a arvore e retorna se uma palavra existe ou não.
///Alem da pesquisa em si, esta funçao retorna a altura da palavra pesquisada,
///a quantidade de comparações e a quantidade de palavras no texto.
int pesquisaTST (Celula *raiz, char *PALAVRA, int *contPlv, int *contComp, int*altura)
{
    (*contComp)++;
    if (raiz == NULL)
    {
        (*contPlv)++;
        return 0;
    }
    (*contComp)++;
    if (*PALAVRA < raiz->palavra)
    {
        (*altura)++;
       return pesquisaTST(raiz->esq, PALAVRA, contPlv, contComp,altura);
    }
    else if (*PALAVRA > raiz ->palavra && (*contComp)++)
        {
            (*contComp)++;
            (*altura)++;
            return pesquisaTST(raiz->dir, PALAVRA, contPlv, contComp,altura);
        }

    else if (*PALAVRA == raiz->palavra && (*contComp)++)
    {
        (*contComp)++;
        (*altura)++;
        if (*(PALAVRA+1)=='\0')
        {
            (*contComp)++;
            (*contPlv)++;
            return raiz->palavraCompleta;
        }
        else
        {
            return pesquisaTST(raiz->ig, (PALAVRA+1), contPlv, contComp,altura);
        }
    }
}


/// A função quantidade de palavras percorre a arvore no a no
/// ate encontrar nossa variavel de controle 'palavraCompleta',
/// se esta for um nosso contador recebe mais um.
void quantPalavras(Celula *raiz, int *quantidade)
{
     if(raiz!=NULL)
    {

        if (raiz->palavraCompleta == 1)
        {
            (*quantidade) ++;

        }

        quantPalavras(raiz->ig,quantidade);
        quantPalavras(raiz->dir,quantidade);
        quantPalavras(raiz->esq,quantidade);

    }
}

/// Funçao externa que retorna a quantidade de palavras no dicionario.
int externoQuantPalavras(Celula *raiz)
{
    int quantidade_palavras = 0;
    quantPalavras(raiz, &quantidade_palavras);
    return quantidade_palavras;
}
