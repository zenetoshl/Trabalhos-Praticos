// Interface

#ifndef CLI_H
#define CLI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "bmh.h"
#include "shiftand.h"
#include "timer.h"

#define ESCOLHAMAX 16
#define ARQUIVOMAX 256
#define ESPERAR printf("\nPressione ENTER para continuar...\n"); getchar()

void CLILimparTela();
void CLIImprimirCabecalho(char analise);

void CLIMenu();
void CLIBMH(char analise);
void CLIShiftAnd(char analise);
void CLIAnalise();

int  CLILerTexto(char *dir, char *texto);
void CLIEscreverRegistro(FILE *out, double val, char nl);
void CLIMostrarMatches(char *texto, LList *matches);

#endif
