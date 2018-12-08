// Algoritmo BMH

#ifndef BMH_H
#define BMH_H

#include <stdlib.h>
#include <string.h>

#include "param.h"
#include "list.h"
#include "cores.h"

void LeArq(char* txt, char* nomeArq);
LList BMHMatch(char* texto, char* padrao);
LList BMHColor(char* texto, char* padrao);

#endif