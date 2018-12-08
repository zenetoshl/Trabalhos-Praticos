// Shift-And

#ifndef SHIFTAND_H
#define SHIFTAND_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "param.h"
#include "list.h"
#include "cores.h"

void  SHNCriarMascaras(long mascaras[C], char *padrao);
LList SHNMatch(char *texto, char *padrao);
LList SHNColor(char *texto, char *padrao);

#endif