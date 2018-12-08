//
// Created by Jose on 08/08/18.
//
#include <stdio.h>
#include <stdlib.h>
#define M 22
#define N 82


typedef struct {
    char quadro[M][N];
}arte;

void desenhasw(arte*, int, int);
void desenhaquad (arte*);
void desenhax (arte*,int,int);
void desenhaplus (arte*,int,int);


//basico
void ast(arte*);
void plus(arte*);
void X(arte*);
void sw(arte*);

int checkplus (arte,int,int);
int checksw (arte,int,int);
int checkx (arte,int,int);
//fim basico

//caindo
void fall(arte* desenho);


void desenha (arte);

