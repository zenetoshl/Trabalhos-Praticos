/*
	Bárbara de Oliveira Souza 3039
	Caio Augusto Moreira 3042
	Jose Grigorio Neto 3046

*/

#include "arvore.h"
void Inicializa(TipoApontador *Dicionario)
{
    *Dicionario = NULL;
}
///Funções de Inserção
void Insere(TipoRegistro Reg, TipoApontador *Dicionario, int *hInsere, int *cPesquisa, double *Falha, double *Total)
{
    short Cresceu;
    TipoRegistro RegRetorno;
    TipoPagina *ApRetorno, *ApTemp;
    Ins(Reg, *Dicionario, &Cresceu, &RegRetorno, &ApRetorno, hInsere, cPesquisa, Falha);
    (*cPesquisa)++;
    if (Cresceu)  /* Arvore cresce na altura pela raiz */
    {
        ApTemp = (TipoPagina *)malloc(sizeof(TipoPagina));
        ApTemp->n = 1;
        ApTemp->r[0] = RegRetorno;
        ApTemp->p[1] = ApRetorno;
        ApTemp->p[0] = *Dicionario;
        *Dicionario = ApTemp;
    }
    (*Total)++;
    (*hInsere)++;
}
void Ins(TipoRegistro Reg, TipoApontador Dicionario, short *Cresceu, TipoRegistro *RegRetorno,  TipoApontador *ApRetorno, int *hInsere, int *cPesquisa, double *Falha)
{
    long i = 1;
    long j;
    TipoApontador ApTemp;
    (*cPesquisa)++;
    if (Dicionario == NULL)
    {
        *Cresceu = TRUE; (*RegRetorno) = Reg; (*ApRetorno) = NULL;
        (*hInsere--);
        return;
    }
    while (i < Dicionario->n && Reg.Chave > Dicionario->r[i-1].Chave)
    {
        (*cPesquisa)++;
        i++;
    }
    (*cPesquisa)++;
    if (Reg.Chave == Dicionario->r[i-1].Chave)
    {
        (*Falha)++;
        *Cresceu = FALSE;
        return;
    }
    (*cPesquisa)++;
    if (Reg.Chave < Dicionario->r[i-1].Chave)
        i--;
    Ins(Reg, Dicionario->p[i], Cresceu, RegRetorno, ApRetorno, hInsere, cPesquisa, Falha);
    (*cPesquisa)++;
    (*hInsere)++;
    if (!*Cresceu)
        return;
    (*cPesquisa)++;
    if (Dicionario->n < MM)   /* Pagina tem espaco */
    {
        InsereNaPagina(Dicionario, *RegRetorno, *ApRetorno, cPesquisa);
        *Cresceu = FALSE;
        return;
    }
    /* Overflow: Pagina tem que ser dividida */
    ApTemp = (TipoApontador)malloc(sizeof(TipoPagina));
    ApTemp->n = 0;  ApTemp->p[0] = NULL;
    (*cPesquisa)++;
    if (i < M + 1)
    {
        InsereNaPagina(ApTemp, Dicionario->r[MM-1], Dicionario->p[MM], cPesquisa);
        Dicionario->n--;
        InsereNaPagina(Dicionario, *RegRetorno, *ApRetorno, cPesquisa);
    }
    else InsereNaPagina(ApTemp, *RegRetorno, *ApRetorno, cPesquisa);
    for (j = M + 2; j <= MM; j++)
        InsereNaPagina(ApTemp, Dicionario->r[j-1], Dicionario->p[j], cPesquisa);
    Dicionario->n = M;
    ApTemp->p[0] = Dicionario->p[M+1];
    *RegRetorno = Dicionario->r[M];  *ApRetorno = ApTemp;
}
void InsereNaPagina(TipoApontador Dicionario, TipoRegistro Reg, TipoApontador ApDir, int *cPesquisa)
{
    short NaoAchouPosicao;
    int k;
    k = Dicionario->n;
    NaoAchouPosicao = (k > 0);
    while (NaoAchouPosicao)
    {
        (*cPesquisa)++;
        if (Reg.Chave >= Dicionario->r[k-1].Chave)
        {
            NaoAchouPosicao = FALSE;
            break;
        }
        Dicionario->r[k] = Dicionario->r[k-1];
        Dicionario->p[k+1] = Dicionario->p[k];
        k--;
        (*cPesquisa)++;
        if (k < 1)
            NaoAchouPosicao = FALSE;
    }
    Dicionario->r[k] = Reg;
    Dicionario->p[k+1] = ApDir;
    Dicionario->n++;
}
/*Fim de Operações de Inserção*/
///Operações de Retirada
void Retira(TipoChave Ch, TipoApontador *Dicionario,int *hRemover, int *cRemover, double *Falha, double *Total)
{
    short Diminuiu;
    TipoApontador Aux;
    Ret(Ch, Dicionario, &Diminuiu, hRemover, cRemover, Falha);
    (*cRemover)++;
    if (Diminuiu && (*Dicionario)->n == 0)  /* Arvore diminui na altura */
    {
        Aux = *Dicionario;
        *Dicionario = Aux->p[0];
        free(Aux);
    }
    (*Total)++;
    (*hRemover)++;
}

void Ret(TipoChave registro, TipoApontador *Dicionario, short *Diminuiu,int *hRemover, int *cRemover, double *Falha)
{
    long j, Ind = 1;
    TipoApontador Pag;
    (*cRemover)++;
    if (*Dicionario == NULL)
    {
        (*Falha) ++;
        (*Diminuiu) = FALSE;
        return;
    }
    Pag = *Dicionario;
    while (Ind < Pag->n && registro > Pag->r[Ind-1].Chave)
    {
        (*cRemover)++;
        Ind++;
    }
    (*cRemover)++;
    if (registro == Pag->r[Ind-1].Chave)
    {
        (*cRemover)++;
        if (Pag->p[Ind-1] == NULL)   /* TipoPagina folha */
        {
            Pag->n--;
            *Diminuiu = (Pag->n < M);
            for (j = Ind; j <= Pag->n; j++)
            {
                Pag->r[j-1] = Pag->r[j];
                Pag->p[j] = Pag->p[j+1];
            }
            return;
        }
        /* TipoPagina nao e folha: trocar com antecessor */
        Antecessor(*Dicionario, Ind, Pag->p[Ind-1], Diminuiu, cRemover);
        (*cRemover)++;
        if (*Diminuiu)
            Reconstitui(Pag->p[Ind-1], *Dicionario, Ind - 1, Diminuiu, cRemover);
        return;
    }
    (*cRemover)++;
    if (registro > Pag->r[Ind-1].Chave)
        Ind++;
    Ret(registro, &Pag->p[Ind-1], Diminuiu, hRemover, cRemover, Falha);
    (*hRemover)++;
    (*cRemover)++;
    if (*Diminuiu)
        Reconstitui(Pag->p[Ind-1], *Dicionario, Ind - 1, Diminuiu, cRemover);
}

void Reconstitui(TipoApontador ApPag, TipoApontador ApPai, int PosPai, short *Diminuiu, int *cRemover)
{
    TipoPagina *Aux;  long DispAux, j;
    (*cRemover)++;
    if (PosPai < ApPai->n)  /* Aux = TipoPagina a direita de ApPag */
    {
        Aux = ApPai->p[PosPai+1];
        DispAux = (Aux->n - M + 1) / 2;
        ApPag->r[ApPag->n] = ApPai->r[PosPai];
        ApPag->p[ApPag->n + 1] = Aux->p[0];  ApPag->n++;
        (*cRemover)++;
        if (DispAux > 0)  /* Existe folga: transfere de Aux para ApPag */
        {
            for (j = 1; j < DispAux; j++)
            InsereNaPagina(ApPag, Aux->r[j-1], Aux->p[j], cRemover);
            ApPai->r[PosPai] = Aux->r[DispAux-1];
            Aux->n -= DispAux;
            for (j = 0; j < Aux->n; j++)
                Aux->r[j] = Aux->r[j + DispAux];
            for (j = 0; j <= Aux->n; j++)
                Aux->p[j] = Aux->p[j + DispAux];
            *Diminuiu = FALSE;
        }
        else /* Fusao: intercala Aux em ApPag e libera Aux */
        {
            for (j = 1; j <= M; j++)
                InsereNaPagina(ApPag, Aux->r[j-1], Aux->p[j], cRemover);
            free(Aux);
            for (j = PosPai + 1; j < ApPai->n; j++)
            {
                ApPai->r[j-1] = ApPai->r[j];
                ApPai->p[j] = ApPai->p[j+1];
            }
            ApPai->n--;
            (*cRemover)++;
            if (ApPai->n >= M)
                *Diminuiu = FALSE;
        }
    }
    else /* Aux = TipoPagina a esquerda de ApPag */
    {
        Aux = ApPai->p[PosPai-1];
        DispAux = (Aux->n - M + 1) / 2;
        for (j = ApPag->n; j >= 1; j--)
            ApPag->r[j] = ApPag->r[j-1];
        ApPag->r[0] = ApPai->r[PosPai-1];
        for (j = ApPag->n; j >= 0; j--)
            ApPag->p[j+1] = ApPag->p[j];
            ApPag->n++;
        (*cRemover)++;
        if (DispAux > 0) /* Existe folga: transf. de Aux para ApPag */
        {
            for (j = 1; j < DispAux; j++)
                InsereNaPagina(ApPag, Aux->r[Aux->n - j],Aux->p[Aux->n - j + 1], cRemover);
            ApPag->p[0] = Aux->p[Aux->n - DispAux + 1];
            ApPai->r[PosPai-1] = Aux->r[Aux->n - DispAux];
            Aux->n -= DispAux;  *Diminuiu = FALSE;
        }
        else /* Fusao: intercala ApPag em Aux e libera ApPag */
        {
            for (j = 1; j <= M; j++)
                InsereNaPagina(Aux, ApPag->r[j-1], ApPag->p[j], cRemover);
            free(ApPag);  ApPai->n--;
            (*cRemover)++;
            if (ApPai->n >= M)  *Diminuiu = FALSE;
        }
    }
}

void Antecessor(TipoApontador Dicionario, int Ind, TipoApontador ApPai, short *Diminuiu, int *cRemover)
{
    (*cRemover)++;
    if (ApPai->p[ApPai->n] != NULL)
    {
        Antecessor(Dicionario, Ind, ApPai->p[ApPai->n], Diminuiu, cRemover);
        (*cRemover)++;
        if (*Diminuiu)
        Reconstitui(ApPai->p[ApPai->n], ApPai, (long)ApPai->n, Diminuiu, cRemover);
        return;
    }
    Dicionario->r[Ind-1] = ApPai->r[ApPai->n - 1];
    ApPai->n--;  *Diminuiu = (ApPai->n < M);
}
/*Fim Retiradas*/
///Funções de Impressão
void ImprimeI(TipoApontador Dicionario, int nivel)
{
    long i;
    if (Dicionario == NULL) return;
    printf("Nivel %d : ", nivel);
    for (i = 0; i < Dicionario->n; i++)
        printf("%ld ",(long)Dicionario->r[i].Chave);
    putchar('\n');
    nivel++;
    for (i = 0; i <= Dicionario->n; i++)
        ImprimeI(Dicionario->p[i], nivel);
}

void Imprime(TipoApontador Dicionario)
{
    int  n = 0;
    ImprimeI(Dicionario, n);
}
/*Fim de Impressão*/
///Conjunto de Funções próprias
void Pesquisa(TipoRegistro *x, TipoApontador Dicionario, int *HP, int *cPesquisa, double *Falha, double *Total)
{
    long i = 1;
    (*cPesquisa)++;
    if (Dicionario == NULL)
    {
        (*Falha)++;
        (*Total)++;
        ///printf(">TipoRegistro nao esta presente na arvore\n");
        (*HP)--;
        return;
    }
    while (i < Dicionario->n && x->Chave > Dicionario->r[i-1].Chave)
    {
        i++;
        (*cPesquisa)++;
    }
    (*cPesquisa)++;
    if (x->Chave == Dicionario->r[i-1].Chave)
    {
        *x = Dicionario->r[i-1];
        (*Total)++;
        printf(">Match: ' %d '\n",x->Chave);
        return;
    }
    (*cPesquisa)++;
    if (x->Chave < Dicionario->r[i-1].Chave)
    {
        (*HP)++;
        Pesquisa(x, Dicionario->p[i-1],HP, cPesquisa, Falha, Total);
    }
    else
    {
        (*HP) ++;
        Pesquisa(x, Dicionario->p[i],HP, cPesquisa, Falha, Total);
    }
}
