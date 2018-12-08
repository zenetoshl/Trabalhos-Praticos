// Interface

#include "interface.h"

void CLILimparTela() {
    #ifdef WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void CLIImprimirCabecalho(char analise) {
    CLILimparTela();
    printf("\n  [ ...esdiseosn" CL_BG_CYAN CL_FG_BLACK "matching" CL_RESET "hxzsohqueroiquejoksemestrelacabe...]\n");
    printf("                ^      ^\n");
    printf("               [" CL_FG_CYAN "matching" CL_RESET "]\n\n");
    printf(" ======= C A S A M E N T O   D E   C A R A C T E R E S =======\n\n");
    if (analise)
        printf("                >>> ANALYSIS MODE ACTIVATED <<<\n\n");
}

void CLIMenu() {
    char analise = 0;
    char escolha[ESCOLHAMAX] = ".";

    while (escolha[0] != 'X') {
        CLIImprimirCabecalho(analise);

        printf("   Bem-vind@ ao analisador de algoritmos de casamento de caracteres!\n");
        printf("O que deseja fazer?\n\n");
        printf("B - Analisar BMH\n");
        printf("S - Analisar Shift-And\n");
        if (analise) printf("G - Análise múltipla para gráficos\n");
        printf("A - Alternar modo de Análise\n");
        printf("X - Sair\n\n");

        fgets(escolha, ESCOLHAMAX, stdin);
        escolha[0] = toupper(escolha[0]);
        switch (escolha[0]) {
            case 'B':
                CLIBMH(analise);
                break;
            case 'S':
                CLIShiftAnd(analise);
                break;
            case 'G':
                if (analise) {
                    CLIAnalise();
                    break;
                }
            case 'A':
                analise = !analise;
                printf("\n>>> %s Modo de Análise <<<\n", (analise) ? "Entrando no" : "Saindo do");
                printf("Pressione ENTER para continuar...\n");
                getchar();
                break;
            case 'X':
                printf("\nSaindo...\n");
                getchar();
                break;
            default:
                printf("\nComando não reconhecido. Pressione ENTER para continuar...\n");
                getchar();
        }
    }
}

void CLIBMH(char analise) {
    char escolha[ESCOLHAMAX] = "N";
    char texto[N + 1];
    char padrao[M + 1];
    Timer timer;
    LList matches;

    CLIImprimirCabecalho(analise);

    printf(">>> BMH\n");
    printf("Digite o texto a ser analisado:\n");
    fgets(texto, N + 1, stdin);
    texto[strlen(texto) - 1] = '\0';
    printf("\nDigite o padrão a ser procurado:\n");
    fgets(padrao, M + 1, stdin);
    padrao[strlen(padrao) - 1] = '\0';
    printf("\nDeseja usar o modo passo a passo? (s/N)\n");
    if (analise)
        printf("(O tempo é contado apenas no modo normal)\n");
    fgets(escolha, ESCOLHAMAX, stdin);
    escolha[0] = toupper(escolha[0]);
    if (escolha[0] == 'S') {
        matches = BMHColor(texto, padrao);
        printf("\nCasamentos encontrados: %d\n", LListTamanho(matches));
        LListImprimir(&matches);
    } else {
        TimerIniciar(&timer);
        matches = BMHMatch(texto, padrao);
        TimerParar(&timer);
        printf("\nCasamentos encontrados: %d\n", LListTamanho(matches));
        CLIMostrarMatches(texto, &matches);
        if (analise)
            printf(">>> Tempo gasto: %.6lf s\n", TimerTempoTotal(timer));
    }
    ESPERAR;
}

void CLIShiftAnd(char analise) {
    char escolha[ESCOLHAMAX] = "N";
    char texto[N + 1];
    char padrao[M + 1];
    Timer timer;
    LList matches;

    CLIImprimirCabecalho(analise);

    printf(">>> Shift-And\n");
    printf("Digite o texto a ser analisado:\n");
    fgets(texto, N + 1, stdin);
    texto[strlen(texto) - 1] = '\0';
    printf("\nDigite o padrão a ser procurado:\n");
    fgets(padrao, M + 1, stdin);
    padrao[strlen(padrao) - 1] = '\0';
    printf("\nDeseja usar o modo passo a passo? (s/N)\n");
    if (analise)
        printf("(O tempo é contado apenas no modo normal)\n");
    fgets(escolha, ESCOLHAMAX, stdin);
    escolha[0] = toupper(escolha[0]);
    if (escolha[0] == 'S') {
        matches = SHNColor(texto, padrao);
        printf("\nCasamentos encontrados: %d\n", LListTamanho(matches));
        LListImprimir(&matches);
    } else {
        TimerIniciar(&timer);
        matches = SHNMatch(texto, padrao);
        TimerParar(&timer);
        printf("\nCasamentos encontrados: %d\n", LListTamanho(matches));
        CLIMostrarMatches(texto, &matches);
        if (analise)
            printf(">>> Tempo gasto: %.6lf s\n", TimerTempoTotal(timer));
    }
    ESPERAR;
}

void CLIAnalise() {
    FILE *registro = NULL;
    Timer timer;
    char texto[N + 1];
    char padrao[M + 1];
    char arquivo[ARQUIVOMAX];
    char arqpadrao[ARQUIVOMAX];
    char arqsaida[ARQUIVOMAX];
    int i = 1;

    CLIImprimirCabecalho(1);

    printf("\n\tNesta opção você deve especificar um padrão para o nome dos arquivos,\nde modo que todos os arquivos na pasta especificada tenham o nome seguido de um número e a extensão \".txt\".\n");
    printf("Escolha um padrão de nome de arquivo:\n");
    fgets(arqpadrao, ARQUIVOMAX, stdin);
    arqpadrao[strlen(arqpadrao) - 1] = '\0';

    printf("\nDigite o padrão a ser procurado:\n");
    fgets(padrao, M + 1, stdin);
    padrao[strlen(padrao) - 1] = '\0';
    
    sprintf(arqsaida, "out/registro-%s.txt", padrao);
    registro = fopen(arqsaida, "wt");
    if (registro == NULL) {
        printf("ERRO: Falha ao criar arquivo de registro.\n");
        return;
    }

    while (1) {
        sprintf(arquivo, "%s%d.txt", arqpadrao, i);
        if (!CLILerTexto(arquivo, texto)) break;
        CLIEscreverRegistro(registro, (double)strlen(texto), 0);
        printf("Arquivo %d\n", i);
        TimerIniciar(&timer);
        printf("\t\tBMH: %d\t", LListTamanho(BMHMatch(texto, padrao)));
        TimerParar(&timer);
        printf("\tTempo: %.6lf\n", TimerTempoTotal(timer));
        CLIEscreverRegistro(registro, TimerTempoTotal(timer), 0);
        TimerIniciar(&timer);
        printf("\t\tShift-And: %d\t", LListTamanho(SHNMatch(texto, padrao)));
        TimerParar(&timer);
        printf("\tTempo: %.6lf\n", TimerTempoTotal(timer));
        CLIEscreverRegistro(registro, TimerTempoTotal(timer), 0);
        CLIEscreverRegistro(registro, 0.0, 1);
        i++;
    }
    fclose(registro);
    ESPERAR;
}

int CLILerTexto(char *dir, char *texto) {
    FILE *arq = NULL;
    arq = fopen(dir, "rt");
    char c;

    if (arq == NULL)
        return 0;
    
    while ((c = fgetc(arq)) != EOF)
        *texto++ = c;
    *texto = '\0';

    fclose(arq);
    return 1;
}

void CLIEscreverRegistro(FILE *out, double val, char nl) {
    if (out == NULL) return;
    if (nl) fputc('\n', out);
    else fprintf(out, "%.6lf,", val);
}

void CLIMostrarMatches(char *texto, LList *matches) {
    int i;
    Indices ind = LListRetirar(matches);
    for (i = 0; texto[i]; i++) {
        if (i == ind.i) printf(CL_FG_GREEN);
        putchar(texto[i]);
        if (i == ind.j) {
            do {
                ind = LListRetirar(matches);
            } while (ind.j != -1 && ind.j < i);
            if (ind.i > i || ind.i == -1)
                printf(CL_RESET);
        }
    }
    putchar('\n');
}