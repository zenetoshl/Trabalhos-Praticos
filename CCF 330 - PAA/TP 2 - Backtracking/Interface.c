//
// Created by neto on 25/10/18.
//
#include "Interface.h"

void TelaInicial(){
    int op;
    int isAnalise = 0;
    while (1) {
        printf("=Escolha: \n");
        printf("\n1 - Sudoku");
        printf("\n2 - Caca Palavras");
        printf("\n3 - Ativar modo de analise");
        printf("\n4 - Encerrar execucao\n");
        scanf("%d", &op);
        getchar();
        switch (op) {
            case 1:
                TelaSudoku(isAnalise);
                break;
            case 2:
                TelaCacaPalavras(isAnalise);
                break;
            case 3:
                isAnalise = TelaAnalise();
                break;
            case 4:
                return;
            default:
                printf("Opcao invalida!");
                getchar();
        }
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    }
}
void TelaSudoku(int isAnalise) {
    char op;
    char nome[50];
    int i, opcaoSudoku;
    ListaSudoku sudoku;
    AnaliseSudoku ana;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("deseja ler um arquivo especifico? (S/N) (se nao o padrao sera lido)\n");
    scanf("%c", &op);
    toupper(op);
    getchar();
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    while (1) {
    switch (op) {
        case 'S':
            scanf("%s", nome);
            getchar();
            LerArquivo(&sudoku, nome);
            break;
        default:
            LerArquivo(&sudoku, "sudoku.txt");
    }
        printf("Qual sudoku escolher? (entre com um numero negativo para voltar) \n");
        for (i = 0; i < TAM; i++) {
            printf("%d:\n", i);
            PrintSudoku(sudoku.listaSudoku[i]);
            printf("\n");
        }
        scanf("%d", &opcaoSudoku);
        getchar();
        ana.chamadasRecursivas = 0;
        if(opcaoSudoku < 0)
            return;
        if (BacktrakingSudoku(&sudoku.listaSudoku[opcaoSudoku], 0, 0, &ana)) {
            PrintSudoku(sudoku.listaSudoku[opcaoSudoku]);
        } else {
            printf("Sudoku nao tem solucao!");
        }
        if(isAnalise)
            printf("\n\nNumero de chamadas recursivas: %d", ana.chamadasRecursivas);
        getchar();
    }


}
void TelaCacaPalavras(int isAnalise){
    char op;
    char nome[50], palavra[50];
    CacaPalavra cacaPalavra;
    AnaliseCaca ana;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("deseja ler um arquivo especifico? (S/N) (se nao o padrao sera lido)\n");
    scanf("%c", &op);
    toupper(op);
    getchar();
    switch(op){
        case 'S':
            scanf("%s", nome);
            LerArq(&cacaPalavra, nome);
            break;
        default:
            LerArq(&cacaPalavra, "cacapalavra.txt");
    }
    ana.chamadasRecursivas = 0;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("Qual palavra deseja procurar?\n");
    scanf("%s", palavra);
    Procura(&cacaPalavra, palavra, &ana);
    PrintCacaPalavra(cacaPalavra);
    if(isAnalise)
        printf("\n\nNumero de chamadas recursivas: %d", ana.chamadasRecursivas);
    getchar();
}

int TelaAnalise(){
    char op;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("deseja mesmo ativar o modo de analise? (S/N)\n");
    scanf("%c", &op);
    toupper(op);
    getchar();
    switch (op) {
        case 'S':
            return 1;
    } return 0;

}