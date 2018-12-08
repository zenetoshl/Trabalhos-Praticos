#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "interface.h"

int main()
{
    TAdj adjacencias;
    TTimer timer;

    /* Foi mudada a localização do programa para possibilitar o uso de caracteres especiais do português
        nas mensagens da interface. */
    setlocale(LC_ALL,"");

    ADJInicializar(&adjacencias);
    UI_Menu(&adjacencias,&timer);

    return 0;
}
