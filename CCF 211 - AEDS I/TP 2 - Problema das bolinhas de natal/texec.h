/* Tempo de Execu��o
    Resumo de fun��es padr�es de medi��o de tempo, encontradas na biblioteca time.h do C. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

typedef struct {
    LARGE_INTEGER tempoInicial;
    LARGE_INTEGER tempoFinal;
    LARGE_INTEGER freq;
    double tempoTotal;
} TTimer;

//Inclusivo
//typedef struct {
//    clock_t tempoInicial;
//    clock_t tempoFinal;
//    double tempoTotal;
//} TTimer;

void TimerIniciar(TTimer *timer);
void TimerParar(TTimer *timer);
void TimerMostrar(TTimer *timer);
