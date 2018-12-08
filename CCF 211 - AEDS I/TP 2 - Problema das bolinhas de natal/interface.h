/* Interface
    Contém funções que vão permitir a interação do usuário com o programa. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "adj.h"
#include "texec.h"

#define CTRL_PROSSEGUIR 1
#define CTRL_REPETIR 0

#define MAXCHARESCOLHA 32
#define MAXCHARDIRETORIO 256

#define CAB_MENU 0
#define CAB_CASOS 1
#define CAB_CASOCUSTOM 2
#define CAB_CORES 3


void UI_LimparTela();
void UI_Menu(TAdj *adj,TTimer *timer);

void UI_TestarCasos(TAdj *adj,TTimer *timer);
void UI_MudarCores(TAdj *adj);
void UI_Sair();

void UI_Cabecalhos(int c);
