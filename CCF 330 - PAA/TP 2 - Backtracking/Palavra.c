//
// Created by neto on 24/10/18.
//

#include "Palavra.h"


char **Liberar_matriz_real (int m, int n, char **v)
{
    int  i;  /* variavel auxiliar */
    if (v == NULL) return (NULL);
    if (m < 1 || n < 1) {  /* verifica parametros recebidos */
        printf ("** Erro: Parametro invalido **\n");
        return (v);
    }
    for (i=0; i<m; i++) free (v[i]); /* libera as linhas da matriz */
    free (v);      /* libera a matriz (vetor de ponteiros) */
    return (NULL); /* retorna um ponteiro nulo */
}

void Inicializa (CacaPalavra *mats){
    int i;
    mats->matriz = (char **) calloc (mats->X, sizeof(char *));	// Um vetor de m ponteiros para char */
    if (mats->matriz == NULL) {
        printf ("** Erro: Memoria Insuficiente **");
        return;
    }
    /* aloca as colunas da matriz */
    for ( i = 0; i < 5; i++ ) {
        mats->matriz[i] = (char*) calloc (mats->Y, sizeof(char));	/* m vetores de n char */
        if (mats->matriz[i] == NULL) {
            printf ("** Erro: Memoria Insuficiente **");
            return;
        }
    }
    mats->matrizC = (int **) calloc (mats->X, sizeof(int *));	// Um vetor de m ponteiros para inteiro */
    if (mats->matrizC == NULL) {
        printf ("** Erro: Memoria Insuficiente **");
        return;
    }
    /* aloca as colunas da matriz */
    for ( i = 0; i < mats->Y; i++ ) {
        mats->matrizC[i] = (int*) calloc (mats->Y, sizeof(int));	/* m vetores de n inteiros */
        if (mats->matrizC[i] == NULL) {
            printf ("** Erro: Memoria Insuficiente **");
            return;
        }
    }
}
                  // mats, direcao, palavra, marca, i, j
int CacaPalavras(CacaPalavra* mats, int direcao, char* palavra, int* marca, int i, int j, AnaliseCaca *chama){
    int marcaAnterior = mats->matrizC[i][j];
    int qtd = 0;
    chama->chamadasRecursivas++;
    if (palavra[0] == mats->matriz[i][j]) {
        mats->matrizC[i][j] = *marca;
        if (palavra[1] == '\0'){
            (*marca)++;
            return 1;
        }
        if (direcao != ABAIXO && (i + 1) < mats->Y) {
            qtd += CacaPalavras(mats, ABAIXO, palavra + 1, marca, i + 1, j, chama);
        }
        if (direcao != ESQ && direcao != DIR) {
            if ((j + 1) < mats->X)
                qtd += CacaPalavras(mats, DIR, palavra + 1, marca, i, j + 1, chama);
            if ((j - 1) < mats->Y)
                qtd += CacaPalavras(mats, ESQ, palavra + 1, marca, i, j - 1, chama);
        }
        if (qtd == 0){
            mats->matrizC[i][j] = marcaAnterior;
        }
    } return qtd;
}

int Procura (CacaPalavra *mats, char* palavra, AnaliseCaca *chama){
    int i, j, qtd = 0;
    int marca = 1;
    for (i = 0; i < mats->Y; i++){
        for (j = 0; j < mats->X; j++){
            qtd =+ CacaPalavras(mats, INICIO, palavra, &marca, i, j, chama);
        }
    }
    return qtd;
}

void PrintCacaPalavra (CacaPalavra mats){
    int i, j;
    for (i = 0; i < mats.Y; i++){
        for (j = 0; j < mats.X; j++){
            if(mats.matrizC[i][j])
                printf("%c",mats.matriz[i][j]);
            else
                printf("*");
        }
        printf("\n");
    }
}

int LerArq (CacaPalavra* mats, char* nome){
    int i, j;

    FILE* arq;
    arq = fopen(nome, "r");
    fscanf(arq, "%d %d", &(mats->Y), &(mats->X));
    fgetc(arq);
    Inicializa(mats);
    if (arq == NULL)
        return 0;
    for (i = 0; i < mats->Y; i++) {
        for (j = 0; j < mats->X; j++) {
            fscanf(arq, "%c", &(mats->matriz[i][j]));
            mats->matrizC[i][j] = 0;
        }
        fgetc(arq);
    }
    fclose(arq);
    return 1;
}

