// Barbara de Oliveira Souza - 3039
/// Caio Augusto Moreira Campos - 3042
/// Jose Grigorio Neto - 3046
#include "patricia.h"

void Inicializar (TipoArvore *pArvore)
{
    *pArvore=NULL;
}

///InsereEntre é uma funçao auxiliar que é chamada pela Insere quando se faz necessario
/// inserir um determinado no entre outros dois ja existentes.
TipoArvore InsereEntre (char *k, TipoArvore *t, int i, char difere)
{
    TipoArvore aux;
    if(EExterno(*t) || i < (*t)->NO.NInterno.posicao) {

        aux = CriaNoExterno(k);
        if (k[i] < difere)
            return (CriaNoInterno(i, difere, &aux, t));

        else
            return (CriaNoInterno(i, difere, t, &aux));

    }

    else
    {
        if(k[(*t)->NO.NInterno.posicao] >= (*t)->NO.NInterno.letra)
            (*t)->NO.NInterno.Dir = InsereEntre(k,&((*t)->NO.NInterno.Dir),i,difere);
        else
            (*t)->NO.NInterno.Esq = InsereEntre(k,&((*t)->NO.NInterno.Esq),i,difere);
        return (*t);
    }
}
///Funçao que cria um no interno, aquela que contem o char para a comparação; a posiçao deste char na palavra;
///os ponteiros para direita e esquerda.
TipoArvore CriaNoInterno(int i, char K, TipoArvore *Esq,  TipoArvore *Dir)
{

    TipoArvore aux;
    aux = (TipoArvore) malloc(sizeof(TPNo));
    aux->orientacao = Interno;
    aux->NO.NInterno.Esq = *Esq;
    aux->NO.NInterno.Dir = *Dir;
    aux->NO.NInterno.posicao = i;
    aux->NO.NInterno.letra = K;

    return aux;
}
///Função auxilar que retorna se o no é externo
int EExterno (TipoArvore p)
{

    return (p->orientacao == Externo);
}

///Esta funçao cria um no externo (responsavel por armazenar a palavra)
TipoArvore CriaNoExterno (char *k)
{

    TipoArvore aux;
    aux = (TipoArvore) malloc(sizeof(TPNo));
    aux->orientacao = Externo;
    strcpy(aux->NO.Chave, k);
    return aux;
}

///A função insere é responsavel por chamar diversas outras funções auxiliares
///com o intuito de inserir uma nova palavra na arvore, analizando diversos casos
///para trata-los da maneira correta.
TipoArvore Insere(char *k, TipoArvore *t)
{

    TipoArvore aux;
    int i;
    if(*t == NULL){
        return CriaNoExterno(k);
    }
    else
    {
        aux = *t;
        while (!EExterno(aux)) {
            if (strlen(k) >= aux->NO.NInterno.posicao && k[aux->NO.NInterno.posicao] < (aux)->NO.NInterno.letra) {

                aux = aux->NO.NInterno.Esq;
            } else {

                aux = aux->NO.NInterno.Dir;
            }
        }
        i = ComparaPlv((aux)->NO.Chave, k);
        if(i<0){
            return(*t);
        }
        return InsereEntre(k,t,i,maior(k[i],aux->NO.Chave[i]));
    }
}

/// Esta compara duas palavras desde seu primeiro char
/// e retorna a posiçao do char que difere estas.
int ComparaPlv (char *palavraArvore, char *palavraRecebida)
{
    int i=0,tam;
    if(strlen(palavraArvore)<= strlen(palavraRecebida))
        tam = strlen(palavraRecebida);
    else
        tam = strlen(palavraArvore);
    for( i=0; i<=tam; i++)
    {
        if(palavraArvore[i] != palavraRecebida[i])
            return i;
    }
    return -1;

}
///Esta é uma funçao auxiliar que retorna o maior dado dois inteiros.
int maior(int a, int b)
{
    return (a>b)?a:b;
}
///A pesquisa alem de retornar se uma palavra foi encontrada
/// contabiliza a quantidade de comparaçoes e a altura de uma determinada palavra.
int pesquisa(char *k, TipoArvore t,int *qtComp,int *altura)
{
    (*qtComp)++;
    if(EExterno(t))
    {
        (*qtComp)++;
        if(strcmp(k, t->NO.Chave)==0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
        return ;
    }

    (*qtComp)++;
    if(t->NO.NInterno.posicao > strlen(k))
    {
        (*altura)++;
        pesquisa(k, t->NO.NInterno.Esq,qtComp,altura);
        return 0;
    }
    (*qtComp)++;
    if(k[t->NO.NInterno.posicao] >= t->NO.NInterno.letra)
    {
        (*altura)++;
        pesquisa(k,t->NO.NInterno.Dir,qtComp,altura);
    }
    else
    {
        (*altura)++;
        pesquisa(k, t->NO.NInterno.Esq,qtComp,altura);
    }
    return ;
}

///qtNos recebe dois ponteiros para inteiros que sao incrementados a medida que
/// é contabilizado nos internos e externos de uma determinada arvore.
void qtNos(TipoArvore raiz,int *qtNosInternos,int *qtNosExternos)
{
    if( raiz != NULL && EExterno(raiz) == 0)
    {
        (*qtNosInternos)++;
        qtNos(raiz->NO.NInterno.Esq,qtNosInternos,qtNosExternos);
        qtNos(raiz->NO.NInterno.Dir,qtNosInternos,qtNosExternos);
    }
    else if(EExterno(raiz))
        (*qtNosExternos)++;
}

///Funçao responsavel por calcular a altura da arvore
/// ela chama a funçao auxiliar maior para retornar o
///a subarvore de maior profundidade, ate chegar em um  no externo.
int alturaPat (TipoArvore raiz)
{
    if(raiz == NULL)
        return -1;
    else if(EExterno(raiz))
        return 1;
    else
        return 1+(maior(alturaPat(raiz->NO.NInterno.Dir),alturaPat(raiz->NO.NInterno.Esq)));
}

