// BMH

#include "bmh.h"

LList BMHMatch(char *texto, char *padrao){
    LList lista = LListCriar();
    int tamPadrao = strlen(padrao);
    int tamTexto = strlen(texto);
    int d[C];
    int i, j, k;

    for (i = 0; i < C; i++)
        d[i] = tamPadrao;

    for (i = 1; i < tamPadrao; i++)
        d[(unsigned int)padrao[i - 1]] = tamPadrao - i;

    i = tamPadrao;
    while (i <= tamTexto) {
        j = tamPadrao - 1;
        k = i - 1;

        while (texto[k] == padrao[j] && j > 0) {
            k--; j--;
        }

        if (texto[k] == padrao[j] && j == 0)
            LListInserir(&lista, k, k + tamPadrao - 1);

        i = i + d[(unsigned int)texto[i - 1]];
    }
    return lista;
}

LList BMHColor(char *texto, char *padrao) {
    LList lista = LListCriar();
    int tamPadrao = strlen(padrao);
    int tamTexto = strlen(texto);
    char *vetorColor = (char *)malloc(tamTexto * sizeof(char));
    int inicio, breakPoint, fim; //auxiliares do vetor de cores
    int d[C];
    int i, j, k, h;
    
    printf("%s\n", texto);

    for (i = 0; i < C; i++)
        d[i] = tamPadrao;

    for (i = 1; i < tamPadrao; i++)
        d[(unsigned int)padrao[i - 1]] = tamPadrao - i;

    i = tamPadrao;
    while (i <= tamTexto) {
        j = tamPadrao - 1;
        k = i - 1;
        fim = k;
        inicio = k - tamPadrao + 1;
        breakPoint = k + 1;

        for (h = 0; h < tamTexto + 1; h++)
            vetorColor[h] = '*';

        while(texto[k] == padrao[j] && j > 0){
            breakPoint = k;
            k = k - 1;
            j = j - 1;
        }

        if (texto[k] == padrao[j] && j == 0) {
            breakPoint = k;
            LListInserir(&lista, k, k + tamPadrao - 1);
        }
        i = i + d[(unsigned int)texto[i - 1]];
        
        h = tamPadrao;
        for (j  = fim + 1; h >= 0; j--) {
            vetorColor[j] = padrao[h];
            h--;
        }

        printf(CL_FG_GRAY);
        for (j = 0; j < tamTexto + 1; j++) {
            if (breakPoint == j && inicio == j) //deu match
                printf(CL_FG_GREEN);
            else if (inicio == j) //nao deu match
                printf(CL_FG_RED);
            else if (breakPoint == j && breakPoint < fim + 1) //match parcial
                printf(CL_FG_YELLOW);
            else if (fim + 1 == j) //asteriscos
                printf(CL_RESET CL_FG_GRAY);
            printf("%c", vetorColor[j]);  
        }
        printf(CL_RESET "\n");
    }
    return lista;
}