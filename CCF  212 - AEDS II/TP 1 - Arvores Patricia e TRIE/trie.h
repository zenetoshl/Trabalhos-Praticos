/// Barbara de Oliveira Souza - 3039
/// Caio Augusto Moreira Campos - 3042
/// Jose Grigorio Neto - 3046



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
/// A estrutura da celula desta arvore é composta por um char
/// e tres ponteiros, para quando o proximo char é maior igual ou menor.
typedef struct Celula
{
    char palavra;
    int palavraCompleta;
    struct Celula *esq, *dir, *ig;
}Celula;

void inicializaTST (Celula **raiz);
Celula* novaCelula (char palavra);
void inserir (Celula** raiz, char *palavra);
int altura (Celula *raiz);
void contaNos (Celula *raiz, int *contador);
int externoContaNos (Celula *raiz);
void quantPalavras(Celula *raiz, int *quantidade);
int externoQuantPalavras(Celula *raiz);
int pesquisaTST (Celula *raiz, char *PALAVRA, int *contPlv, int *contComp, int *altura);

