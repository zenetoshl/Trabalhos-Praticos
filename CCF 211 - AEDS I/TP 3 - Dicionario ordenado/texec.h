/* Tempo de Execução
    Resumo de funções padrões de medição de tempo, encontradas na biblioteca time.h do C. */

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

//typedef struct {
//    clock_t tempoInicial;
//    clock_t tempoFinal;
//    double tempoTotal;
//} TTimer;

void TimerIniciar(TTimer *timer);
double TimerParar(TTimer *timer);
