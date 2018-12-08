/* Interface de Usuário (UI) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dicionario.h"

#define CTRL_PROSSEGUIR 1
#define CTRL_REPETIR 0

#define MAXCHARESCOLHA 32
#define MAXCHARDIRETORIO 256

void UI_ImprimirCabecalho();
void UI_ImprimirCabecalhoOrd();
void UI_LimparTela();

void UI_MenuPrincipal(TDicionario *dicionario);

void UI_LerArquivo(TDicionario *dicionario);
void UI_InserirPalavra(TDicionario *dicionario);
void UI_RemoverPalavra(TDicionario *dicionario);
void UI_ExibirLetra(TDicionario *dicionario);
void UI_ExibirDicio(TDicionario *dicionario);
void UI_Ordenacoes(TDicionario *dicionario);
void UI_Sair();

