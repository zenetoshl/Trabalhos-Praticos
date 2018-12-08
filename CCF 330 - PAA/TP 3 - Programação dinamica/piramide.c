#include "piramide.h"


int **Liberar_matriz_real (int m, int n, int **v)
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

void InicializaPiramide (piramide *mats, int tamanho){
    int i;
    mats->matriz = (int **) calloc (tamanho, sizeof(int *));	// Um vetor de m ponteiros para int */
    if (mats->matriz == NULL) {
        printf ("** Erro: Memoria Insuficiente **");
        return;
    }
    /* aloca as colunas da matriz */
    for ( i = 0; i < tamanho; i++ ) {
        mats->matriz[i] = (int*) calloc (tamanho, sizeof(int));	/* m vetores de n int */
        if (mats->matriz[i] == NULL) {
            printf ("** Erro: Memoria Insuficiente **");
            return;
        }
    }

    mats->matrizPeso = (int **) calloc (tamanho, sizeof(int *));	// Um vetor de m ponteiros para int */
    if (mats->matrizPeso == NULL) {
        printf ("** Erro: Memoria Insuficiente **");
        return;
    }
    /* aloca as colunas da matriz */
    for ( i = 0; i < tamanho; i++ ) {
        mats->matrizPeso[i] = (int*) calloc (tamanho, sizeof(int));	/* m vetores de n int */
        if (mats->matrizPeso[i] == NULL) {
            printf ("** Erro: Memoria Insuficiente **");
            return;
        }
    }

    return;


}


int LerArq (piramide* mats, char* nome){
    char linha;
    int i,j,max;
    FILE* arq;
    arq = fopen(nome, "r");
    (mats->quantidade)=0;
    /// Conta Linha (tamnaho matriz) ///
    while(fscanf(arq,"%c", &linha)!= EOF){
        if (linha == '\n'){
            (mats->quantidade)++;
        }
    }
    (mats->quantidade)++;
    fclose(arq);
    max = (mats->quantidade);

    /// Inicia Matriz
    arq = fopen(nome, "r");
    InicializaPiramide(mats,(mats->quantidade));

    /// Preenche matriz


    for (i=0;i<max;i++){
        for (j=0;j<max;j++){
            if (j<=i){
              fscanf(arq,"%d",&(mats->matriz[i][j]));
              (mats->matrizPeso)[i][j] = (mats->matriz)[i][j];
            }else {
                mats->matriz[i][j] = -1;
                mats->matrizPeso[i][j] = -1;
            }
        }fgetc(arq);

    }

    fclose(arq);
    return 1;
}


void TrazPraFrente (piramide *piramideJogo){

    int i,j;
    int max =(piramideJogo->quantidade);
    int maiorAux;
    for (i=(max-1); i>=1; i--){
        for (j=0;j<i;j++){
            maiorAux =  maior((piramideJogo->matrizPeso[i][j]), (piramideJogo->matrizPeso[i][j+1]));
            (piramideJogo->matrizPeso[i-1][j]) += maiorAux;
        }
    }

}
void  printarResultado (piramide *piramideJogo){
    int i,j;
    int max;
    max = piramideJogo->quantidade;
    for (i=0;i<max;i++){
        for (j=0;j<max;j++){
            if ((piramideJogo->matrizPeso[i][j])!=-1)
            printf("%d ", piramideJogo->matrizPeso[i][j]);
        }printf("\n");
    }
}


int maior (int a, int b){
    if (a>b)
        return a;
    else
        return b;
}

int Recursiva (piramide *piramidejogo, int i, int j ) {
    int auxPeso;
    if (i== (piramidejogo->quantidade)-1){
        piramidejogo->matrizPeso[i][j] = piramidejogo->matriz[i][j];
        return piramidejogo->matriz[i][j];
    }
    else{
        auxPeso = piramidejogo->matriz[i][j] + maior(Recursiva(piramidejogo,i+1,j),Recursiva(piramidejogo,i+1,j+1));
    }piramidejogo->matrizPeso[i][j] = auxPeso;
    return auxPeso;
}



void ResolveRecursivo(piramide *piramidejogo){
    Recursiva(piramidejogo,0,0);
}

void ResolveMemoization (piramide *piramidejogo){
    int i,j;
    for(i=0;i<(piramidejogo->quantidade);i++){
        for (j=0;j<=i;j++){
            piramidejogo->matrizPeso[i][j]= -1;
        }
    }
    Memoization(piramidejogo, 0, 0);
}

int Memoization(piramide *piramidejogo, int i, int j){
    if (i== (piramidejogo->quantidade)-1){
        piramidejogo->matrizPeso[i][j] = piramidejogo->matriz[i][j];
        return piramidejogo->matriz[i][j];
    }else{
        if (piramidejogo->matrizPeso[i][j] == -1){
            piramidejogo->matrizPeso[i][j] = piramidejogo->matriz[i][j] + maior(Memoization(piramidejogo,i+1,j), Memoization(piramidejogo,i+1,j+1));
        }
        return piramidejogo->matrizPeso[i][j];
    }
}
