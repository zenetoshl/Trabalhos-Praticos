// Shift-And

#include "shiftand.h"

void SHNCriarMascaras(long mascaras[C], char *padrao) {
    int set = 1;
    for (; *padrao; padrao++, set <<= 1)
        mascaras[(unsigned int)*padrao] |= set;
}

LList SHNMatch(char *texto, char *padrao) {
    LList matches = LListCriar();
    long mascaras[C] = { 0 };
    long R = 0;
    long ultimo = 1;
    int i, m = strlen(padrao) - 1;

    if (texto[0] == '\0' || padrao[0] == '\0')
        return matches;
    
    ultimo <<= m;
    SHNCriarMascaras(mascaras, padrao);
    for (i = 0; texto[i]; i++) {
        R = ((R << 1) | 1) & mascaras[(unsigned int)texto[i]];
        if (R & ultimo)
            LListInserir(&matches, i - m, i);
    }
    return matches;
}

LList SHNColor(char *texto, char *padrao) {
    LList matches = LListCriar();
    long mascaras[C] = { 0 };
    long R = 0, Ri;
    long ultimo = 1;
    int i, j, m = strlen(padrao) - 1;

    if (texto[0] == '\0' || padrao[0] == '\0')
        return matches;
    
    ultimo <<= m;
    SHNCriarMascaras(mascaras, padrao);
    for (i = 0; texto[i]; i++) {
        R = ((R << 1) | 1) & mascaras[(unsigned int)texto[i]];
        Ri = R;
        printf(CL_RESET "%c -> ", texto[i]);
        for (j = 0; j <= m; j++, Ri >>= 1)
            printf("%s%c", (Ri % 2) ? CL_FG_GREEN : CL_FG_RED, padrao[j]);
        
        if (R & ultimo) {
            printf(CL_RESET " <- match! [" CL_FG_GREEN "%d" CL_RESET "," CL_FG_GREEN "%d" CL_RESET "]", i - m, i);
            LListInserir(&matches, i - m, i);
        }
        printf(CL_RESET "\n");
    }
    return matches;
}