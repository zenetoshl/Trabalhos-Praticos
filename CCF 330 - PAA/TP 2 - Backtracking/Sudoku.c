//
// Created by neto on 05/10/18.
//

#include "Sudoku.h"

int IsValido(Sudoku *k, int linhaAtual, int colunaAtual, int numero){
    int setorLinha = 3*(linhaAtual/3);
    int setorColuna = 3*(colunaAtual/3);
    int linhaAtual1 = (linhaAtual+2)%3;
    int linhaAtual2 = (linhaAtual+4)%3;
    int coluna1 = (colunaAtual+2)%3;
    int coluna2 = (colunaAtual+4)%3;
    int i;

    //checa se é valido para coluna e linha
    for (i = 0; i < N; i++) {
        if (k->sudoku[i][colunaAtual] == numero || k->sudoku[linhaAtual][i] == numero)
            return 0;
    }

    //checa se é valido dentro da sub-matriz 3x3
    if(k->sudoku[linhaAtual1+setorLinha][coluna1+setorColuna] == numero || k->sudoku[linhaAtual2+setorLinha][coluna1+setorColuna] == numero ||
       k->sudoku[linhaAtual1+setorLinha][coluna2+setorColuna] == numero || k->sudoku[linhaAtual2+setorLinha][coluna2+setorColuna] == numero)
        return 0;
    else return 1;

}

int BacktrakingSudoku(Sudoku *k, int linha, int coluna, AnaliseSudoku *chama){
    int numero;
    chama->chamadasRecursivas++;
    if(linha == N){
        return 1;
    }
    if(k->sudoku[linha][coluna] != 0) {
        if ((coluna + 1) == N) { // fim da linha
            if (BacktrakingSudoku(k, linha + 1, 0, chama)) {
                return 1;
            }
        }else {
            if (BacktrakingSudoku(k, linha, coluna + 1, chama)) {
                return 1;
            }
        }
        return 0;
    }
        for (numero = 1; numero <= 9; numero++) {
            if (IsValido(k, linha, coluna, numero)) {
                k->sudoku[linha][coluna] = numero;
                if ((coluna + 1) == N) { // fim da linha
                    if (BacktrakingSudoku(k, linha + 1, 0, chama)) {
                        return 1;
                    }
                }else {
                    if (BacktrakingSudoku(k, linha, coluna + 1, chama)) {
                        return 1;
                    }
                }
                k->sudoku[linha][coluna] = 0;
            }
        }
    return 0;
}


int LerArquivo(ListaSudoku *lista, char* nome){
    int i, j, k;
    FILE* arq;
    arq = fopen(nome, "r");
    if (arq == NULL)
        return 0;
    for(k = 0; k < TAM; k++) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                fscanf(arq, "%d", &(lista->listaSudoku[k].sudoku[i][j]));
            }
        }
    }
    fclose(arq);
    return 1;
}

void PrintSudoku(Sudoku k){
    int i, j;
    for(i = 0; i < N; i++){
        if(i % 3 == 0)
            printf("o - - - o - - - o - - - o\n");

        for(j = 0; j < N; j++){
            if(j % 3 == 0)
                printf("| ");
            if(!k.sudoku[i][j])
                printf("  ");
            else printf("%d ", k.sudoku[i][j]);
        }

        printf("|\n");
    }

    printf("o - - - o - - - o - - - o\n");
}
