/* Tempo de Execução
    Resumo de funções padrões de medição de tempo, encontradas na biblioteca time.h do C. */

#include "texec.h"

void TimerIniciar(TTimer *timer)
{
    QueryPerformanceCounter(&(timer->tempoInicial));
//    timer->tempoInicial = clock();
}

double TimerParar(TTimer *timer)
{
    QueryPerformanceCounter(&(timer->tempoFinal));
    QueryPerformanceFrequency(&(timer->freq));
    timer->tempoTotal = (double)(timer->tempoFinal.QuadPart - timer->tempoInicial.QuadPart)/timer->freq.QuadPart;
//    timer->tempoFinal = clock();
//    timer->tempoTotal = (double)(timer->tempoFinal - timer->tempoInicial)/CLOCKS_PER_SEC;
    return timer->tempoTotal;
}
