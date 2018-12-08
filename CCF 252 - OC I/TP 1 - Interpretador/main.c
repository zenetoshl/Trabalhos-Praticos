#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define TRUE 1
#define FALSE 0

int identificarOP(char *instrucao, char *operacao);
void identificarRs (char *instrucao,int *posicaoInicio, char *regs);
int identificarImediato (char *instrucao, int *posicaoInicio);
int tratarRegistrador (char *reg);
void binario(char *cadeia, int valor, int bits);

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Salvar estado atual */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    ///Cor Alterada
    /*SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);*/

    ///Voltando ao estado original
    /*SetConsoleTextAttribute(hConsole, saved_attributes);*/

///INICIO DECLARAR VARIAVEIS
    ///Operacoes;
    char addi[5] = {'a','d','d','i'};
    char andi[5] = {'a','n','d','i'};
    char add [4] = {'a','d','d'};
    char sub [4] = {'s','u','b'};
    char sll [4] = {'s','l','l'};
    char srl [4] = {'s','r','l'};
    char and [4] = {'a','n','d'};
    char or [3] = {'o','r'};
    char ori [4] = {'o','r','i'};
    char nor [4] = {'n','o','r'};
    char move[5] = {'m', 'o', 'v', 'e'};
    char clear[6] = {'c', 'l', 'e', 'a', 'r'};
    char not[4] = {'n', 'o', 't'};
    char slt[4] = {'s', 'l', 't'};
    ///FIM Operações;
    ///Variaveis para extrair as funções
    char cadeia[100], aux[17];
    char instrucao[50];
    char reg1 [10];
    char reg2 [10];
    char reg3 [10];
    int imediato;
    /// Fim Variaveis
    ///Variaveis que irão compor a cadeia de bits
    int valor;
    ///FIM Variaveis da cadeia
    cadeia[0] = '\0';
    aux[0] = '\0';
    int i=0;
    FILE *arqEXT;
    FILE *arqASM;
/// FIM DECLARAR VARIAVEIS
    arqASM = fopen("entrada.asm","r");
    arqEXT = fopen("saida.txt","w");
    if(arqASM == NULL)
    {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        printf("Nao foi possivel identificar o arquivo!\n");
    }
    while (fgets(instrucao,50,arqASM)!=NULL)
    {
        if(identificarOP(instrucao, addi) == TRUE)
        {
            i=5;
            binario(cadeia,8,6);
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            printf("OP = addi\n");
            identificarRs(instrucao,&i,reg1);
            valor = tratarRegistrador(reg1);
            binario(aux,valor,5);
            while (instrucao[i]==' ' || instrucao[i]== ',')
                i++;
            identificarRs(instrucao,&i,reg2);
            valor = tratarRegistrador(reg2);
            binario(cadeia,valor,5);
            while (instrucao[i]==' ' || instrucao[i]== ',')
                i++;
            imediato= identificarImediato(instrucao,&i);
            strcat(cadeia, aux);
            binario(cadeia,imediato,16);
            strcat(cadeia,"\n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            printf("%s",cadeia);
        }
        else if(identificarOP(instrucao,add) == TRUE)
        {
            i=4;
            binario(cadeia,0,6); ///op
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            printf("OP = add\n");
            identificarRs(instrucao,&i,reg1);
            valor = tratarRegistrador(reg1);
            binario(aux,valor,5); ///rd (rd e o terceiro registrador da cadeia, nao o primeiro...)
            while (instrucao[i]==' ' || instrucao[i]== ',')
                i++;
            identificarRs(instrucao,&i,reg2);
            valor = tratarRegistrador(reg2);
            binario(cadeia,valor,5); ///rs
            while (instrucao[i]==' ' || instrucao[i]== ',')
                i++;
            identificarRs(instrucao,&i,reg3);
            valor = tratarRegistrador(reg3);
            binario(cadeia,valor,5); ///rt
            strcat(cadeia,aux);
            binario(cadeia,0,5); ///shampt
            binario(cadeia,32,6); ///funct
            strcat(cadeia,"\n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            printf("%s",cadeia);
        }
        else if (identificarOP(instrucao,sub) == TRUE)
        {
            i=4;
            binario(cadeia,0,6);
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            printf("OP = sub\n");
            identificarRs(instrucao,&i,reg1);
            while (instrucao[i]==' ' || instrucao[i]== ',')
                i++;
            valor = tratarRegistrador(reg1);
            binario(aux,valor,5);
            identificarRs(instrucao,&i,reg2);
            while (instrucao[i]==' ' || instrucao[i]== ',')
                i++;
            valor = tratarRegistrador(reg2);
            binario(cadeia,valor,5);
            identificarRs(instrucao,&i,reg3);
            valor = tratarRegistrador(reg3);
            binario(cadeia,valor,5);
            strcat(cadeia,aux);
            binario(cadeia,0,5);
            binario(cadeia,34,6);
            strcat(cadeia,"\n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            printf("%s",cadeia);
        }
        else if (identificarOP(instrucao,sll) == TRUE)
        {
            i=4;
            binario(cadeia,0,11); ///op
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            printf("OP = sll\n");
            identificarRs(instrucao,&i,reg1);
            valor = tratarRegistrador(reg1);
            binario(aux,valor,5); ///rd (rd e o terceiro registrador da cadeia, nao o primeiro...)
            while (instrucao[i]==' ' || instrucao[i]== ',')
                i++;
            identificarRs(instrucao,&i,reg2);
            valor = tratarRegistrador(reg2);
            binario(cadeia,valor,5); ///rs
            while (instrucao[i]==' ' || instrucao[i]== ',')
                i++;
            strcat(cadeia,aux);
            imediato= identificarImediato(instrucao,&i);
            binario(cadeia,imediato,5); ///shampt
            binario(cadeia,0,6); ///funct
            strcat(cadeia,"\n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            printf("%s",cadeia);
        }
        else if (identificarOP(instrucao,srl) == TRUE)
        {
            i=4;
            binario(cadeia,0,11); ///op
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            printf("OP = srl\n");
            identificarRs(instrucao,&i,reg1);
            valor = tratarRegistrador(reg1);
            binario(aux,valor,5); ///rd (rd e o terceiro registrador da cadeia, nao o primeiro...)
            while (instrucao[i]==' ' || instrucao[i]== ',')
                i++;
            identificarRs(instrucao,&i,reg2);
            valor = tratarRegistrador(reg2);
            binario(cadeia,valor,5); ///rs
            while (instrucao[i]==' ' || instrucao[i]== ',')
                i++;
            strcat(cadeia,aux);
            imediato= identificarImediato(instrucao,&i);
            binario(cadeia,imediato,5); ///shampt
            binario(cadeia,2,6); ///funct
            strcat(cadeia,"\n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            printf("%s",cadeia);
        }
        else if(identificarOP(instrucao, andi) == TRUE)
        {
            i=5;
            binario(cadeia,12,6);
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            printf("OP = andi\n");
            identificarRs(instrucao,&i,reg1);
            valor = tratarRegistrador(reg1);
            binario(aux,valor,5);
            while (instrucao[i]==' ' || instrucao[i]== ',')
                i++;
            identificarRs(instrucao,&i,reg2);
            valor= tratarRegistrador(reg2);
            binario(cadeia,valor,5);
            while (instrucao[i]==' ' || instrucao[i]== ',')
                i++;
            imediato= identificarImediato(instrucao,&i);
            strcat(cadeia, aux);
            binario(cadeia,imediato,16);
            strcat(cadeia,"\n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            printf("%s",cadeia);
        }
        else if(identificarOP(instrucao,and) == TRUE)
        {
            i=4;
            binario(cadeia,0,6); ///op
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            printf("OP = and\n");
            identificarRs(instrucao,&i,reg1);
            valor = tratarRegistrador(reg1);
            binario(aux,valor,5); ///rd (rd e o terceiro registrador da cadeia, nao o primeiro...)
            while (instrucao[i]==' ' || instrucao[i]== ',')
                i++;
            identificarRs(instrucao,&i,reg2);
            valor = tratarRegistrador(reg2);
            binario(cadeia,valor,5); ///rs
            while (instrucao[i]==' ' || instrucao[i]== ',')
                i++;
            identificarRs(instrucao,&i,reg3);
            valor = tratarRegistrador(reg3);
            binario(cadeia,valor,5); ///rt
            strcat(cadeia,aux);
            binario(cadeia,0,5); ///shampt
            binario(cadeia,36,6); ///funct
            strcat(cadeia,"\n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            printf("%s",cadeia);
        }
        else if(identificarOP(instrucao,nor) == TRUE)
        {
            i=4;
            binario(cadeia,0,6); ///op
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            printf("OP = nor\n");
            identificarRs(instrucao,&i,reg1);
            valor = tratarRegistrador(reg1);
            binario(aux,valor,5); ///rd (rd e o terceiro registrador da cadeia, nao o primeiro...)
            while (instrucao[i]==' ' || instrucao[i]== ',')
                i++;
            identificarRs(instrucao,&i,reg2);
            valor = tratarRegistrador(reg2);
            binario(cadeia,valor,5); ///rs
            while (instrucao[i]==' ' || instrucao[i]== ',')
                i++;
            identificarRs(instrucao,&i,reg3);
            valor = tratarRegistrador(reg3);
            binario(cadeia,valor,5); ///rt
            strcat(cadeia,aux);
            binario(cadeia,0,5); ///shampt
            binario(cadeia,39,6); ///funct
            strcat(cadeia,"\n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            printf("%s",cadeia);
        }
        else if(identificarOP(instrucao, ori) == TRUE)
        {
            i=4;
            binario(cadeia,13,6);
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            printf("OP = ori\n");
            identificarRs(instrucao,&i,reg1);
            valor = tratarRegistrador(reg1);
            binario(aux,valor,5);
            while (instrucao[i]==' ' || instrucao[i]== ',')
                i++;
            identificarRs(instrucao,&i,reg2);
            valor= tratarRegistrador(reg2);
            binario(cadeia,valor,5);
            while (instrucao[i]==' ' || instrucao[i]== ',')
                i++;
            imediato= identificarImediato(instrucao,&i);
            strcat(cadeia, aux);
            binario(cadeia,imediato,16);
            strcat(cadeia,"\n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            printf("%s",cadeia);
        }
        else if(identificarOP(instrucao,or) == TRUE)
        {
            i=3;
            binario(cadeia,0,6); ///op
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            printf("OP = or\n");
            identificarRs(instrucao,&i,reg1);
            valor = tratarRegistrador(reg1);
            binario(aux,valor,5); ///rd (rd e o terceiro registrador da cadeia, nao o primeiro...)
            while (instrucao[i]==' ' || instrucao[i]== ',')
                i++;
            identificarRs(instrucao,&i,reg2);
            valor = tratarRegistrador(reg2);
            binario(cadeia,valor,5); ///rs
            while (instrucao[i]==' ' || instrucao[i]== ',')
                i++;
            identificarRs(instrucao,&i,reg3);
            valor = tratarRegistrador(reg3);
            binario(cadeia,valor,5); ///rt
            strcat(cadeia,aux);
            binario(cadeia,0,5); ///shampt
            binario(cadeia,37,6); ///funct
            strcat(cadeia,"\n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            printf("%s",cadeia);
        }
        else if(identificarOP(instrucao, move) == TRUE)
        {
            i=5;
            binario(cadeia,8,6);
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            printf("OP = move\n");
            identificarRs(instrucao,&i,reg1);
            valor = tratarRegistrador(reg1);
            binario(aux,valor,5);
            while (instrucao[i]==' ' || instrucao[i]== ',')
                i++;
            identificarRs(instrucao,&i,reg2);
            valor = tratarRegistrador(reg2);
            binario(cadeia,valor,5);
            while (instrucao[i]==' ' || instrucao[i]== ',')
                i++;
            imediato= 0;
            strcat(cadeia, aux);
            binario(cadeia,imediato,16);
            strcat(cadeia,"\n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            printf("%s",cadeia);
        }
        else if(identificarOP(instrucao, clear) == TRUE)
        {
            i=6;
            binario(cadeia,8,6);
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            printf("OP = clear\n");
            identificarRs(instrucao,&i,reg1);
            valor = tratarRegistrador(reg1);
            binario(aux,valor,5);
            while (instrucao[i]==' ' || instrucao[i]== ',')
                i++;
            valor = 0;
            binario(cadeia,valor,5);
            while (instrucao[i]==' ' || instrucao[i]== ',')
                i++;
            imediato= 0;
            strcat(cadeia, aux);
            binario(cadeia,imediato,16);
            strcat(cadeia,"\n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            printf("%s",cadeia);
        }
        else if(identificarOP(instrucao,not) == TRUE)
        {
            i=4;
            binario(cadeia,0,6); ///op
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            printf("OP = not\n");
            identificarRs(instrucao,&i,reg1);
            valor = tratarRegistrador(reg1);
            binario(aux,valor,5); ///rd (rd e o terceiro registrador da cadeia, nao o primeiro...)
            while (instrucao[i]==' ' || instrucao[i]== ',')
                i++;
            identificarRs(instrucao,&i,reg2);
            valor = tratarRegistrador(reg2);
            binario(cadeia,valor,5); ///rs
            while (instrucao[i]==' ' || instrucao[i]== ',')
                i++;
            valor = 0;
            binario(cadeia,valor,5); ///rt
            strcat(cadeia,aux);
            binario(cadeia,0,5); ///shampt
            binario(cadeia,39,6); ///funct
            strcat(cadeia,"\n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            printf("%s",cadeia);
        }
        else if(identificarOP(instrucao,slt) == TRUE)
        {
            i=4;
            binario(cadeia,0,6); ///op
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            printf("OP = slt\n");
            identificarRs(instrucao,&i,reg1);
            valor = tratarRegistrador(reg1);
            binario(aux,valor,5); ///rd (rd e o terceiro registrador da cadeia, nao o primeiro...)
            while (instrucao[i]==' ' || instrucao[i]== ',')
                i++;
            identificarRs(instrucao,&i,reg2);
            valor = tratarRegistrador(reg2);
            binario(cadeia,valor,5); ///rs
            while (instrucao[i]==' ' || instrucao[i]== ',')
                i++;
            identificarRs(instrucao,&i,reg3);
            valor = tratarRegistrador(reg3);
            binario(cadeia,valor,5); ///rt
            strcat(cadeia,aux);
            binario(cadeia,0,5); ///shampt
            binario(cadeia,42,6); ///funct
            strcat(cadeia,"\n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            printf("%s",cadeia);
        }
        else
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("ERRO 404:\n%snao existe\n",instrucao);
        }
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);

        ///printando no arquivo txt
        fprintf(arqEXT,"%s",cadeia);

        printf("-----------------------------------------------\n\n");
        cadeia[0]='\0';
        aux[0]='\0';
        i=0;
    }
    fclose(arqASM);
    fclose(arqEXT);
    return 0;
}
int identificarOP (char *instrucao, char *operacao)
{
    if(strstr(instrucao,operacao)!=NULL)
        return TRUE;
    else
        return FALSE;
}
void identificarRs (char *instrucao, int *posicaoInicio, char *regs)
{
    int k=0;
    char rs[10];
    while(instrucao[*posicaoInicio] != '\n' && instrucao[*posicaoInicio] != ' ' && instrucao[*posicaoInicio] != ',')
    {
        rs[k] = instrucao[*posicaoInicio];
        (*posicaoInicio) ++;
        k++;
    }
    rs[k] = '\0';
    strcpy(regs,rs);
    ///printf("RS: %s\n", regs);
}
int identificarImediato (char *instrucao, int *posicaoInicio)
{
    int i;
    char rs[10];
    identificarRs(instrucao,posicaoInicio,rs);
    i= atoi(rs);
    return i;
}

int tratarRegistrador (char *reg)
{
    int k=0;
    int i=0;
    char aux[1];
    if(reg[i] != '$')
        return -1;
    if(reg[i+1]== 'z')
        return 0;
    i+=2;
    aux[0]=reg[i];
    aux[1]='\0';
    k=atoi(aux);
    if(reg[1] == 'a')
        return 4+k;
    else if(reg[1] == 't')
    {
        if(k == 8)
        return 24;
        else if(k == 9)
        return 25;
        else
            return 8+k;
    }
    else if(reg[1] == 'v')
        return 2+k;
    else if(reg[i] == 'g')
        return 28;
    else if(reg[1] == 'f')
        return 30;
    else if(reg[1] == 'r')
        return 31;
    else if(reg[1] == 's')
    {
        if(reg[2] == 'p')
            return 29;
        else
            return 16+k;
    }
    else
        return -1;
}
void binario (char *cadeia, int valor, int bits)
{
    int tam,i;
    char aux[35], zeros[36];
    zeros[0] = '\0';
    itoa(valor,aux,2);
    tam = strlen(aux);
    for(i = 0; i < bits-tam; i++)
    {
        strcat(zeros,"0");
    }

    strcat(zeros,aux);
    tam = strlen(zeros);

    strcat(cadeia,&zeros[tam-bits]);
}
