#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "interface.h"

int main()
{
    TDicionario dicionario;

    /* Foi mudada a localização do programa para possiblitar o uso de caracteres especiais do português
        nas mensagens da interface. */
    setlocale(LC_ALL,"");

    DICInicializar(&dicionario);

    UI_MenuPrincipal(&dicionario);

    return 0;
}
