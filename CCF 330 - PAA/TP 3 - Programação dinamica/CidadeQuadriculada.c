

#include "CidadeQuadriculada.h"

void Inicializa (Cidade *m){
    int i, j;
    m->cidade = (int **) calloc (m->tam[X], sizeof(int *));	// Um vetor de m ponteiros para inteiro */
    if (m->cidade == NULL) {
        printf ("** Erro: Memoria Insuficiente **");
        return;
    }
    /* aloca as colunas da matriz */
    for ( i = 0; i < m->tam[X]; i++ ) {
        m->cidade[i] = (int*) calloc (m->tam[Y], sizeof(int));	/* m vetores de n inteiros */
        if (m->cidade[i] == NULL) {
            printf ("** Erro: Memoria Insuficiente **");
            return;
        }
    }
}

int LerArqC (Cidade *m, char* nome) {
    int x, y;
    char d;
    FILE *arq;
    arq = fopen(nome, "r");
    fscanf(arq, "%d %d", &(m->tam[X]), &(m->tam[Y]));
    fgetc(arq);

    Inicializa(m);

    fscanf(arq, "%d %d", &(m->startEnd[INICIO][X]), &(m->startEnd[INICIO][Y]));
    fgetc(arq);

    fscanf(arq, "%d %d", &(m->startEnd[FIM][X]), &(m->startEnd[FIM][Y]));
    fgetc(arq);

    m->startEnd[INICIO][Y]--;
    m->startEnd[INICIO][X]--;
    m->startEnd[FIM][Y]--;
    m->startEnd[FIM][X]--;

    while (fscanf(arq, "%d %d %c", &y, &x, &d) != EOF) {
        fgetc(arq);

        if (d == 'L') {
            m->cidade[y - 1][x - 1] = L;
        } else if (d == 'N') {
            m->cidade[y - 1][x - 1] = N;
        }
    }
}

int** CalcularManeiras(Cidade *m) {
    int i, j;
    int **cont;
    cont = (int **) calloc(m->tam[X], sizeof(int *));
    for (i = 0; i < m->tam[X]; i++)
        cont[i] = (int *) calloc(m->tam[Y], sizeof(int));

        for (i = 0; i < m->tam[X]; i++) {
            for (j = 0; j < m->tam[Y]; j++) {
                cont[i][j] = 0;
            }
        }

        cont[m->startEnd[FIM][X]][m->startEnd[FIM][Y]] = 1;
        for (i = m->startEnd[FIM][X]; i >= 0; i--) {
            for (j = m->startEnd[FIM][Y]; j >= 0; j--) {
                if (i < m->startEnd[FIM][X] && m->cidade[i][j] != N) {
                    cont[i][j] += cont[i + 1][j];
                }
                if (j < m->startEnd[FIM][Y] && m->cidade[i][j] != L) {
                    cont[i][j] += cont[i][j + 1];
            }
        }
    }return cont;
}

int CidadeQuad(Cidade *m){
    int** mat;
    mat = CalcularManeiras(m);
    ImprimeCaminho(mat, *m);
    return mat[m->startEnd[INICIO][X]][m->startEnd[INICIO][Y]];
}

void ImprimeCaminho(int **matriz, Cidade m) {
    int i = 0;
    int j = 0;

    int caminho[m.tam[X]][m.tam[Y]];

    for (i = 0; i < m.tam[X]; i++) {
        for (j = 0; j < m.tam[Y]; j++) {
            caminho[i][j] = 0;
        }
        printf("\n");
    }
    i = m.startEnd[INICIO][X];
    j = m.startEnd[INICIO][Y];
    caminho[i][j] = 2;
    int flag = 0;
    while (1) {
        if (i < m.tam[X] - 1 && m.cidade[i][j] != N) {
            if(matriz[i+1][j]){
                i++;
                flag = 1;
            }
            caminho[i][j] = 1;
        }if (j < m.tam[Y] - 1 && m.cidade[i][j] != L){
            if(matriz[i][j+1]){
                j++;
                flag = 1;
            }
            caminho[i][j] = 1;
        }
        if(flag == 0){
            break;
        }
        flag = 0;

    }

    caminho[m.startEnd[FIM][X]][m.startEnd[FIM][Y]] = 2;

    for (i = m.tam[X]-1; i >=  0; i--) {
        for (j = 0; j < m.tam[Y]; j++) {
            printf("%d ", caminho[i][j]);
        }
        printf("\n");
    }
}
