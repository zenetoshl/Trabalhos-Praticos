//
// Created by neto on 05/10/18.
//
#ifndef TP02_SUDOKU_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#endif
#define N 9
#define TAM 5

typedef struct{
    int chamadasRecursivas;
}AnaliseSudoku;

typedef struct{
    int sudoku[N][N];
}Sudoku;

typedef struct {
    Sudoku listaSudoku[TAM];
}ListaSudoku;

int IsValido(Sudoku *k, int linha, int coluna, int numero);
int BacktrakingSudoku(Sudoku *k, int linha, int coluna, AnaliseSudoku *chama);
int LerArquivo(ListaSudoku *lista, char* nome);
void PrintSudoku(Sudoku k);
